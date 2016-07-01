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

public:
	Keypad();
	Keypad(Key up, Key down, Key left, Key right, Key breakBlock);

	Key getUp(void) const;
	Key getDown(void) const;
	Key getLeft(void) const;
	Key getRight(void) const;
	Key getBreakBlock(void) const;
};

inline Key Keypad::getUp(void) const
{
	return up;
}

inline Key Keypad::getDown(void) const
{
	return down;
}

inline Key Keypad::getLeft(void) const
{
	return left;
}

inline Key Keypad::getRight(void) const
{
	return right;
}

inline Key Keypad::getBreakBlock(void) const
{
	return breakBlock;
}

#endif

