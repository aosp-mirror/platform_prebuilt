LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)

LOCAL_PREBUILT_LIBS := \
	libswt-carbon-3236.jnilib \
	libswt-pi-carbon-3236.jnilib

LOCAL_PREBUILT_JAVA_LIBRARIES := \
	swt$(COMMON_JAVA_PACKAGE_SUFFIX) \
	org.eclipse.jface_3.2.0.I20060605-1400$(COMMON_JAVA_PACKAGE_SUFFIX) \
	org.eclipse.equinox.common_3.2.0.v20060603$(COMMON_JAVA_PACKAGE_SUFFIX) \
	org.eclipse.core.commands_3.2.0.I20060605-1400$(COMMON_JAVA_PACKAGE_SUFFIX)

include $(BUILD_HOST_PREBUILT)
