#pragma once

#include <vector>
#include <string>
#include <boost/program_options.hpp>

constexpr auto VERSION = "0.1";

class Application {

private:
    static Application *instance;
    int handleFile(std::string filename, boost::program_options::variables_map &vm);
public:

    bool verbose = false;
    static Application* getInstance();

    Application();

    int run(int argc, char* argv[]);
};
