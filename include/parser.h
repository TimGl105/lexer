#ifndef PARSER_H
#define PARSER_H

#include "grammar.h"


First {
	GrammarVariable variable;
	Vector<TokenType> firsts;
};

struct Follow {
	GrammarVariable variable;
	Vector<TokenType> follows;
};