#include "grammar.h"

First::First()
{

    firsts.push_back({TokenType::INT});
	firsts.push_back({/*TokenType::EPSILON, */TokenType::INT});
	firsts.push_back({TokenType::INT});
	firsts.push_back({TokenType::INT});
	firsts.push_back({TokenType::SQUARE_BRACKET_OPEN/*, TokenType::EPSILON*/});
	firsts.push_back({/*TokenType::EPSILON, */TokenType::IDENTIFIER, TokenType::WRITE, TokenType::READ, TokenType::CURLY_BRACKET_OPEN, TokenType::IF, TokenType::WHILE});
	firsts.push_back({TokenType::IDENTIFIER, TokenType::WRITE, TokenType::READ, TokenType::CURLY_BRACKET_OPEN, TokenType::IF, TokenType::WHILE});
	firsts.push_back({TokenType::PARENTHESIS_OPEN, TokenType::IDENTIFIER, TokenType::INTEGER, TokenType::MINUS, TokenType::NOT});
	firsts.push_back({TokenType::PARENTHESIS_OPEN, TokenType::IDENTIFIER, TokenType::INTEGER, TokenType::MINUS, TokenType::NOT});
	firsts.push_back({TokenType::SQUARE_BRACKET_OPEN/*, TokenType::EPSILON*/});
	firsts.push_back({/*TokenType::EPSILON, */TokenType::PLUS, TokenType::MINUS, TokenType::COLON, TokenType::ASTERISK, TokenType::LESS_THAN, TokenType::GREATER_THAN, TokenType::EQUALITY, TokenType::WHATEVER, TokenType::LOGICAL_AND});
	firsts.push_back({TokenType::PLUS, TokenType::MINUS, TokenType::COLON, TokenType::ASTERISK, TokenType::LESS_THAN, TokenType::GREATER_THAN, TokenType::EQUALITY, TokenType::WHATEVER, TokenType::LOGICAL_AND});

};

Follow::Follow()
{
    follows.push_back(Vector<TokenType>());
	follows.push_back({TokenType::IDENTIFIER, TokenType::WRITE, TokenType::READ, TokenType::CURLY_BRACKET_OPEN, TokenType::IF, TokenType::WHILE});
	follows.push_back({TokenType::SEMICOLON});
	follows.push_back({TokenType::IDENTIFIER});
	follows.push_back({TokenType::CURLY_BRACKET_CLOSE});
	follows.push_back({TokenType::SEMICOLON, TokenType::ELSE});
	follows.push_back({TokenType::SEMICOLON, TokenType::ELSE, TokenType::PARENTHESIS_CLOSE, TokenType::SQUARE_BRACKET_CLOSE});
	follows.push_back({TokenType::PLUS, TokenType::MINUS, TokenType::COLON, TokenType::ASTERISK, TokenType::LESS_THAN, TokenType::GREATER_THAN, TokenType::EQUALITY, TokenType::WHATEVER, TokenType::LOGICAL_AND});
	follows.push_back({TokenType::ASSIGNMENT, TokenType::PARENTHESIS_CLOSE, TokenType::PLUS, TokenType::MINUS, TokenType::COLON, TokenType::ASTERISK, TokenType::LESS_THAN, TokenType::GREATER_THAN, TokenType::EQUALITY, TokenType::WHATEVER, TokenType::LOGICAL_AND});
	follows.push_back({TokenType::SEMICOLON, TokenType::ELSE, TokenType::PARENTHESIS_CLOSE, TokenType::SQUARE_BRACKET_CLOSE});
	follows.push_back({TokenType::PARENTHESIS_OPEN, TokenType::IDENTIFIER, TokenType::INTEGER, TokenType::MINUS, TokenType::NOT});


}
