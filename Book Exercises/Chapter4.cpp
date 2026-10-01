#include "Chapter4.h"

#include <functional>
#include <print>
#include <vector>
#include <string>
#include <string_view>

#include "Utilities.h"

using std::print;
using std::println;
using std::function;
using std::vector;
using std::string;
using std::string_view;

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

}

void BookExercises::Chapter4::Exercise3()
{

}

void BookExercises::Chapter4::Exercise4()
{

}

void BookExercises::Chapter4::Exercise5()
{

}

void BookExercises::Chapter4::Exercise6()
{

}

void BookExercises::Chapter4::Exercise7()
{

}

void BookExercises::Chapter4::Exercise8()
{

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
