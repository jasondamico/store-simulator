#ifndef _ITEM_HOLDER
#define _ITEM_HOLDER

#include <vector>
#include "store_items/stock.h"
#include "helpers/utils.h"

class ItemHolder
{
	// PRIVATE INSTANCE VARIABLES

	std::vector<StockItem> itemsHeld;

	/// <summary>
	/// Removes a specified number of stock of the StockItem object held at the passed index from the list of items held.
	/// </summary>
	/// 
	/// <param name="index">The index at which the item to be removed is located.</param>
	/// <param name="numStockItems">The number of the indicated item that should be removed from the stock.</param>
	void removeItems(int index, int numStockItems);

	/// <summary>
	/// Adds a greater quantity of items to the StockItem object held at the specified index.
	/// </summary>
	/// 
	/// <param name="index">The index at which the item to be removed is located.</param>
	/// <param name="numNewItems">The number by which the quantity of the items in stock should be raised.</param>
	void addItems(int index, int numNewItems);

	/// <summary>
	/// Adds the passed item to the list of items held. If the item is already held, the number of items held by the priorly existing object is increased. 
	/// </summary>
	/// <param name="newItem">The item to be added to the list of items held.</param>
	void addNewItem(StockItem newItem);

	/// <summary>
	/// Returns a reference to the StockItem object held at the specified index.
	/// </summary>
	/// 
	/// <param name="index">The index at which the item to be removed is located.</param>
	/// <returns>A reference to the StockItem object held at the specified index.</returns>
	StockItem& getIthStockItemByRef(int index);

	/// <summary>
	/// Returns the index of the passed StockItem. Returns -1 if the object is not held.
	/// </summary>
	/// 
	/// <param name="item">The item held at the index returned.</param>
	/// <returns>The index at which the passed item is held. -1 if the object is not held. </returns>
	int getItemIndex(StockItem item);

public:
	/// <summary>
	/// Default constructor; creates a basic ItemHolder object.
	/// </summary>
	ItemHolder();

	/// <summary>
	/// Parameterized constructor; creates an ItemHolder object with a specified list of items held.
	/// </summary>
	/// 
	/// <param name="items">The initial list of items held by the ItemHolder object.</param>
	ItemHolder(std::vector<StockItem> items);

	/// <summary>
	/// Returns an integer corresponding to the number of items held.
	/// </summary>
	/// 
	/// <returns>A number representing the number of items held.</returns>
	int getNumItems();

	/// <summary>
	/// Returns the total price of the items held.
	/// </summary>
	/// 
	/// <returns>The sum price of the items held.</returns>
	int getTotal();

	/// <summary>
	/// Returns the StockItem object held at the specified index.
	/// </summary>
	/// 
	/// <param name="index">The index at which the item to be removed is located.</param>
	/// <returns>The StockItem object held at the specified index.</returns>
	StockItem getIthStockItem(int index);

	/// <summary>
	/// Removes the passed StockItem from stock. Prints an error if the object passed is not among the held objects.
	/// </summary>
	/// 
	/// <param name="itemToRemove">The object to be removed.</param>
	void removeItems(StockItem itemToRemove);

	/// <summary>
	/// Adds the passed StockItem object to the group of items held. If the passed object is already held, the quantity of the existing item is increased instead of adding a new object of the same type.
	/// </summary>
	/// 
	/// <param name="newItem">The item to be added to the group of items held.</param>
	void addItems(StockItem newItem);

	/// <summary>
	/// Returns a boolean corresponding to whether or not the ItemHolder object is presently holding any items.
	/// </summary>
	/// 
	/// <returns>TRUE if no items are presently held, FALSE otherwise. </returns>
	bool hasNoItems();

	/// <summary>
	/// Returns a boolean corresponding to whether or not the item at the specified index is out of stock.
	/// </summary>
	/// 
	/// <param name="index">The index at which the item to be removed is located.</param>
	/// <returns>TRUE if the item at the specified index is out of stock, FALSE otherwise.</returns>
	bool ithItemIsOutOfStock(int index);

	/// <summary>
	/// Clears out all of the items presently held.
	/// </summary>
	void clearItems();
};

#endif
