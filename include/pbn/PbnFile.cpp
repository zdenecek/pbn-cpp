#include "PbnFile.h"

#include <exception>

using namespace std;

vector<shared_ptr<SemanticPbnToken>> &PbnFile::getTokens()  {
    return this->tokens;
}

 DealContextObs PbnFile::getDeal(size_t number)  {
    if(!this->hasDealWithNumber(number)) {
        throw out_of_range("File does not contain deal number " + to_string(number));
    }
    return this->dealsByNumber.at(number);
}

bool PbnFile::hasDealWithNumber(size_t number) const {
    return this->dealsByNumber.contains(number);
}

const vector<DealContext> &PbnFile::getDeals() const {
    return this->deals;
}


void PbnFile::insertToken(shared_ptr<SemanticPbnToken> token) {

}

void PbnFile::normalize() {

}


