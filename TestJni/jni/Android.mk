LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := MyActivity
LOCAL_SRC_FILES := ./hbsi_dtd_test_MyActivity.cpp	


include $(BUILD_SHARED_LIBRARY)