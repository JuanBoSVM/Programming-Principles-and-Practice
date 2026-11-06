#pragma once

#include <string_view>

#include "CalculationMode.h"
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

		void SetMode(CalculationMode mode) { m_Mode = mode; }
		CalculationMode GetMode() const { return m_Mode; }

		unsigned int CalculatePermutation(unsigned int n, unsigned int r) const;
		unsigned int CalculateCombination(unsigned int n, unsigned int r) const;

	private:

		double Calculate();
		double CalculateDecimalExpression();
		double CalculateTerm();
		double CalculatePower();
		double CalculatePrimary();

		double CalculateBitwiseExpression();
		double CalculateBitwiseOr();
		double CalculateBitwiseXor();
		double CalculateBitwiseAnd();
		double CalculateBitwiseUnary();
		double CalculateBitwisePrimary();

		void ConvertFactorialsToLogicalNot();
		long long GetBitwiseOperand(double value) const;

		unsigned int CalculateFactorial(unsigned int n) const;
		double CalculateFactorial(double n) const;

	private:

		TokenStream m_TokenStream;
		CalculationMode m_Mode{ CalculationMode::Decimal };
	};
}