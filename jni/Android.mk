LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE  := videokit
#FFMPEG_LIBS := $(shell find ffmpeg -name '*.a')
FFMPEG_LIBS := ffmpeg/libavdevice/libavdevice.a \
ffmpeg/libavformat/libavformat.a \
ffmpeg/libavcodec/libavcodec.a \
ffmpeg/libavfilter/libavfilter.a \
ffmpeg/libavutil/libavutil.a \
ffmpeg/libswscale/libswscale.a \
ffmpeg/libpostproc/libpostproc.a
LOCAL_CFLAGS += -Iffmpeg -Ivideokit
LOCAL_LDLIBS += -llog $(FFMPEG_LIBS) x264/libx264.a
LOCAL_SRC_FILES := videokit/jni_interface.c 
include $(BUILD_SHARED_LIBRARY)

