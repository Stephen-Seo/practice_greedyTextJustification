#include "argparse.hpp"

#include <cstring>
#include <stdexcept>

std::unordered_map<std::string, std::string> ArgParse::parseArgs(
        int argc,
        char **argv,
        const std::vector<std::string> &simpleArgs,
        const std::vector<std::string> &pairedArgs) {
    std::unordered_map<std::string, std::string> mapping;

    --argc; ++argv;
    std::string temp;
    bool mappingFound;
    while(argc > 0) {
        mappingFound = false;
        for(const auto &s : simpleArgs) {
            if(s.size() == 1) {
                temp = std::string("-") + s;
            } else {
                temp = std::string("--") + s;
            }
            if(std::strcmp(temp.c_str(), argv[0]) == 0) {
                mapping.insert({s, ""});
                mappingFound = true;
                break;
            }
        }
        if(mappingFound) {
            --argc; ++argv;
            continue;
        }
        for(const auto &s : pairedArgs) {
            if(s.size() == 1) {
                temp = std::string("-") + s;
            } else {
                temp = std::string("--") + s;
            }
            if(std::strncmp(temp.c_str(), argv[0], temp.size()) == 0) {
                std::string arg;
                if(argv[0][temp.size()] == '=') {
                    arg = argv[0] + temp.size() + 1;
                } else {
                    if(argc > 1) {
                        --argc;
                        ++argv;
                        arg = argv[0];
                    } else {
                        throw std::invalid_argument("Paired arg missing pair");
                    }
                }
                mapping.insert({s, arg});
                mappingFound = true;
                break;
            }
        }

        if(!mappingFound) {
            throw std::invalid_argument("Got invalid arg");
        }

        --argc; ++argv;
    }

    return mapping;
}
