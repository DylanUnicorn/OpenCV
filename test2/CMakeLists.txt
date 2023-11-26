cmake_minimum_required(VERSION 2.7)
project(second)

find_package(OpenCV 4 REQUIRED)
set(CMAKE_CXX_STANDARD 14)

add_executable(second test2.cpp)
target_link_libraries(second ${OpenCV_LIBS})
