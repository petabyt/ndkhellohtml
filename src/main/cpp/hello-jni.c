#include <string.h>
#include <jni.h>

JNIEXPORT jstring JNICALL Java_com_example_myapp_MainActivity_stringFromJNI(JNIEnv* env, jobject thiz) {
	#if defined(__arm__)
	#if defined(__ARM_ARCH_7A__)
	#if defined(__ARM_NEON__)
	#if defined(__ARM_PCS_VFP)
	#define ABI "armeabi-v7a/NEON (hard-float)"
	#else
	#define ABI "armeabi-v7a/NEON"
	#endif
	#else
	#if defined(__ARM_PCS_VFP)
	#define ABI "armeabi-v7a (hard-float)"
	#else
	#define ABI "armeabi-v7a"
	#endif
	#endif
	#else
	#define ABI "armeabi"
	#endif
	#elif defined(__i386__)
	#define ABI "x86"
	#elif defined(__x86_64__)
	#define ABI "x86_64"
	#elif defined(__mips64)  /* mips64el-* toolchain defines __mips__ too */
	#define ABI "mips64"
	#elif defined(__mips__)
	#define ABI "mips"
	#elif defined(__aarch64__)
	#define ABI "arm64-v8a"
	#else
	#define ABI "unknown"
	#endif

	int i = 1 + 2;
	char *string = "Hello. I am C code running on an Android app.";

    return (*env)->NewStringUTF(env, string);
}

JNIEXPORT jintArray JNICALL Java_com_example_myapp_MainActivity_arrayTest(JNIEnv* env, jobject thiz){
	jintArray result;
	int size = 5;
	result = (*env)->NewIntArray(env, size);
	if (result == NULL) {
		return NULL; /* out of memory error thrown */
	}

	jint fill[size];
	for (int i = 0; i < size; i++) {
		fill[i] = 0;
	}

	// move from the temp structure to the java structure
	(*env)->SetIntArrayRegion(env, result, 0, size, fill);
	return result;
}
