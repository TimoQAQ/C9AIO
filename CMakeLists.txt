cmake_minimum_required(VERSION 3.16)
project(C9AIO)

# 指定目标系统为Linux
set(CMAKE_SYSTEM_NAME Linux)

# 设置交叉编译器路径
set(GCC_PATH "/opt/gcc-linaro-4.9.4-2017.01-x86_64_arm-linux-gnueabi")
set(CMAKE_FIND_ROOT_PATH ${GCC_PATH})
set(CMAKE_C_COMPILER "${GCC_PATH}/bin/arm-linux-gnueabi-gcc")
set(CMAKE_CXX_COMPILER "${GCC_PATH}/bin/arm-linux-gnueabi-g++")
set(ENV{PATH} "${CMAKE_FIND_ROOT_PATH}/bin:$ENV{PATH}")
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

include_directories(${CMAKE_CURRENT_BINARY_DIR}/alsa/include)

# 编译库文件
execute_process(
  COMMAND autoreconf -i
  WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib/alsa
)

execute_process(
  COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/lib/alsa/configure --host=arm-linux-gnueabi --prefix=${CMAKE_CURRENT_BINARY_DIR}/alsa
  WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib/alsa
)

execute_process(
  COMMAND make -j8
  WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib/alsa
)

execute_process(
  COMMAND make install
  WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib/alsa
)

link_directories(${CMAKE_CURRENT_BINARY_DIR}/alsa/lib)

# 生成动态库
add_library(c9sdk SHARED ${SOURCES})
target_link_libraries(c9sdk PRIVATE asound)
