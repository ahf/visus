cmake_minimum_required(VERSION 2.8)
project(visus)

find_package(OpenCV REQUIRED)

find_package(Boost 1.53.0 COMPONENTS filesystem system program_options REQUIRED)

set(CMAKE_CXX_FLAGS "-std=c++11 -stdlib=libc++")
INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})

add_subdirectory(src)
