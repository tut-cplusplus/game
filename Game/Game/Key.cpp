#include "Key.hpp"

bool Key::KEY_NORMAL = false;
bool Key::KEY_SPECIAL = true;

Key::Key()
	: keyType(KEY_NORMAL), key(0)
{

}

Key::Key(bool keyType, int key)
	: keyType(keyType), key(key)
{

}

Key::Key(int key)
	: keyType(KEY_NORMAL), key(key)
{

}
