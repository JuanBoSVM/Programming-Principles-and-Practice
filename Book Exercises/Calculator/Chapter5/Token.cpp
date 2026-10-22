#include "Token.h"

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

bool Program::Chapter5::ParenthesisMatch(const Token& left, const Token& right)
{
	return (left.GetType() == Token::Type::StartParenthesis && right.GetType() == Token::Type::EndParenthesis) ||
		(left.GetType() == Token::Type::StartCurlyBrace && right.GetType() == Token::Type::EndCurlyBrace) ||
		(left.GetType() == Token::Type::StartSquareBracket && right.GetType() == Token::Type::EndSquareBracket);
}
