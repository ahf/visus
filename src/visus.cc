/* vim: set sw=4 sts=4 et foldmethod=syntax : */

#include <cstdlib>
#include <exception>
#include <iostream>
#include <string>
#include <vector>

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
            ("add,a", po::value<std::vector<std::string> >(), "Add image to cache")
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

        std::tr1::shared_ptr<Config> config = Config::from_file(options["config"].as<std::string>());

        cout << "Using configuration:" << endl
             << "Detector:" << endl
             << "   Hessian threshold: " << config->detector_hessian_threshold() << endl
             << "   Octaves: " << config->detector_octaves() << endl
             << "   Octave layers: " << config->detector_octave_layers() << endl << endl
             << "Caches:" << endl
             << "   Directory: " << config->cache_directory() << endl
             << endl;

        // Create cache directory.
        if (! boost::filesystem::exists(config->cache_directory()))
        {
            cout << "Creating cache directory: " << config->cache_directory() << endl;
            boost::filesystem::create_directories(config->cache_directory());
        }

        if (options.count("add"))
        {
            std::vector<std::string> files = options["add"].as<std::vector<std::string> >();
            ImageFeatureExtractor extractor(config);

            for (std::vector<std::string>::const_iterator t(files.begin()), t_end(files.end()); t != t_end; ++t)
            {
                std::string hash = hash_file(*t);

                cout << "Extracting features from " << *t << " (" << hash << ")" << endl;

                boost::filesystem::path cache_file = config->cache_directory() + hash.substr(0, 2) + "/" + hash.substr(2, hash.size()) + "/features";

                if (! boost::filesystem::exists(cache_file))
                {
                    ImageFeatures features;
                    features = extractor.extract(*t);

                    boost::filesystem::create_directories(cache_file.parent_path());
                    features.save(cache_file);

                    ImageFeatures reloaded;
                    reloaded.load(cache_file);
                }
            }
        }
    }
    catch (const std::exception & e)
    {
        cerr << "Error: " << e.what() << endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
