#include "Utilities.h"

#include <iostream>
#include <print>
#include <string>

using std::println;
using std::string;

void PrintHeader(string_view header, char delimiter)
{
	// Calculate the length of the header plus two for the border dashes
	const size_t headerLength = header.size() + 2u;

	// Print the header with a border of dashes
	println("{}", string(headerLength, delimiter));
	println("{:^{}}", header, headerLength);
	println("{}", string(headerLength, delimiter));

	// Print two blank lines after the header
	println();
	println();
}

void CallFunctionsWithHeader(string_view header, const vector<function<void()>>& functions)
{
	for (size_t i { 0u }; i < functions.size(); ++i)
	{
		// Print a header for the function
		PrintHeader(format("{} {}", header, i + 1u));

		// Call the function
		functions[i]();

		// Print a blank line after the function
		println();
	}
}

void CleanInputStream()
{
	using std::cin;

	cin.clear();
	cin.ignore(10000, '\n');
}

void StringToLower(string& str)
{
	// Loop through each character in the string and convert it to lowercase
	for (char& c : str)
	{
		// Use static_cast to convert char to unsigned char before calling std::tolower
		// This avoids undefined behavior for negative char values
		c = static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
	}
}
