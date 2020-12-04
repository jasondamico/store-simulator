#include "item_holders/named_item_holder.h"

NamedItemHolder::NamedItemHolder() : ItemHolder()
{
	this->name = "Default";
}

NamedItemHolder::NamedItemHolder(std::string name, std::vector<StockItem> items) : ItemHolder(items)
{
	this->name = name;
}

NamedItemHolder::NamedItemHolder(std::string name) : ItemHolder()
{
	this->name = name;
}

std::string NamedItemHolder::getName()
{
	return this->name;
}
