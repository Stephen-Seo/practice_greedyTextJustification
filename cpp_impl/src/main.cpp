#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

#include "helpers.hpp"

void printHelp() {
    std::cout << "Usage:\n";
    std::cout << "-w <width> - specify the width in integers\n";
    std::cout << "--string <string> - input string to print within the "
        "specified width";
    std::cout << std::endl;
}

int main(int argc, char **argv) {
    Helpers::ParseArgsResultType parsed;
    try {
        parsed = Helpers::parseArgs(argc, argv, {}, {"w", "string"});
    } catch(const std::invalid_argument &e) {
        std::cout << "ERROR: invalid argument\n";
        printHelp();
        return 1;
    }

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
