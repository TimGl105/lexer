#ifndef GRAMMAR_H
#define GRAMMAR_H

#include "scanner.h"
#include "token.h"

#define UNDEF 0
#define VARIABLE 1
#define TOKEN 2

enum class GrammarVariable : unsigned char {
	PROG,
	DECLS,
	DECL,
	ARRAY,
	
	STATEMENT,
	STATEMENTS,
	EXP;
	EXP_2;
	INDEX,
	OP_EXP,
	OP
};

class First {
private:
	Vector<Vector<TokenType>> firsts;
	
	firsts[PROG] = {INT};
	firsts[DECLS] = {EPSILON, INT};
	firsts[DECL] = {INT};
	firsts[ARRAY] = {SQUARE_BRACKET_OPEN, EPSILON};
	firsts[STATEMENT] = {EPSILON, IDENTIFIER, WRITE, READ, CURLY_BRACKET_OPEN, IF, WHILE};
	firsts[STATEMENTS] = {IDENTIFIER, WRITE, READ, CURLY_BRACKET_OPEN, IF, WHILE};
	firsts[EXP] = {PARENTHESIS_OPEN, IDENTIFIER, INTEGER, MINUS, NOT};
	firsts[EXP_2] = {PARENTHESIS_OPEN, IDENTIFIER, INTEGER, MINUS, NOT};
	firsts[INDEX] = {SQUARE_BRACKET_OPEN, EPSILON};
	firsts[OP_EXP] = {EPSILON, PLUS, MINUS, COLON, ASTERISK, LESS_THAN,GREATER_THAN, EQUALITY, WHATEVER, LOGICAL_AND};
	firsts[OP] = {PLUS, MINUS, COLON, ASTERISK, LESS_THAN,GREATER_THAN, EQUALITY, WHATEVER, LOGICAL_AND};
};

class Follow {
private:
	Vector<Vector<TokenType>> follows;
	
	follows[PROG] = {};
	follows[DECLS] = {IDENTIFIER, WRITE, READ, CURLY_BRAKET_OPEN, IF, WHILE};
	follows[DECL] = {SEMICOLON};
	follows[ARRAY] = {IDENTIFIER};
	follows[STATEMENTS] = {CURLY_BRACKET_CLOSE};
	follows[STATEMENT] = {SEMICOLON, ELSE};
	follows[EXP] = {SEMICOLON, ELSE, PARENTHESIS_CLOSE, SQUARE_BRACKET_CLOSE};
	follows[EXP_2] = {PLUS, MINUS, COLON, ASTERISK, LESS_THAN,GREATER_THAN, EQUALITY, WHATEVER, LOGICAL_AND};
	follows[INDEX] = {ASSIGNMENT, PARENTHESIS_CLOSE, PLUS, MINUS, COLON, ASTERISK, LESS_THAN,GREATER_THAN, EQUALITY, WHATEVER, LOGICAL_AND};
	follows[OP_EXP] = {SEMICOLON, ELSE, PARENTHESIS_CLOSE, SQUARE_BRACKET_CLOSE};
	follows[OP] = {PARENTHESIS_OPEN, IDENTIFIER, INTEGER, MINUS, NOT};
}

class Grammar {
public:
    GrammarVariable start = GrammarVariable::PROG;
    Vector<GrammarProduction> productions; 
};

class GrammarProduction {
	GrammarVariable start;
	Vector<GrammarWord> words;
};

class GrammarWord {
public:
   Vector<GrammarCharacter> characters;
   Vector<TokenType> firsts;
   Vector<TokenType> follows;
   GrammarCharacter currentCharacter = characters[0];
};

class GrammarCharacter {
public:
	struct GrammarCharacterType {
		int type;
		union Variable_or_token{
			GrammarVariable variable;
			TokenType token;
		} variable_or_token1; 
	};
   
   bool is_token_type () {
	   if (variable_or_token1.type == TOKEN) : return true ? return false;  
   }
   
   bool is_grammar_variable () {
   	   if (variable_or_token1.type == VARIABLE) : return true ? return false;  
   }
};