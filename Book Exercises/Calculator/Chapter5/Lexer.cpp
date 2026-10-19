#include "Lexer.h"

#include <string>


void Calculator::Chapter5::Lexer::Tokenize(TokenStream& stream, std::string_view input)
{
	using std::string;

	string tokenBuffer;
	size_t tokenStartPosition { 0u };

	for (size_t i { 0u }; i < input.length(); ++i)
	{
		stream << ParseToken(input, i);
	}
}

Calculator::Chapter5::Token Calculator::Chapter5::Lexer::ParseToken(std::string_view input, size_t& pos)
{

}

Calculator::Chapter5::Token Calculator::Chapter5::Lexer::TokenizeNumber(std::string_view number)
{

}

Calculator::Chapter5::Token Calculator::Chapter5::Lexer::TokenizeInteger(std::string_view number)
{

}

Calculator::Chapter5::Token Calculator::Chapter5::Lexer::TokenizeFloatingPoint(std::string_view number)
{

}

Calculator::Chapter5::Token Calculator::Chapter5::Lexer::TokenizeOperator(char op)
{

}

Calculator::Chapter5::Token Calculator::Chapter5::Lexer::TokenizeParenthesis(char paren)
{

}

Calculator::Chapter5::Token Calculator::Chapter5::Lexer::TokenizeAssign()
{

}

Calculator::Chapter5::Token Calculator::Chapter5::Lexer::TokenizeExecute()
{

}
