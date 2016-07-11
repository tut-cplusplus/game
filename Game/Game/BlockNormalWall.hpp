#ifndef ___Class_BlockNormalWall
#define ___Class_BlockNormalWall

#include "BlockWall.hpp"
#include "Size.hpp"

/**
 * 普通の壁クラス．
 */
class BlockNormalWall : public BlockWall {
public:
	BlockNormalWall();
	BlockNormalWall(const Size<double>& size);
	Block* clone(void) const;
};

#endif

