//
// Created by cn on 19.09.20.
//
#include "args.h"

spdlog::level::level_enum extractDebugLevel(OptionsMap const & options) {
	OptionsMap::const_iterator end{};
	auto val = options.find("--debug");
	auto logLevelVal = spdlog::level::info;
	if (val != end && val->second.isString()) {
		logLevelVal = spdlog::level::from_str(val->second.asString());
	} else {
		spdlog::log(spdlog::level::err, R"("Could not determine loglevel.\\n
Possible values are: "trace", "debug", "info", "warning", "error", "critical" and "off"")");
	}
	return logLevelVal;
}


Rolls extractRolls(OptionsMap const & options) {
	OptionsMap::const_iterator end{};
	Rolls reti{};
	std::vector<std::string_view> rolls{};
	auto val = options.find("<roll>");

	if (val != end && val->second.isStringList()) {
		reti.begin = val->second.asStringList().begin();
		reti.end = val->second.asStringList().end();
	}
	return reti;
}
