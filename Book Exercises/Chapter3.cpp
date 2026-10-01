#include "Chapter3.h"

#include <sstream>
#include <string>
#include <string_view>
#include <print>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <limits>

#include "Utilities.h"

using std::count;
using std::erase;
using std::vector;
using std::string;
using std::string_view;
using std::istringstream;
using std::println;
using std::print;
using std::sort;
using std::function;
using std::numeric_limits;
using std::ceil;
using std::log2;

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
	const vector<string_view> bannedWords
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
		// Convert the word to lowercase for case-insensitive comparison
		StringToLower(currentWord);

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
	// Simulate user input
	string input { "Three" };

	// Vector with the spelled-out numbers
	const vector<string_view> spelledOutNumbers
	{
		"zero",
		"one",
		"two",
		"three",
		"four",
		"five",
		"six",
		"seven",
		"eight",
		"nine"
	};

	// Print the user input
	println("The user input is: {}", input);

	// Convert the input to lowercase for case-insensitive comparison
	StringToLower(input);

	// Loop through the spelled-out numbers to find a match
	for (unsigned int i { 0u }; i < spelledOutNumbers.size(); ++i)
	{
		// Skip non-matching numbers
		if (input != spelledOutNumbers[i]) { continue; }

		// Print the corresponding digit if a match is found
		println("The number is: {}", i);

		// Exit the loop after finding a match
		break;
	}
}

void BookExercises::Chapter3::Exercise8()
{
	// Simulate user input
	const string input { "Three 4 +" };
	istringstream iss { input };

	// Vector with the spelled-out numbers
	const vector<string_view> spelledOutNumbers
	{
		"zero",
		"one",
		"two",
		"three",
		"four",
		"five",
		"six",
		"seven",
		"eight",
		"nine"
	};

	// Variables to store the operands and operator
	string operand1Str;
	string	operand2Str;
	int operand1Num { 0 };
	int operand2Num { 0 };
	char operatorChar { ' ' };

	// Print the user input
	println("The user input is: {}", input);

	// Extract the operands and operator from the input
	iss >> operand1Str >> operand2Str >> operatorChar;

	// Convert the first number to digits
	if (operand1Str.length() > 1)
	{
		StringToLower(operand1Str);

		for (unsigned int i { 0u }; i < spelledOutNumbers.size(); ++i)
		{
			if (operand1Str == spelledOutNumbers[i])
			{
				operand1Num = static_cast<int>(i);
				break;
			}
		}
	}

	else { operand1Num = std::stoi(operand1Str); }

	// Convert the second number to digits
	if (operand2Str.length() > 1)
	{
		StringToLower(operand2Str);
		for (unsigned int i { 0u }; i < spelledOutNumbers.size(); ++i)
		{
			if (operand2Str == spelledOutNumbers[i])
			{
				operand2Num = static_cast<int>(i);
				break;
			}
		}
	}

	else { operand2Num = std::stoi(operand2Str); }

	// Perform the calculation based on the operator
	switch (operatorChar)
	{
	case '+':

		println("The sum of {} + {} is: {}", operand1Num, operand2Num, operand1Num + operand2Num);
		break;

	case '-':

		println("The difference of {} - {} is: {}", operand1Num, operand2Num, operand1Num - operand2Num);
		break;

	case '*':

		println("The product of {} * {} is: {}", operand1Num, operand2Num, operand1Num * operand2Num);
		break;

	case '/':

		if (operand2Num != 0.0)
		{
			println("The quotient of {} / {} is: {}", operand1Num, operand2Num, operand1Num / operand2Num);
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

void BookExercises::Chapter3::Exercise9()
{
	// Target numbers to calculate the necessary number of squares
	const vector<unsigned int> targetNumbers
	{
		1000u,
		1000000u,
		1000000000u
	};

	// Loop through the target numbers
	for (const auto& target : targetNumbers)
	{
		// Print the target number with the necessary number of squares
		println
		(
			"You will need {} squares to gain {} grain{} of rice",
			static_cast<unsigned int>(ceil(log2(static_cast<double>(target)))),
			target,
			target == 1 ? " " : "s"
		);
	}
}

void BookExercises::Chapter3::Exercise10()
{
	// Store the maximum values for int and double types
	constexpr int maxInt { numeric_limits<int>::max() };
	constexpr double maxDouble { numeric_limits<double>::max() };

	// Print the maximum values
	println
	(
		"The maximum value for int is: {}, which we would need {} squares for",
		maxInt,
		static_cast<unsigned int>(ceil(log2(maxInt)))
	);

	println
	(
		"The maximum value for double is: {}, which we would need {} squares for",
		maxDouble,
		static_cast<unsigned int>(ceil(log2(maxDouble)))
	);
}

void BookExercises::Chapter3::Exercise11()
{
	// Vector with the "random" sequences of rocks, scissors, and paper
	const vector<vector<char>> sequences
	{
		{ 'r', 's', 'p', 'r', 's', 'p' },
		{ 'r', 'r', 's', 's', 'p', 'p' },
		{ 'r', 's', 'r', 's', 'p', 'p' }
	};

	// Simulate user input for the sequences
	const vector<char> userInputs
	{
		'r',
		'p',
		'p',
		's',
		'r',
		's'
	};

	// String to represent the machine's choice and the user's choice
	string machineChoice;
	string userChoice;

	// Flag to indicate if the user has won
	bool userWon { false };

	// Loop through the sequences and print the results
	for (size_t i { 0u }; i < sequences.size(); ++i)
	{
		// Print the simulation header
		println("Simulating the sequence: {}", i + 1u);
		println();

		// Loop through the sequence and print the results
		for (size_t j { 0u }; j < sequences[i].size(); ++j)
		{
			// Determine the machine's choice based on the character
			switch (sequences[i][j])
			{
			case 'r':
				machineChoice = "Rock";
				break;

			case 's':
				machineChoice = "Scissors";
				break;

			case 'p':
				machineChoice = "Paper";
				break;

			default:
				machineChoice = "Unknown";
				break;
			}

			// Determine the user's choice based on the character
			switch (userInputs[j])
			{
			case 'r':
				userChoice = "Rock";
				break;

			case 's':
				userChoice = "Scissors";
				break;

			case 'p':
				userChoice = "Paper";
				break;

			default:
				userChoice = "Unknown";
				break;
			}

			// Print the user's input and the machine's choice
			println
			(
				"The user input is: {} and the machine's choice is: {}",
				userChoice,
				machineChoice
			);

			// Determine the winner based on the user's input and the machine's choice
			switch (userChoice[0])
			{
			case 'r':
				if (sequences[i][j] == 's') { userWon = true; }
				else { userWon = false; }
				break;

			case 'p':
				if (sequences[i][j] == 'r') { userWon = true; }
				else { userWon = false; }
				break;

			case 's':
				if (sequences[i][j] == 'p') { userWon = true; }
				else { userWon = false; }
				break;
			}

			// Print the result of the game
			if (userChoice == machineChoice) { println("It's a tie!"); }
			else { println("The {} is the winner!", userWon ? "user" : "machine"); }

			// Print a newline for better readability
			println();
		}

		// Print a newline after each sequence
		println();
	}
}

void BookExercises::Chapter3::Exercise12()
{
	// Maximum prime number to generate
	constexpr unsigned int maxPrime { 100u };

	// Vector to store the prime numbers
	vector<unsigned int> primeNumbers;

	// Buffer to store the next prime number
	unsigned int nextPrime { 0u };

	// Prime id Number
	unsigned int primeId { 2u };

	// Flag to indicate if the next prime number is divisible by any of the existing prime numbers
	bool isDivisible { false };

	// Add the first two prime numbers to the vector
	primeNumbers.push_back(2u);
	primeNumbers.push_back(3u);

	// Loop until the vector of prime numbers is filled with the maximum prime number
	while (nextPrime <= maxPrime)
	{
		// Reset the isDivisible flag for the next prime number
		isDivisible = false;

		// Calculate the next possible prime number
		nextPrime = primeId % 2u == 0u ? 6 * (++primeId >> 1u) - 1u : 6 * (primeId++ >> 1u) + 1u;

		// Loop through the existing prime numbers
		for (const auto& prime : primeNumbers)
		{
			// Check if the next prime number is divisible by any of the existing prime numbers
			if (nextPrime % prime == 0u)
			{
				// Set the isDivisible flag to true and break out of the loop
				isDivisible = true;
				break;
			}
		}

		// Add the next prime number to the vector if it is less than or equal to the maximum prime number
		if (nextPrime <= maxPrime && !isDivisible) { primeNumbers.push_back(nextPrime); }
	}

	// Print the header for the prime numbers
	println("Found {} prime numbers up to {}:", primeNumbers.size(), maxPrime);

	// Loop through the prime numbers and print them
	for (const auto& prime : primeNumbers)
	{
		println("{}", prime);
	}
}

void BookExercises::Chapter3::Exercise13()
{
	// Upper limit for the prime numbers
	constexpr unsigned int upperLimit { 100u };

	// Vector to hold numbers from 2 to upperLimit
	vector<unsigned int> numbers(upperLimit - 1u);

	// Fill the vector with numbers from 2 to upperLimit
	for (size_t i { 0u }; i < numbers.size(); ++i)
	{
		numbers[i] = static_cast<unsigned int>(i) + 2u;
	}

	// Loop through the numbers to find prime numbers
	for (const auto& prime : numbers)
	{
		// Loop again through the numbers to check for divisibility
		for (const auto& candidate : numbers)
		{
			// Skip if the divisor is lower or equal to the prime number
			if (candidate <= prime) { continue; }

			// If the candidate is divisible by the prime number, remove it from the vector
			if (candidate % prime == 0u)
			{
				erase(numbers, candidate);
			}
		}
	}

	// Print the prime numbers found
	println("Found {} prime numbers up to {}:", numbers.size(), upperLimit);

	// Loop through the numbers and print them
	for (const auto& prime : numbers)
	{
		println("{}", prime);
	}
}

void BookExercises::Chapter3::Exercise14()
{
	// Simulate user input
	constexpr size_t primeCount { 100u };

	// Vector to store the prime numbers
	vector<unsigned int> primeNumbers;

	// Resize the vector to hold the specified number of prime numbers
	primeNumbers.reserve(primeCount);

	// Fill the vector with the first prime numbers
	primeNumbers.push_back(2u);
	primeNumbers.push_back(3u);

	// Flag to indicate if the next prime number is divisible by any of the existing prime numbers
	bool isDivisible { false };

	// Variable to store the next prime number
	unsigned int nextPrime { 0u };

	// Continue filling the vector with the next prime numbers
	for (unsigned int i { 2u }; primeNumbers.size() < primeCount; ++i)
	{
		// Reset the isDivisible flag for the next prime number
		isDivisible = false;

		// Calculate the next possible prime number
		nextPrime = i % 2u == 0u ? 6 * ((i + 1u) >> 1u) - 1u : 6 * (i >> 1u) + 1u;

		// Loop through the existing prime numbers
		for (const auto& prime : primeNumbers)
		{
			// Check if the next prime number is divisible by any of the existing prime numbers
			if (nextPrime % prime == 0u)
			{
				// Set the isDivisible flag to true and break out of the loop
				isDivisible = true;
				break;
			}
		}

		// Add the next prime number to the vector if it is less than or equal to the maximum prime number
		if (!isDivisible) { primeNumbers.push_back(nextPrime); }
	}

	// Print the header for the prime numbers
	println("The first {} prime numbers are:", primeCount);

	// Loop through the prime numbers and print them
	for (const auto& prime : primeNumbers)
	{
		println("{}", prime);
	}
}

void BookExercises::Chapter3::Exercise15()
{
	// Simulate user input
	vector<int> input { 1, 2, 3, 4, 5, 3, 2, 1, 1, 3, 3 };

	// Print the user input
	println("The user input is: {}", input);

	// Sort the input vector to group identical numbers together
	sort(input.begin(), input.end());

	// Variable to store the most frequently occurring number and its frequency
	int mostFrequentNumber { input[0u] };
	unsigned int highestFrequency { 0u };
	unsigned int currentFrequency { 0u };

	// Loop through unique values in the sorted input vector to find the most frequently occurring number
	for (const auto& value : input)
	{
		// Count occurrences of the current value using std::count
		currentFrequency = static_cast<unsigned int>(count(input.begin(), input.end(), value));

		// If the current frequency is higher than the highest frequency, update the most frequent number and highest frequency
		if (currentFrequency > highestFrequency)
		{
			mostFrequentNumber = value;
			highestFrequency = currentFrequency;
		}
	}

	// Print the most frequently occurring number and its frequency
	println
	(
		"The most frequently occurring number is {} with a frequency of {}",
		mostFrequentNumber,
		highestFrequency
	);
}

void BookExercises::Chapter3::Exercise16()
{
	// Vector to hold the strings
	vector<string_view> strings
	{
		"apple",
		"banana",
		"cherry",
		"date",
		"elderberry",
		"date",
		"banana",
		"banana"
	};

	// Print the original strings
	println("Original strings: {}", strings);

	// Sort the strings in ascending order
	sort(strings.begin(), strings.end());

	// Variable to store the most frequently occurring string and its frequency
	string mostFrequentString { strings[0u] };
	unsigned int highestFrequency { 0u };
	unsigned int currentFrequency { 0u };

	// Loop through unique values in the sorted input vector to find the most frequently occurring string
	for (const auto& value : strings)
	{
		// Count occurrences of the current value using std::count
		currentFrequency = static_cast<unsigned int>(count(strings.begin(), strings.end(), value));

		// If the current frequency is higher than the highest frequency, update the most frequent string and highest frequency
		if (currentFrequency > highestFrequency)
		{
			mostFrequentString = value;
			highestFrequency = currentFrequency;
		}
	}

	// Print the min and max strings
	println("The minimum string is {} and the maximum string is {}", strings.front(), strings.back());

	// Print the most frequently occurring string and its frequency
	println
	(
		"The most frequently occurring string is {} with a frequency of {}",
		mostFrequentString,
		highestFrequency
	);
}

void BookExercises::Chapter3::Exercise17()
{
	// Simulate user input
	constexpr double aValue { 5.0 };
	constexpr double bValue { 7.0 };
	constexpr double cValue { 2.0 };

	// Variables to store the solutions of the quadratic equation
	double xValue1 { 0.0 };
	double xValue2 { 0.0 };

	// Print the user input
	println("The user input is: a = {}, b = {}, c = {}", aValue, bValue, cValue);

	// Calculate the solution using the quadratic formula
	xValue1 = (-bValue + sqrt(bValue * bValue - 4 * aValue * cValue)) / (2 * aValue);
	xValue2 = (-bValue - sqrt(bValue * bValue - 4 * aValue * cValue)) / (2 * aValue);

	// Print the solutions
	println("The solutions are: x1 = {}, x2 = {}", xValue1, xValue2);
}

void BookExercises::Chapter3::Exercise18()
{
	// Simulate user input
	vector<string_view> names { "Alice", "Bob", "Charlie", "David", "Eve", "NoName" };
	vector<unsigned int> scores { 85u, 92u, 78u, 90u, 88u, 0u };


	// Print the user input
	println("The user input is:");

	// Validate that the sizes of the names and scores vectors are equal
	if (names.size() != scores.size())
	{
		println("Error: The sizes of the names and scores vectors are not equal.");
		return;
	}

	// Validate there are no duplicate names in the names vector
	for (const auto& name : names)
	{
		if (count(names.begin(), names.end(), name) > 1)
		{
			println("Error: Duplicate name found: {}", name);
			return;
		}
	}

	// Loop through the names and scores and print them
	for (unsigned int i { 0u }; i < names.size(); ++i)
	{
		println("Name: {}, Score: {}", names[i], scores[i]);
	}
}

void BookExercises::Chapter3::Exercise19()
{
	// Simulate user input
	vector<string_view> names { "Alice", "Bob", "Charlie", "David", "Eve", "NoName" };
	vector<unsigned int> scores { 85u, 92u, 78u, 90u, 88u, 0u };
	constexpr unsigned int score { 85u };



	// Print the user input
	println("The user input is:");

	// Validate that the sizes of the names and scores vectors are equal
	if (names.size() != scores.size())
	{
		println("Error: The sizes of the names and scores vectors are not equal.");
		return;
	}

	// Validate there are no duplicate names in the names vector
	for (const auto& name : names)
	{
		if (count(names.begin(), names.end(), name) > 1)
		{
			println("Error: Duplicate name found: {}", name);
			return;
		}
	}

	// Loop through the names and scores and print them
	for (unsigned int i { 0u }; i < names.size(); ++i)
	{
		println("Name: {}, Score: {}", names[i], scores[i]);
	}

	// Print two newlines for better readability
	println();
	println();

	// Print the simulated user input for the score to search for
	println("The user input is: {}", score);

	// Vector to store the names corresponding to the given score
	vector<string_view> namesWithScore;

	// Loop through the names and scores to find the name corresponding to the given score
	for (size_t i { 0u }; i < scores.size(); ++i)
	{
		// Check if the score matches the given score
		if (scores[i] == score)
		{
			// Add the corresponding name to the namesWithScore vector
			namesWithScore.push_back(names[i]);
		}
	}

	// Print the result of the search
	println
	(
		"Found {} name{} with the score of {}: {}",
		namesWithScore.size(),
		namesWithScore.size() == 1 ? "" : "s",
		score,
		namesWithScore
	);
}

void BookExercises::Chapter3::Exercise20()
{
	// Simulate user input
	vector<string_view> names { "Alice", "Bob", "Charlie", "David", "Eve", "NoName" };
	vector<unsigned int> scores { 85u, 92u, 78u, 90u, 88u, 0u };
	constexpr string_view name { "Alice" };



	// Print the user input
	println("The user input is:");

	// Validate that the sizes of the names and scores vectors are equal
	if (names.size() != scores.size())
	{
		println("Error: The sizes of the names and scores vectors are not equal.");
		return;
	}

	// Validate there are no duplicate names in the names vector
	for (const auto& name : names)
	{
		if (count(names.begin(), names.end(), name) > 1)
		{
			println("Error: Duplicate name found: {}", name);
			return;
		}
	}

	// Loop through the names and scores and print them
	for (unsigned int i { 0u }; i < names.size(); ++i)
	{
		println("Name: {}, Score: {}", names[i], scores[i]);
	}

	// Print two newlines for better readability
	println();
	println();

	// Print the simulated user input for the name to search for
	println("The user input is: {}", name);

	// Vector to store the scores corresponding to the given name
	vector<unsigned int> scoresWithName;

	// Loop through the names and scores to find the score corresponding to the given name
	for (size_t i { 0u }; i < names.size(); ++i)
	{
		// Check if the name matches the given name
		if (names[i] == name)
		{
			// Add the corresponding score to the scoresWithName vector
			scoresWithName.push_back(scores[i]);
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
