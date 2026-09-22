#include <iostream>
#include <string_view>
#include <print>
#include <format>
#include <vector>
#include <functional>

#include "Chapter1.h"
#include "Utilities.h"

using std::print;
using std::println;
using std::cin;
using std::vector;
using std::string_view;
using std::function;
using std::format;

void BookExercises::Chapter1::Exercise1()
{
	println("Hello, programming!");
	println("Here we go!");
}

void BookExercises::Chapter1::Exercise2()
{
	// Store the instructions for Exercise 2 in a vector of string_views
	const vector<string_view> instructions =
	{
		"Start by facing the stairs",
		"Step onto the next step with both feet until you reach the top",
		"Walk five steps forward",
		"Turn right ninety degrees",
		"Walk five steps forward",
		"The bathroom is on your left"
	};

	// Store the assumptions for Exercise 2 in a vector of string_views
	const vector<string_view> assumptions =
	{
		"You are currently facing the stairs",
		"There are no obstacles in your way",
		"You are able to walk and turn without assistance",
		"The stairs are safe to climb",
		"The bathroom is accessible and unlocked",
		"You know how to step up and down stairs safely",
		"You know how to turn and walk in a straight line",
		"You can open and close doors if necessary"
	};

	// Print the assumptions for the exercise
	println("Assumptions:");
	println();

	// Loop through the assumptions and print each one
	for (size_t i { 0u }; i < assumptions.size(); ++i)
	{
		println("{}.- {}", i + 1u, assumptions[i]);
	}


	// Print the instructions for the exercise
	println();
	println("Instructions:");
	println();

	// Loop through the instructions and print each one
	for (size_t i { 0u }; i < instructions.size(); ++i)
	{
		println("{}.- {}", i + 1u, instructions[i]);
	}

	// Print a blank line after the exercise output
	println("");
}

void BookExercises::Chapter1::Exercise3()
{
	// Store the instructions for Exercise 3 in a vector of string_views
	const vector<string_view> instructions =
	{
		"Open the door",
		"Walk through the door",
		"Walk three steps forward",
		"Turn left",
		"Go down eight steps",
		"Turn right",
		"Go down two steps",
		"Turn right",
		"Go down eight steps",
		"Walk five steps forward",
		"Turn left",
		"Walk five steps forward",
		"Turn left",
		"The kitchen is in front of you"
	};

	// Print the instructions for the exercise
	println("How to get to the kitchen:");
	println();

	// Loop through the instructions and print each one
	for (size_t i { 0u }; i < instructions.size(); ++i)
	{
		println("{}.- {}", i + 1u, instructions[i]);
	};

	// Print a blank line after the exercise output
	println("");
}

void BookExercises::Chapter1::Exercise4()
{
	// Store the instructions for baking blueberry muffins in a vector of string_views
	const vector<string_view> instructions =
	{
		"Preheat the oven to 425 degrees Fahrenheit (220 degrees Celsius)",
		"Place an oven rack slightly above the center of the oven",
		"Lightly spray a 12-cup muffin pan with cooking spray",
		"Put 1/3 cup of sugar into a small bowl",
		"Grate 1 1/2 teaspoons of lemon zest into the sugar",
		"Mix the sugar and lemon zest together with a spoon",
		"Divide 2 cups of blueberries into two equal portions",
		"Put 1 cup of blueberries and 1 teaspoon of sugar into a small saucepan",
		"Cook the blueberries over medium heat",
		"Stir the blueberries frequently with a spoon",
		"Press some of the blueberries with the spoon to break them open",
		"Continue cooking the blueberries for about 6 minutes",
		"Cook the blueberries until the mixture becomes thick and is reduced to about 1/4 cup",
		"Transfer the cooked blueberries to a small bowl",
		"Let the cooked blueberries cool for about 10 to 15 minutes",
		"Put 2 1/2 cups of all-purpose flour into a large bowl",
		"Add 2 1/2 teaspoons of baking powder to the flour",
		"Add 1 teaspoon of salt to the flour",
		"Whisk the flour, baking powder, and salt together",
		"Put 2 large eggs into a medium bowl",
		"Add 1 1/8 cups of sugar to the eggs",
		"Whisk the eggs and sugar together for about 45 seconds",
		"Melt 4 tablespoons of unsalted butter",
		"Let the melted butter cool slightly",
		"Slowly add the melted butter to the egg and sugar mixture while whisking",
		"Add 1/4 cup of vegetable oil to the mixture",
		"Whisk until the butter and oil are combined with the other ingredients",
		"Add 1 cup of buttermilk",
		"Add 1 1/2 teaspoons of vanilla extract",
		"Whisk the wet ingredients together",
		"Pour the wet ingredients into the bowl containing the dry ingredients",
		"Add the remaining 1 cup of blueberries",
		"Gently fold the ingredients together with a rubber spatula",
		"Stop mixing when the flour has been incorporated and the batter is still slightly lumpy",
		"Divide the batter evenly between the 12 cups of the muffin pan",
		"Place about 1 teaspoon of the cooked blueberry mixture on top of each muffin",
		"Insert a toothpick into the center of each muffin",
		"Move the toothpick in a small figure-eight pattern to create a blueberry swirl",
		"Sprinkle the lemon sugar evenly over the muffins",
		"Put on oven mitts before handling the hot muffin pan",
		"Place the muffin pan on the oven rack",
		"Close the oven door",
		"Set a timer for 17 minutes",
		"Rotate the muffin pan halfway through the baking time",
		"Check the muffins after about 17 minutes",
		"Insert a clean toothpick into the center of one muffin",
		"Remove the toothpick and check for wet batter",
		"Bake the muffins for a few more minutes if wet batter is still on the toothpick",
		"Put on oven mitts before removing the muffin pan",
		"Remove the muffin pan from the oven",
		"Place the hot muffin pan on a heat-resistant surface",
		"Let the muffins cool in the pan for 5 minutes",
		"Carefully remove the muffins from the pan",
		"Place the muffins on a cooling rack",
		"Let the muffins cool for another 5 minutes",
		"Serve the blueberry muffins"
	};

	println("How to bake blueberry muffins (By ChatGPT):");
	println();

	for (size_t i { 0u }; i < instructions.size(); ++i)
	{
		println("{}.- {}", i + 1u, instructions[i]);
	}

	println("");
}

void BookExercises::Chapter1::Exercise5()
{
	// Store the concepts in a vector of string_views
	const vector<string_view> concepts =
	{
		"//",
		"executable",
		"main()",
		"<<",
		"function",
		"object code",
		"C++",
		"header file",
		"output",
		"comment",
		"IDE",
		"program",
		"compiler",
		"import",
		"source code",
		"compile-time",
		"error",
		"library",
		"statement",
		"cout",
		"linker",
		"module",
		"#include",
		"std",
		"command line",
		"bug",
		"debugging"
	};

	// Store the definitions in a vector of string_views
	// Each definition has the same ID as its corresponding concept
	const vector<string_view> definitions =
	{
		"Symbols used to begin a single-line comment. Everything after them on the same line is ignored by the compiler.",
		"A program file that is ready to be run by the operating system.",
		"The function where execution of a C++ program normally begins.",
		"The insertion operator used with output streams such as cout to send data to the stream.",
		"A reusable block of code designed to perform a specific task. It can receive input and return a result.",
		"The machine code produced from source code by a compiler before it is combined with other object code.",
		"A general-purpose programming language commonly used for applications, games, and systems software.",
		"A file containing declarations and other information that can be included in a C++ source file.",
		"Information produced by a program and displayed, stored, or sent somewhere as a result of the program running.",
		"Text written in source code to explain something to a programmer. Comments are ignored by the compiler.",
		"An Integrated Development Environment. A software application that provides tools for writing, compiling, running, and debugging programs.",
		"A set of instructions written to make a computer perform a particular task.",
		"A program that translates C++ source code into a lower-level form that the computer can use.",
		"A mechanism used in some programming languages to bring functionality or code from another file or module into a program.",
		"The human-readable instructions written by a programmer in a programming language such as C++.",
		"The stage when the compiler is translating and checking source code before the program is run.",
		"A problem detected while writing, compiling, or running a program that prevents it from working as intended.",
		"A collection of reusable code, functions, classes, or other resources that can be used by other programs.",
		"A single instruction in a program, usually ending with a semicolon in C++.",
		"The standard C++ output stream used to send text and other data to the console.",
		"A program that combines object code and libraries to create a final executable program.",
		"A self-contained unit of code that can be developed, compiled, and sometimes reused independently.",
		"A preprocessor directive that tells the compiler to include the contents of a specified header file.",
		"The C++ standard namespace containing many of the language's standard library features.",
		"A text-based interface where commands are entered directly for a computer to execute.",
		"A mistake or defect in a program that causes it to behave incorrectly or unexpectedly.",
		"The process of finding, understanding, and fixing bugs in a program."
	};

	// Loop through the concepts and definitions and print each one
	for (size_t i { 0u }; i < concepts.size(); ++i)
	{
		println("{}.- {}: {}", i + 1u, concepts[i], definitions[i]);
		println();
	}
}

void BookExercises::Chapter1::WholeChapter()
{
	// Store a pointer to the functions in a vector
	const vector<function<void()>> exercises =
	{
		BookExercises::Chapter1::Exercise1,
		BookExercises::Chapter1::Exercise2,
		BookExercises::Chapter1::Exercise3,
		BookExercises::Chapter1::Exercise4,
		BookExercises::Chapter1::Exercise5
	};

	// Loop through the vector and call each function
	CallFunctionsWithHeader("Exercise", exercises);
}