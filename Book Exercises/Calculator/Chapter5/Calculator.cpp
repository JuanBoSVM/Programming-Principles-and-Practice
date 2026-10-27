#include "Calculator.h"

#include <cmath>
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

double Program::Chapter5::Calculator::Calculate()
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

	while (m_TokenStream.Peek().GetType() == Factorial || m_TokenStream.Peek().GetType() == Exponentiation)
	{
		switch (m_TokenStream.Peek().GetType())
		{
		case Factorial:
			m_TokenStream.Get();
			leftValue = std::tgamma(leftValue + 1.0);
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
		const double value{ Calculate() };
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
