#include "helpers.hpp"

#include <cstring>
#include <stdexcept>
#include <algorithm>
#include <iostream>

std::unordered_map<std::string, std::string> Helpers::parseArgs(
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

std::vector<std::string> Helpers::strSplit(const std::string &s, std::vector<char> delimeters) {
    std::vector<std::string> result;
    std::string temp;

    std::sort(delimeters.begin(), delimeters.end());

    for(char c : s) {
        if(std::binary_search(delimeters.begin(), delimeters.end(), c)) {
            if(!temp.empty()) {
                result.push_back(temp);
                temp.clear();
            }
        } else {
            temp += c;
        }
    }
    if(!temp.empty()) {
        result.push_back(temp);
    }

    return result;
}

void Helpers::printDividers(unsigned long long width) {
    for(unsigned long long i = 0; i < width; ++i) {
        if((i + 1) % 5 == 0) {
            std::cout << "+";
        } else {
            std::cout << "-";
        }
    }
    std::cout << std::endl;
}

void Helpers::printGreedyTextJustification(unsigned long long width, const std::vector<std::string> &tokens) {
    const auto printCurrentLine = [width] (std::vector<std::string> &words) {
        unsigned long long spaces = width;
        for(const auto &word : words) {
            if(word.size() > spaces) {
                spaces = 0;
            } else {
                spaces -= word.size();
            }
        }
        for(unsigned int i = 0; i < words.size(); ++i) {
            std::cout << words.at(i);
            for(unsigned int j = 0; j < spaces / words.size(); ++j) {
                std::cout << ' ';
            }
            if(i == words.size() - 1) {
                for(unsigned int j = 0; j < spaces % words.size(); ++j) {
                    std::cout << ' ';
                }
            }
        }
        std::cout << std::endl;
        words.clear();
    };

    std::vector<std::string> currentLine;
    unsigned long long currentToken = 0;
    unsigned long long size = 0;
    while(true) {
        size += tokens.at(currentToken).size();
        if(size + 1 >= width) {
            printCurrentLine(currentLine);
            size = 0;
            continue;
        } else {
            currentLine.push_back(tokens.at(currentToken));
            size += 1;
            ++currentToken;
            if(currentToken >= tokens.size()) {
                break;
            }
        }
    }
    if(!currentLine.empty()) {
        printCurrentLine(currentLine);
    }
}

