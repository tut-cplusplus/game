#ifndef ___Header_Debug
#define ___Header_Debug

#include <string>

#include "Block.hpp"

namespace Debug {
	void dump(const std::string& fpath, Block*** map);
}

#endif

