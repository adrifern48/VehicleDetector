cmake_minimum_required(VERSION 3.7)

project(VehicleDetector)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
add_executable(VehicleDetector src/main.cpp src/CarDetector.cpp)
target_link_libraries(VehicleDetector ${OpenCV_LIBS})

add_definitions(-std=c++17)
set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")