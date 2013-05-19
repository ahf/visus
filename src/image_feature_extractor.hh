/* vim: set sw=4 sts=4 et foldmethod=syntax : */

#ifndef GUARD_IMAGE_FEATURE_EXTRACTOR_HH
#define GUARD_IMAGE_FEATURE_EXTRACTOR_HH 1

#include <tr1/memory>

#include <boost/filesystem/path.hpp>

#include "config.hh"
#include "image_features.hh"

namespace visus
{
    class ImageFeatureExtractor
    {
        private:
            std::tr1::shared_ptr<Config> _config;

        public:
            ImageFeatureExtractor(std::tr1::shared_ptr<Config> config);
            ~ImageFeatureExtractor();

            ImageFeatures extract(const boost::filesystem::path & file) const;
    };
}

#endif
