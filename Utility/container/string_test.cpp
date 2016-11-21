#include "string.h"
#include <iostream>
#include <utility>


void string_out(const String& string) { std::cout << "Stringinhalt:" << string.c_str() << std::endl; };

void test_out(bool test) { std::cout << test << std::endl; };

int main() {

	test_results();
	
return 0;
}

void test_results() {
	String string_1("used");
	test_out("used" == string_1.c_str);
	string_1 += "twice";
	test_out("usedtwice" == string_1.c_str);
	
	String string_2(string_1);
	test_out("usedtwice" == string_2.c_str);
	string_2 += "did not work";
	test_out("usedtwicedid not work" == string_2.c_str);

	String string_3("added");
	test_out("added" == string_3.c_str);
	string_2 = string_3;
	test_out("added" == string_2.c_str);
	swap(string_2, string_1);
	test_out("usedtwice" == string_2.c_str);
	test_out("added" == string_1.c_str);
	test_out("addedadded" == (string_1 + string_3).c_str);

	String string_one_char("a");
	String string_one_char_2("b");
	test_out("ab" == (string_one_char + string_one_char_2).c_str);
	test_out("ac" == (string_one_char + 'c').c_str);

	String string_cut(String("cut-off"), 4);
	test_out("cut_" == string_cut.c_str);

	String string_cut2(String("cut-off"), 6);
	test_out("cut-of" == string_cut2.c_str);

	String str_1(std::move(string_2));
	test_out("usedtwice" == str_1.c_str);
	string_out(string_2);
}

