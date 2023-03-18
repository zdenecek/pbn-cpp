//
// Created by zdnek on 11/03/2023.
//

#include "application.h"
#include "PbnParser.h"

#include <iostream>
#include <vector>
#include <fstream>
#include <istream>
#include <string>

using namespace std;

int Application::run(vector<string>& arguments) {

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
    }
    return 0;
}
