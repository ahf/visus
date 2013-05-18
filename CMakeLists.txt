cmake_minimum_required(VERSION 2.8)
project(visus)

find_package(OpenCV REQUIRED)

find_package(Boost 1.53.0 COMPONENTS system REQUIRED)

INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})

add_subdirectory(src)
