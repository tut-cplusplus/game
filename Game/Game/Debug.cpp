#include <fstream>
#include <typeinfo>

#include "Global.hpp"
#include "BlockAir.hpp"
#include "BlockNormalWall.hpp"
#include "Debug.hpp"

void Debug::dump(const std::string& fpath, Block*** map)
{
	ofstream ofs(fpath);
	ofs << "map dump" << endl;
	ofs << "-1 : nullptr" << endl;
	ofs << " 0 : BlockAir" << endl;
	ofs << " 1 : BlockNormalWall" << endl;
	ofs << " 2 : BlockTrap" << endl;
	unsigned count[4] = {0};
	for (int i = 1; i < Global::MAP_HEIGHT - 1; i++) {
		for (int j = 1; j < Global::MAP_WIDTH - 1; j++) {
			Block* blockPtr = map[i][j];
			int type = -1;
			if (blockPtr != nullptr) {
				const Block& block = *blockPtr;
				if (typeid(block) == typeid(BlockAir))
					type = 0;
				else if (typeid(block) == typeid(BlockNormalWall))
					type = 1;
				else
					type = 2;
			}
			count[type + 1]++;
			ofs << to_string(type);
		}
		ofs << endl;
	}
	ofs << "nullptr          : " << count[0] << endl;
	ofs << "BlockAir         : " << count[1] << endl;
	ofs << "BlockNormalWall  : " << count[2] << endl;
	ofs << "BlockTrap        : " << count[3] << endl;
	unsigned sum = 0;
	for (unsigned i = 0; i < sizeof(count) / sizeof(count[0]); i++)
		sum += count[i];
	ofs << "sum              : " << sum << endl;
	ofs << "correct map size : " << (Global::MAP_HEIGHT - 2) * (Global::MAP_WIDTH - 2) << endl;
}

