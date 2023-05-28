#ifndef PROGRAM_PBNAPPLICATION_HPP_
#define PROGRAM_PBNAPPLICATION_HPP_

#include <vector>
#include <string>
#include <boost/program_options.hpp>

constexpr auto VERSION = "0.1";

/// @brief This class represents the pbn application.
class Application
{

private:
    static Application *instance;
    int handleFile(std::string filename, boost::program_options::variables_map &vm);

public:
    bool verbose = false;
    
    /// @brief Application instance sigleton
    static Application *getInstance();

    Application();

    /// @brief Entry point; Runs the application with the given command line arguments. 
    int run(int argc, char *argv[]);
};

#endif // PROGRAM_PBNAPPLICATION_HPP_

