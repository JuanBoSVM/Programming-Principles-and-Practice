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
	int num;

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
		// Print the count of numbers to be summed
		print("Sum of the first {} numbers ( ", count);

		// Loop through the numbers
		for (unsigned int i { 0u }; i < count; ++i)
		{
			// Add the current number to the sum
			sum += numbers[i];

			// Print the current number
			print("{} ", numbers[i]);
		}

		// Print the sum of the numbers
		println(") = {}", sum);
	}
}

void BookExercises::Chapter4::Exercise9()
{

}

void BookExercises::Chapter4::Exercise10()
{

}

void BookExercises::Chapter4::Exercise11()
{

}

void BookExercises::Chapter4::Exercise12()
{

}

void BookExercises::Chapter4::Exercise13()
{

}

void BookExercises::Chapter4::Exercise14()
{

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
