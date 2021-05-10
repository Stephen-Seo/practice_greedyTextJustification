#ifndef GREEDY_TEXT_JUSTIFICATION_ARG_PARSE_HPP
#define GREEDY_TEXT_JUSTIFICATION_ARG_PARSE_HPP

#include <string>
#include <unordered_map>

namespace ArgParse {
    std::unordered_map<std::string, std::string> parseArgs(int argc, char **argv);
} // namespace ArgParse

#endif
