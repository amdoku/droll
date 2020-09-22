//
// Created by cn on 19.09.20.
//

#ifndef DROLL_ARGS_H
#define DROLL_ARGS_H
#include <map>
#include <string>
#include <vector>
#include <optional>

#include <docopt/docopt.h>
#include <spdlog/spdlog.h>

using OptionsMap = std::map<std::string, docopt::value>;

[[nodiscard]]
spdlog::level::level_enum extractDebugLevel(OptionsMap const & options);

struct Rolls {
	std::vector<std::string>::const_iterator begin{};
	std::vector<std::string>::const_iterator end{};
};

[[nodiscard]]
Rolls extractRolls(OptionsMap const & options);

#endif //DROLL_ARGS_H
