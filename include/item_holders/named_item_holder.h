#ifndef _NAMED_ITEM_HOLDER
#define _NAMED_ITEM_HOLDER

#include "item_holders/item_holder.h"

class NamedItemHolder : public ItemHolder
{
	// PRIVATE INSTANCE VARIABLES

	std::string name;

	public:
		/// <summary>
		/// Default constructor; creates a basic NamedItemHolder object.
		/// </summary>
		NamedItemHolder();

		/// <summary>
		/// Parameterized constructor; creates an NamedItemHolder object with a specified name and list of items held.
		/// </summary>
		/// 
		/// <param name="name">The name of the ItemHolder object.</param>
		/// <param name="items">The initial list of items held by the ItemHolder object.</param>
		NamedItemHolder(std::string name, std::vector<StockItem> items);

		/// <summary>
		/// Parameterized constructor; creates an ItemHolder object with a specified name.
		/// </summary>
		/// 
		/// <param name="name">The name of the ItemHolder object.</param>
		NamedItemHolder(std::string name);

		/// <summary>
		/// Returns the name of the ItemHolder object.
		/// </summary>
		/// 
		/// <returns>The name of the ItemHolder object.</returns>
		std::string getName();
};

#endif // !_NAMED_ITEM_HOLDER
