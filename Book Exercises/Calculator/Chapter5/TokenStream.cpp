#include "TokenStream.h"
#include "Lexer.h"

Program::Chapter5::TokenStream::TokenStream(std::string_view str)
	: m_RawData(str)
{
	Lexer lexer{ m_RawData };
	lexer.GetTokens(*this, str);
}

Program::Chapter5::Token Program::Chapter5::TokenStream::Get()
{
	if (m_Data.empty()) { return Token::Type::Invalid; }

	Token nextToken{ m_Data.front() };
	m_Data.erase(m_Data.begin());

	return nextToken;
}

Program::Chapter5::Token Program::Chapter5::TokenStream::Peek() const
{
	if (m_Data.empty()) { return Token::Type::Invalid; }

	return m_Data.front();
}

Program::Chapter5::TokenStream& Program::Chapter5::TokenStream::Putback(const Token& token)
{
	m_Data.insert(m_Data.begin(), token);

	return *this;
}

void Program::Chapter5::TokenStream::Ignore()
{
	if (m_Data.empty()) { return; }

	m_Data.erase(m_Data.begin());
}

void Program::Chapter5::TokenStream::Clear()
{
	m_Data.clear();
}

Program::Chapter5::TokenStream& Program::Chapter5::TokenStream::operator<<(const Token& token)
{
	return Putback(token);
}

Program::Chapter5::TokenStream& Program::Chapter5::TokenStream::operator<<(const std::vector<Token>& tokens)
{
	m_Data = tokens;

	return *this;
}
