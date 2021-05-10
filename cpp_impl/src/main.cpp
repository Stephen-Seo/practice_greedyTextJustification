#include <iostream>
#include <string>
#include <vector>

#include "helpers.hpp"

int main(int argc, char **argv) {
    auto parsed = Helpers::parseArgs(argc, argv, {}, {"w", "string"});

//    for(auto pair : parsed) {
//        std::cout << pair.first << ", " << pair.second << std::endl;
//    }

    unsigned long long width;
    if(auto iter = parsed.find("w"); iter != parsed.end()) {
        width = std::stoull(iter->second);
        std::cout << "Got width == " << width << std::endl;
    } else {
        return 1;
    }

    std::string str;
    if(auto iter = parsed.find("string"); iter != parsed.end()) {
        str = iter->second;
        std::cout << "Got string == \"" << str << "\"" << std::endl;
    } else {
        return 2;
    }

    Helpers::printDividers(width);

    std::vector<std::string> tokens = Helpers::strSplit(str, {' ', '\n', '\r'});

//    for(auto token : tokens) {
//        std::cout << token << '\n';
//    }
//    std::cout << std::endl;

    Helpers::printGreedyTextJustification(width, tokens);

    Helpers::printDividers(width);

    return 0;
}
