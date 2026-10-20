#include "TokenStream.h"
#include "Lexer.h"

Calculator::Chapter5::TokenStream::TokenStream(std::string_view str)
	: m_RawData(str)
{
	Lexer lexer{ m_RawData };
	lexer.GetTokens(*this, str);
}

Calculator::Chapter5::Token Calculator::Chapter5::TokenStream::Get()
{
	return {};
}

Calculator::Chapter5::Token Calculator::Chapter5::TokenStream::Peek() const
{
	return {};
}

Calculator::Chapter5::TokenStream& Calculator::Chapter5::TokenStream::Putback(const Token& token)
{
	return *this;
}

void Calculator::Chapter5::TokenStream::Ignore(const Token::Type type)
{

}

void Calculator::Chapter5::TokenStream::Clear()
{

}

Calculator::Chapter5::TokenStream& Calculator::Chapter5::operator<<(TokenStream& stream, const Token& token)
{
	return stream.Putback(token);
}

Calculator::Chapter5::TokenStream& Calculator::Chapter5::operator<<(TokenStream& stream, const std::vector<Token>& tokens)
{
	for (const auto& token : tokens)
	{
		stream << token;
	}

	return stream;
}
