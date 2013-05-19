/* vim: set sw=4 sts=4 et foldmethod=syntax : */

#include <fstream>

#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>

#include <boost/serialization/vector.hpp>

#include "image_features.hh"

using namespace visus;
using namespace cv;

KeyPoints ImageFeatures::keypoints() const
{
    return _keypoints;
}

void ImageFeatures::set_keypoints(const KeyPoints & value)
{
    _keypoints = value;
}

Feature ImageFeatures::feature() const
{
    return _feature;
}

void ImageFeatures::set_feature(const Feature & value)
{
    _feature = value;
}

void ImageFeatures::save(const boost::filesystem::path & file)
{
    std::ofstream stream(file.string().c_str());
    boost::archive::binary_oarchive archive(stream);
    archive << *this;
}

void ImageFeatures::load(const boost::filesystem::path & file)
{
    std::ifstream stream(file.string().c_str());
    boost::archive::binary_iarchive archive(stream);
    archive >> *this;
}
