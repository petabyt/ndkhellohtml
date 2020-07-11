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
	jobjectArray array;
	int size = 5;
	array = (*env)->NewObjectArray(
		env,
		size,
		(*env)->FindClass(env, "java/lang/String"),
		(*env)->NewStringUTF(env, "")
	 );

	if (array == NULL) {
		return NULL;
	}

	char *testArray[5] = {
		"<br>Woah...<br>",
		"Is this C?..<br>",
		"Wow..<br>",
		"That's like..<br>",
		"Friggin cool."
	};

	for (int i = 0; i < size; i++) {
		(*env)->SetObjectArrayElement(
			env,
			array,
			i,
			(*env)->NewStringUTF(env, testArray[i])
		);
	}

	//(*env)->SetIntArrayRegion(env, result, 0, size, fill);
	return array;
}
