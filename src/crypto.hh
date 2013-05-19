/* vim: set sw=4 sts=4 et foldmethod=syntax : */

#ifndef GUARD_CRYPTO_HH
#define GUARD_CRYPTO_HH 1

#include <string>

#include <boost/filesystem/path.hpp>

namespace visus
{
    std::string hash_file(const boost::filesystem::path & file);
}

#endif
