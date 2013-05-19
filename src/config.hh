/* vim: set sw=4 sts=4 et foldmethod=syntax : */

#ifndef GUARD_CONFIG_HH
#define GUARD_CONFIG_HH 1

#include <memory>
#include <string>

namespace visus
{
    class Config
    {
        private:
            // Detector.
            double _detector_hessian_threshold = 400.0;
            int _detector_octaves = 3;
            int _detector_octave_layers = 4;

            // Cache.
            std::string _cache_features_directory;
            std::string _cache_keypoints_directory;

        public:
            static std::shared_ptr<Config> from_file(const std::string & filename);

            double detector_hessian_threshold() const;
            void set_detector_hessian_threshold(double value);

            int detector_octaves() const;
            void set_detector_octaves(int value);

            int detector_octave_layers() const;
            void set_detector_octave_layers(int value);

            std::string cache_features_directory() const;
            void set_cache_features_directory(const std::string & value);

            std::string cache_keypoints_directory() const;
            void set_cache_keypoints_directory(const std::string & value);
    };
}

#endif
