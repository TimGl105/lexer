#include "string.h"
#include <iostream>
#include <utility>


void string_out(const String& string) { std::cout << "Stringinhalt:" << string.c_str() << std::endl; };


int main() {

	String string_1("used");
	string_out(string_1);
	string_1 += "twice";
	
	String string_2(string_1);
	
	string_2 += "did not work";
	
	String string_3("added");
	string_2 = string_3;
	swap(string_2, string_1);
	string_out(string_2);
	
	String string_one_char("a");
	String string_one_char_2("b");
	string_out(string_one_char + string_one_char_2);
	string_out(string_one_char + 'c');
    //string_out(string_3);
    string_out(string_1 + string_3);

	String string_cut(String("cut-off"), 4);
	string_out(string_cut);

	String string_cut2(String("cut-off"), 6);
	string_out(string_cut2);

	String str_1(std::move(string_2));
	string_out(str_1);
	string_out(string_2);
	
return 0;
}

bool 

