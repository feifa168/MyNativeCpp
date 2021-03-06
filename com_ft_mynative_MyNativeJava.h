/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_ft_mynative_MyNativeJava */

#ifndef _Included_com_ft_mynative_MyNativeJava
#define _Included_com_ft_mynative_MyNativeJava
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_ft_mynative_MyNativeJava
 * Method:    fun
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_ft_mynative_MyNativeJava_fun
  (JNIEnv *, jobject);

/*
 * Class:     com_ft_mynative_MyNativeJava
 * Method:    fun2
 * Signature: (Ljava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_com_ft_mynative_MyNativeJava_fun2
  (JNIEnv *, jobject, jstring);

/*
 * Class:     com_ft_mynative_MyNativeJava
 * Method:    fun3
 * Signature: ([Ljava/lang/Integer;)V
 */
JNIEXPORT void JNICALL Java_com_ft_mynative_MyNativeJava_fun3
  (JNIEnv *, jobject, jobjectArray);

/*
 * Class:     com_ft_mynative_MyNativeJava
 * Method:    baseTypes
 * Signature: (ICZSJFDB)Z
 */
JNIEXPORT jboolean JNICALL Java_com_ft_mynative_MyNativeJava_baseTypes
  (JNIEnv *, jobject, jint, jchar, jboolean, jshort, jlong, jfloat, jdouble, jbyte);

/*
 * Class:     com_ft_mynative_MyNativeJava
 * Method:    wrapBaseTypes
 * Signature: (Ljava/lang/Integer;Ljava/lang/Character;Ljava/lang/Boolean;Ljava/lang/Short;Ljava/lang/Long;Ljava/lang/Float;Ljava/lang/Double;Ljava/lang/Byte;)Ljava/lang/Boolean;
 */
JNIEXPORT jobject JNICALL Java_com_ft_mynative_MyNativeJava_wrapBaseTypes
  (JNIEnv *, jobject, jobject, jobject, jobject, jobject, jobject, jobject, jobject, jobject);

/*
 * Class:     com_ft_mynative_MyNativeJava
 * Method:    intArray
 * Signature: ([I)[Z
 */
JNIEXPORT jbooleanArray JNICALL Java_com_ft_mynative_MyNativeJava_intArray
  (JNIEnv *, jobject, jintArray);

/*
 * Class:     com_ft_mynative_MyNativeJava
 * Method:    wrapIntArray
 * Signature: ([Ljava/lang/Integer;)[Ljava/lang/Boolean;
 */
JNIEXPORT jobjectArray JNICALL Java_com_ft_mynative_MyNativeJava_wrapIntArray
  (JNIEnv *, jobject, jobjectArray);

/*
 * Class:     com_ft_mynative_MyNativeJava
 * Method:    stringTest
 * Signature: (Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_ft_mynative_MyNativeJava_stringTest
  (JNIEnv *, jobject, jstring);

/*
 * Class:     com_ft_mynative_MyNativeJava
 * Method:    strArrTest
 * Signature: ([Ljava/lang/String;)[Ljava/lang/String;
 */
JNIEXPORT jobjectArray JNICALL Java_com_ft_mynative_MyNativeJava_strArrTest
  (JNIEnv *, jobject, jobjectArray);

/*
 * Class:     com_ft_mynative_MyNativeJava
 * Method:    modifyFields
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_ft_mynative_MyNativeJava_modifyFields
  (JNIEnv *, jobject);

/*
 * Class:     com_ft_mynative_MyNativeJava
 * Method:    testMethod
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_ft_mynative_MyNativeJava_testMethod
  (JNIEnv *, jobject);

#ifdef __cplusplus
}
#endif
#endif
