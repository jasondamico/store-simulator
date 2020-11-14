#include "helpers/utils.h"
#include <algorithm>
#include <vector>

std::string toUpper(std::string string)
{
	std::for_each(string.begin(), string.end(), [](char& c) {
		c = ::toupper(c);
		});

	return string;
}

int getIntInput()
{
	int input;

	while (!(std::cin >> input))
	{
		clearBuffer();
		std::cout << "Invalid input - an integer value must be entered. Try again: ";
	}

	clearBuffer();

	return input;
}

void clearBuffer()
{
	std::cin.clear();
	std::cin.ignore(10000, '\n');  // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool validYesOrNo(std::string response)
{
	return response == "y" || response == "n";
}

bool isYes(std::string response)
{
	return response == "y";
}

bool getUserYesNo(std::string prompt)
{
	std::cout << prompt << " [y/n] ";
	std::string response;
	getline(std::cin, response);

	while (!validYesOrNo(response))
	{
		std::cout << "Invalid reponse - please enter either \"y\" or \"n\": ";
		getline(std::cin, response);
	}

	return isYes(response);
}
