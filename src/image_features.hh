/* vim: set sw=4 sts=4 et foldmethod=syntax : */

#ifndef GUARD_IMAGE_FEATURES_HH
#define GUARD_IMAGE_FEATURES_HH 1

#include <vector>

#include <opencv2/core/core.hpp>
#include <opencv2/features2d/features2d.hpp>

#include <boost/filesystem/path.hpp>

#include <boost/serialization/access.hpp>

#include "serializers.hh"

namespace visus
{
    typedef std::vector<cv::KeyPoint> KeyPoints;
    typedef cv::Mat Feature;

    class ImageFeatures
    {
        private:
            friend class boost::serialization::access;

            KeyPoints _keypoints;
            Feature _feature;

            template <typename Archive_>
            void serialize(Archive_ & archive, const unsigned int version)
            {
                archive & _keypoints;
                archive & _feature;
            }

        public:
            KeyPoints keypoints() const;
            void set_keypoints(const KeyPoints & value);

            Feature feature() const;
            void set_feature(const Feature & value);

            void save(const boost::filesystem::path & file);
            void load(const boost::filesystem::path & file);
    };
}

#endif
