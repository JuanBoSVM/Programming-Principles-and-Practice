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

		TokenStream(const TokenStream&) = default;
		TokenStream& operator=(const TokenStream&) = default;

		TokenStream(TokenStream&&) = default;
		TokenStream& operator=(TokenStream&&) = default;

	public:

		Token Get();
		Token Peek() const;

		TokenStream& Putback(const Token& token);
		void Ignore();

		void Clear();

		TokenStream& operator<< (const Token& token);
		TokenStream& operator<< (const std::vector<Token>& tokens);

	private:

		std::string_view m_RawData;
		std::vector<Token> m_Data;
	};
}