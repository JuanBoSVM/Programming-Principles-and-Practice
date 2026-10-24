#pragma once

#include <string_view>
#include <vector>

#include "Token.h"
#include "TokenStream.h"

namespace Program::Chapter5
{
	class Parser
	{
	public:
		Parser() = default;
		~Parser() = default;

		Parser(std::string_view str);

		Parser(const Parser&) = delete;
		Parser& operator=(const Parser&) = delete;

		Parser(Parser&&) = delete;
		Parser& operator=(Parser&&) = delete;

	public:

		void GetTokens(TokenStream& stream);
		void GetTokens(TokenStream& stream, std::string_view str);

		inline const std::vector<Token>& GetTokens() const { return m_Tokens; }

	private:

		void AssignInput(std::string_view str);

		void CleanInput();

		void Tokenize();

		Token ParseToken(size_t& pos) const;

		int FindTokenEndPosition(size_t& pos, const Token& tokenBuffer) const;

		bool IsEndofToken(Token::Type type, char c) const;

	private:

		std::string m_Input;
		std::vector<Token> m_Tokens;
	};
}