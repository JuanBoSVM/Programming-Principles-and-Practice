#include "Chapter4.h"

#include <functional>
#include <print>
#include <vector>
#include <string>
#include <string_view>
#include <sstream>

#include "Utilities.h"

using std::print;
using std::println;
using std::find;
using std::function;
using std::vector;
using std::string;
using std::string_view;
using std::istringstream;

void BookExercises::Chapter4::TryThis1()
{
	vector<string_view> errors = {
		"int s1 = area(7, 2;",
		"int s2 = area(7, 2)",
		"Int s3 = area(7, 2);",
		"int s4 = area('7,2);"
	};

	vector<string_view> errorMessages = {
		") missing",
		"; missing",
		"Int (with a capitalized \'i\') is not a type",
		"non-terminated character \' ; terminating \' is missing)"
	};

	// Print the errors and their corresponding messages
	for (size_t i { 0 }; i < errors.size(); ++i)
	{
		println("Bad Code: {}", errors[i]);
		println("Reason: {}", errorMessages[i]);
		println();
	}
}

void BookExercises::Chapter4::TryThis2()
{
	vector<string_view> errors = {
		"int x0 = arena(7, 2);",
		"int x1 = area(7);",
		"int x2 = area(\"seven\", 2);"
	};

	vector <string_view> errorMessages = {
		"undeclared function",
		"wrong number of arguments",
		"1st argument has a wrong type"
	};

	// Print the errors and their corresponding messages
	for (size_t i { 0 }; i < errors.size(); ++i)
	{
		println("Bad Code: {}", errors[i]);
		println("Reason: {}", errorMessages[i]);
		println();
	}
}

void BookExercises::Chapter4::TryThis3()
{
	constexpr int x { 7 };
	constexpr int y { 2 };
	constexpr int z { 3 };

	int area1 = x * y;
	if (area1 <= 0) { println("Error: negative area"); }
	int area2 = 1 * z;
	int area3 = y * z;
	double ratio = double(area1) / area3;

	// Print the results
	println("Area1 (x * y): {}", area1);
	println("Area2 (1 * z): {}", area2);
	println("Area3 (y * z): {}", area3);
	println("Ratio (area1 / area3): {}", ratio);
}

void BookExercises::Chapter4::TryThis4()
{
	string_view code
	{
		"void Error()\n{\n    throw runtime_error(\"An error occurred\");\n}"
	};

	// Print the code snippet
	println("Code Snippet:\n{}", code);
	println();

	// Print the explanation of the error
	println("This code will crash due to the unhandled exception thrown");
}

void BookExercises::Chapter4::TryThis5()
{
	println("The area of a 2cm per side hexagon should be around 9 cm squared.");
	println("Since the area of a square of 3cm per side is 9 cm squared");
}

void BookExercises::Chapter4::TryThis6()
{
	println("The estimate driving time between Guadalajara and Mexico City is around 6 hours.");
	println("The actual driving time by car is around 6 hours and 30 minutes, depending on traffic and road conditions.");
}

void BookExercises::Chapter4::TryThis7()
{
	constexpr int maxValue { std::numeric_limits<int>::max() };
	constexpr int secondValue { 2 };

	println("First value {} and second value {} are both larger than 0", maxValue, secondValue);
	println("Multiplying them will result in an overflow, and fail the post-condition: {}", maxValue * secondValue);
}

void BookExercises::Chapter4::Exercise1()
{
	// Vector of function pointers
	vector<function<void()>> tryThisFunctions = {
		TryThis1,
		TryThis2,
		TryThis3,
		TryThis4,
		TryThis5,
		TryThis6,
		TryThis7
	};

	// Call each function in the vector
	CallFunctionsWithHeader("Try This", tryThisFunctions);
}

void BookExercises::Chapter4::Exercise2()
{
	// Vector of wrong code snippets
	vector<string_view> wrongCodeSnippets = {
		"Int k = c + 273.25;",
		"return Int",
		"cin >> d;",
		"double k = ctok(\"k\")",
		"Cout << k << '\\n';"
	};

	// Vector with the corrected code snippets
	vector<string_view> correctedCodeSnippets = {
		"double k = c + 273.25;",
		"return k;",
		"cin >> c;",
		"double k = ctok(c);",
		"cout << k << '\\n';"
	};

	// Vector with the explanations for each correction
	vector<string_view> explanations = {
		"Int is capitalized. It should be of type double",
		"Return statement should return k, not Int",
		"Variable d is not declared. It should be c",
		"Function ctok expects a double, not a string",
		"Cout is capitalized. It should be cout"
	};

	for (size_t i { 0u }; i < wrongCodeSnippets.size(); ++i)
	{
		println("Wrong Code: {}", wrongCodeSnippets[i]);
		println("Corrected Code: {}", correctedCodeSnippets[i]);
		println("Explanation: {}", explanations[i]);
		println();
	}
}

void BookExercises::Chapter4::Exercise3()
{
	// Simulate user input
	constexpr double celsius { -274.0 };
	constexpr double absoluteZeroCelsius { -273.15 };
	constexpr double kelvin { celsius + 273.15 };

	// Print the user input
	println("User Input: {}C", celsius);

	// Validate the input
	if (celsius < absoluteZeroCelsius)
	{
		println("Error: Temperature below absolute zero is not physically possible.");
	}

	else
	{
		println("Temperature in Kelvin: {} K", kelvin);
	}
}

void BookExercises::Chapter4::Exercise4()
{
	// Simulate user input
	constexpr double celsius { -274.0 };
	constexpr double absoluteZeroCelsius { -273.15 };
	constexpr double kelvin { celsius < absoluteZeroCelsius ? -1.0 : celsius + 273.15 };

	// Print the user input
	println("User Input: {}C", celsius);

	// Print the result based on the validation
	if (kelvin < 0)
	{
		println("Error: Temperature below absolute zero is not physically possible.");
	}

	else
	{
		println("Temperature in Kelvin: {} K", kelvin);
	}
}

void BookExercises::Chapter4::Exercise5()
{
	// Simulate user input
	constexpr double kelvin { 15.0 };
	constexpr double celsius { kelvin - 273.15 };

	// Print the user input
	println("User Input: {}K", kelvin);

	// Print the result based on the validation
	if (kelvin < 0)
	{
		println("Error: Temperature below absolute zero is not physically possible.");
	}

	else
	{
		println("Temperature in Celsius: {}C", celsius);
	}
}

void BookExercises::Chapter4::Exercise6()
{
	// Simulate user input
	constexpr double celsius { 25.0 };
	constexpr double fahrenheit { 60.0 };

	// Print the user input
	println("User Input: {}C and {}F", celsius, fahrenheit);
	println();

	// Convert Celsius to Fahrenheit and print the result
	constexpr double convertedFahrenheit { (celsius * 9.0 / 5.0) + 32.0 };
	println("Converted Fahrenheit: {}F", convertedFahrenheit);

	// Convert Fahrenheit to Celsius and print the result
	constexpr double convertedCelsius { (fahrenheit - 32.0) * 5.0 / 9.0 };
	println("Converted Celsius: {}C", convertedCelsius);
}

void BookExercises::Chapter4::Exercise7()
{
	// Simulate user input
	constexpr double a { 3.0 };
	constexpr double b { 4.0 };
	constexpr double c { 5.0 };

	// Print the user input
	println("User Input: a = {}, b = {}, c = {}", a, b, c);
	println();

	// Calculate the discriminant
	constexpr double discriminant { (b * b) - (4 * a * c) };

	// Print the discriminant
	println("Discriminant: {}", discriminant);

	// Validate there are real roots
	if (discriminant < 0) { println("No real solutions!"); }

	// Calculate and print the roots if they exist
	else
	{
		const double root1 { (-b + std::sqrt(discriminant)) / (2 * a) };
		const double root2 { (-b - std::sqrt(discriminant)) / (2 * a) };
		println("Roots: {} and {}", root1, root2);
	}
}

void BookExercises::Chapter4::Exercise8()
{
	// Simulate user input
	constexpr unsigned int count { 3u };
	string_view input { "1 2 3 4 5 |" };
	istringstream iss { string(input) };

	// Print the user input
	println("User Input: {}", input);

	// Vector to hold the numbers
	vector<int> numbers;

	// Buffer to hold each number read from the input stream
	int num { 0 };

	// Read numbers from the input stream until the '|' character is encountered
	while (iss >> num)
	{
		numbers.push_back(num);
	}

	// Variable to hold the sum of the numbers
	int sum { 0 };

	// Validate that the count of numbers read matches the expected count
	if (numbers.size() < count)
	{
		println("Error: Expected at least {} numbers, but got {}.", count, numbers.size());
	}

	// Calculate the sum of the numbers if the count is valid
	else
	{
		// Resize the numbers vector to the specified count
		numbers.resize(count);

		// Loop through the numbers and calculate the sum
		for (const auto& number : numbers)
		{
			sum += number;
		}

		// Print the count of numbers to be summed
		print("Sum of the first {} numbers {}: {}", count, numbers, sum);
	}
}

void BookExercises::Chapter4::Exercise9()
{
	// Simulate user input
	constexpr unsigned int count { 3u };
	string_view input { "1 2 3 4 5 |" };
	istringstream iss { string(input) };

	// Print the user input
	println("User Input: {}", input);

	// Vector to hold the numbers
	vector<int> numbers;

	// Buffer to hold each number read from the input stream
	int num { 0 };

	// Read numbers from the input stream until the '|' character is encountered
	while (iss >> num)
	{
		numbers.push_back(num);
	}

	// Variable to hold the sum of the numbers
	int sum { 0 };

	// Validate that the count of numbers read matches the expected count
	if (numbers.size() < count)
	{
		println("Error: Expected at least {} numbers, but got {}.", count, numbers.size());
	}

	// Calculate the sum of the numbers if the count is valid
	else
	{
		// Resize the numbers vector to the specified count
		numbers.resize(count);

		// Loop through the numbers and calculate the sum
		for (const auto& number : numbers)
		{
			sum += number;
		}

		// Warn if the result cannot be represented in an int
		if (sum < 0)
		{
			println();
			println("Warning: The sum of the numbers is negative, which may indicate an overflow.");
			println();
		}

		else
		{
			// Print the count of numbers to be summed
			print("Sum of the first {} numbers {}: {}", count, numbers, sum);
		}
	}
}

void BookExercises::Chapter4::Exercise10()
{
	// Simulate user input
	constexpr unsigned int count { 3u };
	string_view input { "1 2 3 4 5 |" };
	istringstream iss { string(input) };

	// Print the user input
	println("User Input: {}", input);

	// Vector to hold the numbers
	vector<double> numbers;

	// Vector to hold the differences between consecutive numbers
	vector<double> differences;

	// Buffer to hold each number read from the input stream
	double num { 0.0 };

	// Read numbers from the input stream until the '|' character is encountered
	while (iss >> num)
	{
		numbers.push_back(num);
	}

	// Variable to hold the sum of the numbers
	double sum { 0 };

	// Validate that the count of numbers read matches the expected count
	if (numbers.size() < count)
	{
		println("Error: Expected at least {} numbers, but got {}.", count, numbers.size());
	}

	// Calculate the sum of the numbers if the count is valid
	else
	{
		// Resize the numbers vector to the specified count
		numbers.resize(count);

		// Loop through the numbers and calculate the sum
		for (const auto& number : numbers)
		{
			sum += number;
		}

		// Warn if the result cannot be represented in an int
		if (sum < 0)
		{
			println();
			println("Warning: The sum of the numbers is negative, which may indicate an overflow.");
			println();
		}

		else
		{
			// Print the count of numbers to be summed
			print("Sum of the first {} numbers {}: {}", count, numbers, sum);
		}
	}

	// Validate that there are enough numbers to calculate differences
	if (numbers.size() >= 2)
	{
		// Reserve space for the differences vector
		differences.reserve(numbers.size() - 1u);

		// Loop through the numbers
		for (size_t i { 1u }; i < numbers.size(); ++i)
		{
			differences.push_back(numbers[i] - numbers[i - 1u]);
		}

		// Print the differences between consecutive numbers
		print("Differences between consecutive numbers: {}", differences);
	}
}

void BookExercises::Chapter4::Exercise11()
{
	// Simulate user input
	constexpr unsigned int count { 9u };

	// Print the user input
	println("User Input: {}", count);

	// Generate first N Fibonacci numbers (starting with 1, 1)
	vector<int> fibSequence;
	fibSequence.reserve(count);

	// Add the first two Fibonacci numbers if count is at least 1 or 2
	if (count >= 1u) fibSequence.push_back(1);
	if (count >= 2u) fibSequence.push_back(1);

	// Generate the rest of the Fibonacci numbers up to the specified count
	for (unsigned int i = 2u; i < count; ++i)
	{
		int next = fibSequence[i - 1] + fibSequence[i - 2];
		fibSequence.push_back(next);
	}

	// Print the first N Fibonacci numbers
	print("First {} Fibonacci numbers: {}\n", count, fibSequence);

	// Variable to keep track of the extra Fibonacci numbers generated beyond the initial count
	int extraCount { count };

	// Keep adding Fibonacci numbers until the next number would exceed the maximum value of an int
	while (fibSequence.back() + fibSequence[fibSequence.size() - 2] > 0)
	{
		// Add the next Fibonacci number to the sequence
		fibSequence.push_back(fibSequence.back() + fibSequence[fibSequence.size() - 2]);

		// Increment the count of extra Fibonacci numbers generated
		++extraCount;
	}

	// Print the largest Fibonacci number that fits in an int
	println("Largest Fibonacci number that fits in an int is F{} = {}", extraCount, fibSequence.back());
}

void BookExercises::Chapter4::Exercise12()
{
	// Correct answer for the game "Bulls and Cows" with 4 digits
	vector<int> numbers { 1, 2, 3, 4 };

	// Simulate user input for the guess
	vector<int> guess { 1, 2, 4, 3 };

	// Flag to indicate if the user's still guessing
	bool isStillGuessing { true };

	// Variables to count bulls and cows
	unsigned int bulls { 0u };
	unsigned int cows { 0u };

	// Loop until the user guesses correctly
	while (isStillGuessing)
	{
		// Print the user's guess
		println("User Guess: {}", guess);

		// Calculate bulls and cows
		for (size_t i { 0u }; i < numbers.size(); ++i)
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
		guess.push_back(1);
		guess.push_back(2);
		guess.push_back(3);
		guess.push_back(4);

		// Print a blank line for better readability between guesses
		println();
	}
}

void BookExercises::Chapter4::Exercise13()
{
	// Maximum number of games to play and maximum number of guesses per game
	constexpr unsigned int maxGames { 3u };
	constexpr unsigned int maxGuesses { 3u };

	// Correct answer for the game "Bulls and Cows" with 4 digits
	vector<int> numbers { 1, 2, 3, 4 };

	// Simulate user input for the guess
	vector<int> guess { 1, 2, 4, 3 };

	// Flag to indicate if the user's still guessing
	bool isStillGuessing { true };

	// Variables to count bulls and cows
	unsigned int bulls { 0u };
	unsigned int cows { 0u };

	// Counters to prevent infinite loops and track the number of games played
	unsigned int gamesPlayed { 0u };
	unsigned int guessCount { 0u };

	// Buffer to hold the unique digits
	int uniqueDigit { 0 };

	// Loop until the user guesses correctly
	while (isStillGuessing)
	{
		// Print the user's guess
		println("User Guess: {}", guess);

		// Check if the user wants to exit the game
		if (guess[0] == -1)
		{
			println("Exiting the game.");
			isStillGuessing = false;
		}

		// Calculate bulls and cows
		for (size_t i { 0u }; i < numbers.size(); ++i)
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

			// Regenerate the correct answer for the next round at random
			numbers.clear();

			// Reset the guess count for the next game
			guessCount = 0;

			// Generate 4 unique random digits between 0 and 9
			while (numbers.size() < 4)
			{
				uniqueDigit = RandomNumber(0, 9);

				// Check if the digit is already in the numbers vector
				if (find(numbers.begin(), numbers.end(), uniqueDigit) == numbers.end())
				{
					// Add the unique digit to the numbers vector
					numbers.push_back(uniqueDigit);
				}
			}

			// Increment the number of games played
			++gamesPlayed;

			// Stop the game if the maximum number of games has been reached
			if (gamesPlayed >= maxGames)
			{
				println("Maximum number of games ({}) reached. Exiting the game.", maxGames);
				isStillGuessing = false;
			}
		}

		// Reset bulls and cows for the next guess
		bulls = 0;
		cows = 0;
		guess.clear();
		++guessCount;

		// Check if the maximum number of guesses has been reached
		if (guessCount < maxGuesses)
		{

			// Simulate the next guess
			while (guess.size() < 4)
			{
				uniqueDigit = RandomNumber(0, 9);

				// Check if the digit is already in the guess vector
				if (find(guess.begin(), guess.end(), uniqueDigit) == guess.end())
				{
					// Add the unique digit to the guess vector
					guess.push_back(uniqueDigit);
				}
			}
		}

		// Cheat and "guess" the correct answer
		else { guess = numbers; }

		// Print a blank line for better readability between guesses
		println();
	}
}

void BookExercises::Chapter4::Exercise14()
{
	// Valid days of the week wit common abbreviations
	const vector<string_view> validDays = {
		"monday",
		"tuesday",
		"wednesday",
		"thursday",
		"friday",
		"saturday",
		"sunday",
		"mon",
		"tue",
		"wed",
		"thu",
		"fri",
		"sat",
		"sun"
	};

	// Simulate user input (with some invalid entries)
	vector<string_view> daysInput
	{
		"Monday",
		"tuesday",
		"Funday",
		"Wed",
		"Thurs",
		"Friday",
		"Saturday",
		"Sun"
	};

	// Simulate user input
	const vector<int> valueInput
	{
		1,
		2,
		3,
		4,
		5,
		6,
		7,
		8
	};

	// Variable to hold the sum of valid values and count of invalid days
	int sum { 0 };
	unsigned int invalidCount { 0u };


	// Loop through the user input and validate each day
	for (size_t i { 0u }; i < daysInput.size(); ++i)
	{
		// Check if the current day is valid
		if (find(validDays.begin(), validDays.end(), StringToLower(daysInput[i])) != validDays.end())
		{
			// Valid day, add the corresponding value to the sum
			sum += valueInput[i];
		}

		// Invalid day, increment the invalid count and print a warning
		else { ++invalidCount; }
	}

	// Print the user input for days and values
	println("User Input Days: {}", daysInput);
	println("User Input Values: {}", valueInput);

	// Print a blank line for better readability
	println();

	// Print the results
	println("Sum of valid values: {}", sum);
	println("Number of invalid days: {}", invalidCount);
}

void BookExercises::Chapter4::WholeChapter()
{
	// Vector of function pointers
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
		Exercise11,
		Exercise12,
		Exercise13,
		Exercise14
	};

	// Call each function in the vector
	CallFunctionsWithHeader("Exercise", exerciseFunctions);
}
