## 简介
>MyNativeCpp是一个为项目MyNativeJava提供native方法的动态库工程。

>使用环境
* 环境 win7 64位系统
* java: IDEA 2018.1 + jdk1.8
* c++ : CLion 2018.2 + mingw-w64
* 依赖库及文件
    * **%JAVA_HOME%\lib\jvm.lib**
    * **%JAVA_HOME%\include;%JAVA_HOME%\include\jni.h**
    * **%JAVA_HOME%\include;%JAVA_HOME%\include\win32\jni_md.h**

## 模块
* jni概述
* native接口文件
* 动态库提供本地方法
* java使用本地方法

### jni概述
>待补充

>参考
* [JNI学习笔记](http://jellypaul.github.io/java/2016/08/08/JNI%E5%AD%A6%E4%B9%A0%E7%AC%94%E8%AE%B0.html)
* [Java Programming Tutorial Java Native Interface](https://www3.ntu.edu.sg/home/ehchua/programming/java/JavaNativeInterface.html)

### native接口文件
>include目录下javah生成的接口文件，具体操作参见[native接口生成](https://github.com/feifa168/MyNativeJava/blob/master/README.md)。

>[接口文件](https://github.com/feifa168/MyNativeCpp/blob/master/com_ft_mynative_MyNativeJava.h)会逐步更新，主要用于测试
```c++
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

#ifdef __cplusplus
}
#endif
#endif
```

### 动态库提供本地方法
>CLion生成动态库，jdk是64位，原本使用的Mingw是32位程序，生成的dll在64位java程序中不能使用，
又下载了mingw64，配置使CLion使用64位mingw，CLion使用CMake编译程序。

[CMakeList.txt](https://github.com/feifa168/MyNativeCpp/blob/master/CMakeLists.txt)
```
cmake_minimum_required(VERSION 3.12)
project(MyNativeJava)

set(CMAKE_CXX_STANDARD 14)

set(INC_DIR D:/java/jdk1.8.0_192/include;D:/java/jdk1.8.0_192/include/win32;../include)
set(LINK_DIR D:/java/jdk1.8.0_192/lib)
set(SOURCE_FILES com_ft_mynative_MyNativeJava.cpp com_ft_mynative_MyNativeJava.h)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "../../MyNativeJava")

include_directories(${INC_DIR})
link_directories(${LINK_DIR})
link_libraries(jvm jawt)

add_library(MyNativeJava SHARED com_ft_mynative_MyNativeJava.cpp com_ft_mynative_MyNativeJava.h)
```

生成的dll直接指定输出到[MyNativeJava](https://github.com/feifa168/MyNativeJava)目录下，CMakeLists.txt中设置set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "../../MyNativeJava")，需要MyNativeJava与MyNativeCpp放在一个目录下。
具体方法请参考源代码


### java使用本地方法
详情参见[java调用动态库](https://github.com/feifa168/MyNativeJava/blob/master/README.md)
>静态块加载dll
```java
public class MyNativeJava {
    static {
        System.loadLibrary("libMyNativeJava");
    }
}
```
>加载成功就可以使用native方法了，fun，fun2，fun3是测试用的几个方法，后续会加入更多内容，比如类成员修改，类方法执行等。
详情参见[MyNativeJava.java](https://github.com/feifa168/MyNativeJava/blob/master/src/main/java/com/ft/mynative/MyNativeJava.java)
```java
public class MyNativeJava {
    static {
        System.loadLibrary("libMyNativeJava");
    }

    private native void fun();
    private native int fun2(String s);
    private native void fun3(Integer[] ia);

    public static void main(String[] args) {
        MyNativeJava nativeHello = new MyNativeJava();
        nativeHello.fun();
        System.out.println(nativeHello.fun2("hello, tom"));
        nativeHello.fun3(new Integer[]{3, 5});
    }
}
