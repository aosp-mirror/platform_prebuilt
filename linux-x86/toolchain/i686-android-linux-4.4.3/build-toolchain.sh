#!/bin/sh
#
# This script is used to rebuild the x86 toolchain Linux
# (i686-android-linux-4.4.3) completely from scratch.
#
# CURRENTLY UNTESTED ON OSX!!
#
# You need to have a recent AOSP workspace, and have ANDROID_BUILD_TOP
# point to it. Usually, this variable is defined in your environment after
# you call "lunch <product>-<variant>"
#

PRODUCT_NAME=full_x86
ARCH=x86
GCC_VERSION=4.4.3
TOOLCHAIN_INSTALL_NAME=i686-android-linux-$GCC_VERSION
TOOLCHAIN_BIN_PREFIX=i686-android-linux-
TOOLCHAIN_BUILD_NAME=$ARCH-$GCC_VERSION
PLATFORM=android-9

MPFR_VERSION=2.4.1
GDB_VERSION=6.6
BINUTILS_VERSION=2.20.1

GIT_DATE=20110303

HOST_OS=`uname -s`
case "$HOST_OS" in
    Darwin)
        HOST_OS=darwin
        HOST_TAG=darwin-x86
        BUILD_NUM_CPUS=$(sysctl -n hw.ncpu)
        ;;
    Linux)
        # note that building  32-bit binaries on x86_64 is handled later
        HOST_OS=linux
        HOST_TAG=linux-x86
        BUILD_NUM_CPUS=$(grep -c processor /proc/cpuinfo)
        ;;
    *)
        echo "ERROR: Unsupported OS: $HOST_OS"
        exit 1
esac

PREBUILT_INSTALL_DIR=prebuilt/$HOST_TAG/toolchain/$TOOLCHAIN_INSTALL_NAME
#PREBUILT_INSTALL_DIR=/tmp/zoo

PREBUILT_GDB_DIR=prebuilt/android-$ARCH/gdbserver

# If
if [ -z "$ANDROID_BUILD_TOP" ]; then
    if [ ! -f build/envsetup.sh ]; then
        echo "Please run this script from the top of a valid AOSP platform source tree"
        echo "or define ANDROID_BUILD_TOP in your environment to point to it. Note that"
        echo "this variable is typically defined by running 'lunch <name>' too."
        exit 1
    fi
    ANDROID_BUILD_TOP=.
fi

# Today's date, ISO format, only used to determine the temporary directory.
TODAY=`date '+%Y%m%d'`

VERBOSE_FLAG=
: ${V:=0}
if [ "$V" -gt 0 ]; then
    VERBOSE_FLAG="--verbose"
fi

# A few useful functions
#
fail_panic ()
{
    if [ $? != 0 ]; then
        echo "PANIC: $@"
        exit 1
    fi
}

run ()
{
    echo "### $@"
    $@
}

# Compute the number of parallel build jobs
#
JOBS=$(( $BUILD_NUM_CPUS * 2 ))

# Temporary directory where we're going to store every intermediate file.
#
# Normally, none of the generated executables should embed/use this path
# but select something complex to avoid problems if this is not the case
#
TMPDIR=/tmp/$TOOLCHAIN_INSTALL_NAME-$TODAY
mkdir -p $TMPDIR
fail_panic "Can't create temporary directory: $TMPDIR"

# System libraries needed to bootstrap the toolchain
SYSTEM_LIBS="libc libm libdl libstdc++"

# Where to download the toolchain sources from android.git.kernel.org
TOOLCHAIN_SRC_DIR=$TMPDIR/toolchain-sources

# Where to build the toolchain binaries
TOOLCHAIN_BUILD_DIR=$TMPDIR/toolchain-build

# Directory where we will copy the content of development/ndk
# and update it with the freshest libraries from the system.
DEVELOPMENT_DIR=$TMPDIR/devel

# Where to place the installed binaries (NDK installation-like)
TOOLCHAIN_INSTALL_DIR=$TMPDIR/ndk-install

build_system_libraries ()
{
    echo "Building $PRODUCT_NAME system libraries: $SYSTEM_LIBS"
    cd $ANDROID_BUILD_TOP &&
    make $SYSTEM_LIBS -j$JOBS
    fail_panic "Could not build $PRODUCT_NAME system libraries!"
}

download_toolchain_sources ()
{
    # We don't use ndk/build/tools/download-toolchain-sources.sh here
    # because it removes all .info files, which breaks the ToT source
    # build as of 2011-03-03
    #
    echo "Download toolchain patches to: $TOOLCHAIN_SRC_DIR"
    GIT_PREFIX=git://android.git.kernel.org/toolchain
    for PROJECT in build binutils gcc gdb mpfr gmp gold; do
        PROJECT_DIR="$TOOLCHAIN_SRC_DIR/$PROJECT"
        PROJECT_GIT="$GIT_PREFIX/$PROJECT.git"
        echo "$PROJECT: Cleaning"
        rm -rf $PROJECT_DIR
        echo "$PROJECT: Downloading sources from: $PROJECT_GIT"
        (git clone $PROJECT_GIT $PROJECT_DIR) > /dev/null 2>&1
        fail_panic "$PROJECT: Could not git clone!!"
        if [ -n "$GIT_DATE" ] ; then
            echo "$PROJECT: Switching to sources for date '$GIT_DATE'"
            (cd $PROJECT_DIR &&
             REVISION=`git rev-list -n 1 --until="$GIT_DATE" HEAD` &&
             run git checkout $REVISION) > /dev/null 2>&1
            fail_panic "$PROJECT: Could not checkout?"
        fi
    done
    fail_panic "Could not download toolchain sources!"
}

build_development_dir ()
{
    echo "Copy development/ndk to: $DEVELOPMENT_DIR"
    rm -rf $DEVELOPMENT_DIR
    cp -rf $ANDROID_BUILD_TOP/development/ndk $DEVELOPMENT_DIR
    fail_panic "Could not copy development/ndk!"
}

build_sysroot ()
{
    echo "Generate platform files into: $TOOLCHAIN_INSTALL_DIR"
    ndk/build/tools/build-platforms.sh \
        --abi=$ARCH --no-symlinks --no-samples \
        --src-dir=$DEVELOPMENT_DIR \
        --dst-dir=$TOOLCHAIN_INSTALL_DIR
    fail_panic "Could not generate build sysroot"

    echo "Copying system files into: $TOOLCHAIN_INSTALL_DIR/sysroot"
    cp -r $TOOLCHAIN_INSTALL_DIR/platforms/$PLATFORM/arch-$ARCH $TOOLCHAIN_INSTALL_DIR/sysroot
    fail_panic "Could not copy files to: $TOOLCHAIN_INSTALL_DIR/sysroot"

    rm -rf $TOOLCHAIN_INSTALL_DIR/sysroot/usr/lib
}

build_gcc ()
{
    echo "Building $TOOLCHAIN_INSTALL_NAME now (this can be long)."
    mkdir -p $TOOLCHAIN_BUILD_DIR && rm -rf $TOOLCHAIN_BUILD_DIR/*
    run ndk/build/tools/build-gcc.sh \
        --sysroot=$TOOLCHAIN_INSTALL_DIR/sysroot \
        --build-out=$TOOLCHAIN_BUILD_DIR \
        --mpfr-version=$MPFR_VERSION \
        --gdb-version=$GDB_VERSION \
        --binutils-version=$BINUTILS_VERSION \
        "$TOOLCHAIN_SRC_DIR" "$TOOLCHAIN_INSTALL_DIR" $TOOLCHAIN_BUILD_NAME

    fail_panic "Could not build compiler!"
}

install_gcc ()
{
    echo "Installing toolchain to $PREBUILT_INSTALL_DIR"
    SRCDIR=$TOOLCHAIN_INSTALL_DIR/toolchains/$TOOLCHAIN_BUILD_NAME/prebuilt/$HOST_TAG
    mkdir -p $PREBUILT_INSTALL_DIR &&
    rm -rf $PREBUILT_INSTALL_DIR/* &&
    (cd $SRCDIR && tar cf - --exclude=sysroot *) | tar xf - -C $PREBUILT_INSTALL_DIR
    fail_panic "Can't install!"
    # Copy toolchain license files too
    # Plus this script as well!
    cp ndk/build/tools/toolchain-licenses/* $PREBUILT_INSTALL_DIR &&
    cp $0 $PREBUILT_INSTALL_DIR
}

download_toolchain_sources
build_development_dir
build_sysroot
build_gcc
install_gcc

echo "Done!"
