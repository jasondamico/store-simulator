#include <string>
#include <iostream>
#include "helpers/setup.h"

Store setupStore()
{
	std::string storeName;
	setStoreName(storeName);

	std::cout << "Great! We need some items to store in " << storeName << "." << std::endl << std::endl;

	std::vector<StockItem> items;
	setItems(items);

	return Store(storeName, items);
}

Customer setupCustomer()
{
	std::string customerName;
	int budget;
	setCustomerName(customerName);
	setCustomerBudget(budget);

	return Customer(customerName, budget);
}

void setStoreName(std::string& storeName)
{
	std::string name;

	std::cout << "What is the name of your store? ";
	getline(std::cin, name);

	storeName = name;
}

void setCustomerName(std::string& customerName)
{
	std::string name;

	std::cout << "What is the name of the customer shopping? ";
	getline(std::cin, name);

	customerName = name;
}

void setCustomerBudget(int& budget)
{
	int inputBudget;

	std::cout << "How much money (whole number) do you have to spend? ";
	inputBudget = getIntInput();
	std::cout << std::endl << std::endl;

	budget = inputBudget;
}

void setItems(std::vector<StockItem>& items)
{
	bool stillAddingItems = true;

	while (stillAddingItems)
	{
		addItem(items);

		stillAddingItems = checkForContinue();

		std::cout << std::endl;
	}
}

void addItem(std::vector<StockItem>& items)
{
	std::string name;

	std::cout << "What is the name of the item you would like to add? ";
	getline(std::cin, name);

	int count;
	std::cout << "How many " << name << " items would you like to add to the store? ";
	count = getIntInput();

	while (count <= 0)
	{
		std::cout << "Invalid input - an value greater than 0 must be entered. Try again: ";
		count = getIntInput();
	}

	int price;
	std::cout << "What is the price per " << name << " item (whole number)? ";
	price = getIntInput();
	std::cout << std::endl;

	while (price <= 0)
	{
		std::cout << "Invalid input - an value greater than 0 must be entered. Try again: ";
		price = getIntInput();
	}

	items.push_back(StockItem(name, count, price));
}

bool checkForContinue()
{
	return getUserYesNo("Would you like to add more items to the store?");
}
