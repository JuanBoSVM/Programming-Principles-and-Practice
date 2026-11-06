#include "Lexer.h"

#include <cctype>
#include <string>

Program::Chapter5::Lexer::Lexer(std::string_view str)
	: m_Input(str)
{
	CleanInput();
}

void Program::Chapter5::Lexer::GetTokens(TokenStream& stream)
{
	m_Tokens.clear();
	m_Tokens.reserve(m_Input.length());

	Tokenize();

	stream << m_Tokens;
}

void Program::Chapter5::Lexer::GetTokens(TokenStream& stream, std::string_view str)
{
	AssignInput(str);

	GetTokens(stream);
}

void Program::Chapter5::Lexer::AssignInput(std::string_view str)
{
	m_Input = str;
	CleanInput();
}

void Program::Chapter5::Lexer::CleanInput()
{
	m_Input.erase(std::remove_if(m_Input.begin(), m_Input.end(), [](char c) { return std::isspace(c); }), m_Input.end());
}

void Program::Chapter5::Lexer::Tokenize()
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

Program::Chapter5::Token Program::Chapter5::Lexer::ParseToken(size_t& pos) const
{
	Token tokenBuffer;
	const size_t tokenStartPosition{ pos };

	tokenBuffer.SetTypeFromChar(m_Input[tokenStartPosition]);
	const int tokenEndPosition{ FindTokenEndPosition(pos, tokenBuffer) };
	tokenBuffer.SetValue(m_Input.substr(tokenStartPosition, static_cast<size_t>(tokenEndPosition) - tokenStartPosition + 1ULL));

	return tokenBuffer;
}

int Program::Chapter5::Lexer::FindTokenEndPosition(size_t& pos, const Token& tokenBuffer) const
{
	const bool isNumber{ std::isdigit(static_cast<unsigned char>(m_Input[pos])) != 0 };

	if (!isNumber)
	{
		return static_cast<int>(pos);
	}

	for (size_t i{ pos + 1ULL }; i < m_Input.length(); ++i)
	{
		if (IsEndofToken(tokenBuffer.GetType(), m_Input[i]))
		{
			pos = i - 1ULL;
			return static_cast<int>(pos);
		}
	}

	pos = m_Input.length() - 1ULL;
	return static_cast<int>(pos);
}

bool Program::Chapter5::Lexer::IsEndofToken(Token::Type type, char c) const
{
	using enum Token::Type;

	if (type == Number) { return !std::isdigit(static_cast<unsigned char>(c)) && c != '.' && c != ','; }

	return true;
}
