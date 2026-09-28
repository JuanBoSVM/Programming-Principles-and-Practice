#include "Chapter3.h"

#include <sstream>
#include <string>
#include <print>
#include <vector>
#include <algorithm>
#include <functional>

#include "Utilities.h"

using std::vector;
using std::string;
using std::istringstream;
using std::println;
using std::print;
using std::sort;
using std::function;

void BookExercises::Chapter3::TryThis1()
{
	// Simulate user input
	const string input { "150y" };
	istringstream iss { input };

	// Conversion constants
	constexpr double dollarPerYen { 0.0073 };
	constexpr double dollarPerKroner { 0.15 };
	constexpr double dollarPerPound { 1.31 };

	// Print the user input
	println("The user input is: {}", input);

	// Read the amount and currency from the input stream
	double amount { 0.0 };
	char currency { ' ' };
	iss >> amount >> currency;

	// Print the amount converted to dollars based on the currency
	if (currency == 'y')
	{
		println("The amount in dollars is: ${:.2f}", amount * dollarPerYen);
	}
	else if (currency == 'k')
	{
		println("The amount in dollars is: ${:.2f}", amount * dollarPerKroner);
	}
	else if (currency == 'p')
	{
		println("The amount in dollars is: ${:.2f}", amount * dollarPerPound);
	}
	else
	{
		println("Invalid currency.");
	}
}

void BookExercises::Chapter3::TryThis2()
{
	// Simulate user input
	const string input { "150y" };
	istringstream iss { input };

	// Conversion constants
	constexpr double dollarPerYen { 0.0073 };
	constexpr double dollarPerKroner { 0.15 };
	constexpr double dollarPerPound { 1.31 };
	constexpr double dollarPerSwissFranc { 1.04 };

	// Print the user input
	println("The user input is: {}", input);

	// Read the amount and currency from the input stream
	double amount { 0.0 };
	char currency { ' ' };
	iss >> amount >> currency;

	// Print the amount converted to dollars based on the currency
	switch (currency)
	{
	case 'y':
		println("The amount in dollars is: ${:.2f}", amount * dollarPerYen);
		break;

	case 'k':
		println("The amount in dollars is: ${:.2f}", amount * dollarPerKroner);
		break;

	case 'p':
		println("The amount in dollars is: ${:.2f}", amount * dollarPerPound);
		break;

	case 's':
		println("The amount in dollars is: ${:.2f}", amount * dollarPerSwissFranc);
		break;

	default:
		println("Invalid currency.");
		break;
	}
}

void BookExercises::Chapter3::TryThis3()
{
	// Delimiter characters
	char startChar { 'a' };
	char endChar { 'z' };

	char currentChar { startChar };

	// Loop through the range of characters
	while (currentChar <= endChar)
	{
		// Print the current character and its ASCII value
		println("Character: {}, ASCII value: {}", currentChar, static_cast<int>(currentChar));

		// Increment the current character
		++currentChar;
	}
}

void BookExercises::Chapter3::TryThis4()
{
	// Delimiter characters
	char startChar { '0' };
	char endChar { '9' };

	// Loop through the range of characters
	for (char c { startChar }; c <= endChar; ++c)
	{
		println("Character: {}, ASCII value: {}", c, static_cast<int>(c));
	}

	// Change the delimiter characters to uppercase letters
	startChar = 'A';
	endChar = 'Z';

	// Loop through the range of characters
	for (char c { startChar }; c <= endChar; ++c)
	{
		println("Character: {}, ASCII value: {}", c, static_cast<int>(c));
	}

	// Change the delimiter characters to lowercase letters
	startChar = 'a';
	endChar = 'z';

	// Loop through the range of characters
	for (char c { startChar }; c <= endChar; ++c)
	{
		println("Character: {}, ASCII value: {}", c, static_cast<int>(c));
	}
}

void BookExercises::Chapter3::TryThis5()
{
	// Simulate user input
	constexpr int numInputs { 5 };

	int result { 0 };

	// Print the user input
	println("The user input is: {}", numInputs);

	// Square the input without multiplying
	for (int i { 0 }; i < numInputs; ++i)
	{
		result += numInputs;
	}

	// Print the result
	println("The square of {} is: {}", numInputs, result);
}

void BookExercises::Chapter3::TryThis6()
{
	// Simulate user input
	const string input { "I like broccoli but not potatoes." };
	istringstream iss { input };

	// Define a vector of banned words
	const vector<string> bannedWords
	{
		"Broccoli",
		"broccoli",
		"Cauliflower",
		"cauliflower",
		"Spinach",
		"spinach"
	};

	// Print the user input
	println("The user input is: {}", input);

	// Variable to store the current word being read
	string currentWord;

	// Flag to indicate if the current word is banned
	bool isBanned { false };

	// Read the input stream word by word
	while (iss >> currentWord)
	{
		// Check if the word is in the banned words list
		for (const auto& bannedWord : bannedWords)
		{
			isBanned = (currentWord == bannedWord) || isBanned;
		}

		// Print the current word if it is not banned
		print("{} ", isBanned ? "Bleep" : currentWord);

		// Reset the isBanned flag for the next word
		isBanned = false;
	}

	// Print a newline at the end
	println();
}

void BookExercises::Chapter3::Exercise1()
{
	// Vector to store the TryThis functions
	vector<function<void()>> tryThisFunctions {
		TryThis1,
		TryThis2,
		TryThis3,
		TryThis4,
		TryThis5,
		TryThis6
	};

	// Print the TryThis functions
	CallFunctionsWithHeader("Try this", tryThisFunctions);
}

void BookExercises::Chapter3::Exercise2()
{
	// Simulate user input
	const string input { "Programming" };

	// Print the user input
	println("The user input is: {}", input);

	// Loop through each character in the input string and print it
	for (const char& c : input)
	{
		println("Character: {}, ASCII value: {}", c, static_cast<int>(c));
	}
}

void BookExercises::Chapter3::Exercise3()
{
	// Simulate user input
	const string input { "26 27 28 29" };
	istringstream iss { input };

	// Vector to store the temperatures
	vector<int> temps;

	// Variable to store the current temperature
	int currentTemp { 0 };

	// Variable to store the median of the temperatures
	double median { 0.0 };

	// Print the user input
	println("The user input is: {}", input);

	// Read the numbers from the input stream and store them in the vector
	while (iss)
	{
		// Read the current temperature from the input stream
		iss >> currentTemp;

		// If the read was successful, add the current temperature to the vector
		if (iss) { temps.push_back(currentTemp); }
	}

	// Sort the temperatures in ascending order
	sort(temps.begin(), temps.end());

	// Check if the set of temperatures is even
	if (temps.size() % 2 == 0)
	{
		// Calculate the average of the two middle values
		median = (temps[(temps.size() >> 1) - 1] + temps[temps.size() >> 1]) / 2.0;
	}

	// The set of temperatures is odd
	else
	{
		// If the number of temperatures is odd, take the middle value
		median = temps[temps.size() >> 1];
	}

	// Print the median of the temperatures
	println("The median of the temperatures is: {}", median);
}

void BookExercises::Chapter3::Exercise4()
{
	// Simulate user input
	const string input { "17.54 28.31 39.67 42.15" };
	istringstream iss { input };

	// Vector to store the numbers
	vector<double> distances;

	// Variable to store the current number
	double currentDistance { 0.0 };

	// Variable to store the sum of the numbers
	double sumOfDistances { 0.0 };

	// Variable to store the average of the numbers
	double averageOfDistances { 0.0 };

	// Print the user input
	println("The user input is: {}", input);

	// Read the numbers from the input stream and store them in the vector
	while (iss >> currentDistance)
	{
		distances.push_back(currentDistance);
	}

	// Calculate the sum of the numbers
	for (const auto& distance : distances)
	{
		sumOfDistances += distance;
	}

	// Calculate the average of the numbers
	averageOfDistances = sumOfDistances / static_cast<double>(distances.size());

	// Print the total sum of the numbers
	println("The total sum of the distances is: {:.2f}", sumOfDistances);

	// Print the average of the numbers
	println("The average of the distances is: {:.2f}", averageOfDistances);

	// Sort the numbers in ascending order
	sort(distances.begin(), distances.end());

	// Print the smallest and largest numbers
	println("The smallest distance is: {:.2f}", distances.front());
	println("The largest distance is: {:.2f}", distances.back());
}

void BookExercises::Chapter3::Exercise5()
{
	// Simulate user input
	const unsigned int input { 3u };

	// Print the user input
	println("The user input is: {}", input);
	println();

	// Flags to simulate the user input for the loop
	bool isGreaterThan { false };
	bool isCorrectGuess { false };

	// Variables to store the program's guess range
	unsigned int lowerBound { 0u };
	unsigned int upperBound { 100u };
	unsigned int programGuess { 50u };

	// Counter to track the number of guesses
	unsigned int guessCount { 0u };

	// Loop until the program correctly guesses the number
	while (!isCorrectGuess)
	{
		// Calculate the program's guess as the midpoint of the range
		programGuess = (lowerBound + upperBound) >> 1;

		// Check the range of the program's guess
		// If the range is one, the program has guessed the number
		if (lowerBound == upperBound) { isCorrectGuess = true; }

		// The range is too large, so the program needs to narrow it down
		else
		{
			// Print the current guess count
			println("Question number {}:", ++guessCount);

			// Print the program's question
			println("Is your number greater than {}?", programGuess);

			// Simulate user input for the program's guess
			isGreaterThan = (input > programGuess);

			// Print the simulated user input
			println("The user input is: {}", isGreaterThan ? "Yes" : "No");

			// If the user's number is greater than the program's guess, update the lower bound
			if (isGreaterThan) { lowerBound = programGuess + 1; }

			// If the user's number is less than or equal to the program's guess, update the upper bound
			else { upperBound = programGuess; }
		}

		// Print a newline for better readability
		println();
	}

	// Print the program's guess
	println("The program has guessed the number {} in {} guesses", programGuess, guessCount);
}

void BookExercises::Chapter3::Exercise6()
{
	// Simulate user input
	const string input { "30.3 17.4 +" };
	istringstream iss { input };

	// Variables to store the operands and operator
	double operand1 { 0.0 };
	double operand2 { 0.0 };
	char operatorChar { ' ' };

	// Print the user input
	println("The user input is: {}", input);

	// Extract the operands and operator from the input
	iss >> operand1 >> operand2 >> operatorChar;

	// Perform the calculation based on the operator
	switch (operatorChar)
	{
	case '+':

		println("The sum of {} + {} is: {}", operand1, operand2, operand1 + operand2);
		break;

	case '-':

		println("The difference of {} - {} is: {}", operand1, operand2, operand1 - operand2);
		break;

	case '*':

		println("The product of {} * {} is: {}", operand1, operand2, operand1 * operand2);
		break;

	case '/':

		if (operand2 != 0.0)
		{
			println("The quotient of {} / {} is: {}", operand1, operand2, operand1 / operand2);
		}

		else
		{
			println("Error: Division by zero is not allowed.");
		}
		break;

	default:
		println("Invalid operator.");
		break;
	}
}

void BookExercises::Chapter3::Exercise7()
{

}

void BookExercises::Chapter3::Exercise8()
{

}

void BookExercises::Chapter3::Exercise9()
{

}

void BookExercises::Chapter3::Exercise10()
{
}

void BookExercises::Chapter3::Exercise11()
{
}

void BookExercises::Chapter3::Exercise12()
{
}

void BookExercises::Chapter3::Exercise13()
{
}

void BookExercises::Chapter3::Exercise14()
{
}

void BookExercises::Chapter3::Exercise15()
{
}

void BookExercises::Chapter3::Exercise16()
{
}

void BookExercises::Chapter3::Exercise17()
{
}

void BookExercises::Chapter3::Exercise18()
{
}

void BookExercises::Chapter3::Exercise19()
{
}

void BookExercises::Chapter3::Exercise20()
{
}

void BookExercises::Chapter3::WholeChapter()
{
	// Vector to store the Exercise functions
	vector<function<void()>> exerciseFunctions {
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
		Exercise11,
		Exercise12,
		Exercise13,
		Exercise14,
		Exercise15,
		Exercise16,
		Exercise17,
		Exercise18,
		Exercise19,
		Exercise20
	};

	// Print the Exercise functions
	CallFunctionsWithHeader("Exercise", exerciseFunctions);
}
