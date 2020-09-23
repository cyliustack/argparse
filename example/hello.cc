#include <iostream> // std:cout
#include <cstring>  // std::string
#include <vector>   // vector of meminfo samples 
#include <map>      // store meminfo fields
#include "argparse.hpp"

int main(int argc, char* argv[]) {
    argparse::ArgumentParser parser;
    parser.add_argument("--say", "welcome to use argparse!"); 
    parser.add_argument("--verbose", "true"); 
    std::map<std::string, std::string> args = parser.parse_args(argc, argv);
    if (argc == 1) { 
        std::cout << "usage: ./hello --say \"hello,world\"" << std::endl;
    }
    else {
        parser.dump();
    }
    return 0; 
}
