
#include <iostream>
#include <vector>
#include <fstream>
#include <istream>

#include "include/pbn/PbnParser.h"
#include "program/application.h"

using namespace std;

int run(vector<string>& arguments) {

    Application app;
    app.run(arguments);

    return 0;
}

int main(int argc, char *argv[]) {
    vector<string> arguments(argv+1, argv + argc);
    return run(arguments);
}


