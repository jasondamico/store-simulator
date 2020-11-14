#include <iostream>
#include "store_items/stock.h"
#include "helpers/setup.h"
#include "item_holders/store.h"
#include "helpers/utils.h"
#include "transactions/menu.h"
#include "item_holders/customer.h"
#include "transactions/checkout.h"
#include <vector>

const bool DEBUGGING = false;

void printPurchasedItems(Customer customer)
{
	for (int i = 0; i < customer.getNumPurchasedItems(); i++)
	{
		StockItem item = customer.getIthPurchasedItem(i);

		std::cout << item << std::endl;
	}
}

void intro()
{
	std::cout << "Welcome to the store simulator!" << std::endl << std::endl;
}

void conclusion(Store store, Customer customer)
{
	std::cout << std::endl;
	std::cout << "Thank you for shopping at " << store.getName() << " today, " << customer.getName() << "! Here are the items you purchased:" << std::endl << std::endl;

	printPurchasedItems(customer);

	std::cout << std::endl << "Please come back soon!" << std::endl;
}

int main() {
	intro();

	Store store;
	Customer customer;

	if (DEBUGGING)
	{
		std::vector<StockItem> defaultItems = { StockItem("Tomatoes", 10, 2), StockItem("Bananas", 12, 2), StockItem("Apples", 24, 2) };
		store = Store("Bow Street Market", defaultItems);
		std::vector <StockItem> customerCart = {
			StockItem("Tomatoes", 3, 2),
			StockItem("Bananas", 10, 2),
			StockItem("Pinapple", 8, 2)
		};

		customer = Customer("Jason", customerCart, 100);
	}
	else
	{
		store = setupStore();
		customer = setupCustomer();
	}

	Menu menu = Menu(store, customer);

	bool stillOrdering = true;
	bool stillShopping = true;

	while (stillShopping)
	{
		while (stillOrdering)
		{
			std::cout << menu;

			int choice = menu.getMenuChoice();

			if (menu.isStopIndicator(choice))
			{
				stillOrdering = false;
			}
			else
			{
				menu.chooseItem(choice);
			}
		}

		std::cout << std::endl;

		Checkout checkout = Checkout(store, customer);
		checkout.enterCheckout();

		bool continueShopping = getUserYesNo("Would you like return to the store to buy more items?");

		if (continueShopping)
		{
			stillOrdering = true;
		}
		else
		{
			stillShopping = false;
		}
	}

	std::cout << std::endl;

	conclusion(store, customer);

	return -1;
}
