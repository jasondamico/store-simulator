#ifndef _CHECKOUT
#define _CHECKOUT

#include "item_holders/customer.h"
#include "item_holders/store.h"
#include "helpers/utils.h"

class Checkout
{
	// PRIVATE INSTANCE VARIABLES

	Store& store;
	Customer& customer;

	/// <summary>
	/// Prints the receipt associated with the items held by the customer.
	/// </summary>
	void printReceipt();

	/// <summary>
	/// Returns an integer corresponding to the minimum width (in characters) required to print the receipt.
	/// </summary>
	/// 
	/// <returns>The minimum width (in characters) required to print the receipt.</returns>
	int getMinReceiptWidth();

	/// <summary>
	/// Prints an individual item on the receipt as specified by the passed index.
	/// </summary>
	/// 
	/// <param name="index">The index at which the customer is holding a particular object.</param>
	void printReceiptItem(int index);

	/// <summary>
	/// Prints a line of a specified width corresponding to the "summation line", or the line that seperates the list of items on the receipt and the total.
	/// </summary>
	/// 
	/// <param name="width">The desired width of the summation line.</param>
	void printSummationLine(int width);

	/// <summary>
	/// Given an index at which the customer is holding a StockItem, returns the portion of the string to be used on the receipt that does not include the price.
	/// </summary>
	/// <param name="index">An index where the customer is holding a StockItem from which a formatted receipt line, without the price, will be returned.</param>
	/// <returns>A formatted string ready to be used in receipt printing, omitting the price of the item.</returns>
	std::string getNonPriceReceiptString(int index);

	/// <summary>
	/// Given a passed StockItem, returns the portion of the string to be used on the receipt that does not include the price.
	/// </summary>
	/// 
	/// <param name="item">The StockItem from which the formatted receipt line, without the price, will be returned.</param>
	/// <returns>A formatted string ready to be used in receipt printing, omitting the price of the item.</returns>
	std::string getNonPriceReceiptString(StockItem item);

	/// <summary>
	/// Given a passed index at which the customer holds a StockItem, returns the portion of the string to be used on the receipt that only includes the price.
	/// </summary>
	/// 
	/// <param name="index">An index where the customer is holding a StockItem from which the formatted receipt line, only including the price corresponding to the item, will be returned.</param>
	/// <returns>A formatted string ready to be used in receipt printing, only including the price of the item.</returns>
	std::string getPriceReceiptString(int index);

	/// <summary>
	/// Given a passed StockItem, returns the portion of the string to be used on the receipt that only includes the price.
	/// </summary>
	/// 
	/// <param name="item">The StockItem from which the formatted receipt line, only including the price corresponding to the item, will be returned.</param>
	/// <returns>A formatted string ready to be used in receipt printing, only including the price of the item.</returns>
	std::string getPriceReceiptString(StockItem item);

	/// <summary>
	/// Asks the user whether or not they would like to proceed with the checkout process and returns their answer in the form of a boolean. 
	/// </summary>
	/// 
	/// <returns>TRUE if the user would like to continue the checkout process, FALSE otherwise.</returns>
	bool confirmCheckout();

	/// <summary>
	/// Begins the checkout process.
	/// </summary>
	void initiateCheckout();

	/// <summary>
	/// Removes the items held by the customer and stocks them back in the store.
	/// </summary>
	void putCartBack();

public:
	/// <summary>
	/// Paramaterized constructor; creates a Checkout object using the passed references to a Store and Customer object.
	/// </summary>
	/// 
	/// <param name="store_">A reference to a Store object to be used in checkout.</param>
	/// <param name="customer_">A reference to a Customer object to be used in checkout</param>
	Checkout(Store& store_, Customer& customer_);

	/// <summary>
	/// Enters the customer into the checkout process.
	/// </summary>
	void enterCheckout();
};

#endif // !_CHECKOUT
