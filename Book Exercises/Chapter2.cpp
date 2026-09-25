#include "Chapter2.h"

#include <print>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <functional>
#include <format>
#include <algorithm>
#include <cmath>

#include "Utilities.h"

using std::string;
using std::vector;
using std::function;
using std::format;
using std::transform;
using std::print;
using std::println;

void BookExercises::Chapter2::TryThis1()
{
	// Simulate user input for the exercise
	const string name { "Juan" };
	constexpr double age { 29.5 };

	// Print the user input values
	println("The user input values are: {} and {}", name, age);
	println();

	// Display the output
	println("Hi, {}! You are {} months old!", name, age * 12.0);
}

void BookExercises::Chapter2::TryThis2()
{
	// Simulate user input for the exercise
	constexpr int number { 7 };

	// Print the user input value
	println("The user input value is: {}", number);
	println();

	// Display the output
	println("Number: {}", number);
	println("Number plus one: {}", number + 1);
	println("Twice the number: {}", 2 * number);
	println("Number squared: {}", number * number);
	println("Half the number: {}", number / 2);
	println("Square root of the number: {}", sqrt(number));
	println("Reminder of the number divided by 2: {}", number % 2);
}

void BookExercises::Chapter2::TryThis3()
{
	// Simulate user input for the exercise
	string input { "The cat cat jumped" };
	std::istringstream iss(input);

	// Print the user input value
	println("The user input value is: \"{}\"", input);

	// Store the previous and current words for comparison
	string previous;
	string current;

	// Read words from the input stream and check for repetitions
	while (iss >> current)
	{
		// check if the word is the same as last
		if (previous == current)
		{
			println("Repeated word: \"{}\"", current);
		}

		// Update the previous word for the next iteration
		previous = current;
	}
}

void BookExercises::Chapter2::TryThis4()
{
	// Simulate user input for the exercise
	string input { "She she laughed \"he he he!\" because what he did did not look very very good good" };
	std::istringstream iss(input);

	// Print the user input value
	println("The user input value is: \"{}\"", input);

	// Store the previous and current words for comparison
	string previous;
	string current;

	// Read words from the input stream and check for repetitions
	while (iss >> current)
	{
		// check if the word is the same as last
		if (previous == current)
		{
			println("Repeated word: \"{}\"", current);
		}

		// Update the previous word for the next iteration
		previous = current;
	}
}

void BookExercises::Chapter2::TryThis5()
{
	// Store the invalid strings
	string variable { "STRING s = \"Goodbye, cruel world! \"" };
	string command { "cOut << S << '\\n';" };

	// Print the invalid strings and explain why they are invalid
	println("The following string is invalid because \"STRING\" should be \"string\":");
	println("{}", variable);
	println();

	println("The following string is invalid because \"cOut\" should be \"cout\":");
	println("{}", command);
}

void BookExercises::Chapter2::Trythis6()
{
	// Vector of function pointers to the TryThis6_x functions
	vector<function<void()>> tryThis6Functions = {
		TryThis6_1,
		TryThis6_2,
		TryThis6_3,
		TryThis6_4,
		TryThis6_5
	};

	// Call each function in the vector
	CallFunctionsWithHeader("Try This 6 -", tryThis6Functions);
}

void BookExercises::Chapter2::TryThis6_0(double input)
{
	using std::cout;
	using std::cin;
	using std::endl;

	int i = input;
	char c = i;
	cout
		<< "d==" << input
		<< " i==" << i
		<< " c==" << c
		<< " char(" << c << ")"
		<< endl;
}

void BookExercises::Chapter2::TryThis6_1()
{
	// User input 1
	println("User input 1:");
	TryThis6_0(1);

	// Separator
	println();

	// User input 2
	println("User input 2:");
	TryThis6_0(2);
}

void BookExercises::Chapter2::TryThis6_2()
{
	// User input 128
	println("User input 128:");
	TryThis6_0(128);

	// Separator
	println();

	// User input 1001
	println("User input 1001:");
	TryThis6_0(1001);
}

void BookExercises::Chapter2::TryThis6_3()
{
	// User input -1
	println("User input -1:");
	TryThis6_0(-1);

	// Separator
	println();

	// User input -2
	println("User input -2:");
	TryThis6_0(-2);
}

void BookExercises::Chapter2::TryThis6_4()
{
	// User input 56
	println("User input 56:");
	TryThis6_0(56);

	// Separator
	println();

	// User input 89
	println("User input 89:");
	TryThis6_0(89);

	// Separator
	println();

	// User input 128
	println("User input 128:");
	TryThis6_0(128);
}

void BookExercises::Chapter2::TryThis6_5()
{
	// User input 56.9
	println("User input 56.9:");
	TryThis6_0(56.9);

	// Separator
	println();

	// User input 56.2
	println("User input 56.2:");
	TryThis6_0(56.2);
}

void BookExercises::Chapter2::Exercise1()
{
	// Store all the try this functions in a vector of function pointers
	vector<function<void()>> tryThisFunctions = {
		TryThis1,
		TryThis2,
		TryThis3,
		TryThis4,
		TryThis5,
		Trythis6
	};

	// Call each function in the vector
	CallFunctionsWithHeader("Try This", tryThisFunctions);
}

void BookExercises::Chapter2::Exercise2()
{
	// Value set to simulate user input for the exercise
	constexpr float miles { 120.0f };

	// Conversion factor from miles to kilometers
	constexpr float kilometersPerMile { 1.609f };

	// Print the user input value
	println("The user input value is: {}", miles);
	println();

	// "Prompt the user to enter a number of miles and simulate the input
	println("Enter a number of miles: {}", miles);

	// Convert miles to kilometers
	const float kilometers = miles * kilometersPerMile;

	// Display the result
	println("The number of kilometers is: {}", kilometers);
}

void BookExercises::Chapter2::Exercise3()
{
	// Legal variable names
	const int age = 20;
	const int playerScore = 100;
	const int _lives = 3;
	const int level2 = 2;
	const int player_score = 50;

	/*
	Illegal variable names

	int 2players = 10;
	int player - name = 10;
	int player score = 10;
	int double = 0;
	int int = 5;
	int return = 10;
	int @score = 100;
	*/
}

void BookExercises::Chapter2::Exercise4()
{
	// Values set to simulate user input for the exercise
	constexpr int val1 { 3 };
	constexpr int val2 { 7 };

	// Print the user input values
	println("The user input values are: {} and {}", val1, val2);
	println();

	// Display the reports
	println("The smaller value is {}", (val1 < val2) ? val1 : val2);
	println("The larger value is {}", (val1 > val2) ? val1 : val2);
	println("The sum is {}", val1 + val2);
	println("The difference is {}", val1 - val2);
	println("The product is {}", val1 * val2);
	println("The ratio is {}", static_cast<float>(val1) / static_cast<float>(val2));
}

void BookExercises::Chapter2::Exercise5()
{
	// Values set to simulate user input for the exercise
	constexpr double val1 { 3.0 };
	constexpr double val2 { 7.0 };

	// Print the user input values
	println("The user input values are: {} and {}", val1, val2);
	println();

	// Display the reports
	println("The smaller value is {}", (val1 < val2) ? val1 : val2);
	println("The larger value is {}", (val1 > val2) ? val1 : val2);
	println("The sum is {}", val1 + val2);
	println("The difference is {}", val1 - val2);
	println("The product is {}", val1 * val2);
	println("The ratio is {}", val1 / val2);
}

void BookExercises::Chapter2::Exercise6()
{
	// Values set to simulate user input for the exercise
	constexpr int first { 0 };
	constexpr int second { 1 };
	constexpr int third { 2 };

	// Print the user input values
	println("The user input values are: {}, {}, and {}", first, second, third);
	println();

	// Introduce the values into a vector for easier processing
	vector<int> values { first, second, third };

	// Sort the values in ascending order
	std::sort(values.begin(), values.end());

	// Print the sorted values
	println("The values in ascending order are: {}, {}, {}", values[0], values[1], values[2]);
}

void BookExercises::Chapter2::Exercise7()
{
	// Values set to simulate user input for the exercise
	const string name1 { "John Doe" };
	const string name2 { "Jane Smith" };
	const string name3 { "Alice Johnson" };

	// Print the user input values
	println("The user input values are: {}, {}, and {}", name1, name2, name3);
	println();

	// Introduce the names into a vector for easier processing
	vector<string> names { name1, name2, name3 };

	// Sort the names in alphabetical order
	std::sort(names.begin(), names.end());

	// Print the sorted names
	println("The names in alphabetical order are: {}, {}, {}", names[0], names[1], names[2]);
}

void BookExercises::Chapter2::Exercise8()
{
	// Value set to simulate user input for the exercise
	constexpr int numberToTest { 3 };

	// Print the user input value
	println("The user input value is: {}", numberToTest);
	println();

	// Check if the number is even or odd and display the result
	println("The number {} is {}", numberToTest, (numberToTest % 2 == 0) ? "even" : "odd");
}

void BookExercises::Chapter2::Exercise9()
{
	// Known numbers
	vector<string> numbers
	{
		"zero",
		"one",
		"two",
		"three",
		"four"
	};

	// Value set to simulate user input for the exercise
	string_view userInput1 { "Three" };
	string_view userInput2 { "Five" };

	// Flags to track if a match was found
	bool matchFound1 { false };
	bool matchFound2 { false };

	// Print the user input value
	println("The user input values are: {} and {}", userInput1, userInput2);
	println();

	// Convert user input to lowercase for case-insensitive comparison
	string userInputLower1 { userInput1 };
	StringToLower(userInputLower1);

	string userInputLower2 { userInput2 };
	StringToLower(userInputLower2);

	// Check if the user input matches any of the known numbers
	for (size_t i { 0u }; i < numbers.size(); ++i)
	{
		if (userInputLower1 == numbers[i])
		{
			println("The user input \"{}\" matches the number: {}", userInput1, i);
			matchFound1 = true;
		}

		if (userInputLower2 == numbers[i])
		{
			println("The user input \"{}\" matches the number: {}", userInput2, i);
			matchFound2 = true;
		}
	}

	// If no match was found, inform the user
	if (!matchFound1)
	{
		println("The user input \"{}\" does not match any known number.", userInput1);
	}

	if (!matchFound2)
	{
		println("The user input \"{}\" does not match any known number.", userInput2);
	}
}

void BookExercises::Chapter2::Exercise10()
{
	// Values set to simulate user input for the exercise
	const string operation { "+" };
	constexpr double operand1 { 100.0 };
	constexpr double operand2 { 7.0 };

	// Print the user input values
	println("The user input values are: {}, {}, and {}", operation, operand1, operand2);
	println();

	// Print a placeholder for the operation
	print("{} {} {} = ", operand1, operation, operand2);

	// Perform the requested operation
	if (operation == "+" || operation == "plus")
	{
		println("{}", operand1 + operand2);
	}

	else if (operation == "-" || operation == "−" || operation == "minus")
	{
		println("{}", operand1 - operand2);
	}

	else if (operation == "*" || operation == "mul")
	{
		println("{}", operand1 * operand2);
	}

	else if (operation == "/" || operation == "div")
	{
		println("{}", operand1 / operand2);
	}

	else
	{
		println("The operation \"{}\" is not recognized.", operation);
	}
}

void BookExercises::Chapter2::Exercise11()
{
	// Values set to simulate user input for the exercise
	constexpr int pennies { 23 };
	constexpr int nickels { 17 };
	constexpr int dimes { 14 };
	constexpr int quarters { 7 };
	constexpr int halfDollars { 3 };
	constexpr int oneDollarCoins { 1 };

	constexpr int penniesValue { 1 };
	constexpr int nickelsValue { 5 };
	constexpr int dimesValue { 10 };
	constexpr int quartersValue { 25 };
	constexpr int halfDollarsValue { 50 };
	constexpr int oneDollarCoinsValue { 100 };

	// Print the user input values
	println("The user input values are: {}, {}, {}, {}, {}, and {}", pennies, nickels, dimes, quarters, halfDollars, oneDollarCoins);
	println();

	// Print the simulated prompts and input values
	println("How many pennies do you have? {}", pennies);
	println("How many nickels do you have? {}", nickels);
	println("How many dimes do you have? {}", dimes);
	println("How many quarters do you have? {}", quarters);
	println("How many half dollars do you have? {}", halfDollars);
	println("How many one-dollar coins do you have? {}", oneDollarCoins);
	println();

	// Print each coin count with grammatically correct singular or plural wording
	println("You have {} {}", pennies, (pennies == 1) ? "penny" : "pennies");
	println("You have {} {}", nickels, (nickels == 1) ? "nickel" : "nickels");
	println("You have {} {}", dimes, (dimes == 1) ? "dime" : "dimes");
	println("You have {} {}", quarters, (quarters == 1) ? "quarter" : "quarters");
	println("You have {} {}", halfDollars, (halfDollars == 1) ? "half dollar" : "half dollars");
	println("You have {} {}", oneDollarCoins, (oneDollarCoins == 1) ? "one-dollar coin" : "one-dollar coins");

	// Calculate and display the total value of the coins in dollars and cents
	const int totalCents
	{
		pennies * penniesValue +
		nickels * nickelsValue +
		dimes * dimesValue +
		quarters * quartersValue +
		halfDollars * halfDollarsValue +
		oneDollarCoins * oneDollarCoinsValue
	};

	const double totalDollars = static_cast<double>(totalCents) / 100.0;
	println("The value of all of your coins is ${:.2f}.", totalDollars);
}

void BookExercises::Chapter2::WholeChapter()
{
	// Store all the exercise functions in a vector of function pointers
	vector<function<void()>> exerciseFunctions = {
		Exercise1,
		Exercise2,
		Exercise3,
		Exercise4,
		Exercise5,
		Exercise6,
		Exercise7,
		Exercise8,
		Exercise9,
		Exercise10,
		Exercise11
	};

	// Call each function in the vector
	CallFunctionsWithHeader("Exercise", exerciseFunctions);
}
