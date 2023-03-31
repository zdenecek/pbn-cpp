
#include "PbnApplication.h"
#include "PbnParser.h"

#include <iostream>
#include <vector>
#include <fstream>
#include <istream>
#include <string>

#include <boost/program_options.hpp>

namespace po = boost::program_options;

Application *Application::instance = nullptr;


Application *Application::getInstance()
{
    return Application::instance;
}

Application::Application()
{
    if(this->instance != nullptr)
        throw  std::runtime_error("PbnApplication already exists");
    this->instance = this;
}

int Application::run(int ac, char *av[])
{
    po::options_description opts_desc("Allowed options");
    opts_desc.add_options()
            ("help,h", "produce help message")
            ("version", "print version information")
            ("verbose,v", "print additional information about the file")
            ("strip,s", "remove all results, site and event information")
            ("analyze,a", po::value<std::string>()->implicit_value("OptimumResultTable"), "create double dummy analyses for each board")
            ("output,o", po::value<std::string>(), "output file name, if not specified, the program will use the input file name")
            ("info", "print information about the file")
            // positional
            ("inputfile,i", po::value<std::string>()->required() ,"input file name");
            ;

    po::positional_options_description pos_opts_desc;
    pos_opts_desc.add("inputfile", 1);


    po::variables_map vm {};

    auto parsed = po::command_line_parser(ac, av)
    .options(opts_desc)
    .positional(pos_opts_desc)
    .run();

    po::store(parsed, vm, true);

    if(vm.count("help")) {
        std::cout << opts_desc << std::endl;
        return 0;
    }

    if(vm.count("version")) {
        std::cout << "pbn " << VERSION << std::endl;
        return 0;
    }

    if(vm.count("verbose")) {
        this->verbose = true;
    }

    if(vm.count("inputfile") == 0) {
        std::cerr << "No input file specified" << std::endl;
        return 1;
    }

    std::string filename = vm["inputfile"].as<std::string>();

    return this->handleFile(filename, vm);
}

int Application::handleFile(std::string filename, po::variables_map &vm)
{  

    std::ifstream inputFile;
    inputFile.open(filename);

    if (!inputFile.is_open()) {
        std::cout << "Could not open file: " << filename << std::endl;
        return 1;
    }

    PbnParser parser;
    auto file = parser.parse(inputFile);
    inputFile.close();

    file.normalize();

    for (auto &token: file.getTokens()) {
        std::cout << "<" << token->typeName() << "> " << token->toString() << std::endl;
    }
    return 0;
}
