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
	return {};
}

Program::Chapter5::Token Program::Chapter5::TokenStream::Peek() const
{
	return {};
}

Program::Chapter5::TokenStream& Program::Chapter5::TokenStream::Putback(const Token& token)
{
	return *this;
}

void Program::Chapter5::TokenStream::Ignore(const Token::Type type)
{

}

void Program::Chapter5::TokenStream::Clear()
{

}

Program::Chapter5::TokenStream& Program::Chapter5::operator<<(TokenStream& stream, const Token& token)
{
	return stream.Putback(token);
}

Program::Chapter5::TokenStream& Program::Chapter5::operator<<(TokenStream& stream, const std::vector<Token>& tokens)
{
	for (const auto& token : tokens)
	{
		stream << token;
	}

	return stream;
}
