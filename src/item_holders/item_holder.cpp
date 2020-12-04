#include <string>
#include <vector>
#include "item_holders/item_holder.h"

ItemHolder::ItemHolder()
{
	
}

ItemHolder::ItemHolder(std::vector<StockItem> items) 
{
	this->itemsHeld = items;
}

int ItemHolder::getNumItems()
{
	return this->itemsHeld.size();
}

StockItem ItemHolder::getIthStockItem(int index)
{
	return this->itemsHeld[index];
}

StockItem& ItemHolder::getIthStockItemByRef(int index)
{
	return this->itemsHeld[index];
}

void ItemHolder::removeItems(StockItem itemToRemove)
{
	int itemIndex = this->getItemIndex(itemToRemove);

	if (itemIndex != -1)
	{
		this->removeItems(itemIndex, itemToRemove.getNumItems());
	}
	else
	{
		std::cout << "ERROR - This item is not in stock." << std::endl;
	}
}

void ItemHolder::removeItems(int index, int numStockItems)
{
	this->getIthStockItemByRef(index).removeItems(numStockItems);
}

int ItemHolder::getItemIndex(StockItem item)
{
	int i = 0;

	for (int i = 0; i < this->getNumItems(); i++)
	{
		if (item == this->getIthStockItem(i))
		{
			return i;
		}
	}

	return -1;
}

void ItemHolder::addItems(StockItem newItem)
{
	int itemIndex = this->getItemIndex(newItem);

	if (itemIndex != -1)
	{
		this->addItems(itemIndex, newItem.getNumItems());
	}
	else
	{
		this->addNewItem(newItem);
	}
}

void ItemHolder::addItems(int index, int numNewItems)
{
	this->itemsHeld[index].addItems(numNewItems);
}

void ItemHolder::addNewItem(StockItem newItem)
{
	this->itemsHeld.push_back(newItem);
}

bool ItemHolder::hasNoItems()
{
	return this->getNumItems() == 0;
}

bool ItemHolder::ithItemIsOutOfStock(int index)
{
	return this->getIthStockItem(index).isOutOfStock();
}

int ItemHolder::getTotal()
{
	int total = 0;

	for (int i = 0; i < this->getNumItems(); i++)
	{
		total += this->getIthStockItem(i).getTotal();
	}

	return total;
}

void ItemHolder::clearItems()
{
	this->itemsHeld = { };
}
