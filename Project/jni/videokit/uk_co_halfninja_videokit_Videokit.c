

#include <android/log.h>
#include "logjam.h"
#include "uk_co_halfninja_videokit_Videokit.h"

#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char **argv);

JavaVM *sVm = NULL;

#define LOG_ERROR(message) __android_log_write(ANDROID_LOG_ERROR, "VideoKit", message)
#define LOG_INFO(message) __android_log_write(ANDROID_LOG_INFO, "VideoKit", message)

jint JNI_OnLoad( JavaVM* vm, void* reserved )
{
	LOG_INFO("Loading native library compiled at " __TIME__ " " __DATE__);
	sVm = vm;
	return JNI_VERSION_1_6;
}

JNIEXPORT void JNICALL Java_uk_co_halfninja_videokit_Videokit_run(JNIEnv *env, jobject obj, jobjectArray args)
{
	int i = 0;
	int argc = 0;
	char **argv = NULL;
	jstring *strr = NULL;

	if (args != NULL) {
		argc = (*env)->GetArrayLength(env, args);
		argv = (char **) malloc(sizeof(char *) * argc);
		strr = (jstring *) malloc(sizeof(jstring) * argc);

		for(i=0;i<argc;i++)
		{
			strr[i] = (jstring)(*env)->GetObjectArrayElement(env, args, i);
			argv[i] = (char *)(*env)->GetStringUTFChars(env, strr[i], 0);
		}
	}	

	main(argc, argv);
	
	for(i=0;i<argc;i++)
	{
		(*env)->ReleaseStringUTFChars(env, strr[i], argv[i]);
	}
	free(argv);
	free(strr);
}
