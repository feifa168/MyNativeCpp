#include "com_ft_mynative_MyNativeJava.h"

#include <iostream>
#include <cstring>

using std::cout;
using std::endl;

 /*
 * Class:     com_ft_mynative_MyNativeJava
 * Method:    fun
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_ft_mynative_MyNativeJava_fun
(JNIEnv *, jobject) {
    cout << "fun()" << endl;
}

/*
 * Class:     com_ft_mynative_MyNativeJava
 * Method:    fun2
 * Signature: (Ljava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_com_ft_mynative_MyNativeJava_fun2
        (JNIEnv *env, jobject thisObj, jstring str) {
    const char *cStr = env->GetStringUTFChars(str, NULL);
    if (NULL != cStr) {
        cout << "fun2(" << cStr << ")"  << endl;
    } else {
        cout << "fun2(string) fail"  << endl;
    }

    jint len = strlen(cStr);
    env->ReleaseStringUTFChars(str, cStr);

    return len;
}

/*
 * Class:     com_ft_mynative_MyNativeJava
 * Method:    fun3
 * Signature: ([Ljava/lang/Integer;)V
 */
JNIEXPORT void JNICALL Java_com_ft_mynative_MyNativeJava_fun3
(JNIEnv *env, jobject thisObj, jobjectArray intArr) {
    jclass clsInteger = env->FindClass("java/lang/Integer");
    if (NULL == clsInteger) {
        cout << "find class java/lang/Integer fail" << endl;
        return;
    }

    jmethodID method = env->GetMethodID(clsInteger, "intValue", "()I");
    if (NULL == method) {
        cout << "find method intValue()I fail" << endl;
        return;
    }

    jint sum = 0;
    jsize len = env->GetArrayLength(intArr);
    cout << "IntegerArray len is " << len << " items is ";
    for (int i=0; i<len; i++) {
        jobject objInteger = env->GetObjectArrayElement(intArr, i);
        if (NULL != objInteger) {
            jint ivalue = env->CallIntMethod(objInteger, method);
            cout << ivalue << ", ";
            sum += ivalue;
        }
    }
    cout << "total is " << sum << endl;
}