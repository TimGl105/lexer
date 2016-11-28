#include "string.h"
#include <iostream>
#include <utility>


void string_out(const String& string) { std::cout << "Stringinhalt:" << string.c_str() << std::endl; }

void test_out(const char* asserted, const String& test_string) { 
	std::cout << "Asserted:" << asserted << " "; 
	string_out(test_string);  
}

int main() {

	String str_empty;
	test_out("", str_empty);

	String string_1("used");
	test_out("used", string_1);
	string_1 += "twice";
	//string_out(string_1);
	test_out("usedtwice", string_1);
	
	String string_2(string_1);
	//string_out(string_2);
	test_out("usedtwice", string_2);
	string_2 += "did not work";
	//string_out(string_2);
	test_out("usedtwicedid not work", string_2);
	
	String string_3("added");
	//string_out(string_3);
	test_out("added", string_3);
	string_2 = string_3;
	//string_out(string_2);
	test_out("added" ,string_2);
	swap(string_2, string_1);
	//string_out(string_2);
	test_out("usedtwice", string_2);
	//string_out(string_1);
	test_out("added", string_1);
	
	String string_one_char("a");
	String string_one_char_2("b");
	String string_two_chars = string_one_char + string_one_char_2;
	//string_out(string_two_chars);
	test_out("ab", (string_two_chars));
	
	String string_two_chars2 = string_one_char + 'c';
	//string_out(string_two_chars2);
    test_out("ac", (string_two_chars2));
	
	String string_conc = string_1 + string_3;
	//string_out(string_conc);
    test_out("addedadded", (string_conc));

	//String string_cut(String("cut-off"), 4);
	String string_cut3("cut-off", 4);
	//string_out(string_cut3);
	test_out("cut-", string_cut3);

	//String string_cut2(String("cut-off"), 6);
	String string_cut4("cut-off", 6);
	//string_out(string_cut4);
	test_out("cut-of", string_cut4);

	String str_1(std::move(string_2));
	//string_out(str_1);
	test_out("usedtwice", str_1);
	//string_out(string_2);
	test_out("", string_2);
	
	String str_const("const");
	std::cout << str_const[2] << std::endl;
	//str_const[2]);
	
	String str_index(str_1);
	std::cout << "d" == str_index[3] << std::endl;
	std::cout << "w" == str_index[5] << std::endl;
	std::cout << "i" == str_index[6] << std::endl;
	std::cout << "" == str_index[9] << std::endl;
	
	String str_max("ab", 65535);
	std::cout << string_1.size() << std::endl;
	std::cout << string_cut4.size() << std::endl;
	std::cout << str_max.size() << std::endl;
	std::cout << str_empty.size() << std::endl;
	
	String str_empty2;
	
	
	std::cout << string_1 == string_3 << std::endl;
	std::cout << str_empty == str_empty2 << std::endl;
	std::cout << string_one_char != string_one_char_2 << std::endl;
	
	string_1.clear();
	test_out("", string_1);
	
return 0;
}

