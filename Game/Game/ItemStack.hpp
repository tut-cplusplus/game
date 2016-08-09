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

	void operator--(void);
	Type getType(void) const;
	int getNum(void) const;
};

inline void ItemStack::operator--(void)
{
	num--;
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

