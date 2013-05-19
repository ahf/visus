/* vim: set sw=4 sts=4 et foldmethod=syntax : */

#include <cassert>

#include <boost/filesystem.hpp>

#include <opencv2/core/core.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/nonfree/features2d.hpp>

#include "crypto.hh"
#include "image_feature_extractor.hh"

using namespace visus;

ImageFeatureExtractor::ImageFeatureExtractor(std::tr1::shared_ptr<Config> config) :
    _config(config)
{
}

ImageFeatureExtractor::~ImageFeatureExtractor()
{
}

ImageFeatures ImageFeatureExtractor::extract(const boost::filesystem::path & file) const
{
    cv::Mat image = cv::imread(file.string(), cv::IMREAD_GRAYSCALE);
    assert(image.data);

    KeyPoints keypoints;
    Feature feature;

    // Feature detector.
    cv::SurfFeatureDetector detector(_config->detector_hessian_threshold(), _config->detector_octaves(), _config->detector_octave_layers());
    detector.detect(image, keypoints);

    // Feature extractor.
    cv::SurfDescriptorExtractor extractor;
    extractor.compute(image, keypoints, feature);

    ImageFeatures r;
    r.set_keypoints(keypoints);
    r.set_feature(feature);

    return r;
}
