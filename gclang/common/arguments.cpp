//
// Created by molumn on 2023-11-17.
//
#include "gclang/common/arguments.hpp"

Arguments::Arguments(int argc, char* argv[]) {

    std::string executable = argv[0];
    size_t last_dot = executable.find_last_of('.');
    if (last_dot == std::string::npos) {
        type = "";
    } else {
        if (std::string extension = executable.substr(last_dot + 1); extension.empty()) {

        } else if (extension == "something") {

        }
    }

    int i = 1;
    subcommand = argv[i];
    std::string tmp;
    ++i;
    do {
        if (argv[i][0] == '-') {
            tmp = argv[i];
            tmp = tmp.substr(tmp.find_last_not_of('-'));
            ++i;
            tags[tmp] = argv[i];
        } else {
            target = argv[i];
        }
    } while (++i < argc);
}
