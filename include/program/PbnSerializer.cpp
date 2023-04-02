#include "PbnSerializer.h"
#include <iostream>
#include <fstream>  




void PbnSerializer::serialize(const PbnFile &file, const std::string &filename) const
{
    std::string name = filename;
    if(!filename.ends_with(".pbn")) {
        name += ".pbn";
    }
    std::ofstream outfile (name);
    serialize(file, outfile);
    outfile.close();
}

void PbnSerializer::serialize(const PbnFile &file, std::ostream &output_stream) const
{
    file.serialize(output_stream);
}
