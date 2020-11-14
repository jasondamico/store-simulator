#ifndef _STOCK
#define _STOCK

#include <string>
#include <iostream>

class StockItem
{
	// PRIVATE INSTANCE VARIABLES

	std::string name;
	int count;
	int pricePerItem;

	public:
		/// <summary>
		/// Default constructor; creates a basic StockItem object.
		/// </summary>
		StockItem();

		/// <summary>
		/// Parameterized constructor; creates a StockItem with a specified name, count and and price per item.
		/// </summary>
		/// 
		/// <param name="name">The name of the new StockItem.</param>
		/// <param name="count">The number of this item held.</param>
		/// <param name="pricePerItem">The price per unit of this item.</param>
		StockItem(std::string name, int count, int pricePerItem);

		/// <summary>
		/// Returns the number of the item that are stocked.
		/// </summary>
		/// 
		/// <returns>An integer corresponding to how many of this item type is stocked.</returns>
		int getNumItems();

		/// <summary>
		/// Returns the name of the item.
		/// </summary>
		/// 
		/// <returns>A string representing the item's name.</returns>
		std::string getName();

		/// <summary>
		/// Returns the item's price per unit.
		/// </summary>
		/// 
		/// <returns>A integer corresponding to the price per unit of the item.</returns>
		int getPrice();

		/// <summary>
		/// Returns the price of the entire stock (based on the amount of stock and the price per item).
		/// </summary>
		/// 
		/// <returns>An integer corresponding to the price of the entire stock.</returns>
		int getTotal();

		/// <summary>
		/// Returns a boolean corresponding to whether or not the passed quantity can be removed from the stocked item.
		/// </summary>
		/// 
		/// <param name="quantity">A number of items that either can or cannot be removed based on the amount of items in stock.</param>
		/// <returns>TRUE if the passed quantity may be removed from stock, FALSE otherwise. </returns>
		bool canRemove(int quantity);

		/// <summary>
		/// Removes a passed number of items from stock. Only removes the passed quantity if that is an acceptable amount to remove from the stock.
		/// </summary>
		/// 
		/// <param name="quantity">A number of items that either can or cannot be removed based on the amount of items in stock.</param>
		void removeItems(int quantity);

		/// <summary>
		/// Adds a passed number of items to the stock. 
		/// </summary>
		/// 
		/// <param name="numItems">A number of items to be added to stock.</param>
		void addItems(int numItems);

		/// <summary>
		/// Returns a boolean corresponding to whether or not the item is out of stock.
		/// </summary>
		/// 
		/// <returns>TRUE if the item is out of stock, FALSE otherwise.</returns>
		bool isOutOfStock();
	
		/// <summary>
		/// Returns a boolean corresponding to whether or not two StockItems are of the same type.
		/// </summary>
		/// 
		/// <returns>A boolean corresponding to whether or not two StockItems are of the same type.</returns>
		bool operator == (StockItem item);

		/// <summary>
		/// Outputs the StockItem object in a client-friendly fashion.
		/// </summary>
		/// 
		/// <returns>A client-friendly output of the StockItem object.</returns>
		friend std::ostream& operator << (std::ostream& output, StockItem item);
};

#endif // _STOCK
