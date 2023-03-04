
#include <iostream>
#include <vector>
#include <fstream>
#include <istream>

#include "include/pbn/PbnParser.h"

using namespace std;

int run(vector<string>& arguments) {
    if(arguments.size() < 1) {
        cout << "Invalid number of arguments supplied!";
        return 1;
    }

    ifstream inputFile;
    inputFile.open(arguments[0]);

    if(!inputFile.is_open()) {
        cout << "Could not open file!";
        return 1;
    }

    PbnParser parser;
    auto file = parser.parse(inputFile);
    inputFile.close();

    file.normalize();


    for(auto& token : file.getTokens()) {
       cout << "<" <<  token->typeName() << "> " << token->toString() << endl;
      //  if(token->toString() == "A") cout << '1';
    }

    return 0;
}

int main(int argc, char *argv[]) {
    vector<string> arguments(argv+1, argv + argc);
    return run(arguments);
}


