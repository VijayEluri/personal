/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class org_rosuda_JRI_Rengine */

#ifndef _Included_org_rosuda_JRI_Rengine
#define _Included_org_rosuda_JRI_Rengine
#ifdef __cplusplus
extern "C" {
#endif
#undef org_rosuda_JRI_Rengine_MIN_PRIORITY
#define org_rosuda_JRI_Rengine_MIN_PRIORITY 1L
#undef org_rosuda_JRI_Rengine_NORM_PRIORITY
#define org_rosuda_JRI_Rengine_NORM_PRIORITY 5L
#undef org_rosuda_JRI_Rengine_MAX_PRIORITY
#define org_rosuda_JRI_Rengine_MAX_PRIORITY 10L
/*
 * Class:     org_rosuda_JRI_Rengine
 * Method:    rniSetupR
 * Signature: ([Ljava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_org_rosuda_JRI_Rengine_rniSetupR
  (JNIEnv *, jobject, jobjectArray);

/*
 * Class:     org_rosuda_JRI_Rengine
 * Method:    rniParse
 * Signature: (Ljava/lang/String;I)J
 */
JNIEXPORT jlong JNICALL Java_org_rosuda_JRI_Rengine_rniParse
  (JNIEnv *, jobject, jstring, jint);

/*
 * Class:     org_rosuda_JRI_Rengine
 * Method:    rniEval
 * Signature: (JJ)J
 */
JNIEXPORT jlong JNICALL Java_org_rosuda_JRI_Rengine_rniEval
  (JNIEnv *, jobject, jlong, jlong);

/*
 * Class:     org_rosuda_JRI_Rengine
 * Method:    rniProtect
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_org_rosuda_JRI_Rengine_rniProtect
  (JNIEnv *, jobject, jlong);

/*
 * Class:     org_rosuda_JRI_Rengine
 * Method:    rniUnprotect
 * Signature: (I)V
 */
JNIEXPORT void JNICALL Java_org_rosuda_JRI_Rengine_rniUnprotect
  (JNIEnv *, jobject, jint);

/*
 * Class:     org_rosuda_JRI_Rengine
 * Method:    rniGetString
 * Signature: (J)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_org_rosuda_JRI_Rengine_rniGetString
  (JNIEnv *, jobject, jlong);

/*
 * Class:     org_rosuda_JRI_Rengine
 * Method:    rniGetStringArray
 * Signature: (J)[Ljava/lang/String;
 */
JNIEXPORT jobjectArray JNICALL Java_org_rosuda_JRI_Rengine_rniGetStringArray
  (JNIEnv *, jobject, jlong);

/*
 * Class:     org_rosuda_JRI_Rengine
 * Method:    rniGetIntArray
 * Signature: (J)[I
 */
JNIEXPORT jintArray JNICALL Java_org_rosuda_JRI_Rengine_rniGetIntArray
  (JNIEnv *, jobject, jlong);

/*
 * Class:     org_rosuda_JRI_Rengine
 * Method:    rniGetDoubleArray
 * Signature: (J)[D
 */
JNIEXPORT jdoubleArray JNICALL Java_org_rosuda_JRI_Rengine_rniGetDoubleArray
  (JNIEnv *, jobject, jlong);

/*
 * Class:     org_rosuda_JRI_Rengine
 * Method:    rniGetVector
 * Signature: (J)[J
 */
JNIEXPORT jlongArray JNICALL Java_org_rosuda_JRI_Rengine_rniGetVector
  (JNIEnv *, jobject, jlong);

/*
 * Class:     org_rosuda_JRI_Rengine
 * Method:    rniPutString
 * Signature: (Ljava/lang/String;)J
 */
JNIEXPORT jlong JNICALL Java_org_rosuda_JRI_Rengine_rniPutString
  (JNIEnv *, jobject, jstring);

/*
 * Class:     org_rosuda_JRI_Rengine
 * Method:    rniPutStringArray
 * Signature: ([Ljava/lang/String;)J
 */
JNIEXPORT jlong JNICALL Java_org_rosuda_JRI_Rengine_rniPutStringArray
  (JNIEnv *, jobject, jobjectArray);

/*
 * Class:     org_rosuda_JRI_Rengine
 * Method:    rniPutIntArray
 * Signature: ([I)J
 */
JNIEXPORT jlong JNICALL Java_org_rosuda_JRI_Rengine_rniPutIntArray
  (JNIEnv *, jobject, jintArray);

/*
 * Class:     org_rosuda_JRI_Rengine
 * Method:    rniPutDoubleArray
 * Signature: ([D)J
 */
JNIEXPORT jlong JNICALL Java_org_rosuda_JRI_Rengine_rniPutDoubleArray
  (JNIEnv *, jobject, jdoubleArray);

/*
 * Class:     org_rosuda_JRI_Rengine
 * Method:    rniPutVector
 * Signature: ([J)J
 */
JNIEXPORT jlong JNICALL Java_org_rosuda_JRI_Rengine_rniPutVector
  (JNIEnv *, jobject, jlongArray);

/*
 * Class:     org_rosuda_JRI_Rengine
 * Method:    rniGetAttr
 * Signature: (JLjava/lang/String;)J
 */
JNIEXPORT jlong JNICALL Java_org_rosuda_JRI_Rengine_rniGetAttr
  (JNIEnv *, jobject, jlong, jstring);

/*
 * Class:     org_rosuda_JRI_Rengine
 * Method:    rniSetAttr
 * Signature: (JLjava/lang/String;J)V
 */
JNIEXPORT void JNICALL Java_org_rosuda_JRI_Rengine_rniSetAttr
  (JNIEnv *, jobject, jlong, jstring, jlong);

/*
 * Class:     org_rosuda_JRI_Rengine
 * Method:    rniInherits
 * Signature: (JLjava/lang/String;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_rosuda_JRI_Rengine_rniInherits
  (JNIEnv *, jobject, jlong, jstring);

/*
 * Class:     org_rosuda_JRI_Rengine
 * Method:    rniCons
 * Signature: (JJ)J
 */
JNIEXPORT jlong JNICALL Java_org_rosuda_JRI_Rengine_rniCons
  (JNIEnv *, jobject, jlong, jlong);

/*
 * Class:     org_rosuda_JRI_Rengine
 * Method:    rniCAR
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_org_rosuda_JRI_Rengine_rniCAR
  (JNIEnv *, jobject, jlong);

/*
 * Class:     org_rosuda_JRI_Rengine
 * Method:    rniCDR
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_org_rosuda_JRI_Rengine_rniCDR
  (JNIEnv *, jobject, jlong);

/*
 * Class:     org_rosuda_JRI_Rengine
 * Method:    rniTAG
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_org_rosuda_JRI_Rengine_rniTAG
  (JNIEnv *, jobject, jlong);

/*
 * Class:     org_rosuda_JRI_Rengine
 * Method:    rniPutList
 * Signature: ([J)J
 */
JNIEXPORT jlong JNICALL Java_org_rosuda_JRI_Rengine_rniPutList
  (JNIEnv *, jobject, jlongArray);

/*
 * Class:     org_rosuda_JRI_Rengine
 * Method:    rniGetList
 * Signature: (J)[J
 */
JNIEXPORT jlongArray JNICALL Java_org_rosuda_JRI_Rengine_rniGetList
  (JNIEnv *, jobject, jlong);

/*
 * Class:     org_rosuda_JRI_Rengine
 * Method:    rniGetSymbolName
 * Signature: (J)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_org_rosuda_JRI_Rengine_rniGetSymbolName
  (JNIEnv *, jobject, jlong);

/*
 * Class:     org_rosuda_JRI_Rengine
 * Method:    rniInstallSymbol
 * Signature: (Ljava/lang/String;)J
 */
JNIEXPORT jlong JNICALL Java_org_rosuda_JRI_Rengine_rniInstallSymbol
  (JNIEnv *, jobject, jstring);

/*
 * Class:     org_rosuda_JRI_Rengine
 * Method:    rniJavaToXref
 * Signature: (Ljava/lang/Object;)J
 */
JNIEXPORT jlong JNICALL Java_org_rosuda_JRI_Rengine_rniJavaToXref
  (JNIEnv *, jobject, jobject);

/*
 * Class:     org_rosuda_JRI_Rengine
 * Method:    rniXrefToJava
 * Signature: (J)Ljava/lang/Object;
 */
JNIEXPORT jobject JNICALL Java_org_rosuda_JRI_Rengine_rniXrefToJava
  (JNIEnv *, jobject, jlong);

/*
 * Class:     org_rosuda_JRI_Rengine
 * Method:    rniGetVersion
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_org_rosuda_JRI_Rengine_rniGetVersion
  (JNIEnv *, jclass);

/*
 * Class:     org_rosuda_JRI_Rengine
 * Method:    rniStop
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_org_rosuda_JRI_Rengine_rniStop
  (JNIEnv *, jobject, jint);

/*
 * Class:     org_rosuda_JRI_Rengine
 * Method:    rniAssign
 * Signature: (Ljava/lang/String;JJ)V
 */
JNIEXPORT void JNICALL Java_org_rosuda_JRI_Rengine_rniAssign
  (JNIEnv *, jobject, jstring, jlong, jlong);

/*
 * Class:     org_rosuda_JRI_Rengine
 * Method:    rniExpType
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_org_rosuda_JRI_Rengine_rniExpType
  (JNIEnv *, jobject, jlong);

/*
 * Class:     org_rosuda_JRI_Rengine
 * Method:    rniRunMainLoop
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_org_rosuda_JRI_Rengine_rniRunMainLoop
  (JNIEnv *, jobject);

/*
 * Class:     org_rosuda_JRI_Rengine
 * Method:    rniIdle
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_org_rosuda_JRI_Rengine_rniIdle
  (JNIEnv *, jobject);

#ifdef __cplusplus
}
#endif
#endif
