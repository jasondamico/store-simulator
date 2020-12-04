#include "item_holders/store.h"

Store::Store() : NamedItemHolder()
{

}

Store::Store(std::string storeName, std::vector<StockItem> storeItems) : NamedItemHolder(storeName, storeItems)
{

}
