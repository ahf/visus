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
    class ImageFeatures
    {
        typedef std::vector<cv::KeyPoint> KeyPoints;
        typedef std::vector<cv::Mat> Features;

        private:
            friend class boost::serialization::access;

            KeyPoints _keypoints;
            Features _features;

            template <typename Archive_>
            void serialize(Archive_ & archive, const unsigned int version)
            {
                archive & _keypoints;
                archive & _features;
            }

        public:
            ImageFeatures() = default;
            ~ImageFeatures() = default;

            KeyPoints keypoints() const;
            void set_keypoints(const KeyPoints & value);

            Features features() const;
            void set_features(const Features & value);

            void save(const boost::filesystem::path & file);
            void load(const boost::filesystem::path & file);
    };
}

#endif
