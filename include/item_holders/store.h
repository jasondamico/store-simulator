#ifndef _STORE
#define _STORE

#include "item_holders/named_item_holder.h"

class Store : public NamedItemHolder
{
public:
	/// <summary>
	/// Default constructor; creates a basic store.
	/// </summary>
	Store();

	/// <summary>
	/// Paramaterized constructor; creates a store with a specified name and items held within the store.
	/// </summary>
	/// 
	/// <param name="storeName">The name of the store.</param>
	/// <param name="storeItems">The items the store initially has in their inventory. </param>
	Store(std::string storeName, std::vector<StockItem> storeItems);
};

#endif // !_STORE
