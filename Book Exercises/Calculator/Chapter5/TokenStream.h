#pragma once

#include "Token.h"

#include <vector>
#include <string_view>

namespace Program::Chapter5
{
	using Program::Chapter5::Token;

	class TokenStream
	{
	public:

		TokenStream() = default;
		~TokenStream() = default;

		TokenStream(std::string_view str);

		TokenStream(const TokenStream&) = delete;
		TokenStream& operator=(const TokenStream&) = delete;

		TokenStream(TokenStream&&) = delete;
		TokenStream& operator=(TokenStream&&) = delete;

	public:

		Token Get();
		Token Peek() const;

		TokenStream& Putback(const Token& token);
		void Ignore(const Token::Type type);

		void Clear();

	private:

		std::string_view m_RawData;
		std::vector<Token> m_Data;
	};

	TokenStream& operator<< (TokenStream& stream, const Token& token);
	TokenStream& operator<< (TokenStream& stream, const std::vector<Token>& tokens);
}