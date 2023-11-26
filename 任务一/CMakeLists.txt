cmake_minimum_required(VERSION 2.7)
project(first)

find_package(OpenCV 4 REQUIRED)
set(CMAKE_CXX_STANDARD 14)

add_executable(main main.cpp)
target_link_libraries(main ${OpenCV_LIBS})
