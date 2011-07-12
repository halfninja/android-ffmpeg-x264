LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE  := videokit
# These need to be in the right order
FFMPEG_LIBS := ffmpeg/libavdevice/libavdevice.a \
ffmpeg/libavformat/libavformat.a \
ffmpeg/libavcodec/libavcodec.a \
ffmpeg/libavfilter/libavfilter.a \
ffmpeg/libswscale/libswscale.a \
ffmpeg/libavutil/libavutil.a \
ffmpeg/libpostproc/libpostproc.a
# ffmpeg uses its own deprecated functions liberally, so turn off that annoying noise
LOCAL_CFLAGS += -Iffmpeg -Ivideokit -Wno-deprecated-declarations 
LOCAL_LDLIBS += -llog $(FFMPEG_LIBS) x264/libx264.a
LOCAL_SRC_FILES := videokit/cmdutils.c videokit/jni_interface.c
include $(BUILD_SHARED_LIBRARY)

