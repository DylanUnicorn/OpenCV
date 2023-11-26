cmake_minimum_required(VERSION 2.7)
project(third)

find_package(OpenCV 4 REQUIRED)
set(CMAKE_CXX_STANDARD 14)

add_executable(third third.cpp)
target_link_libraries(third ${OpenCV_LIBS})
