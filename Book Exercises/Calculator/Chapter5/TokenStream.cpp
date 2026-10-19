#include "TokenStream.h"
#include "Lexer.h"

Calculator::Chapter5::TokenStream::TokenStream(std::string_view str) : m_RawData(str)
{
	Lexer lexer;
	lexer.Tokenize(*this, str);
}

Calculator::Chapter5::Token Calculator::Chapter5::TokenStream::Get()
{

}

Calculator::Chapter5::Token Calculator::Chapter5::TokenStream::Peek() const
{

}

Calculator::Chapter5::TokenStream::TokenStream Calculator::Chapter5::TokenStream::Putback(const Token& token)
{

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
