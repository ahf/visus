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
            double _detector_hessian_treshold = 400.0;
            int _detector_octaves = 3;
            int _detector_octave_layers = 4;

        public:
            static std::shared_ptr<Config> from_file(const std::string & filename);

            double detector_hessian_treshold() const;
            void set_detector_hessian_treshold(double value);

            int detector_octaves() const;
            void set_detector_octaves(int value);

            int detector_octave_layers() const;
            void set_detector_octave_layers(int value);
    };
}

#endif
