/* vim: set sw=4 sts=4 et foldmethod=syntax : */

#include <cryptopp/files.h>
#include <cryptopp/hex.h>
#include <cryptopp/sha.h>

#include "crypto.hh"

std::string visus::hash_file(const boost::filesystem::path & file)
{
    std::string r;

    CryptoPP::SHA1 hash;
    CryptoPP::FileSource(file.string().c_str(), true, new CryptoPP::HashFilter(hash, new CryptoPP::HexEncoder(new CryptoPP::StringSink(r), true)));

    return r;
}
