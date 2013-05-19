add_executable(visus visus.cc config.cc crypto.cc image_features.cc image_feature_extractor.cc)
target_link_libraries(visus ${OpenCV_LIBS} ${Boost_LIBRARIES} ${CRYPTO++_LIBRARIES})
