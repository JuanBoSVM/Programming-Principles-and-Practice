#include "Chapter5.h"

#include "Calculator/Chapter5/Calculator.h"
#include "Utilities.h"

#include <print>
#include <exception>

using std::print;
using std::println;

void BookExercises::Chapter5::TryThis1()
{
	println("We could add a priority layer to the system.");
}

void BookExercises::Chapter5::TryThis2()
{
	println("The calculator doesn't work as expected!");
}

void BookExercises::Chapter5::TryThis3()
{
	println("Nothing to code here");
}

void BookExercises::Chapter5::Exercise1()
{
	// Vector to store the try this exercises
	vector<function<void()>> tryThisExercises = {
		TryThis1,
		TryThis2,
		TryThis3
	};

	CallFunctionsWithHeader("Try This", tryThisExercises);
}

void BookExercises::Chapter5::Exercise2()
{
	// Simulate user input
	string_view input{ "(4 + 5)*6 / (3 + 4)" };

	// Create a calculator object
	Program::Chapter5::Calculator calculator;

	// Print user input
	println("User input: {}", input);

	try
	{
		// Calculate the result
		double result = calculator.Calculate(input);

		// Print the result
		println("The result is {}", result);
	}

	catch (const std::exception& e)
	{
		println("Error: {}", e.what());
	}
}

void BookExercises::Chapter5::Exercise3()
{
	// Simulate user input
	string_view input{ "{(-74+40*+2)*6} / [57+-3.5*3!]" };

	// Create a calculator object
	Program::Chapter5::Calculator calculator;

	// Print user input
	println("User input: {}", input);

	try
	{
		// Calculate the result
		double result = calculator.Calculate(input);

		// Print the result
		println("The result is {}", result);
	}

	catch (const std::exception& e)
	{
		println("Error: {}", e.what());
	}
}

void BookExercises::Chapter5::Exercise4()
{
	// Define a structure to hold the name and score
	struct Name_Value
	{
		string_view name;
		unsigned int score;
	};

	// Simulate user input
	vector<Name_Value> nameValues{
		{ "Alice", 85u },
		{ "Bob", 92u },
		{ "Charlie", 78u },
		{ "David", 90u },
		{ "Eve", 88u },
		{ "NoName", 0u }
	};

	string_view name{ "Bob" };

	// Print the user input
	println("The user input is:");

	// Validate there are no duplicate names in the names vector
	for (size_t i{ 0u }; i < nameValues.size(); ++i)
	{
		// Store the current name
		string_view currentName{ nameValues[i].name };

		// Loop through the remaining names to check for duplicates
		for (size_t j{ i + 1u }; j < nameValues.size(); ++j)
		{
			if (currentName == nameValues[j].name)
			{
				println("Duplicate name found: {}", std::string(currentName));
			}
		}
	}

	// Loop through the nameValues vector and print the names and scores
	for (const auto& nv : nameValues)
	{
		println("Name: {}, Score: {}", nv.name, nv.score);
	}

	// Print two newlines for better readability
	println();
	println();

	// Print the simulated user input for the name to search for
	println("The user input is: {}", name);

	// Vector to store the scores corresponding to the given name
	vector<unsigned int> scoresWithName;

	// Loop through the names and scores to find the score corresponding to the given name
	for (size_t i{ 0u }; i < nameValues.size(); ++i)
	{
		// Check if the name matches the given name
		if (nameValues[i].name == name)
		{
			// Add the corresponding score to the scoresWithName vector
			scoresWithName.push_back(nameValues[i].score);
		}
	}

	// Print the result of the search
	println
	(
		"Found {} score{} for the name {}: {}",
		scoresWithName.size(),
		scoresWithName.size() == 1 ? "" : "s",
		name,
		scoresWithName
	);
}

void BookExercises::Chapter5::Exercise5()
{

}

void BookExercises::Chapter5::Exercise6()
{
	// Correct answer for the game "Bulls and Cows" with 4 digits
	vector numbers{ 'a', 'b', 'c', 'd' };

	// Simulate user input for the guess
	vector guess{ 'a', 'b', 'd', 'c' };

	// Flag to indicate if the user's still guessing
	bool isStillGuessing{ true };

	// Variables to count bulls and cows
	unsigned int bulls{ 0u };
	unsigned int cows{ 0u };

	// Loop until the user guesses correctly
	while (isStillGuessing)
	{
		// Print the user's guess
		println("User Guess: {}", guess);

		// Calculate bulls and cows
		for (size_t i{ 0u }; i < numbers.size(); ++i)
		{
			// Correct digit in the correct position (bull)
			if (guess[i] == numbers[i]) { ++bulls; }

			// Correct digit in the wrong position (cow)
			else if (find(numbers.begin(), numbers.end(), guess[i]) != numbers.end()) { ++cows; }
		}

		// Print the result of the guess
		println("Guess: {} | Bulls: {}, Cows: {}", guess, bulls, cows);

		// Check if the user guessed correctly
		if (bulls == static_cast<int>(numbers.size()))
		{
			// User guessed correctly, exit the loop
			println("Congratulations! You've guessed the correct number!");
			isStillGuessing = false;
		}

		// Reset bulls and cows for the next guess
		bulls = 0;
		cows = 0;
		guess.clear();

		// Simulate the next guess
		guess.push_back('a');
		guess.push_back('b');
		guess.push_back('c');
		guess.push_back('d');

		// Print a blank line for better readability between guesses
		println();
	}
}

void BookExercises::Chapter5::Exercise7()
{
	// Simulate user input
	string_view input{ "3693" };

	// Variable to store the decimal placement of the number
	int decimalPlacement{ static_cast<int>(input.length()) };

	// Print the user input
	println("User input: {}", input);

	// Print the first part of the result
	print("{} is ", input);

	// Loop through the input string
	for (unsigned int i{ 0u }; i < input.length(); ++i)
	{
		// Print the number as an int
		print("{} ", static_cast<int>(input[i]) - static_cast<int>('0'));

		switch (decimalPlacement--)
		{
		case 4:
			print("thousand");
			break;

		case 3:
			print("hundred");
			break;

		case 2:
			print("ten");
			break;

		case 1:
			print("one");
			break;

		default:
			break;
		}

		// Add the 's' for plural if necessary and a space after each number
		print("{} ", static_cast<int>(input[i]) - static_cast<int>('0') == 1 ? "" : "s");
	}

	println();
	println();
}

void BookExercises::Chapter5::Exercise8()
{
	// Simulate user input for the permutation of the input string
	unsigned int permA{ 3 };
	unsigned int permB{ 2 };

	// Simulate user input for the combination of the input string
	unsigned int combA{ 5 };
	unsigned int combB{ 2 };

	// Print the user input for the permutation
	println("User input for permutation: {}, {}", permA, permB);
	println();

	// Print the user input for the combination
	println("User input for combination: {}, {}", combA, combB);
	println();

	// Print a blank line for better readability
	println();

	// Create a calculator object
	Program::Chapter5::Calculator calculator;

	try
	{
		// Calculate the permutation
		unsigned int permutation{ calculator.CalculatePermutation(permA, permB) };

		// Calculate the combination
		unsigned int combination{ calculator.CalculateCombination(combA, combB) };

		// Print the result of the permutation
		println("The permutation of {} and {} is {}", permA, permB, permutation);
		println();

		// Print the result of the combination
		println("The combination of {} and {} is {}", combA, combB, combination);
		println();
	}

	catch (const std::exception& e)
	{
		println("Error: {}", e.what());
	}
}

void BookExercises::Chapter5::WholeChapter()
{
	// Vector to store the exercises
	vector<function<void()>> exercises = {
		Exercise1,
		Exercise2,
		Exercise3,
		Exercise4,
		Exercise5,
		Exercise6,
		Exercise7,
		Exercise8
	};

	CallFunctionsWithHeader("Exercise", exercises);
}
