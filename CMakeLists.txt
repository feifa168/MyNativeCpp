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

add_library(MyNativeJava SHARED ${SOURCE_FILES})
#add_executable(MyNativeJava ${SOURCE_FILES})