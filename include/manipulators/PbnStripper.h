
#pragma once

#include "PbnFile.h"

#include <string>
#include <vector>
#include <memory>

class PbnStripper {

public:
    std::vector<std::string> allowed_tags;

    PbnStripper();
    explicit PbnStripper(std::vector<std::string> allowed_tags) : allowed_tags(allowed_tags) {}

    void strip(PbnFile &file);

};