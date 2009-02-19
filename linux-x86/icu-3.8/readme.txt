This directory contains the Linux versions
of three ICU tools potentially needed during
the Android build process. The tools can be
re-created using the following steps:

(1) Copy the whole "/extlibs/icu-3.8"
    directory somewhere else.

(2) Change to the copy of the directory.

(3) Execute "./runConfigureICU Linux".

(4) Modify the file "icuconfig.mk".
    Search for "ENABLE_STATIC" and change
    its value to TRUE. Change the value of
    "ENABLE_SHARED" to empty.

(5) Execute "make".

(6) If you're successful, the results of
    your efforts will reside in "bin".
    Copy them here.
