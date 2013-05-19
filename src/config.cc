/* vim: set sw=4 sts=4 et foldmethod=syntax : */

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

#include "config.hh"

namespace pt = boost::property_tree;

using namespace visus;

std::tr1::shared_ptr<Config> Config::from_file(const std::string & filename)
{
    pt::ptree tree;
    pt::json_parser::read_json(filename, tree);

    std::tr1::shared_ptr<Config> r(new Config);

    // Detector.
    r->set_detector_hessian_threshold(tree.get<double>("detector.hessian_threshold", 400.0));
    r->set_detector_octaves(tree.get<int>("detector.octaves", 3));
    r->set_detector_octave_layers(tree.get<int>("detector.octave_layers", 4));

    // Cache.
    r->set_cache_directory(tree.get<std::string>("cache.directory", "cache/"));

    return r;
}

double Config::detector_hessian_threshold() const
{
    return _detector_hessian_threshold;
}

void Config::set_detector_hessian_threshold(double value)
{
    _detector_hessian_threshold = value;
}

int Config::detector_octaves() const
{
    return _detector_octaves;
}

void Config::set_detector_octaves(int value)
{
    _detector_octaves = value;
}

int Config::detector_octave_layers() const
{
    return _detector_octave_layers;
}

void Config::set_detector_octave_layers(int value)
{
    _detector_octave_layers = value;
}

std::string Config::cache_directory() const
{
    return _cache_directory;
}

void Config::set_cache_directory(const std::string & value)
{
    _cache_directory = value;
}
