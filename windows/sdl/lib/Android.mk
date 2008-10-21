LOCAL_PATH := $(my-dir)
include $(CLEAR_VARS)

LOCAL_PREBUILT_LIBS := \
	libSDL.a \
	libSDLmain.a

include $(BUILD_HOST_PREBUILT)
