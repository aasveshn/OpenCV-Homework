cmake_minimum_required(VERSION 3.0)

project(OpenCVComputingHomework)

find_package(OpenCV REQUIRED)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ")

add_executable(a.out main.cpp FirstTask/FirstTask.cpp)

target_link_libraries(a.out ${OpenCV_LIBS})


set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR})
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})

