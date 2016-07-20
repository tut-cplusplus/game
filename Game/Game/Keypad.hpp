#ifndef ___Class_Keypad
#define ___Class_Keypad

#include "Key.hpp"

class Keypad {
private:
	Key up;
	Key down;
	Key left;
	Key right;
	Key breakBlock;
	Key placeWall;
	Key placeTrap;
	Key placeDecoy;

public:
	Keypad();
	Keypad(Key up, Key down, Key left, Key right, Key breakBlock, Key placeWall, Key placeTrap, Key placeDecoy);

	const Key& getUp(void) const;
	const Key& getDown(void) const;
	const Key& getLeft(void) const;
	const Key& getRight(void) const;
	const Key& getBreakBlock(void) const;
	const Key& getPlaceWall(void) const;
	const Key& getPlaceTrap(void) const;
	const Key& getPlaceDecoy(void) const;
};

inline const Key& Keypad::getUp(void) const
{
	return up;
}

inline const Key& Keypad::getDown(void) const
{
	return down;
}

inline const Key& Keypad::getLeft(void) const
{
	return left;
}

inline const Key& Keypad::getRight(void) const
{
	return right;
}

inline const Key& Keypad::getBreakBlock(void) const
{
	return breakBlock;
}

inline const Key& Keypad::getPlaceWall(void) const
{
	return placeWall;
}

inline const Key& Keypad::getPlaceTrap(void) const
{
	return placeTrap;
}

inline const Key& Keypad::getPlaceDecoy(void) const
{
	return placeDecoy;
}

#endif

