#ifndef GRAMMAR_H
#define GRAMMAR_H

#include "scanner.h"
#include "token.h"
#include "vector.h"

enum class GrammarVariable : unsigned char {
	PROG,
	DECLS,
	DECL,
	ARRAY,

	STATEMENT,
	STATEMENTS,
	EXP,
	EXP_2,
	INDEX,
	OP_EXP,
	OP
};

class First {
private:
	Vector<Vector<TokenType>> firsts;

public:
    First();
};

class Follow {
private:
	Vector<Vector<TokenType>> follows;

public:
    Follow();

	Vector<TokenType> get_follows_for_type(GrammarVariable variable) {
		return follows[static_cast<std::size_t>(variable)];
	}
};

class GrammarCharacter {
private:
    enum class dreck {
        VARIABLE,
        TOKEN
    };

    struct GrammarCharacterType { // constructor missing which sets variable
		dreck type;
		union Variable_or_token
		{
			GrammarVariable variable;
			TokenType token;
		} variable_or_token;
	} grammar_character_type;

public:

   bool is_grammar_variable () {
       return grammar_character_type.type == dreck::VARIABLE;
   }

   bool is_token_type () {
       return grammar_character_type.type == dreck::TOKEN;
   }
};

class GrammarWord {
public:
   Vector<GrammarCharacter> characters; //better: sorted list
};

class GrammarProduction {
	GrammarVariable start;
	Vector<GrammarWord> words;
};


class Grammar {
public:
    GrammarVariable start = GrammarVariable::PROG;
    Vector<GrammarProduction> productions;
};



#endif // GRAMMAR_H
