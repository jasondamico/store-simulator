#include "item_holders/store.h"

Store::Store() : ItemHolder()
{

}

Store::Store(std::string storeName, std::vector<StockItem> storeItems) : ItemHolder(storeName, storeItems)
{

}
