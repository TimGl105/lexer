#include "string.h"
#include "string.cpp"
#include <iostream>
#include <utility>


void string_out(const String& string) { std::cout << "Stringinhalt:" << string.c_str() << std::endl; };

void test_out(bool test) { std::cout << test << std::endl; };

int main() {

	String string_1("used");
	string_out(string_1);
	test_out("used" == string_1);
	string_1 += "twice";
	string_out(string_1);
	test_out("usedtwice" == string_1);
	
	String string_2(string_1);
	string_out(string_2);
	test_out("used" == string_2);
	string_2 += "did not work";
	string_out(string_2);
	test_out("useddid not work" == string_2);
	
	String string_3("added");
	string_out(string_3);
	test_out("added" == string_3);
	string_2 = string_3;
	string_out(string_2);
	test_out("added" == string_2);
	swap(string_2, string_1);
	string_out(string_2);
	test_out("usedtwice" == string_2);
	string_out(string_1);
	test_out("added" == string_1);
	
	String string_one_char("a");
	String string_one_char_2("b");
	string_out(string_one_char + string_one_char_2);
	test_out("ab" == (string_one_char + string_one_char_2));
	string_out(string_one_char + 'c');
    test_out("ac" == (string_one_char + 'c'));
	string_out(string_1 + string_3);
    test_out("addedadded" == (string_1 + string_3));

	//String string_cut(String("cut-off"), 4);
	String string_cut3("cut-off", 4);
	string_out(string_cut3);
	test_out("cut-" == string_cut3);

	//String string_cut2(String("cut-off"), 6);
	String string_cut4("cut-off", 6);
	string_out(string_cut4);
	test_out("cut-of" == string_cut4);

	String str_1(std::move(string_2));
	string_out(str_1);
	test_out("usedtwice" == str_1);
	string_out(string_2);
	test_out("" == string_2);
	
return 0;
} 

