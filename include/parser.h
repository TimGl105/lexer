#ifndef PARSER_H
#define PARSER_H

#include "grammar.h"

class Parser {
private:
	Vector<Vector<GrammarWord>> parse_table;

public:

    ParseTable();

};
#endif // PARSER_H
