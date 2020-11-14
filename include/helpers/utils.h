#ifndef _UTILS
#define _UTILS

#include <string>
#include <iostream>
#include <vector>
#include "store_items/stock.h"

/// <summary>
/// Converts and returns the passed string to uppercase.
/// SOURCE: http://www.cplusplus.com/reference/locale/toupper/
/// </summary>
/// 
/// <param name="string">An unformatted string.</param>
/// <returns>The uppercase equivalent of the passed string.</returns>
std::string toUpper(std::string string);

/// <summary>
/// Prompts the user for a valid integer input value, catching their improper input until a valid value is entered. Returns the value upon reception.
/// </summary>
/// <returns>An integer value inputted by the user.</returns>
int getIntInput();

/// <summary>
/// Clears the existing values within the cin buffer, preparing for more input.
/// </summary>
void clearBuffer();

/// <summary>
/// Returns a boolean corresponding to whether or not the passed response is a valid yes or no response.
/// </summary>
/// 
/// <param name="response">A string that is potentially a valid yes or no response.</param>
/// <returns>TRUE if the passed string is a valid yes or no response, FALSE otherwise.</returns>
bool validYesOrNo(std::string response);

/// <summary>
/// Returns a boolean corresponding to whether or not the passed response is a yes.
/// </summary>
/// 
/// <param name="response">A response that is potentially a yes.</param>
/// <returns>TRUE if the passed response is a yes, FALSE otherwise.</returns>
bool isYes(std::string response);

/// <summary>
/// Prompts and gets a valid yes or no response. Returns a boolean corresponding to whether or not the response was a yes.
/// </summary>
/// 
/// <param name="prompt">The prompt to which the user must answer with a yes or no response.</param>
/// <returns>TRUE if the response is a yes, FALSE otherwise.</returns>
bool getUserYesNo(std::string prompt);

#endif // !_UTILS
