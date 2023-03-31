#include "PbnFile.h"

#include <exception>
#include <stdexcept>
#include <string>
#include <vector>
#include <memory>

std::vector<std::shared_ptr<SemanticPbnToken>> &PbnFile::getTokens()  {
    return this->tokens;
}

 DealContextObs PbnFile::getDeal(size_t number)  {
    if(!this->hasDealWithNumber(number)) {
        throw std::out_of_range("File does not contain deal number " + std::to_string(number));
    }
    return this->dealsByNumber.at(number);
}

bool PbnFile::hasDealWithNumber(size_t number) const {
    return this->dealsByNumber.contains(number);
}

const std::vector<DealContext> &PbnFile::getDeals() const {
    return this->deals;
}


void PbnFile::insertToken(std::shared_ptr<SemanticPbnToken> token) {

}

void PbnFile::normalize() {

}


