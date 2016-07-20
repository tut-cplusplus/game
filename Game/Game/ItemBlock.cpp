#include <iostream>

#include "ItemBlock.hpp"

using namespace std;

void ItemBlock::init(void)
{
	if (block == nullptr)
		return;
	animation = block->getItemAnimation();
	animation.setLoop(true);
	animation.start();
	animation.setSize(size);
}

Block* ItemBlock::generateBlock(void) const
{
	if (block == nullptr)
		return nullptr;
	return block->clone();
}

ItemBlock::ItemBlock()
	: Rectangle(), block(nullptr)
{
	init();
}

ItemBlock::ItemBlock(const Vector<double>& position, Block* block)
	: Rectangle(block->getSize()), position(position), block(block)
{
	init();
}

ItemBlock::ItemBlock(const Vector<double>& position, const Size<double>& size, Block* block)
	: Rectangle(size), position(position), block(block)
{
	init();
}

ItemBlock::ItemBlock(const ItemBlock& itemBlock)
	: Rectangle(itemBlock.size), position(itemBlock.position), block(itemBlock.block->clone()), animation(itemBlock.animation)
{

}

ItemBlock::~ItemBlock()
{
	delete block;
}

void ItemBlock::draw(void)
{
	double width = size.getWidth();
	double height = size.getHeight();
	glEnable(GL_TEXTURE_2D);
	glPushMatrix();
	glTranslated(position.getX() * width, position.getY() * height, 0.0);
	animation.draw();
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
}

