g++ -O3 -DBUILDING_EXAMPLE_DLL -fopenmp -Wshadow -Wsign-conversion -pedantic -Wall -Wextra -Wcast-align -Wcast-qual -Wctor-dtor-privacy -Wdisabled-optimization -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wnoexcept -Wold-style-cast -Woverloaded-virtual -Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=1 -Wswitch-default -Wundef -Werror -Wno-unused -Wno-unknown-pragmas -Wno-long-long  -fopenmp -DDDS_THREADS_BOOST -DDDS_THREADS_OPENMP -DDDS_THREADS_STL -c 
System.cpp
#pragma once

#include "PbnFile.h"

#include <string>
#include <vector>
#include <memory>