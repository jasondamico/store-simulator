#include "store_items/stock.h"

// Default constructor
StockItem::StockItem()
{
	this->name = "Tomatoes";
	this->count = 5;
	this->pricePerItem = 2;
}

StockItem::StockItem(std::string name, int count, int pricePerItem)
{
	this->name = name;
	this->count = count;
	this->pricePerItem = pricePerItem;
}

int StockItem::getNumItems()
{
	return this->count;
}

std::string StockItem::getName()
{
	return this->name;
}

int StockItem::getPrice()
{
	return this->pricePerItem;
}

int StockItem::getTotal()
{
	return this->getPrice() * this->getNumItems();
}

bool StockItem::canRemove(int quantity)
{
	return quantity <= this->getNumItems();
}

void StockItem::removeItems(int quantity)
{
	if (canRemove(quantity)) {
		this->count = this->count - quantity;
	}
	else
	{
		std::cout << "ERROR: Cannot remove " << quantity << " " << this->name << " items from stock (" << this->getNumItems() << " max)." << std::endl;
	}
}

void StockItem::addItems(int numItems)
{
	this->count = this->count + numItems;
}

bool StockItem::isOutOfStock()
{
	return this->getNumItems() == 0;
}

bool StockItem::operator == (StockItem item)
{
	return this->name == item.name;
}

std::ostream& operator << (std::ostream& output, StockItem item)
{
	output << item.getName() << ": " << item.getNumItems();
	return output;
}
