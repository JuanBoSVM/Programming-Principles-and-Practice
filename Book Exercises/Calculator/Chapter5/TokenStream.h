#pragma once

#include "Token.h"

#include <vector>

namespace Calculator::Chapter5
{
	using Calculator::Chapter5::Token;

	class TokenStream
	{
	public:

		Token Get();
		Token Peek() const;

		void Putback(const Token& token);
		void Ignore(const Token::Type type);

		void Clear();

	private:

		std::vector<Token> m_Data;
	};
}