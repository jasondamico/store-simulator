#include "item_holders/customer.h"

Customer::Customer() : ItemHolder()
{
	this->budget = 0;
}

Customer::Customer(std::string customerName, std::vector<StockItem> cartItems, int budget) : ItemHolder(customerName, cartItems)
{
	this->budget = budget;
}

Customer::Customer(std::string customerName) : ItemHolder(customerName)
{
	this->budget = 0;
}

Customer::Customer(std::string customerName, int budget) : ItemHolder(customerName)
{
	this->budget = budget;
}

int Customer::getBudget()
{
	return this->budget;
}

bool Customer::canCheckout()
{
	return this->getBudget() >= this->getTotal();
}

void Customer::addPurchasedItems(std::vector<StockItem> items)
{
	for (int i = 0; i < items.size(); i++)
	{
		this->purchasedItems.push_back(items[i]);
	}
}

void Customer::addPurchasedItem(StockItem item)
{
	this->purchasedItems.push_back(item);
}

void Customer::transferPurchasedItems()
{
	for (int i = 0; i < this->getNumItems(); i++)
	{
		this->addPurchasedItem(this->getIthStockItem(i));
	}

	this->clearItems();
}

void Customer::reduceBudget(int amount)
{
	if (budget - amount >= 0)
	{
		this->budget = budget - amount;
	}
	else
	{
		std::cout << "ERROR - Budget cannot be reduced by more than " << this->budget << ".";
	}
}

bool Customer::hasPurchasedItems()
{
	return getNumPurchasedItems() > 0;
}

int Customer::getNumPurchasedItems()
{
	return this->purchasedItems.size();
}

StockItem Customer::getIthPurchasedItem(int index)
{
	return this->purchasedItems[index];
}