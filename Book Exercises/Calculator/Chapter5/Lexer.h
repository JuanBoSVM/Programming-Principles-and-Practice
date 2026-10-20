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

		void TokenizeNumber(Token& token, std::string_view value);

		void TokenizeInteger(Token& token, std::string_view value);

		void TokenizeFloatingPoint(Token& token, std::string_view value);

		void TokenizeOperator(Token& token, char value);

		void TokenizeParenthesis(Token& token, char value);

		void TokenizeAssign(Token& token, char value);

		void TokenizeExecute(Token& token, char value);

		bool IsOperator(char c) const;

		bool IsStartOfParenthesis(char c) const;

		bool IsEndOfParenthesis(char c) const;

		bool IsEndofToken(Token::Type type, char c) const;
	};
}