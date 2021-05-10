#include <iostream>

#include "argparse.hpp"

int main(int argc, char **argv) {
    auto parsed = ArgParse::parseArgs(argc, argv, {"a", "b"}, {"apple"});

    for(auto pair : parsed) {
        std::cout << pair.first << ", " << pair.second << std::endl;
    }

    return 0;
}
