add_executable(visus visus.cc config.cc crypto.cc)
target_link_libraries(visus ${OpenCV_LIBS} ${Boost_LIBRARIES} ${CRYPTO++_LIBRARIES})
