#include "Parser.h"

#include <string>


Program::Chapter5::Parser::Parser(std::string_view str)
	: m_Input(str)
{
	CleanInput();
}

void Program::Chapter5::Parser::GetTokens(TokenStream& stream)
{
	m_Tokens.clear();
	m_Tokens.reserve(m_Input.length());

	Tokenize();

	stream << m_Tokens;
}

void Program::Chapter5::Parser::GetTokens(TokenStream& stream, std::string_view str)
{
	AssignInput(str);

	GetTokens(stream);
}

void Program::Chapter5::Parser::AssignInput(std::string_view str)
{
	m_Input = str;
	CleanInput();
}

void Program::Chapter5::Parser::CleanInput()
{
	m_Input.erase(std::remove_if(m_Input.begin(), m_Input.end(), [](char c) { return std::isspace(c); }), m_Input.end());
}

void Program::Chapter5::Parser::Tokenize()
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

Program::Chapter5::Token Program::Chapter5::Parser::ParseToken(size_t& pos) const
{
	using enum Token::Type;

	Token tokenBuffer;
	size_t tokenStartPosition{ pos };
	size_t tokenEndPosition{ 0ULL };

	tokenBuffer.SetTypeFromChar(m_Input[pos]);

	tokenEndPosition = FindTokenEndPosition(pos, tokenBuffer);

	std::string tokenValue{ m_Input.substr(tokenStartPosition, tokenEndPosition - tokenStartPosition + 1) };

	tokenBuffer.SetValue(tokenValue);

	return tokenBuffer;
}

int Program::Chapter5::Parser::FindTokenEndPosition(size_t& pos, const Token& tokenBuffer) const
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

bool Program::Chapter5::Parser::IsEndofToken(Token::Type type, char c) const
{
	using enum Token::Type;

	if (type == Number) { return !isdigit(c) && c != '.' && c != ','; }

	return true;
}
