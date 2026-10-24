#pragma once

#include <string_view>

#include "Token.h"
#include "TokenStream.h"
#include "Parser.h"

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

	private:

		TokenStream m_TokenStream;
	};
}