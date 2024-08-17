cmake_minimum_required(VERSION 3.24.4)

project(OpencvTest)

set(CMAKE_CXX_STANDARD 17)

set(OpenCV_DIR D:/Software/OpenCV/opencv-4.10.0-builds/install)

find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(OpencvTest 03.cpp)

target_link_libraries(OpencvTest ${OpenCV_LIBS})