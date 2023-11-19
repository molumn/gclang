//
// Created by molumn on 2023-11-17.
//

#ifndef ARGUMENTS_H
#define ARGUMENTS_H

#include <string>
#include <unordered_map>

class Arguments {
public:
    Arguments() = default;
    Arguments(int argc, char* argv[]);
    ~Arguments() = default;

private:
    std::string type;
    std::string subcommand;
    std::unordered_map<std::string, std::string> tags = {};
    std::string target;

};

#endif //ARGUMENTS_H
