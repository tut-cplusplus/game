#ifndef ___Class_Key
#define ___Class_Key

#include <iostream>

using namespace std;

class Key {
protected:
	static bool KEY_NORMAL;
	static bool KEY_SPECIAL;

private:
	bool keyType;
	int key;

public:
	Key();
	Key(bool keyType, int key);
	Key(int key);

	inline bool getKeyType(void) const;
	inline int getKey(void) const;
	bool operator==(const Key& key) const;
	bool operator!=(const Key& key) const;
};

inline bool Key::getKeyType(void) const
{
	return keyType;
}

inline int Key::getKey(void) const
{
	return key;
}

inline bool Key::operator==(const Key& key) const
{
	return keyType == key.keyType && this->key == key.key;
}

inline bool Key::operator!=(const Key& key) const
{
	return !operator==(key);
}

#endif

