#include "Lexer.h"

#include <string>


void Calculator::Chapter5::Lexer::Tokenize(TokenStream& stream, std::string_view input)
{

	for (size_t i{ 0u }; i < input.length(); ++i)
	{
		stream << ParseToken(input, i);
	}
}

Calculator::Chapter5::Token Calculator::Chapter5::Lexer::ParseToken(std::string_view input, size_t& pos)
{
	using std::string;
	using enum Token::Type;

	Token tokenBuffer;
	size_t tokenStartPosition{ pos };
	size_t tokenEndPosition{ pos };

	if (char startChar{ input[pos] }; isdigit(startChar)) { tokenBuffer.SetType(Number); }
	else if (IsOperator(startChar)) { tokenBuffer.SetType(Operator); }
	else if (IsStartOfParenthesis(startChar)) { tokenBuffer.SetType(StartParenthesis); }
	else if (IsEndOfParenthesis(startChar)) { tokenBuffer.SetType(EndParenthesis); }
	else if (startChar == '=') { tokenBuffer.SetType(Assign); }
	else if (startChar == ';') { tokenBuffer.SetType(Execute); }

	for (size_t i{ 0u }; i < input.length(); ++i)
	{
		if (IsEndofToken(tokenBuffer.GetType(), input[i]))
		{
			tokenEndPosition = i;
			break;
		}
	}

	switch (tokenBuffer.GetType())
	{
	case Token::Type::Invalid:
		break;
	case Token::Type::Empty:
		break;
	case Token::Type::Number:
		break;
	case Token::Type::Integer:
		break;
	case Token::Type::FloatingPoint:
		break;
	case Token::Type::Operator:
		break;
	case Token::Type::StartParenthesis:
		break;
	case Token::Type::EndParenthesis:
		break;
	case Token::Type::Execute:
		break;
	case Token::Type::Assign:
		break;
	case Token::Type::End:
		break;
	default:
		break;
	}
}

bool Calculator::Chapter5::Lexer::IsEndofToken(Token::Type type, char c) const
{
	using enum Token::Type;
	using std::string;

	switch (type)
	{
	case Integer:
		return !isdigit(c) && c != ',';

	case FloatingPoint:
		return !isdigit(c) && c != '.' && c != ',';

	case Operator:
		return string("+-*/!^").contains(c);

	case StartParenthesis:
		return string("({[").contains(c);

	case EndParenthesis:
		return string(")}]").contains(c);

	case Assign:
		return c != '=';

	case Execute:
		return c != ';';

	default:
		return true;
	}
}

void Calculator::Chapter5::Lexer::TokenizeNumber(Token& token, std::string_view value)
{

}

void Calculator::Chapter5::Lexer::TokenizeInteger(Token& token, std::string_view value)
{

}

void Calculator::Chapter5::Lexer::TokenizeFloatingPoint(Token& token, std::string_view value)
{

}

void Calculator::Chapter5::Lexer::TokenizeOperator(Token& token, char value)
{

}

void Calculator::Chapter5::Lexer::TokenizeParenthesis(Token& token, char value)
{

}

void Calculator::Chapter5::Lexer::TokenizeAssign(Token& token, char value)
{

}

void Calculator::Chapter5::Lexer::TokenizeExecute(Token& token, char value)
{

}

bool Calculator::Chapter5::Lexer::IsOperator(char c) const
{
	return std::string("+-*/!^").contains(c);
}

bool Calculator::Chapter5::Lexer::IsStartOfParenthesis(char c) const
{
	return std::string("({[").contains(c);
}

bool Calculator::Chapter5::Lexer::IsEndOfParenthesis(char c) const
{
	return std::string(")}]").contains(c);
}
