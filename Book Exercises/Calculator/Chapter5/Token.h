#pragma once

#include<string>

namespace Calculator::Chapter5
{
	class Token
	{
	public:

		enum class Type : int8_t
		{
			Invalid = -1,
			Empty,
			Number,
			Integer,
			FloatingPoint,
			Operator,
			StartParenthesis,
			EndParenthesis,
			Execute,
			Assign,
			End
		};

	public:

		Token() = default;
		~Token() = default;

	public:

		void SetTypeFromChar(char c);

		inline void SetType(Type type) { m_Type = type; }
		inline void SetValue(std::string_view value) { m_Value = value.data(); }

		inline Type GetType() const { return m_Type; }

		inline char GetOperatorValue() const { return m_Value[0]; }
		inline char GetParenthesisValue() const { return m_Value[0]; }
		inline long GetIntegerValue() const { return stol(m_Value); }
		inline double GetFloatingPointValue() const { return stod(m_Value); }

	private:

		Type m_Type{ Type::Empty };

		std::string m_Value;
	};
}