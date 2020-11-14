#include "transactions/checkout.h"

Checkout::Checkout(Store& store_, Customer& customer_) : store(store_), customer(customer_)
{

}

void Checkout::enterCheckout()
{
	std::cout << "ENTERING CHECKOUT . . . " << std::endl << std::endl;

	if (!customer.hasNoItems())
	{
		this->printReceipt();

		if (this->confirmCheckout())
		{
			if (this->customer.canCheckout())
			{
				this->initiateCheckout();
			}
			else
			{
				std::cout << "ERROR - Customer has insufficient funds to pay for their cart. Items will now return to stock." << std::endl;
				this->putCartBack();
			}
		}
	}
	else
	{
		std::cout << "ERROR - Customer has no items. Please return to the store and add items to your cart before entering the checkout." << std::endl;
	}
}

void Checkout::printReceipt()
{
	int width = this->getMinReceiptWidth();
	std::string whitespace = "  ";

	std::cout << "Your total for today is: " << std::endl;

	for (int i = 0; i < this->customer.getNumItems(); i++)
	{
		std::string nonPriceString = this->getNonPriceReceiptString(i);
		std::string priceString = this->getPriceReceiptString(i);

		std::cout << nonPriceString << whitespace;
		std::cout.width(width - nonPriceString.length());
		std::cout << std::right << priceString << std::endl;
	}

	this->printSummationLine(width + whitespace.length());

	std::string total = "TOTAL:";
	std::cout << total << whitespace;
	std::cout.width(width - total.length());
	std::cout << std::right << "$" + std::to_string(this->customer.getTotal()) << std::endl;
	std::cout << std::endl;
}

void Checkout::printReceiptItem(int index)
{
	std::cout << this->getNonPriceReceiptString(index) << "  " << this->getPriceReceiptString(index);
}

void Checkout::printSummationLine(int width = 10)
{
	for (int i = 0; i < width; i++)
	{
		std::cout << "_";
	}

	std::cout << std::endl;
}

int Checkout::getMinReceiptWidth()
{
	int largestWidth = 0;

	for (int i = 0; i < this->customer.getNumItems(); i++)
	{
		std::string str = this->getNonPriceReceiptString(i) + this->getPriceReceiptString(i);
		int width = str.length();

		if (width > largestWidth)
		{
			largestWidth = width;
		}
	}

	return largestWidth;
}

std::string Checkout::getNonPriceReceiptString(int index)
{
	return this->getNonPriceReceiptString(this->customer.getIthStockItem(index));
}

std::string Checkout::getNonPriceReceiptString(StockItem item)
{
	return item.getName() + " (x" + std::to_string(item.getNumItems()) + "):";
}

std::string Checkout::getPriceReceiptString(int index)
{
	return this->getPriceReceiptString(this->customer.getIthStockItem(index));
}

std::string Checkout::getPriceReceiptString(StockItem item)
{
	return "$" + std::to_string(item.getTotal());
}

bool Checkout::confirmCheckout()
{
	return getUserYesNo("Would you like to complete your transaction?");
}

void Checkout::initiateCheckout()
{
	this->customer.reduceBudget(this->customer.getTotal());
	this->customer.transferPurchasedItems();

	std::cout << "Transaction complete." << std::endl;
}

void Checkout::putCartBack()
{
	for (int i = 0; i < this->customer.getNumItems(); i++)
	{
		this->store.addItems(this->customer.getIthStockItem(i));
	}

	this->customer.clearItems();
}
