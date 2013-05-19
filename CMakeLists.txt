cmake_minimum_required(VERSION 2.8)
project(visus)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

find_package(OpenCV REQUIRED)
find_package(Crypto++ REQUIRED)

find_package(Boost 1.53.0 COMPONENTS filesystem serialization system program_options REQUIRED)

set(CMAKE_CXX_FLAGS "-std=c++11 -stdlib=libc++")
INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR} ${CRYPTO++_INCLUDE_DIR})

add_subdirectory(src)
