#pragma once

#include <cstdint>

namespace Calculator::Chapter5::Token
{
	enum class Type : int8_t
	{
		Invalid = -1,
		Empty,
		Number,
		Operator,
		Parenthesis,
		End,
	};
}