cmake_minimum_required(VERSION 3.16)
project(C9AIO)

# 指定目标系统为Linux
set(CMAKE_SYSTEM_NAME Linux)

# 设置交叉编译器路径
set(GCC_PATH "/opt/gcc-linaro-4.9.4-2017.01-x86_64_arm-linux-gnueabi")
set(CMAKE_FIND_ROOT_PATH ${GCC_PATH})
set(CMAKE_C_COMPILER "${GCC_PATH}/bin/arm-linux-gnueabi-gcc")
set(CMAKE_CXX_COMPILER "${GCC_PATH}/bin/arm-linux-gnueabi-g++")

# 设置其他交叉编译选项
#set(CMAKE_SYSROOT /opt/gcc-linaro-4.9.4-2017.01-x86_64_arm-linux-gnueabi)
#set(CMAKE_LIBRARY_PATH <path_to_cross_libraries>)
#set(CMAKE_INCLUDE_PATH <path_to_cross_includes>)

# 设置编译选项
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -march=armv7-a -mthumb-interwork -mfloat-abi=softfp -mfpu=neon -fno-omit-frame-pointer -funwind-tables -g -Wall -fPIC -O3 -std=c++11")

# 设置源文件列表
set(SOURCES
    src/main.cpp
)

# 生成动态库
add_library(c9sdk SHARED ${SOURCES})
