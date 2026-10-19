#pragma once

#include "Token.h"
#include "TokenStream.h"

namespace Calculator::Chapter5
{
	class Lexer
	{
	public:
		Lexer() = default;
		~Lexer() = default;

		Lexer(const Lexer&) = delete;
		Lexer& operator=(const Lexer&) = delete;

		Lexer(Lexer&&) = delete;
		Lexer& operator=(Lexer&&) = delete;

	public:

		void Tokenize(TokenStream& stream, std::string_view input);

	private:

		Token ParseToken(std::string_view input, size_t& pos);

		Token TokenizeNumber(std::string_view number);

		Token TokenizeInteger(std::string_view number);

		Token TokenizeFloatingPoint(std::string_view number);

		Token TokenizeOperator(char op);

		Token TokenizeParenthesis(char paren);

		Token TokenizeAssign();

		Token TokenizeExecute();

	};
}