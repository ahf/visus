/* vim: set sw=4 sts=4 et foldmethod=syntax : */

#ifndef GUARD_CONFIG_HH
#define GUARD_CONFIG_HH 1

#include <string>
#include <tr1/memory>

namespace visus
{
    class Config
    {
        private:
            // Detector.
            double _detector_hessian_threshold;
            int _detector_octaves;
            int _detector_octave_layers;

            // Cache.
            std::string _cache_directory;

        public:
            static std::tr1::shared_ptr<Config> from_file(const std::string & filename);

            double detector_hessian_threshold() const;
            void set_detector_hessian_threshold(double value);

            int detector_octaves() const;
            void set_detector_octaves(int value);

            int detector_octave_layers() const;
            void set_detector_octave_layers(int value);

            std::string cache_directory() const;
            void set_cache_directory(const std::string & value);
    };
}

#endif
