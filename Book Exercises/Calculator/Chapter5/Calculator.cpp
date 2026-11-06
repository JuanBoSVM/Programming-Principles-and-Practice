#include "Calculator.h"

#include <cmath>
#include <limits>
#include <stdexcept>

double Program::Chapter5::Calculator::Calculate(std::string_view str)
{
	m_TokenStream = TokenStream(str);

	return Calculate();
}

double Program::Chapter5::Calculator::Calculate(TokenStream& stream)
{
	m_TokenStream = stream;

	return Calculate();
}

unsigned int Program::Chapter5::Calculator::CalculatePermutation(unsigned int n, unsigned int r) const
{
	if (n < r)
	{
		throw std::invalid_argument("n must be greater than or equal to r for permutation calculation");
	}

	return CalculateFactorial(n) / CalculateFactorial(n - r);
}

unsigned int Program::Chapter5::Calculator::CalculateCombination(unsigned int n, unsigned int r) const
{
	if (n < r)
	{
		throw std::invalid_argument("n must be greater than or equal to r for combination calculation");
	}

	return CalculatePermutation(n, r) / CalculateFactorial(r);
}

double Program::Chapter5::Calculator::Calculate()
{
	if (m_Mode == CalculationMode::Bitwise)
	{
		ConvertFactorialsToLogicalNot();
		return CalculateBitwiseExpression();
	}

	return CalculateDecimalExpression();
}

double Program::Chapter5::Calculator::CalculateDecimalExpression()
{
	using enum Token::Type;

	double leftValue{ CalculateTerm() };

	while (m_TokenStream.Peek().GetType() == Addition || m_TokenStream.Peek().GetType() == Subtraction)
	{
		switch (m_TokenStream.Peek().GetType())
		{
		case Addition:
			m_TokenStream.Get();
			leftValue += CalculateTerm();
			break;

		case Subtraction:
			m_TokenStream.Get();
			leftValue -= CalculateTerm();
			break;
		}
	}

	return leftValue;
}

double Program::Chapter5::Calculator::CalculateTerm()
{
	using enum Token::Type;

	double leftValue{ CalculatePower() };

	while (m_TokenStream.Peek().GetType() == Multiplication || m_TokenStream.Peek().GetType() == Division)
	{
		switch (m_TokenStream.Peek().GetType())
		{
		case Multiplication:
			m_TokenStream.Get();
			leftValue *= CalculatePower();
			break;
		case Division:
			m_TokenStream.Get();
			leftValue /= CalculatePower();
			break;
		}
	}

	return leftValue;
}

double Program::Chapter5::Calculator::CalculatePower()
{
	using enum Token::Type;

	double leftValue{ CalculatePrimary() };

	while (m_TokenStream.Peek().GetType() == Factorial || m_TokenStream.Peek().GetType() == LogicalNot || m_TokenStream.Peek().GetType() == Exponentiation)
	{
		switch (m_TokenStream.Peek().GetType())
		{
		case Factorial:
		case LogicalNot:
			m_TokenStream.Get();
			leftValue = CalculateFactorial(leftValue);
			break;

		case Exponentiation:
			m_TokenStream.Get();
			leftValue = std::pow(leftValue, CalculatePrimary());
			break;
		}
	}

	return leftValue;
}

double Program::Chapter5::Calculator::CalculatePrimary()
{
	using enum Token::Type;

	const Token token{ m_TokenStream.Get() };

	switch (token.GetType())
	{
	case Addition:
		return CalculatePrimary();
	case Subtraction:
		return -CalculatePrimary();
	case Number:
		return static_cast<double>(token);
	}

	if (token.IsStartParenthesis())
	{
		const double value{ CalculateDecimalExpression() };
		const Token closingToken{ m_TokenStream.Get() };

		if (!token.ParenthesisMatch(closingToken))
		{
			throw std::runtime_error("Mismatched parenthesis");
		}

		return value;
	}

	if (token.IsEndParenthesis())
	{
		throw std::runtime_error("Unexpected closing parenthesis");
	}

	throw std::runtime_error("Invalid token");
}

double Program::Chapter5::Calculator::CalculateBitwiseExpression()
{
	return CalculateBitwiseOr();
}

double Program::Chapter5::Calculator::CalculateBitwiseOr()
{
	using enum Token::Type;

	long long leftValue{ GetBitwiseOperand(CalculateBitwiseXor()) };

	while (m_TokenStream.Peek().GetType() == BitwiseOr)
	{
		m_TokenStream.Get();
		leftValue |= GetBitwiseOperand(CalculateBitwiseXor());
	}

	return static_cast<double>(leftValue);
}

double Program::Chapter5::Calculator::CalculateBitwiseXor()
{
	using enum Token::Type;

	long long leftValue{ GetBitwiseOperand(CalculateBitwiseAnd()) };

	while (m_TokenStream.Peek().GetType() == Exponentiation)
	{
		m_TokenStream.Get();
		leftValue ^= GetBitwiseOperand(CalculateBitwiseAnd());
	}

	return static_cast<double>(leftValue);
}

double Program::Chapter5::Calculator::CalculateBitwiseAnd()
{
	using enum Token::Type;

	long long leftValue{ GetBitwiseOperand(CalculateBitwiseUnary()) };

	while (m_TokenStream.Peek().GetType() == BitwiseAnd)
	{
		m_TokenStream.Get();
		leftValue &= GetBitwiseOperand(CalculateBitwiseUnary());
	}

	return static_cast<double>(leftValue);
}

double Program::Chapter5::Calculator::CalculateBitwiseUnary()
{
	using enum Token::Type;

	const Token::Type type{ m_TokenStream.Peek().GetType() };

	if (type == LogicalNot)
	{
		m_TokenStream.Get();
		return static_cast<double>(~GetBitwiseOperand(CalculateBitwiseUnary()));
	}

	if (type == Factorial)
	{
		throw std::runtime_error("Bitwise logical-not token was not normalized");
	}

	if (type == Complement)
	{
		m_TokenStream.Get();
		return static_cast<double>(~GetBitwiseOperand(CalculateBitwiseUnary())) + 1.0;
	}

	return CalculateBitwisePrimary();
}

double Program::Chapter5::Calculator::CalculateBitwisePrimary()
{
	using enum Token::Type;

	const Token token{ m_TokenStream.Get() };

	if (token.GetType() == Number)
	{
		return static_cast<double>(GetBitwiseOperand(token.GetFloatingPointValue()));
	}

	if (token.IsStartParenthesis())
	{
		const double value{ CalculateBitwiseExpression() };
		const Token closingToken{ m_TokenStream.Get() };

		if (!token.ParenthesisMatch(closingToken))
		{
			throw std::runtime_error("Mismatched parenthesis");
		}

		return value;
	}

	if (token.IsEndParenthesis())
	{
		throw std::runtime_error("Unexpected closing parenthesis");
	}

	throw std::runtime_error("Invalid bitwise token");
}

void Program::Chapter5::Calculator::ConvertFactorialsToLogicalNot()
{
	using enum Token::Type;

	std::vector<Token> tokens;
	Token token;

	while ((token = m_TokenStream.Get()).GetType() != Invalid)
	{
		if (token.GetType() == Factorial)
		{
			token.SetType(LogicalNot);
		}

		tokens.push_back(token);

		if (token.GetType() == End)
		{
			break;
		}
	}

	for (auto tokenIterator{ tokens.rbegin() }; tokenIterator != tokens.rend(); ++tokenIterator)
	{
		m_TokenStream.Putback(*tokenIterator);
	}
}

long long Program::Chapter5::Calculator::GetBitwiseOperand(double value) const
{
	using enum Token::Type;

	// Check if the value is an integer
	if (std::trunc(value) != value)
	{
		throw std::invalid_argument("Bitwise operands must be integer values");
	}

	return static_cast<long long>(value);
}

unsigned int Program::Chapter5::Calculator::CalculateFactorial(unsigned int n) const
{
	return static_cast<unsigned int>(std::tgamma(n + 1U));
}

double Program::Chapter5::Calculator::CalculateFactorial(double n) const
{
	return std::tgamma(n + 1.0);
}
