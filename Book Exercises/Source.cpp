#include <iostream>
#include <functional>
#include <vector>
#include <format>
#include <print>

#include "Utilities.h"
#include "BookChapters.h"

using std::vector;
using std::function;
using std::format;
using std::print;
using std::println;
using std::cin;

int main()
{
	// Variable to hold the chapter number to run
	unsigned int chapterNumber { 1u };

	// Vector of function pointers to chapter functions
	const vector<function<void()>> chapters =
	{
		BookExercises::Chapter1::WholeChapter,
		BookExercises::Chapter2::WholeChapter,
		BookExercises::Chapter3::WholeChapter
	};

	// Print the header for the book exercises
	PrintHeader("Book Exercises", '=');

	while (chapterNumber != 0)
	{
		// Prompt the user to select a chapter
		print("Please select a chapter to run ( 1 - {} ) or 0 to exit: ", chapters.size());

		// Read the user's input
		cin >> chapterNumber;

		// Validate the input and run the selected chapter
		while (chapterNumber > chapters.size() || cin.fail())
		{
			// Clear the error state of cin and ignore the rest of the line
			CleanInputStream();

			// Prompt the user to select a valid chapter number
			print("Invalid chapter number. Please select a chapter between 1 and {}: ", chapters.size());

			// Read the user's input again
			cin >> chapterNumber;
		}

		// Run the selected chapter if the user did not choose to exit
		if (chapterNumber != 0)
		{
			// Print the header for the selected chapter
			PrintHeader(format("Chapter {}", chapterNumber));

			// Run the selected chapter
			chapters[chapterNumber - 1]();
		}
	}

	return 0;
}