#include "Chapter5.h"

#include "Calculator.h"
#include "Utilities.h"

#include <print>

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
	string_view input{ "{(4+5)*6} / (3+4)" };

	Calculator::Chapter5::Lexer lexer{ input };
	Calculator::Chapter5::TokenStream stream;

	lexer.GetTokens(stream);
}

void BookExercises::Chapter5::Exercise3()
{

}

void BookExercises::Chapter5::Exercise4()
{

}

void BookExercises::Chapter5::Exercise5()
{

}

void BookExercises::Chapter5::Exercise6()
{

}

void BookExercises::Chapter5::Exercise7()
{

}

void BookExercises::Chapter5::Exercise8()
{

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
