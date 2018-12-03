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

/*
 * Class:     com_ft_mynative_MyNativeJava
 * Method:    baseTypes
 * Signature: (ICZSJFDB)Z
 */
JNIEXPORT jboolean JNICALL Java_com_ft_mynative_MyNativeJava_baseTypes
        (JNIEnv *env, jobject thisObj, jint ia, jchar cb, jboolean bc, jshort sd, jlong le, jfloat ff, jdouble dj, jbyte bh) {
    cout << " jint " << ia      << endl;
    cout << " jchar " << cb     << endl;
    cout << " jboolean " << (bc==JNI_TRUE)  << endl;
    cout << " jshort " << sd    << endl;
    cout << " jlong " << le     << endl;
    cout << " jfloat " << ff    << endl;
    cout << " jdouble " << dj   << endl;
    cout << " jbyte " << bh     << endl;

    cout << "jXXX 直接转换成 XXX" << endl;

    int xxx_ia  = ia;
    char xxx_cb = cb;
    bool xxx_bc = (bc==JNI_TRUE);
    short xxx_sd = sd;
    long xxx_le = le;
    float xxx_ff = ff;
    double xxx_dj = dj;
    unsigned char xxx_bh = bh;

    cout << " int " << xxx_ia      << endl;
    cout << " char " << xxx_cb     << endl;
    cout << " boolean " << xxx_bc  << endl;
    cout << " short " << xxx_sd    << endl;
    cout << " long " << xxx_le     << endl;
    cout << " float " << xxx_ff    << endl;
    cout << " double " << xxx_dj   << endl;
    cout << " byte " << xxx_bh     << endl;

    return true;
}

template<typename T>
void parse_wrap_base_type(JNIEnv *env, jobject thisObj, const char *className, const char *methodName, const char *rparams) {
    jclass cls = NULL;
    jmethodID mid = NULL;

    cls = env->FindClass(className);
    if (NULL == cls) {
        cout << "FindClass(" << className << ") fail" << endl;
        return;
    }
    mid = env->GetMethodID(cls, methodName, rparams);
    if (NULL == mid) {
        cout << "get method " << methodName << "(" << rparams << ") fail" << endl;
        return;
    }
    T t = (T)env->CallIntMethod(thisObj, mid);
    cout << "parse_wrap_base_type<T>(" << className << ", " << methodName << ", " << rparams << ") = " << t << endl;
}

/*
 * Class:     com_ft_mynative_MyNativeJava
 * Method:    wrapBaseTypes
 * Signature: (Ljava/lang/Integer;Ljava/lang/Character;Ljava/lang/Boolean;Ljava/lang/Short;Ljava/lang/Long;Ljava/lang/Float;Ljava/lang/Double;Ljava/lang/Byte;)Ljava/lang/Boolean;
 */
JNIEXPORT jobject JNICALL Java_com_ft_mynative_MyNativeJava_wrapBaseTypes
        (JNIEnv *env, jobject thisObj, jobject ia, jobject cb, jobject bc, jobject sd, jobject le, jobject ff, jobject dh, jobject bi) {
//    new Integer(5).intValue();
//    new Boolean(false).booleanValue();
//    new Short((short)4).shortValue();
//    new Long((long)6).longValue();
//    new Character('a').charValue();
//    new Float(5.0f).floatValue();
//    new Double(5.9).doubleValue();
//    new Byte((byte)5).byteValue();
//    Boolean.valueOf(false);
    parse_wrap_base_type<int>(env,              ia, "Ljava/lang/Integer;",      "intValue",     "()I");
    parse_wrap_base_type<bool>(env,             bc, "Ljava/lang/Boolean;",      "booleanValue", "()Z");
    parse_wrap_base_type<char>(env,             cb, "Ljava/lang/Character;",    "charValue",    "()C");
    parse_wrap_base_type<short>(env,            sd, "Ljava/lang/Short;",        "shortValue",   "()S");
    parse_wrap_base_type<long>(env,             le, "Ljava/lang/Long;",         "longValue",    "()J");
    parse_wrap_base_type<float>(env,            ff, "Ljava/lang/Float;",        "floatValue",   "()F");
    parse_wrap_base_type<double>(env,           dh, "Ljava/lang/Double;",       "doubleValue",  "()D");
    parse_wrap_base_type<unsigned char>(env,    bi, "Ljava/lang/Byte;",         "byteValue",    "()B");

    jobject obj = NULL;
    jmethodID mid = NULL;
    jclass cls = env->FindClass("Ljava/lang/Boolean;");
    if (NULL != cls) {
        mid = env->GetMethodID(cls, "<init>", "(Z)V");
        if (NULL != mid) {
            obj = env->NewObject(cls, mid, true);
            cout << "use constructor method conv is ok" << endl;
        }

        mid = env->GetStaticMethodID(cls, "valueOf", "(Z)Ljava/lang/Boolean;");
        if (NULL != mid) {
            env->CallStaticBooleanMethod(cls, mid, false);
            cout << "use static method conv is ok" << endl;
        }
    }

    return obj;
}

/*
 * Class:     com_ft_mynative_MyNativeJava
 * Method:    intArray
 * Signature: ([I)[Z
 */
JNIEXPORT jbooleanArray JNICALL Java_com_ft_mynative_MyNativeJava_intArray
        (JNIEnv *env, jobject thisObj, jintArray intA) {
    jsize len = env->GetArrayLength(intA);
    jint ji = 0;
    jint sum = 0;
    cout << "conv jintArray to c int[], len is " << len << ", items is " << endl;

    jclass cls = env->FindClass("Ljava/lang/Boolean;");
    jbooleanArray boolArr = env->NewBooleanArray(len);
    jboolean *bools = new jboolean[len];

    jboolean jb = false;
    jint *jia = env->GetIntArrayElements(intA, &jb);
    if (NULL != jia) {
        for (int i=0; i<len; i++) {
            ji = jia[i];
            sum += ji;
            cout << ji << ", ";

            // num 偶数 则为 true，否则为false
            bools[i] = (ji&1) == 1 ? true : false;
        }
        env->SetBooleanArrayRegion(boolArr, 0, len, bools);
        env->ReleaseIntArrayElements(intA, jia, 0);
    }
    cout << " total is " << sum << endl;

    return boolArr;
}

/*
 * Class:     com_ft_mynative_MyNativeJava
 * Method:    wrapIntArray
 * Signature: ([Ljava/lang/Integer;)[Ljava/lang/Boolean;
 */
JNIEXPORT jobjectArray JNICALL Java_com_ft_mynative_MyNativeJava_wrapIntArray
        (JNIEnv *env, jobject thisObj, jobjectArray integerA) {
    jsize len = env->GetArrayLength(integerA);
    jint ji = 0;
    jint sum = 0;
    cout << "conv jintArray to c int[], len is " << len << ", items is " << endl;

    jclass cls = env->FindClass("Ljava/lang/Boolean;");

    jobjectArray boolArr = env->NewObjectArray(len, cls, NULL);

    jboolean jb = false;
    jobject jobj = NULL;
    for (int i=0; i<len; i++) {
        jobj = env->GetObjectArrayElement(integerA, i);
        if (NULL != jobj) {
            jmethodID mid = env->GetMethodID(env->FindClass("Ljava/lang/Integer;"), "intValue", "()I");
            if (NULL != mid) {
                ji = (jint)env->CallIntMethod(jobj, mid);
                sum += ji;
                cout << ji << ", ";

                // num 偶数 则为 true，否则为false
                jobject obj = NULL;
                if (NULL != cls) {
                    jmethodID mid = env->GetStaticMethodID(cls, "valueOf", "(Z)Ljava/lang/Boolean;");
                    jboolean isok = (ji&1)==1 ? true : false;
                    if (NULL != mid) {
                        obj = env->CallStaticObjectMethod(cls, mid, isok);
                        env->SetObjectArrayElement(boolArr, i, obj);
                    }
                }
            }
        }
    }

    cout << " total is " << sum << endl;

    return boolArr;
}

/*
 * Class:     com_ft_mynative_MyNativeJava
 * Method:    stringTest
 * Signature: (Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_ft_mynative_MyNativeJava_stringTest
        (JNIEnv *env, jobject thisObj, jstring jstr) {
    jboolean isok = false;
    const char *cstr = env->GetStringUTFChars(jstr, NULL);
    cout << "input str is \"" <<  cstr <<"\"" << endl;
    env->ReleaseStringUTFChars(jstr, cstr);

    char buf[256];
    sprintf(buf, "\"%s\" is modifyed", cstr);
    jstring jsret = env->NewStringUTF(buf);
    return jsret;
}

/*
 * Class:     com_ft_mynative_MyNativeJava
 * Method:    strArrTest
 * Signature: ([Ljava/lang/String;)[Ljava/lang/String;
 */
JNIEXPORT jobjectArray JNICALL Java_com_ft_mynative_MyNativeJava_strArrTest
        (JNIEnv *env, jobject thisObj, jobjectArray jobjA) {
    int len = env->GetArrayLength(jobjA);
    cout << "String[] len is " << len << ", items is " << endl;
    if (len < 1) {
        return NULL;
    }

    jobjectArray jobjs = env->NewObjectArray(len, env->FindClass("Ljava/lang/String;"), NULL);
    for (int i=0; i<len; i++) {
        jstring jstr1 = (jstring)env->GetObjectArrayElement(jobjA, i);
        const char *js = env->GetStringUTFChars(jstr1, NULL);
        cout << js << ", " << endl;
        char buf[256];
        sprintf(buf, "%s after modify", js);
        env->ReleaseStringUTFChars(jstr1, js);

        jstring jstr = env->NewStringUTF(buf);
        env->SetObjectArrayElement(jobjs, i, jstr);
    }
    return jobjs;
}

/*
 * Class:     com_ft_mynative_MyNativeJava
 * Method:    modifyFields
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_ft_mynative_MyNativeJava_modifyFields
        (JNIEnv *env, jobject thisObj) {
//    private int num = 5;
//    private char[] ca = {'a', 'b'};
//    private String str = "tom";
//    private String[] strA = {"one", "two"};
//
//    private static int snum = 5;
//    private static char[] sca = {'a', 'b'};
//    private static String sstr = "bruce";
//    private static String[] sstrA = {"Monday", "Tuesty"};
    jclass cls = env->GetObjectClass(thisObj);
    if (NULL == cls) {
        cout << "getObjectClass is NULL" << endl;
        return;
    }
    jfieldID fid = NULL;

    // private int num = 5; + 2
    fid = env->GetFieldID(cls, "num", "I");
    if (NULL != fid) {
        jint it = env->GetIntField(thisObj, fid);
        env->SetIntField(thisObj, fid, it+2);
        cout << "modify filed num from " << it << " to " << it+2 << endl;
    }

    // modify private char[] ca = {'a', 'b'}; + 2
    fid = env->GetFieldID(cls, "ca", "[C");
    if (NULL != fid) {
        jcharArray carr = (jcharArray)env->GetObjectField(thisObj, fid);
        int arrLen = env->GetArrayLength(carr);
        jchar *cs = (jchar*)env->GetCharArrayElements(carr, NULL);
        cout << "modify field ca['a', 'b'] len is " << arrLen << endl;
        carr = env->NewCharArray(arrLen);
        jchar *pca = new jchar[arrLen];
        for (int i=0; i<arrLen; i++) {
            pca[i] = cs[i] + 2;
            cout << "from " << (char)cs[i] << " to " << (char)((char)(cs[i])+2) << endl;
        }
        env->SetCharArrayRegion(carr, 0, arrLen, pca);
        env->SetObjectField(thisObj, fid, carr);
        env->ReleaseCharArrayElements(carr, (jchar*)cs, 0);
    }

    // modify private String str = "tom"; + 2
    // modify private String[] strA = {"one", "two"}; + 2

    // modify private static int snum = 5; + 2
    fid = env->GetStaticFieldID(cls, "snum", "I");
    if (NULL != fid) {
        jint jit = env->GetStaticIntField(cls, fid);
        env->SetStaticIntField(cls, fid, jit+2);
        cout << "modify static snum from " << jit << " to " << jit+2 << endl;
    }
    // modify private static char[] sca = {'a', 'b'}; + 2
    // modify private static String sstr = "bruce"; + 2
    // modify private static String[] sstrA = {"Monday", "Tuesty"}; + 2
    fid = env->GetStaticFieldID(cls, "sstrA", "[Ljava/lang/String;");
    if (NULL != fid) {
        jobjectArray strArr = (jobjectArray)env->GetStaticObjectField(cls, fid);
        int len = env->GetArrayLength(strArr);
        if (len > 0) {
            cout << "modify static String[] sstrA, len is " << len << endl;
            cout << "before modify items is " << endl;
            for (int i=0; i<len; i++) {
                jstring str = (jstring)env->GetObjectArrayElement(strArr, i);
                const char *cstr = env->GetStringUTFChars(str, NULL);
                cout << cstr << ", " << endl;

                char buf[128];
                sprintf(buf, "%s after modify", cstr);
                jstring jstr2 = env->NewStringUTF(buf);
                env->SetObjectArrayElement(strArr, i, jstr2);
                env->ReleaseStringUTFChars(str, cstr);
            }

            cout << "after modify items is " << endl;
            for (int i=0; i<len; i++) {
                jstring str = (jstring)env->GetObjectArrayElement(strArr, i);
                const char *cstr = env->GetStringUTFChars(str, NULL);
                cout << cstr << ", " << endl;
                env->ReleaseStringUTFChars(str, cstr);
            }

            env->SetStaticObjectField(cls, fid, strArr);
        }
    }
}

/*
 * Class:     com_ft_mynative_MyNativeJava
 * Method:    testMethod
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_ft_mynative_MyNativeJava_testMethod
        (JNIEnv *env, jobject thisObj) {

    jclass cls = env->GetObjectClass(thisObj);
    if (NULL == cls) {
        cout << "getobjectclass is null" << endl;
        return;
    }

    jmethodID mid = NULL;
//    private void testInt(int a);
    mid = env->GetMethodID(cls, "testInt", "(I)V");
    if (NULL != mid) {
        env->CallVoidMethod(thisObj, mid, 5);
    }

//    private void testString(String s);
    mid = env->GetMethodID(cls, "testString", "(Ljava/lang/String;)V");
    if (NULL != mid) {
        char *cstr = new char[32];
        strcpy(cstr, "this is c string");
        jstring jstr = env->NewStringUTF(cstr);
        env->CallVoidMethod(thisObj, mid, jstr);
        // 不能释放，会出错，让java自己释放
        //env->ReleaseStringUTFChars(jstr, cstr);
    }

//    private static void stestInt(int a);
    mid = env->GetStaticMethodID(cls, "stestInt", "(I)V");
    if (NULL != mid) {
        env->CallStaticVoidMethod(cls, mid, 5);
    }
//    private static void stestString(String s);
    mid = env->GetStaticMethodID(cls, "stestString", "(Ljava/lang/String;)V");
    if (NULL != mid) {
        const char *cstr = "this is c string";
        jstring jstr = env->NewStringUTF(cstr);
        env->CallStaticVoidMethod(cls, mid, jstr);
        //env->ReleaseStringUTFChars(jstr, cstr);
    }
}