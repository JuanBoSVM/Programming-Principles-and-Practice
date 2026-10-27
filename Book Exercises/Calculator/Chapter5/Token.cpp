#include "Token.h"

Program::Chapter5::Token::Token(Type type)
	: m_Type(type)
{}

Program::Chapter5::Token::Token(Type type, std::string_view value)
	: m_Type(type), m_Value(value)
{}

void Program::Chapter5::Token::SetTypeFromChar(char c)
{
	using enum Type;

	if (isdigit(c)) { m_Type = Number; }
	else if (c == '+') { m_Type = Addition; }
	else if (c == '-') { m_Type = Subtraction; }
	else if (c == '*') { m_Type = Multiplication; }
	else if (c == '/') { m_Type = Division; }
	else if (c == '^') { m_Type = Exponentiation; }
	else if (c == '!') { m_Type = Factorial; }
	else if (c == '(') { m_Type = StartParenthesis; }
	else if (c == '{') { m_Type = StartCurlyBrace; }
	else if (c == '[') { m_Type = StartSquareBracket; }
	else if (c == ')') { m_Type = EndParenthesis; }
	else if (c == '}') { m_Type = EndCurlyBrace; }
	else if (c == ']') { m_Type = EndSquareBracket; }
	else if (c == '=') { m_Type = Assign; }
	else if (c == ';') { m_Type = Execute; }
	else { m_Type = Invalid; }
}

bool Program::Chapter5::Token::IsStartParenthesis() const
{
	switch (m_Type)
	{
	case Type::StartParenthesis:
	case Type::StartCurlyBrace:
	case Type::StartSquareBracket:
		return true;

	default:
		return false;
	}
}

bool Program::Chapter5::Token::IsEndParenthesis() const
{
	switch (m_Type)
	{
	case Type::EndParenthesis:
	case Type::EndCurlyBrace:
	case Type::EndSquareBracket:
		return true;

	default:
		return false;
	}
}

bool Program::Chapter5::Token::ParenthesisMatch(const Token& other) const
{
	switch (m_Type)
	{
	case Type::StartParenthesis:
		return other.m_Type == Type::EndParenthesis;

	case Type::StartCurlyBrace:
		return other.m_Type == Type::EndCurlyBrace;

	case Type::StartSquareBracket:
		return other.m_Type == Type::EndSquareBracket;

	default:
		return false;
	}
}
