#include "ItemStack.hpp"

using namespace std;

ItemStack::ItemStack()
{

}

ItemStack::ItemStack(Type type, unsigned num)
	: type(type), num(num)
{

}

