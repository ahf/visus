/* vim: set sw=4 sts=4 et foldmethod=syntax : */

#include <cstdlib>
#include <exception>
#include <iostream>
#include <string>

#include <boost/filesystem.hpp>
#include <boost/program_options.hpp>

#include "visus.hh"

namespace po = boost::program_options;

using namespace visus;

using std::cout;
using std::cerr;
using std::endl;

int main(int argc, char *argv[])
{
    std::string application_name = boost::filesystem::basename(argv[0]);

    try
    {
        po::options_description description("Options");
        description.add_options()
            ("help,h", "Print this help message.")
            ("config,c", po::value<std::string>()->default_value("config.json"), "Specify configuration file.");

        po::variables_map options;
        po::store(po::parse_command_line(argc, argv, description), options);

        // --help and -h.
        // Display a help message.
        if (options.count("help"))
        {
            cout << description << endl;
            return EXIT_SUCCESS;
        }

        po::notify(options);

        auto config = Config::from_file(options["config"].as<std::string>());

        cout << "Using configuration:" << endl
             << "Detector:" << endl
             << "   Hessian threshold: " << config->detector_hessian_threshold() << endl
             << "   Octaves: " << config->detector_octaves() << endl
             << "   Octave layers: " << config->detector_octave_layers() << endl << endl
             << "Caches:" << endl
             << "   Features directory: " << config->cache_features_directory() << endl
             << "   Keypoints directory: " << config->cache_keypoints_directory() << endl
             << endl;

        // Create cache directories.
        if (! boost::filesystem::exists(config->cache_features_directory()))
        {
            cout << "Creating cache directory: " << config->cache_features_directory() << endl;
            boost::filesystem::create_directories(config->cache_features_directory());
        }

        if (! boost::filesystem::exists(config->cache_keypoints_directory()))
        {
            cout << "Creating cache directory: " << config->cache_keypoints_directory() << endl;
            boost::filesystem::create_directories(config->cache_keypoints_directory());
        }
    }
    catch (const std::exception & e)
    {
        cerr << "Error: " << e.what() << endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
