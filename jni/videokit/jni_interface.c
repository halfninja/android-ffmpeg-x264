
#include "libavformat/avformat.h"
#include "libavdevice/avdevice.h"
#include "libswscale/swscale.h"

#include <android/log.h>
#include "jni_interface.h"

#include <stdlib.h>
#include <stdbool.h>

AVFormatContext *pFormatCtx;

bool initted = false;

// the fuck is this exit shit doing
#define exit exit_function_not_allowed
#define LOG_ERROR(message) __android_log_write(ANDROID_LOG_ERROR, "VideoKit", message)
#define LOG_INFO(message) __android_log_write(ANDROID_LOG_INFO, "VideoKit", message)
#define EXCEPTION_CODE 256

int throwException(JNIEnv *env, const char* message)
{
  jclass newExcCls;
  (*env)->ExceptionDescribe(env);
  (*env)->ExceptionClear(env);
  newExcCls = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
  (*env)->ThrowNew(env, newExcCls, message);
  (*env)->DeleteLocalRef(env, newExcCls);
  return EXCEPTION_CODE;
}

JNIEXPORT void JNICALL Java_uk_co_halfninja_videokit_Videokit_initialise(JNIEnv *env, jobject self)
{
  if (!initted) 
  {
    LOG_INFO("Initialising VideoKit");
    av_register_all();
    initted = true;
  }
  else
  {
    LOG_INFO("Already initialised Videokit, ignoring init()");    
  }
}

JNIEXPORT void JNICALL Java_uk_co_halfninja_videokit_Videokit_setSize (JNIEnv *env, jobject self, jstring size)
{
  LOG_INFO("Let's throw an exception!");
  throwException(env, "Bam, not supported");
}
