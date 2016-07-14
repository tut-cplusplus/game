#include "Keypad.hpp"

Keypad::Keypad()
{

}

Keypad::Keypad(Key up, Key down, Key left, Key right, Key breakBlock, Key placeWall, Key placeTrap, Key placeDecoy)
	: up(up), down(down), left(left), right(right), breakBlock(breakBlock), placeWall(placeWall), placeTrap(placeTrap), placeDecoy(placeDecoy)
{

}

