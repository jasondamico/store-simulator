#include <iostream>
#include "transactions/menu.h"

Menu::Menu(Store& store_, Customer& customer_) : store(store_), customer(customer_)
{

}

int Menu::getNumMenuItems()
{
	return this->store.getNumItems();
}

void Menu::printMenu()
{
	this->printBorder();
	this->printWelcome();

	for (int i = 0; i < this->getNumMenuItems(); i++)
	{
		this->printMenuItem(i);
	}

	std::cout << std::endl << std::endl;
	this->printCustomerBudget();

	if (!(this->customer.hasNoItems()))
	{
		std::cout << std::endl;
		this->printCart();
	}

	this->printBorder();
}

void Menu::printMenuItem(int index)
{
	StockItem item = this->store.getIthStockItem(index);

	std::cout << "[" << this->indexToMenuChoice(index) << "] " << toUpper(item.getName()) << " ($" << item.getPrice() << "/per item): " << this->getCountDisplay(item) << std::endl;
}

void Menu::printBorder()
{
	std::cout << "------------------------------------------" << std::endl;
}

void Menu::printWelcome()
{
	std::cout << "WELCOME TO " << toUpper(this->store.getName()) << "!" << std::endl;
	std::cout << "To select an item, please enter its number on the menu below. Enter [0] to stop shopping." << std::endl << std::endl;

	std::cout << "STORE MENU" << std::endl;
}

void Menu::printCart()
{
	std::cout << "CART CONTENTS:" << std::endl;

	int cartItems = this->customer.getNumItems();

	for (int i = 0; i < cartItems; i++)
	{
		StockItem ithCartItem = customer.getIthStockItem(i);

		std::cout << toUpper(ithCartItem.getName()) << ": " << this->getCountDisplay(ithCartItem) << std::endl;
	}
}

void Menu::printCustomerBudget()
{
	std::cout << "CUSTOMER BUDGET: $" << this->customer.getBudget() << std::endl;
}

std::string Menu::getCountDisplay(StockItem item)
{
	int count = item.getNumItems();

	if (count != 0)
	{
		return std::to_string(count);
	}
	else
	{
		return "OUT OF STOCK";
	}
}

int Menu::getMenuChoice()
{
	std::cout << "What item would you like from " << this->store.getName() << "? ";
	int menuChoice = getIntInput();

	while (!isValidMenuChoice(menuChoice))
	{
		if (!(this->isInMenuRange(menuChoice)))
		{
			std::cout << "Invalid input - must be a valid menu choice (between 1 and " << this->getNumMenuItems() << ") " << std::endl;
		}
		else
		{
			std::cout << "Invalid input - menu choice (" << this->store.getIthStockItem(this->menuChoiceToIndex(menuChoice)).getName() << ") is out of stock." << std::endl;
		}

		std::cout << "What item would you like from " << this->store.getName() << "? ";
		menuChoice = getIntInput();
		std::cout << std::endl;
	}

	return menuChoice;
}

bool Menu::isValidMenuChoice(int menuChoice)
{
	return this->isStopIndicator(menuChoice) || (this->isInMenuRange(menuChoice) && !this->store.ithItemIsOutOfStock(this->menuChoiceToIndex(menuChoice)));
}

bool Menu::isInMenuRange(int menuChoice)
{
	return menuChoice >= 1 && menuChoice <= this->getNumMenuItems();
}

void Menu::chooseItem(int menuChoice)
{
	int choiceIndex = this->menuChoiceToIndex(menuChoice);
	std::string choiceName = this->store.getIthStockItem(choiceIndex).getName();
	int price = this->store.getIthStockItem(choiceIndex).getPrice();

	int numItems = getUserNumItemsChoice(choiceIndex);
	StockItem itemToRemove = StockItem(choiceName, numItems, price);

	this->store.removeItems(itemToRemove);

	this->customer.addItems(itemToRemove);
}

bool Menu::isStopIndicator(int menuChoice)
{
	return menuChoice == 0;
}

int Menu::getUserNumItemsChoice(int choiceIndex)
{
	int maxItems = this->store.getIthStockItem(choiceIndex).getNumItems();
	std::string choiceName = this->store.getIthStockItem(choiceIndex).getName();

	std::cout << "How many " << this->store.getIthStockItem(choiceIndex).getName() << " items would you like? ";
	int numberOfItems = getIntInput();

	while (!(numberOfItems <= maxItems && numberOfItems >= 1))
	{
		if (numberOfItems < 1)
		{
			std::cout << "Invalid input - must request 1 or more " << choiceName << " items." << std::endl;
		}
		else
		{
			std::cout << "Invalid input - must request " << maxItems << " or fewer items." << std::endl;
		}

		std::cout << "How many " << this->store.getIthStockItem(choiceIndex).getName() << " items would you like? ";

		numberOfItems = getIntInput();
	}

	std::cout << std::endl;

	return numberOfItems;
}

int Menu::menuChoiceToIndex(int menuChoice)
{
	return menuChoice - 1;
}

int Menu::indexToMenuChoice(int index)
{
	return index + 1;
}

std::ostream& operator << (std::ostream& output, Menu menu)
{
	menu.printBorder();
	menu.printWelcome();

	for (int i = 0; i < menu.getNumMenuItems(); i++)
	{
		menu.printMenuItem(i);
	}

	std::cout << std::endl << std::endl;
	menu.printCustomerBudget();

	if (!(menu.customer.hasNoItems()))
	{
		std::cout << std::endl;
		menu.printCart();
	}

	menu.printBorder();

	return output;
}
