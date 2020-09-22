#include <functional>
#include <iostream>
#include <iomanip>

#include <spdlog/spdlog.h>
#include <docopt/docopt.h>
#include <boost/spirit/home/x3.hpp>

#include "util/args.h"

static constexpr auto USAGE =
  R"(Dice Roll.

    Usage:
          droll [--debug=<level>] <roll> ...
          droll (-h | --help)
          droll --version

    Options:
          -h --help          Show this screen
          --version          Show version
          --debug=<level>    Log level [default: info]
)";

int main(int argc, const char **argv) {
	OptionsMap args = docopt::docopt(USAGE,
	  { std::next(argv, 1), std::next(argv, argc) },
	  true, // show help if requested
	  "droll 0.0.1"); // version string

	spdlog::level::level_enum debugLevel = extractDebugLevel(args);
	spdlog::set_level(debugLevel);

	for (auto const &arg : args) {
		std::cout << std::quoted(arg.first) << ": " << arg.second << std::endl;
	}

	auto rolls{extractRolls(args)};
	std::for_each(rolls.begin, rolls.end, [](auto &&val) {
		spdlog::info("{}", val);
	});
}
