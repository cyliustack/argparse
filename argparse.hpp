/***
MIT License

Copyright (c) 2020 James

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
***/

#ifndef __ARGPARSE__
#define __ARGPARSE__
#include<iostream>
#include<map>

namespace argparse {
    std::map<std::string, std::string> args; 
    class ArgumentParser {
        std::map<std::string, std::string> args; 
        public:
        ArgumentParser () {
    
        } 
        void add_argument(const std::string, const std::string);
        void dump(void);
        std::map<std::string, std::string> parse_args(int, char*[]); 
    };
    
    void ArgumentParser::add_argument(const std::string flag,
                                      const std::string value)
    {
        args.insert(std::pair<std::string,std::string>(flag, value)); 
    }
    
    void ArgumentParser::dump()
    {
        std::cout << "Program Arguments:" << std::endl;
        for(auto arg: args) {
            std::cout << "[" << arg.first << "] = " << arg.second << std::endl;
        }
    }

    std::map<std::string, std::string> ArgumentParser::parse_args(int argc, char* argv[]) {
        for (int i=1; i<argc-1;) {
            std::string key(argv[i]);
            auto search = args.find(key);
            if (search != args.end()) {
                std::string value(argv[i+1]);
                args[key] = value; 
                i+=2;
            }
            else {
                i++;
            }
        }

        return args; 
    }
}

#endif 

