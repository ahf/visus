add_executable(visus visus.cc config.cc)
target_link_libraries(visus ${OpenCV_LIBS} ${Boost_LIBRARIES})
