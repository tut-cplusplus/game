#ifndef ___Header_Debug
#define ___Header_Debug

#include <string>

#include "Block.hpp"
#include "RegionSet.hpp"

namespace Debug {
	void dump(const std::string& fpath, Block*** map);
	void dump(const std::string& fpath, const RegionSet& regionSet);
}

#endif

