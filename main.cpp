
#include "boost/program_options.hpp"
#include "PbnApplication.h"

#include <iostream>

int main(int ac, char *av[]) {

    try {
        Application app;
        return app.run(ac, av);
    } catch (const boost::program_options::error &e) {
        std::cerr << "An error with options occured: " << e.what() << std::endl;
        return 1;
    } catch (const std::exception &e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
        return 1;
    } catch (...) {
        std::cerr << "An unknown error occurred." << std::endl;
        throw;
    }
}


