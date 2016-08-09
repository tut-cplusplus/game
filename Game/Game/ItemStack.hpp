#ifndef ___Class_ItemStack
#define ___Class_ItemStack

class ItemStack {
public:
	enum Type {WALL, TRAP, DECOY, MAX_BLOCK_TYPE};

private:
	Type type;
	unsigned num;

public:
	ItemStack();
	ItemStack(Type type, unsigned num);

	ItemStack& operator++(void);
	ItemStack& operator--(void);
	Type getType(void) const;
	int getNum(void) const;
};

inline ItemStack& ItemStack::operator++(void)
{
	num++;
	return *this;
}

inline ItemStack& ItemStack::operator--(void)
{
	num--;
	return *this;
}

inline ItemStack::Type ItemStack::getType(void) const
{
	return type;
}

inline int ItemStack::getNum(void) const
{
	return num;
}

#endif

