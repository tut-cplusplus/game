#ifndef ___Class_BlockUnbreakableWall
#define ___Class_BlockUnbreakableWall

#include "BlockWall.hpp"
#include "Size.hpp"

class BlockUnbreakableWall : public BlockWall {
public:
	BlockUnbreakableWall();
	BlockUnbreakableWall(const Size<double>& size);

	void changeColor(void) const;
	bool isBreakable(void) const;
	void draw(void);
};

#endif

