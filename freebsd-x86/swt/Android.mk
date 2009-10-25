# Get a intermediate dir
LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := swt_tmp
LOCAL_MODULE_CLASS := JAVA_LIBRARIES
LOCAL_UNINSTALLABLE_MODULE := yes

include $(BUILD_SYSTEM)/base_rules.mk

SWT_INTERMEDIATES_DIR := $(intermediates)

$(LOCAL_BUILT_MODULE):
	$(hide) touch $@

# Real declare predefined Java library
LOCAL_PATH:= $(SWT_INTERMEDIATES_DIR)
include $(CLEAR_VARS)

LOCAL_PREBUILT_JAVA_LIBRARIES := \
	swt$(COMMON_JAVA_PACKAGE_SUFFIX)

include $(BUILD_HOST_PREBUILT)

$(SWT_INTERMEDIATES_DIR)/swt$(COMMON_JAVA_PACKAGE_SUFFIX):
	$(hide) \
	if [ ! -e $(SWT_INTERMEDIATES_DIR) ]; then \
		mkdir -p $(SWT_INTERMEDIATES_DIR); \
	fi
	$(hide) \
	if [ -e /usr/local/share/java/classes/swt.jar ]; then \
		cp /usr/local/share/java/classes/swt.jar \
			$(SWT_INTERMEDIATES_DIR); \
	else \
		echo "Please install FreeBSD swt port before build Android"; \
	fi
