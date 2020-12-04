#ifndef _CUSTOMER
#define _CUSTOMER

#include "item_holders/named_item_holder.h"

class Customer : public NamedItemHolder
{
	// PRIVATE INSTANCE VARIABLES 

	int budget;
	std::vector<StockItem> purchasedItems;

public:
	/// <summary>
	/// Default constructor; creates a basic Customer object.
	/// </summary>
	Customer();

	/// <summary>
	/// Parameterized constructor; creates a Customer with a specified name, amount in their cart and budget.
	/// </summary>
	/// 
	/// <param name="customerName">The name of the new customer.</param>
	/// <param name="cartItems">The items the customer intially has in their cart.</param>
	/// <param name="budget">The customer's starting budget.</param>
	Customer(std::string customerName, std::vector<StockItem> cartItems, int budget);

	/// <summary>
	/// Parameterized constructor; creates a Customer with a specified name.
	/// </summary>
	/// 
	/// <param name="customerName">The name of the new customer.</param>
	Customer(std::string customerName);

	/// <summary>
	/// Parameterized constructor; creates a Customer with a specified name and budget.
	/// </summary>
	/// 
	/// <param name="customerName">The name of the new customer.</param>
	/// <param name="budget">The customer's starting budget.</param>
	Customer(std::string customerName, int budget);

	/// <summary>
	/// Returns the amount of money the customer presently holds.
	/// </summary>
	/// 
	/// <returns>An integer corresponding to the amount of money the customer presently holds.</returns>
	int getBudget();

	/// <summary>
	/// Returns a boolean corresponding to whether or not the customer can enter the checkout process.
	/// </summary>
	/// 
	/// <returns>TRUE if the customer may begin to checkout, FALSE otherwise.</returns>
	bool canCheckout();

	/// <summary>
	/// Adds the passed vector of items to the list of the customer's purchased items.
	/// </summary>
	/// 
	/// <param name="items">A list of items that the customer has recently purchased.</param>
	void addPurchasedItems(std::vector<StockItem> items);

	/// <summary>
	/// Adds the passed item to the group of purchased items.
	/// </summary>
	/// 
	/// <param name="item">An item to be added to the list of items that the customer has purchased.</param>
	void addPurchasedItem(StockItem item);

	/// <summary>
	/// Transfers the items in the customer's cart to the group of purchased items, clearing the user cart in doing so.
	/// </summary>
	void transferPurchasedItems();

	/// <summary>
	/// Reduces the customer's budget by the passed amount. Prints an error if the amount entered cannot be detracted from the current budget.
	/// </summary>
	/// 
	/// <param name="amount">The amount to reduce the customer's budget by.</param>
	void reduceBudget(int amount);

	/// <summary>
	/// Returns a boolean representing whether or not the customer has purchased any items.
	/// </summary>
	/// 
	/// <returns>TRUE if the user has purchased items, FALSE otherwise.</returns>
	bool hasPurchasedItems();

	/// <summary>
	/// Returns the number of items the customer has purchased.
	/// </summary>
	/// 
	/// <returns>An integer corresponding to the number of items the user has purchased.</returns>
	int getNumPurchasedItems();

	/// <summary>
	/// Gets the item purchased held at the specified index. 
	/// </summary>
	/// 
	/// <param name="index">The index that holds the desired purchased item.</param>
	/// <returns>The purchased StockItem object held at the specified index.</returns>
	StockItem getIthPurchasedItem(int index);
};

#endif // !CUSTOMER
