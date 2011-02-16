LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE  := videokit
FFMPEG_LIBS := $(shell find ffmpeg -name '*.a')
LOCAL_CFLAGS += -Iffmpeg -Ivideokit
LOCAL_LDLIBS += -llog $(FFMPEG_LIBS) x264/libx264.a
LOCAL_SRC_FILES := videokit/jni_interface.c 
include $(BUILD_SHARED_LIBRARY)

