#ifndef ___Class_BlockUnbreakableWall
#define ___Class_BlockUnbreakableWall

#include "BlockWall.hpp"

class BlockUnbreakableWall : public BlockWall {
public:
	BlockUnbreakableWall();
	BlockUnbreakableWall(double width, double height);

	void changeColor(void) const;
	bool isBreakable(void) const;
	void draw(void);
};

#endif

