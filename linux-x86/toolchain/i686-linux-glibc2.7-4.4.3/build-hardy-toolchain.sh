#!/bin/sh
#
# Copyright (C) 2010 The Android Open Source Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

# This script is used to rebuild the Linux 32-bit cross-toolchain
# that allows you to generate 32-bit binaries that target Ubuntu 8.04
# (a.k.a. Hardy Heron) instead of the host system (which usually is 10.04,
# a.k.a. Lucid Lynx)
#

# You will need a working NDK install or working directory (which is used
# to download and patch the toolchain sources from android.git.kernel.org)
#
# Define the NDK variable in your environment before calling this script,
# or it will complain loudly. For example, you can invoke it as:
#
#  export NDK=/path/to/ndk
#  ./uild-hardy-toolchain.sh
#
# Then *wait* for a very long time (about 13minutes on an 8-core HP z600)
# A package file will be generated in /tmp, its name dumped by the script
# in case of success.
#
# There are no command-line options right now, modify the definitions under
# the "CONFIGURATION" section below if you want to change stuff.
#

###########################################################################
###########################################################################
#####
#####  C O N F I G U R A T I O N
#####
###########################################################################
###########################################################################

# We only support running this script on Linux
OS=`uname -s`
case "$OS" in
    Linux)
        OS=linux
        ;;
    *)
        echo "ERROR: This script can only run on Linux!"
        exit 1
        ;;
esac

# Set V to 1 to enable verbose mode
V=${V:-0}

# Location of temporary directory where everything will be downloaded
# configured, built and installed before we generate the final
# package archive
ROOT_DIR=/tmp/gcc-hardy32
mkdir -p $ROOT_DIR

# Location where we download packages from the Ubuntu servers
DOWNLOAD_DIR=$ROOT_DIR/download

# Location of the Android NDK
if [ -z "$NDK" ] ; then
    echo "ERROR: Please define the NDK variable to point to a valid"
    echo "       NDK directory (installation or git repository)."
    echo "       This is needed to download the toolchain sources."
    exit 1
fi

NDK_DOWNLOAD_TOOLCHAIN_SOURCES_SH="$NDK/build/tools/download-toolchain-sources.sh"
if [ ! -f "$NDK_DOWNLOAD_TOOLCHAIN_SOURCES_SH" ] ; then\
    echo "ERROR: Missing script: $NDK_DOWNLOAD_TOOLCHAIN_SOURCES_SH"
    echo "Your NDK variable probably points to an invalid directory!"
    exit 1
fi

# Versions of various toolchain components, do not touch unless you know
# what you're doing!
BINUTILS_VERSION=2.19
GMP_VERSION=4.2.4
MPFR_VERSION=2.4.1
GCC_VERSION=4.4.3
GCC_TARGET=i686-linux
GMP_TARGET=i386-linux

# Location where we will download the toolchain sources
TOOLCHAIN_SRC_DIR=$ROOT_DIR/toolchain-src

# Location of original sysroot
# You must create it with the "hardy-sysroot.sh" script
ORG_SYSROOT_DIR=$ROOT_DIR/sysroot

# Name of the final generated toolchain
TOOLCHAIN_NAME=$GCC_TARGET-glibc2.7-$GCC_VERSION

# Name of the final toolchain binary tarball that this script will create
TOOLCHAIN_ARCHIVE=/tmp/$TOOLCHAIN_NAME.tar.bz2

# Location where we're going to install the toolchain
INSTALL_DIR=$ROOT_DIR/$TOOLCHAIN_NAME

# Location of the final sysroot. This must be a sub-directory of INSTALL_DIR
# to ensure that the toolchain binaries are properly relocatable (i.e. can
# be used when moved to another directory).
SYSROOT_DIR=$INSTALL_DIR/sysroot

# Try to parallelize the build for faster performance.
NUM_CPUS=`cat /proc/cpuinfo | grep processor | wc -l`
MAKE_FLAGS="-j$NUM_CPUS"

# The list of packages we need to download from the Ubuntu servers and
# extract into the original sysroot
UBUNTU_PACKAGES=

add_ubuntu_package ()
{
    UBUNTU_PACKAGES="$UBUNTU_PACKAGES $@"
}

# The package files containing kernel headers for Hardy and the C
# library headers and binaries
add_ubuntu_package \
    http://mirrors.us.kernel.org/ubuntu//pool/main/l/linux/linux-libc-dev_2.6.24-28.81_i386.deb \
    http://security.ubuntu.com/ubuntu/pool/main/g/glibc/libc6_2.7-10ubuntu7_i386.deb \
    http://security.ubuntu.com/ubuntu/pool/main/g/glibc/libc6-dev_2.7-10ubuntu7_i386.deb

# The X11 headers and binaries (for the emulator)
add_ubuntu_package \
    http://mirrors.us.kernel.org/ubuntu//pool/main/libx/libx11/libx11-6_1.1.3-1ubuntu2_i386.deb \
    http://mirrors.us.kernel.org/ubuntu//pool/main/libx/libx11/libx11-dev_1.1.3-1ubuntu2_i386.deb \
    http://mirrors.us.kernel.org/ubuntu//pool/main/x/x11proto-core/x11proto-core-dev_7.0.11-1_all.deb \
    http://mirrors.us.kernel.org/ubuntu//pool/main/x/x11proto-xext/x11proto-xext-dev_7.0.2-5ubuntu1_all.deb \
    http://mirrors.us.kernel.org/ubuntu//pool/main/x/x11proto-input/x11proto-input-dev_1.4.2-1_all.deb \
    http://mirrors.us.kernel.org/ubuntu//pool/main/x/x11proto-kb/x11proto-kb-dev_1.0.3-2ubuntu1_all.deb

# Audio libraries (required by the emulator)
add_ubuntu_package \
    http://mirrors.us.kernel.org/ubuntu//pool/main/a/alsa-lib/libasound2_1.0.15-3ubuntu4_i386.deb \
    http://mirrors.us.kernel.org/ubuntu//pool/main/a/alsa-lib/libasound2-dev_1.0.15-3ubuntu4_i386.deb \
    http://mirrors.us.kernel.org/ubuntu//pool/main/e/esound/libesd-alsa0_0.2.38-0ubuntu9_i386.deb \
    http://mirrors.us.kernel.org/ubuntu//pool/main/e/esound/libesd0-dev_0.2.38-0ubuntu9_i386.deb \
    http://security.ubuntu.com/ubuntu/pool/main/a/audiofile/libaudiofile-dev_0.2.6-7ubuntu1.8.04.1_i386.deb \
    http://security.ubuntu.com/ubuntu/pool/main/p/pulseaudio/libpulse0_0.9.10-1ubuntu1.1_i386.deb \
    http://security.ubuntu.com/ubuntu/pool/main/p/pulseaudio/libpulse-dev_0.9.10-1ubuntu1.1_i386.deb

# ZLib
add_ubuntu_package \
    http://mirrors.us.kernel.org/ubuntu//pool/main/z/zlib/zlib1g_1.2.3.3.dfsg-7ubuntu1_i386.deb \
    http://mirrors.us.kernel.org/ubuntu//pool/main/z/zlib/zlib1g-dev_1.2.3.3.dfsg-7ubuntu1_i386.deb \
    http://mirrors.us.kernel.org/ubuntu//pool/main/n/ncurses/libncurses5_5.6+20071124-1ubuntu2_i386.deb \
    http://mirrors.us.kernel.org/ubuntu//pool/main/n/ncurses/libncurses5-dev_5.6+20071124-1ubuntu2_i386.deb

###########################################################################
###########################################################################
#####
#####  E N D   O F   C O N F I G U R A T I O N
#####
###########################################################################
###########################################################################

panic ()
{
    echo "ERROR: $@"
    exit 1
}

fail_panic ()
{
    if [ $? != 0 ] ; then
        echo "ERROR: $@"
        exit 1
    fi
}

if [ "$V" != 0 ] ; then
    run () {
        echo "## COMMAND: $@"
        $@
    }
else
    run () {
        $@ >>$TMPLOG 2>&1
    }
fi

OLD_PATH="$PATH"
OLD_LD_LIBRARY_PATH="$LD_LIBRARY_PATH"

BUILD_DIR=$ROOT_DIR/build
mkdir -p $BUILD_DIR

TMPLOG=$BUILD_DIR/build.log
rm -rf $TMPLOG && touch $TMPLOG

BUILD_BINUTILS_DIR=$BUILD_DIR/binutils
BUILD_GMP_DIR=$BUILD_DIR/gmp
BUILD_MPFR_DIR=$BUILD_DIR/mpfr
BUILD_GCC_DIR=$BUILD_DIR/gcc

TIMESTAMPS_DIR=$BUILD_DIR/timestamps
mkdir -p $TIMESTAMPS_DIR

if [ "$V" = 0 ] ; then
    echo "To follow build, run: tail -F $TMPLOG"
fi

# returns 0 iff the string in $2 matches the pattern in $1
# $1: pattern
# $2: string
pattern_match ()
{
    echo "$2" | grep -q -E -e "$1"
}

# Find if a given shell program is available.
# We need to take care of the fact that the 'which <foo>' command
# may return either an empty string (Linux) or something like
# "no <foo> in ..." (Darwin). Also, we need to redirect stderr
# to /dev/null for Cygwin
#
# $1: variable name
# $2: program name
#
# Result: set $1 to the full path of the corresponding command
#         or to the empty/undefined string if not available
#
find_program ()
{
    local PROG
    PROG=`which $2 2>/dev/null`
    if [ -n "$PROG" ] ; then
        if pattern_match '^no ' "$PROG"; then
            PROG=
        fi
    fi
    eval $1="$PROG"
}

# Copy a directory, create target location if needed
#
# $1: source directory
# $2: target directory location
#
copy_directory ()
{
    local SRCDIR="$1"
    local DSTDIR="$2"
    if [ ! -d "$SRCDIR" ] ; then
        panic "Can't copy from non-directory: $SRCDIR"
    fi
    mkdir -p "$DSTDIR" && (cd "$SRCDIR" && tar cf - *) | (tar xf - -C "$DSTDIR")
    fail_panic "Cannot copy to directory: $DSTDIR"
}

find_program CMD_WGET wget
find_program CMD_CURL curl
find_program CMD_SCRP scp

# Download a file with either 'curl', 'wget' or 'scp'
#
# $1: source URL (e.g. http://foo.com, ssh://blah, /some/path)
# $2: target file
download_file ()
{
    # Is this HTTP, HTTPS or FTP ?
    if pattern_match "^(http|https|ftp):.*" "$1"; then
        if [ -n "$CMD_WGET" ] ; then
            run $CMD_WGET -O $2 $1
        elif [ -n "$CMD_CURL" ] ; then
            run $CMD_CURL -o $2 $1
        else
            echo "Please install wget or curl on this machine"
            exit 1
        fi
        return
    fi

    # Is this SSH ?
    # Accept both ssh://<path> or <machine>:<path>
    #
    if pattern_match "^(ssh|[^:]+):.*" "$1"; then
        if [ -n "$CMD_SCP" ] ; then
            scp_src=`echo $1 | sed -e s%ssh://%%g`
            run $CMD_SCP $scp_src $2
        else
            echo "Please install scp on this machine"
            exit 1
        fi
        return
    fi

    # Is this a file copy ?
    # Accept both file://<path> or /<path>
    #
    if pattern_match "^(file://|/).*" "$1"; then
        cp_src=`echo $1 | sed -e s%^file://%%g`
        run cp -f $cp_src $2
        return
    fi

    # Unknown schema
    echo "ERROR: Unsupported source URI: $1"
    exit 1
}

# A variant of 'download_file' used to specify the target directory
# $1: source URL
# $2: target directory
download_file_to ()
{
    local URL="$1"
    local DIR="$2"
    local DST="$DIR/`basename $URL`"
    mkdir -p $DIR
    download_file "$URL" "$DST"
}

# Pack a given archive
#
# $1: archive file path (including extension)
# $2: source directory for archive content
# $3+: list of files (including patterns), all if empty
pack_archive ()
{
    local ARCHIVE="$1"
    local SRCDIR="$2"
    local SRCFILES
    local TARFLAGS ZIPFLAGS
    shift; shift;
    if [ -z "$1" ] ; then
        SRCFILES="*"
    else
        SRCFILES="$@"
    fi
    if [ "`basename $ARCHIVE`" = "$ARCHIVE" ] ; then
        ARCHIVE="`pwd`/$ARCHIVE"
    fi
    mkdir -p `dirname $ARCHIVE`
    if [ "$VERBOSE2" = "yes" ] ; then
        TARFLAGS="vcf"
        ZIPFLAGS="-9r"
    else
        TARFLAGS="cf"
        ZIPFLAGS="-9qr"
    fi
    case "$ARCHIVE" in
        *.zip)
            (cd $SRCDIR && run zip $ZIPFLAGS "$ARCHIVE" $SRCFILES)
            ;;
        *.tar)
            (cd $SRCDIR && run tar $TARFLAGS "$ARCHIVE" $SRCFILES)
            ;;
        *.tar.gz)
            (cd $SRCDIR && run tar z$TARFLAGS "$ARCHIVE" $SRCFILES)
            ;;
        *.tar.bz2)
            (cd $SRCDIR && run tar j$TARFLAGS "$ARCHIVE" $SRCFILES)
            ;;
        *)
            panic "Unsupported archive format: $ARCHIVE"
            ;;
    esac
}

# Does the host compiler generate 32-bit machine code?
# If not, add the -m32 flag to the compiler name to ensure this.
#
compute_host_flags ()
{
    HOST_CC=${CC:-gcc}
    HOST_CXX=${CXX-g++}
    echo -n "Checking for ccache..."
    find_program CMD_CCACHE ccache
    if [ -n "$CMD_CCACHE" ] ; then
        echo "$HOST_CC" | tr ' ' '\n' | grep -q -e "ccache"
        if [ $? = 0 ] ; then
            echo "yes (ignored)"
        else
            echo "yes"
            HOST_CC="ccache $HOST_CC"
            HOST_CXX="ccache $HOST_CXX"
        fi
    else
        echo "no"
    fi
    echo -n "Checking whether the compiler generates 32-bit code... "
    cat > $BUILD_DIR/conftest.c << EOF
    /* This will fail to compile if void* is not 32-bit */
    int test_array[1 - 2*(sizeof(void*) != 4)];
EOF
    $HOST_CC -o $BUILD_DIR/conftest.o -c $BUILD_DIR/conftest.c > $BUILD_DIR/conftest.log 2>&1
    if [ $? != 0 ] ; then
        echo "no"
        HOST_CC="$HOST_CC -m32"
        HOST_CXX="$HOST_CXX -m32"
    else
        echo "yes"
    fi
    export CC="$HOST_CC"
    export CXX="$HOST_CXX"
}

compute_host_flags

# Return the value of a given named variable
# $1: variable name
#
# example:
#    FOO=BAR
#    BAR=ZOO
#    echo `var_value $FOO`
#    will print 'ZOO'
#
var_value ()
{
    # find a better way to do that ?
    eval echo "$`echo $1`"
}

var_list_append ()
{
    local VARNAME=$1
    local VARVAL=`var_value $VARNAME`
    shift
    if [ -z "$VARVAL" ] ; then
        eval $VARNAME=\"$@\"
    else
        eval $VARNAME=\"$VARVAL $@\"
    fi
}

var_list_prepend ()
{
    local VARNAME=$1
    local VARVAL=`var_value $VARNAME`
    shift
    if [ -z "$VARVAL" ] ; then
        eval $VARNAME=\"$@\"
    else
        eval $VARNAME=\"$@ $VARVAL\"
    fi
}

_list_first ()
{
    echo $1
}

_list_rest ()
{
    shift
    echo "$@"
}

var_list_pop_first ()
{
    local VARNAME=$1
    local VARVAL=`var_value $VARNAME`
    local FIRST=`_list_first $VARVAL`
    eval $VARNAME=\"`_list_rest $VARVAL`\"
    echo "$FIRST"
}

_list_first ()
{
    echo $1
}

_list_rest ()
{
    shift
    echo "$@"
}

var_list_first ()
{
    local VAL=`var_value $1`
    _list_first $VAL
}

var_list_rest ()
{
    local VAL=`var_value $1`
    _list_rest $VAL
}

ALL_TASKS=

# Define a new task for this build script
# $1: Task name (e.g. build_stuff)
# $2: Task description
# $3: Optional: command name (will be cmd_$1 by default)
#
task_define ()
{
    local TASK="$1"
    local DESCR="$2"
    local COMMAND="${3:-cmd_$1}"

    var_list_append ALL_TASKS $TASK
    task_set $TASK name "$TASK"
    task_set $TASK descr "$DESCR"
    task_set $TASK cmd "$COMMAND"
    task_set $TASK deps ""
}

task_set ()
{
    local TASK="$1"
    local FIELD="$2"
    shift; shift;
    eval TASK_${TASK}__${FIELD}=\"$@\"
}

task_get ()
{
    var_value TASK_$1__$2
}

# return the list of dependencies for a given task
task_get_deps ()
{
    task_get $1 deps
}

task_get_cmd ()
{
    task_get $1 cmd
}

task_get_descr ()
{
    task_get $1 descr
}

# $1: task name
# $2+: other tasks this task depends on.
task_depends ()
{
    local TASK="$1"
    shift;
    var_list_append TASK_${TASK}__deps $@
}

task_dump ()
{
    local TASK
    for TASK in $ALL_TASKS; do
        local DEPS="`task_get_deps $TASK`"
        local CMD="`task_get_cmd $TASK`"
        local DESCR="`task_get_descr $TASK`"
        echo "TASK $TASK: $DESCR: $CMD"
        echo ">  $DEPS"
    done
}

task_visit ()
{
    task_set $TASK visit 1
}

task_unvisit ()
{
    task_set $TASK visit 0
}

task_is_visited ()
{
    [ `task_get $TASK visit` = 1 ]
}

task_queue_reset ()
{
    TASK_QUEUE=
}

task_queue_push ()
{
    var_list_append TASK_QUEUE $1
}

task_queue_pop ()
{
    local FIRST=`var_list_first TASK_QUEUE`
    TASK_QUEUE=`var_list_rest TASK_QUEUE`
}

do_all_tasks ()
{
    local TASK
    local TASK_LIST=
    task_queue_reset
    # Clear visit flags
    for TASK in $ALL_TASKS; do
        task_unvisit $TASK
    done
    task_queue_push $1
    while [ -n "$TASK_QUEUE" ] ; do
        TASK=`task_queue_pop`
        if task_is_visited $TASK; then
            continue
        fi
        # Prepend the task to the list if its timestamp is not set
        if [ ! -f $TIMESTAMPS_DIR/$TASK ]; then
            var_list_prepend TASK_LIST $TASK
        fi
        # Add all dependencies to the work-queue
        local SUBTASK
        for SUBTASK in `task_get_deps $TASK`; do
            task_queue_push $SUBTASK
        done
        task_visit $TASK
    done

    # Now, TASK_LIST contains the
}

do_task ()
{
    local TASK="$1"
    local DEPS="`task_get_deps $TASK`"
    local DESCR="`task_get_descr $TASK`"
    local DEP
    #echo ">> $TASK: $DEPS"
    if [ -f "$TIMESTAMPS_DIR/$TASK" ] ; then
        echo "Skipping $1: already done."
        return 0
    fi

    # do_task for any dependents
    for DEP in $DEPS; do
        #echo "  ? $DEP"
        if [ ! -f "$TIMESTAMPS_DIR/$DEP" ] ; then
            do_task $DEP
        fi
    done

    echo "Running: $DESCR"
    if [ "$V" != 0 ] ; then
        eval `task_get_cmd $TASK`
    else
        eval `task_get_cmd $TASK` >> $TMPLOG 2>&1
    fi
    if [ $? != 0 ] ; then
        echo "ERROR: Cannot $DESCR"
        exit 1
    fi

    touch "$TIMESTAMPS_DIR/$TASK"
}

task_define download_toolchain_sources "Download toolchain sources from android.git.kernel.org"
cmd_download_toolchain_sources ()
{
    $NDK_DOWNLOAD_TOOLCHAIN_SOURCES_SH $TOOLCHAIN_SRC_DIR
}

task_define download_packages "Download Ubuntu packages"
cmd_download_packages ()
{
    local PACKAGE

    mkdir -p $DOWNLOAD_DIR &&
    for PACKAGE in $UBUNTU_PACKAGES; do
        echo "Downloading $PACKAGE"
        download_file_to $PACKAGE $DOWNLOAD_DIR
    done
}

task_define build_sysroot "Build sysroot"
task_depends build_sysroot download_packages

cmd_build_sysroot ()
{
    local PACKAGE
    for PACKAGE in $UBUNTU_PACKAGES; do
        local SRC_PKG=$DOWNLOAD_DIR/`basename $PACKAGE`
        echo "Extracting $SRC_PKG"
        dpkg -x $SRC_PKG $ORG_SYSROOT_DIR/
    done
}

# Now, we need to patch libc.so which is actually a linker script
# referencing /lib and /usr/lib. Do the same for libpthread.so
patch_library ()
{
    echo "Patching $1"
    sed -i -e "s! /lib/! !g" -e "s! /usr/lib/! !g" $1
}

task_define copy_sysroot "Fix and copy sysroot"
task_depends copy_sysroot build_sysroot
cmd_copy_sysroot ()
{
    local SL

    # Copy the content of $BUILD_DIR/lib to $SYSROOT_DIR/usr/lib
    copy_directory $ORG_SYSROOT_DIR/lib $SYSROOT_DIR/usr/lib
    copy_directory $ORG_SYSROOT_DIR/usr/lib $SYSROOT_DIR/usr/lib
    copy_directory $ORG_SYSROOT_DIR/usr/include $SYSROOT_DIR/usr/include

    # We need to fix the symlink like librt.so -> /lib/librt.so.1
    # in $SYSROOT_DIR/usr/lib, they should point to librt.so.1 instead now.
    SYMLINKS=`ls -l $SYSROOT_DIR/usr/lib | grep /lib/ | awk '{ print $11; }'`
    cd $SYSROOT_DIR/usr/lib
    for SL in $SYMLINKS; do
        # convert /lib/libfoo.so.<n> into 'libfoo.so.<n>' for the target
        local DST=`echo $SL | sed -e 's!^/lib/!!g'`
        # convery libfoo.so.<n> into libfoo.so for the source
        local SRC=`echo $DST | sed -e 's!\.[0-9]*$!!g'`
        echo "Fixing symlink $SRC --> $DST"
        ln -sf $DST $SRC
    done

    patch_library $SYSROOT_DIR/usr/lib/libc.so
    patch_library $SYSROOT_DIR/usr/lib/libpthread.so
}



task_define configure_binutils "Configure binutils-$BINUTILS_VERSION"
task_depends configure_binutils download_toolchain_sources copy_sysroot
cmd_configure_binutils ()
{
    OUT_DIR=$BUILD_BINUTILS_DIR
    mkdir -p $OUT_DIR && cd $OUT_DIR &&
    $TOOLCHAIN_SRC_DIR/binutils/binutils-$BINUTILS_VERSION/configure \
        --prefix=$INSTALL_DIR \
        --with-sysroot=$SYSROOT_DIR \
        --target=$GCC_TARGET
}

task_define build_binutils "Build binutils-$BINUTILS_VERSION"
task_depends build_binutils configure_binutils
cmd_build_binutils ()
{
    cd $BUILD_BINUTILS_DIR &&
    make $MAKE_FLAGS
}

task_define install_binutils "Install binutils-$BINUTILS_VERSION"
task_depends install_binutils build_binutils

cmd_install_binutils ()
{
    cd $BUILD_BINUTILS_DIR &&
    make install
}

task_define extract_gmp "Extract sources for gmp-$GMP_VERSION"
task_depends extract_gmp download_toolchain_sources
cmd_extract_gmp ()
{
    OUT_DIR=$BUILD_GMP_DIR
    mkdir -p $OUT_DIR && cd $OUT_DIR &&
    tar xjf $TOOLCHAIN_SRC_DIR/gmp/gmp-$GMP_VERSION.tar.bz2
}

task_define configure_gmp "Configure gmp-$GMP_VERSION"
task_depends configure_gmp extract_gmp install_binutils
cmd_configure_gmp ()
{
    export ABI=32 &&
    cd $BUILD_GMP_DIR && mkdir -p build && cd build &&
    ../gmp-$GMP_VERSION/configure --prefix=$INSTALL_DIR --host=$GMP_TARGET --disable-shared
}

task_define build_gmp "Build gmp-$GMP_VERSION"
task_depends build_gmp configure_gmp
cmd_build_gmp ()
{
    export ABI=32 &&
    cd $BUILD_GMP_DIR/build &&
    make $MAKE_FLAGS
}

task_define install_gmp "Install gmp-$GMP_VERSION"
task_depends install_gmp build_gmp
cmd_install_gmp ()
{
    cd $BUILD_GMP_DIR/build &&
    make install
}

# Third, build mpfr
task_define extract_mpfr "Extract sources from mpfr-$MPFR_VERSION"
task_depends extract_mpfr download_toolchain_sources
cmd_extract_mpfr ()
{
    OUT_DIR=$BUILD_MPFR_DIR
    mkdir -p $OUT_DIR && cd $OUT_DIR &&
    tar xjf $TOOLCHAIN_SRC_DIR/mpfr/mpfr-$MPFR_VERSION.tar.bz2
}

task_define configure_mpfr "Configure mpfr-$MPFR_VERSION"
task_depends configure_mpfr extract_mpfr install_gmp
cmd_configure_mpfr ()
{
    cd $BUILD_MPFR_DIR && mkdir -p build && cd build &&
    ../mpfr-$MPFR_VERSION/configure \
        --prefix=$INSTALL_DIR \
        --host=$GMP_TARGET \
        --with-gmp=$INSTALL_DIR \
        --with-sysroot=$SYSROOT_DIR \
        --disable-shared
}

task_define build_mpfr "Build mpfr-$MPFR_VERSION"
task_depends build_mpfr configure_mpfr
cmd_build_mpfr ()
{
    cd $BUILD_MPFR_DIR/build &&
    make $MAKE_FLAGS
}

task_define install_mpfr "Install mpfr-$MPFR_VERSION"
task_depends install_mpfr build_mpfr
cmd_install_mpfr ()
{
    cd $BUILD_MPFR_DIR/build &&
    make install
}


# Fourth, the compiler itself
task_define configure_gcc "Configure gcc-$GCC_VERSION"
task_depends configure_gcc download_toolchain_sources install_binutils install_gmp install_mpfr
cmd_configure_gcc ()
{
    OUT_DIR=$BUILD_GCC_DIR
    mkdir -p $OUT_DIR && cd $OUT_DIR &&
    export PATH=$INSTALL_DIR/bin:$OLD_PATH &&
    export CFLAGS="-m32" &&
    export CC_FOR_TARGET="$HOST_CC" &&
    export LD_LIBRARY_PATH=$INSTALL_DIR/lib:$OLD_LD_LIBRARY_PATH &&
    export LDFLAGS="-L$INSTALL_DIR/lib" &&
    $TOOLCHAIN_SRC_DIR/gcc/gcc-$GCC_VERSION/configure \
        --prefix=$INSTALL_DIR \
        --with-sysroot=$SYSROOT_DIR \
        --disable-nls \
        --with-gmp=$INSTALL_DIR \
        --with-mpfr=$INSTALL_DIR \
        --target=$GCC_TARGET \
        --disable-plugin \
        --enable-languages=c,c++
}

task_define build_gcc "Build gcc-$GCC_VERSION"
task_depends build_gcc configure_gcc
cmd_build_gcc ()
{
    export PATH=$INSTALL_DIR/bin:$OLD_PATH &&
    export LD_LIBRARY_PATH=$INSTALL_DIR/lib:$OLD_LD_LIBRARY_PATH &&
    cd $BUILD_GCC_DIR &&
    make $MAKE_FLAGS
}

task_define install_gcc "Install gcc-$GCC_VERSION"
task_depends install_gcc build_gcc
cmd_install_gcc ()
{
    export PATH=$INSTALL_DIR/bin:$OLD_PATH &&
    export LD_LIBRARY_PATH=$INSTALL_DIR/lib:$OLD_LD_LIBRARY_PATH &&
    cd $BUILD_GCC_DIR &&
    make install
}

task_define cleanup_toolchain "Cleanup toolchain"
task_depends cleanup_toolchain install_gcc
cmd_cleanup_toolchain ()
{
    # Remove un-needed directories and files
    rm -rf $INSTALL_DIR/share
    rm -rf $INSTALL_DIR/man
    rm -rf $INSTALL_DIR/info
    rm -rf $INSTALL_DIR/lib32
    rm -rf $INSTALL_DIR/libexec/*/*/install-tools

    (strip $INSTALL_DIR/bin/*)
    true
}

task_define package_toolchain "Package final toolchain"
task_depends package_toolchain cleanup_toolchain
cmd_package_toolchain ()
{
    pack_archive $TOOLCHAIN_ARCHIVE "`dirname $INSTALL_DIR`" "`basename $INSTALL_DIR`"
}

#do_task package_toolchain
do_task package_toolchain

echo "Done, see $TOOLCHAIN_ARCHIVE"
