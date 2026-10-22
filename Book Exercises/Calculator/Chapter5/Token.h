#pragma once

#include<string>

namespace Program::Chapter5
{
	class Token
	{
	public:

		enum class Type : int8_t
		{
			Invalid = -1,
			Empty,
			Number,
			Addition,
			Subtraction,
			Multiplication,
			Division,
			Exponentiation,
			Factorial,
			StartParenthesis,
			StartCurlyBrace,
			StartSquareBracket,
			EndParenthesis,
			EndCurlyBrace,
			EndSquareBracket,
			Execute,
			Assign,
			End
		};

	public:

		Token() = default;
		~Token() = default;

		Token(Type type, std::string_view value);

	public:

		void SetTypeFromChar(char c);

		inline void SetType(Type type) { m_Type = type; }
		inline void SetValue(std::string_view value) { m_Value = value.data(); }

		inline Type GetType() const { return m_Type; }

		inline char GetCharacterValue() const { return m_Value[0]; }
		inline double GetFloatingPointValue() const { return stod(m_Value); }

	private:

		Type m_Type{ Type::Empty };

		std::string m_Value;
	};

	bool ParenthesisMatch(const Token& left, const Token& right);
}