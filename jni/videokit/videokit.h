
static JavaVM *sVm;

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *jvm, void *reserved)
{
	LOGI("Loading library compiled at " __TIME__);
	sVm = jvm;
	return JNI_VERSION_1_2;
}

JNIEnv* getJNIEnv() {
    JNIEnv* env = NULL;
    if ((*sVm)->GetEnv(sVm, (void**) &env, JNI_VERSION_1_4) != JNI_OK) {
	LOGE("Failed to obtain JNIEnv");
        return NULL;
    }
    return env;
}

int throwException(JNIEnv *env, const char* message)
{
  jclass newExcCls;
  (*env)->ExceptionDescribe(env);
  (*env)->ExceptionClear(env);
  newExcCls = (*env)->FindClass(env, "java/lang/RuntimeException");
  (*env)->ThrowNew(env, newExcCls, message);
  (*env)->DeleteLocalRef(env, newExcCls);
  return 255;
}

JNIEXPORT void JNICALL Java_uk_co_halfninja_videokit_Videokit_run(JNIEnv *env, jobject obj, jobjectArray args) {
	int i = 0;
	int argc = 0;
	char **argv = NULL;

	if (args != NULL) {
		argc = (*env)->GetArrayLength(env, args);
		argv = (char **) malloc(sizeof(char *) * argc);

		LOGI("Found %d options", argc);
	
		for(i=0;i<argc;i++)
		{
			jstring str = (jstring)(*env)->GetObjectArrayElement(env, args, i);
			argv[i] = (char *)(*env)->GetStringUTFChars(env, str, NULL);   
		}
	}	

	/* parse options */
	main(argc, argv);
}
