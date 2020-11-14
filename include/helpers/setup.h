#ifndef _SETUP
#define _SETUP

#include <vector>
#include "store_items/stock.h"
#include "item_holders/store.h"
#include "helpers/utils.h"
#include "item_holders/customer.h"

/// <summary>
/// Asks the user various questions relating to the store they are creating and returns a Store object based on their answers. 
/// </summary>
/// 
/// <returns>A Store object containing the characteristics outlined by the user.</returns>
Store setupStore();

/// <summary>
/// Asks the user various questions relating to the customer shopping and returns a Customer object based on their answers. 
/// </summary>
/// 
/// <returns>A Customer object containing the characteristics outlined by the user.</returns>
Customer setupCustomer();

/// <summary>
/// Gets the name of the store from the user and assigns it to the passed variable.
/// </summary>
/// 
/// <param name="storeName">A reference to the variable to which the user's input for the store name will be assigned.</param>
void setStoreName(std::string& storeName);

/// <summary>
/// Gets the name of the customer shopping from the user and assigns it to the passed variable.
/// </summary>
/// <param name="customerName">A reference to the variable to which the user's input for the customer name will be assigned.</param>
void setCustomerName(std::string& customerName);

/// <summary>
/// Gets the budget of the customer shopping from the user and assigns it to the passed variable.
/// </summary>
/// <param name="budget">A reference to the variable to which the user's input for the customer budget will be assigned.</param>
void setCustomerBudget(int& budget);

/// <summary>
/// Gets the list of items stocked in the store from the user and assigns it to the passed variable.
/// </summary>
/// 
/// <param name="items">A reference to the variable to which the user's input for the store's item stock will be assigned.</param>
void setItems(std::vector<StockItem>& items);

/// <summary>
/// Adds an individual item to the passed list of items. 
/// </summary>
/// 
/// <param name="items">A reference to the variable to which the user's input for the store's item stock will be assigned.</param>
void addItem(std::vector<StockItem>& items);

/// <summary>
/// Checks to see if the user would like to add more items to the store and returns a boolean corresponding to their answer.
/// </summary>
/// 
/// <returns>TRUE if the user would like to continue adding to the list of items to stock the store with, FALSE otherwise.</returns>
bool checkForContinue();

#endif // !_SETUP
