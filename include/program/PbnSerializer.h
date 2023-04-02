
#include <string>
#include <ostream>

#include "PbnFile.h"

class PbnSerializer {

    public:
        void serialize( const PbnFile& file, const std::string& filename) const;
        void serialize( const PbnFile& file, std::ostream& output_stream) const;
};