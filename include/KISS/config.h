// Copyright 2020 Carmelo Evoli - MIT License
#ifndef KISS_INCLUDE_CONFIG_H_
#define KISS_INCLUDE_CONFIG_H_

namespace KISS {

// Directory holding the upstream input tables, relative to the working directory.
constexpr const char* const kDataDir = "data/";

// Directory where converted output tables are written. Created at runtime if missing.
constexpr const char* const kOutputDir = "output/";

}  // namespace KISS

#endif  // KISS_INCLUDE_CONFIG_H_
