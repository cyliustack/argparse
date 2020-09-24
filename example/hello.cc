#include <iostream> // std:cout
#include <cstring>  // std::string
#include <vector>   // vector of meminfo samples 
#include <map>      // store meminfo fields
#include "argparse.hpp"

int main(int argc, char* argv[]) {
    
    if (argc == 1) { 
        std::cout << "usage: ./hello --say \"hello,world\"" << std::endl;
        exit(-1);
    }

    argparse::ArgumentParser parser;
    parser.add_argument("--say", "welcome to use argparse!"); 
    parser.add_argument("--verbose", "false"); 
    std::map<std::string, std::string> args = parser.parse_args(argc, argv);
    
    if (args["--verbose"] == "true") {
        parser.dump();
    }
    return 0; 
}
