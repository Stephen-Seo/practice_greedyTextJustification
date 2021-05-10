#ifndef GREEDY_TEXT_JUSTIFICATION_ARG_HELPERS_HPP
#define GREEDY_TEXT_JUSTIFICATION_ARG_HELPERS_HPP

#include <string>
#include <unordered_map>
#include <vector>

namespace Helpers {
    std::unordered_map<std::string, std::string> parseArgs(
        int argc,
        char **argv,
        const std::vector<std::string> &simpleArgs,
        const std::vector<std::string> &pairedArgs);

    std::vector<std::string> strSplit(const std::string &s, std::vector<char> delimeters);

    void printDividers(unsigned long long width);

    void printGreedyTextJustification(unsigned long long width, const std::vector<std::string> &tokens);
} // namespace Helpers

#endif
