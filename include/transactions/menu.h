#ifndef _MENU
#define _MENU

#include "item_holders/store.h"
#include "helpers/utils.h"
#include "item_holders/customer.h"
#include <string>

class Menu
{
	// PRIVATE INSTANCE VARIABLES

	Store& store;
	Customer& customer;

	/// <summary>
	/// Prints a border for the menu.
	/// </summary>
	void printBorder();

	/// <summary>
	/// Prints a welcome section for the menu.
	/// </summary>
	void printWelcome();

	/// <summary>
	/// Prints the menu item at the specified index.
	/// </summary>
	/// 
	/// <param name="index">The index holding the object to be printed on the menu. </param>
	void printMenuItem(int index);

	/// <summary>
	/// Prints out the contents of the customer's cart.
	/// </summary>
	void printCart();

	/// <summary>
	/// Prints the customer's budget.
	/// </summary>
	void printCustomerBudget();

	/// <summary>
	/// Returns a boolean corresponding to whether or not the passed value is a valid menu choice (i.e., that the choice entered is on the menu).
	/// </summary>
	/// 
	/// <param name="menuChoice">An integer representing a choice on the menu.</param>
	/// <returns>TRUE if the passed menu choice is valid, FALSE otherwise.</returns>
	bool isValidMenuChoice(int menuChoice);

	/// <summary>
	/// Returns the number of items held on the menu.
	/// </summary>
	/// 
	/// <returns>An integer value representing the number of values on the menu.</returns>
	int getNumMenuItems();

	/// <summary>
	/// Gets the number of items that the user would like from their indicated menu choice.
	/// </summary>
	/// 
	/// <param name="choiceIndex"></param>
	/// <returns></returns>
	int getUserNumItemsChoice(int choiceIndex);

	/// <summary>
	/// Returns a boolean corresponding to whether or not the passed menu choice is within the range of value displayed on the menu.
	/// </summary>
	/// 
	/// <param name="menuChoice">A value that is potentially within the range of values displayed on the menu.</param>
	/// <returns>TRUE if the passed value is within the range of values on the menu, FALSE otherwise.</returns>
	bool isInMenuRange(int menuChoice);

	/// <summary>
	/// Returns a string representation of the quantity of the passed StockItem for ease of menu display.
	/// </summary>
	/// 
	/// <param name="item">A StockItem object.</param>
	/// <returns>A string representing the count of the passed StockItem object.</returns>
	std::string getCountDisplay(StockItem item);

	/// <summary>
	/// Converts the integer value of the passed menu choice to the corresponding integer at which the menu choice is held by the store.
	/// </summary>
	/// 
	/// <param name="menuChoice">The integer representing a menu choice.</param>
	/// <returns>The index at which the menu choice is held by the store.</returns>
	int menuChoiceToIndex(int menuChoice);

	/// <summary>
	/// Converts the index at which the store holds an item to its integer representative on the menu.
	/// </summary>
	/// 
	/// <param name="index">The index at which an item is held by the store.</param>
	/// <returns>The corresponding integer value that represents the item on the menu.</returns>
	int indexToMenuChoice(int index);

public:
	/// <summary>
	/// Paramaterized constructor; creates a new Menu object with using the passed Store and Customer references.
	/// </summary>
	/// 
	/// <param name="store_">A reference to a Store object to be used in the menu.</param>
	/// <param name="customer_">A reference to a Customer object to be used in the menu.</param>
	Menu(Store& store_, Customer& customer_);

	/// <summary>
	/// Prints a representation of the Menu object.
	/// </summary>
	void printMenu();

	/// <summary>
	/// Retrieves and returns a valid menu choice from the user.
	/// </summary>
	/// 
	/// <returns>A valid menu choice inputted by the user.</returns>
	int getMenuChoice();

	/// <summary>
	/// Chooses an item from the menu based on the passed menu choice and determines how many of said item the user would like. After this is determined, the items are removed from the store and added to the customer's cart.
	/// </summary>
	/// 
	/// <param name="menuChoice">The integer value displayed on the menu corresponding to the user's item choice.</param>
	void chooseItem(int menuChoice);

	/// <summary>
	/// Returns a boolean corresponding to whether or not the passed value is a stop indicator, meaning the user wishes to exit the menu.
	/// </summary>
	/// 
	/// <param name="menuChoice">The integer value displayed on the menu corresponding to the user's item choice.</param>
	/// <returns>TRUE if the user entered a value indicating that they would like to exit the menu, FALSE otherwise.</returns>
	bool isStopIndicator(int menuChoice);

	/// <summary>
	/// Returns a client-friendly output of the Menu object.
	/// </summary>
	/// 
	/// <returns>A client-friendly output of the Menu object.</returns>
	friend std::ostream& operator << (std::ostream& output, Menu menu);
};

#endif // !_MENU
