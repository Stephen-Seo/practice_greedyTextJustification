#ifndef GREEDY_TEXT_JUSTIFICATION_ARG_PARSE_HPP
#define GREEDY_TEXT_JUSTIFICATION_ARG_PARSE_HPP

#include <string>
#include <unordered_map>
#include <vector>

namespace ArgParse {
    std::unordered_map<std::string, std::string> parseArgs(
        int argc,
        char **argv,
        const std::vector<std::string> &simpleArgs,
        const std::vector<std::string> &pairedArgs);
} // namespace ArgParse

#endif
