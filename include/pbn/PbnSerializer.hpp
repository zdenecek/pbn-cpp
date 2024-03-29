#ifndef PBN_PBNSERIALIZER_HPP_
#define PBN_PBNSERIALIZER_HPP_

#include <string>
#include <ostream>

#include "PbnFile.hpp"

/// @brief Serialize a pbn file to a file or stream
class PbnSerializer
{

public:
    /// @brief Serialize the pbn file to a physical file
    /// @param filename Path to save the file to 
    void serialize(const PbnFile &file, const std::string &filename) const;

    /// @brief Serialize the pbn file to a stream
    /// @param output_stream Stream to serialize the file to
    void serialize(const PbnFile &file, std::ostream &output_stream) const;
};

#endif // PBN_PBNSERIALIZER_HPP_
