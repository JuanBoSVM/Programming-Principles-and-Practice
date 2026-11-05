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

		unsigned int CalculatePermutation(unsigned int n, unsigned int r) const;
		unsigned int CalculateCombination(unsigned int n, unsigned int r) const;

	private:

		double Calculate();
		double CalculateTerm();
		double CalculatePower();
		double CalculatePrimary();

		unsigned int CalculateFactorial(unsigned int n) const;
		double CalculateFactorial(double n) const;

	private:

		TokenStream m_TokenStream;
	};
}