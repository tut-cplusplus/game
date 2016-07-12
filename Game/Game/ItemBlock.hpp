#ifndef ___Class_ItemBlock
#define ___Class_ItemBlock

#include "Vector.hpp"
#include "Rectangle.hpp"
#include "Animation.hpp"
#include "Block.hpp"
#include "Size.hpp"

class ItemBlock : public Utility::Rectangle {
protected:
	Vector<double> position;
	Block* block;
	Animation animation;

protected:
	void init(void);
	virtual Block* generateBlock(void) const;

public:
	ItemBlock();
	ItemBlock(const Vector<double>& position, Block* block);
	ItemBlock(const Vector<double>& position, const Size<double>& size, Block* block);
	ItemBlock(const ItemBlock& itemBlock);
	~ItemBlock();

	void draw(void);
	/**
	 * アクセッサ
	 */
	void setSize(const Size<double>& size);
};

inline void ItemBlock::setSize(const Size<double>& size)
{
	this->size = size;
}

#endif

