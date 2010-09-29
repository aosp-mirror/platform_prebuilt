LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

# Explicitly mark gdbserver as "eng" so that it doesn't
# get included in user or SDK builds. (GPL issues)
#
ifeq ($(ARCH_ARM_HAVE_TLS_REGISTER),true)
LOCAL_SRC_FILES := gdbserver.tls
else
LOCAL_SRC_FILES := gdbserver
endif
LOCAL_MODULE := gdbserver
LOCAL_MODULE_CLASS := EXECUTABLES
LOCAL_MODULE_TAGS := debug
include $(BUILD_PREBUILT)

# Any prebuilt files with default TAGS can use the below:
prebuilt_files :=

$(call add-prebuilt-files, EXECUTABLES, $(prebuilt_files))
