LOCAL_PATH := $(call my-dir)


include $(CLEAR_VARS)

LOCAL_LDLIBS :=  -lm -L$(SYSROOT)/usr/lib -llog -lGLESv1_CM  -ldl -lGLESv2

LOCAL_MODULE    := MyRenderer
LOCAL_SRC_FILES := ./hbsi_dtd_opengles_MyRenderer.cpp



include $(BUILD_SHARED_LIBRARY)