#include "Lexer.h"

#include <string>


Calculator::Chapter5::Lexer::Lexer(std::string_view str)
	: m_Input(str)
{
	CleanInput();
}

void Calculator::Chapter5::Lexer::GetTokens(TokenStream& stream)
{
	m_Tokens.clear();
	m_Tokens.reserve(m_Input.length());

	Tokenize();

	stream << m_Tokens;
}

void Calculator::Chapter5::Lexer::GetTokens(TokenStream& stream, std::string_view str)
{
	AssignInput(str);

	GetTokens(stream);
}

void Calculator::Chapter5::Lexer::AssignInput(std::string_view str)
{
	m_Input = str;
	CleanInput();
}

void Calculator::Chapter5::Lexer::CleanInput()
{
	m_Input.erase(std::remove_if(m_Input.begin(), m_Input.end(), [](char c) { return std::isspace(c); }), m_Input.end());
}

void Calculator::Chapter5::Lexer::Tokenize()
{
	using enum Token::Type;

	if (m_Input.empty())
	{
		m_Tokens.emplace_back(End, "");
		return;
	}

	for (size_t i{ 0u }; i < m_Input.length(); ++i)
	{
		m_Tokens.emplace_back(ParseToken(i));
	}

	if (m_Tokens.back().GetType() != Execute) { m_Tokens.emplace_back(End, ""); }
}

Calculator::Chapter5::Token Calculator::Chapter5::Lexer::ParseToken(size_t& pos) const
{
	using enum Token::Type;

	Token tokenBuffer;
	size_t tokenStartPosition{ pos };
	size_t tokenEndPosition{ 0ULL };

	tokenBuffer.SetTypeFromChar(m_Input[pos]);

	tokenEndPosition = FindTokenEndPosition(pos, tokenBuffer);

	std::string tokenValue{ m_Input.substr(tokenStartPosition, tokenEndPosition - tokenStartPosition + 1) };

	if (tokenBuffer.GetType() == Number)
	{
		if (tokenValue.contains('.')) { tokenBuffer.SetType(FloatingPoint); }
		else { tokenBuffer.SetType(Integer); }
	}

	tokenBuffer.SetValue(tokenValue);

	return tokenBuffer;
}

int Calculator::Chapter5::Lexer::FindTokenEndPosition(size_t& pos, const Token& tokenBuffer) const
{
	constexpr int errorPosition{ -1 };

	for (size_t i{ pos + 1ULL }; i < m_Input.length(); ++i)
	{
		if (IsEndofToken(tokenBuffer.GetType(), m_Input[i]))
		{
			pos = i - 1ULL;
			return static_cast<int>(i - 1ULL);
		}
	}

	return errorPosition;
}

bool Calculator::Chapter5::Lexer::IsEndofToken(Token::Type type, char c) const
{
	using enum Token::Type;
	using std::string;

	switch (type)
	{
	case Integer:
		return !isdigit(c) && c != ',';

	case Number:
	case FloatingPoint:
		return !isdigit(c) && c != '.' && c != ',';

	case Addition:
	case Subtraction:
	case Multiplication:
	case Division:
	case Exponentiation:
	case Factorial:
	case StartParenthesis:
	case EndParenthesis:
	case Assign:
	case Execute:
	default:
		return true;
	}
}
