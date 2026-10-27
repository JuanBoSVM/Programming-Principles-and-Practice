#pragma once

#include <string_view>

#include "Token.h"
#include "TokenStream.h"
#include "Lexer.h"

namespace Program::Chapter5
{
	class Calculator
	{
	public:

		Calculator() = default;
		~Calculator() = default;

		Calculator(const Calculator&) = delete;
		Calculator& operator=(const Calculator&) = delete;

		Calculator(Calculator&&) = delete;
		Calculator& operator=(Calculator&&) = delete;

	public:

		double Calculate(std::string_view str);
		double Calculate(TokenStream& stream);

	private:

		double Calculate();
		double CalculateTerm();
		double CalculatePower();
		double CalculatePrimary();

	private:

		TokenStream m_TokenStream;
	};
}