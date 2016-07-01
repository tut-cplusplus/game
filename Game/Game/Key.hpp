#ifndef ___Class_Key
#define ___Class_Key

class Key {
private:
	static bool KEY_NORMAL;
	static bool KEY_SPECIAL;

private:
	bool keyType;
	int key;

public:
	Key();
	Key(bool keyType, int key);
	Key(int key);

	bool operator==(const Key& key) const;
	bool operator!=(const Key& key) const;
};

inline bool Key::operator==(const Key& key) const
{
	return keyType == key.keyType && key == key;
}

inline bool Key::operator!=(const Key& key) const
{
	return !operator==(key);
}

#endif

