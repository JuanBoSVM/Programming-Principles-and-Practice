#include "Token.h"

void Calculator::Chapter5::Token::SetTypeFromChar(char c)
{
	if (isdigit(c)) { m_Type = Type::Number; }
	else if (std::string("+-*/!^").contains(c)) { m_Type = Type::Operator; }
	else if (std::string("({[").contains(c)) { m_Type = Type::StartParenthesis; }
	else if (std::string(")}]").contains(c)) { m_Type = Type::EndParenthesis; }
	else if (c == '=') { m_Type = Type::Assign; }
	else if (c == ';') { m_Type = Type::Execute; }
	else { m_Type = Type::Invalid; }
}
