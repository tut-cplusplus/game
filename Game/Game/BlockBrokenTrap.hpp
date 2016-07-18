#ifndef ___Class_BlockBrokenTrap
#define ___Class_BlockBrokenTrap

#include "Block.hpp"

class BlockBrokenTrap : public Block {
public:
	BlockBrokenTrap();
	BlockBrokenTrap(const Size<double>& size);

	void loadAnimations(void);
	std::string getAnimationPath(void) const;
	bool isTransparent(void) const;
};

#endif

