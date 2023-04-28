
#pragma once

#include "PbnFile.h"

#include "dds.h"

#include <string>
#include <vector>
#include <iostream>
#include <memory>

namespace manipulators
{

    class PbnBoardAnalyzer
    {
        public:

        void analyze(PbnFile &pbnFile) ;

    };

}