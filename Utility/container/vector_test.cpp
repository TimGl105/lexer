/*
 * vetortest.cpp
 *
 *  Created on: 14.11.2016
 *      Author: Tim
 */
#include "vector.h"
#include <iostream>
#include <string>
#include "string.h"

void t_out(bool t) { std::cout << "Test: " << t << std::endl; }

void s_out(const String& string) { std::cout << string.c_str() << std::endl; }

int main() {

	// 
	
	//Testcase 1: done 
	Vector<int> random_vec(std::size_t(100), 1);
	random_vec[99] = 99;
	const Vector<int> const_random_vec = random_vec;
	auto iterator = const_random_vec.find(99);
	if(iterator != const_random_vec.cend() && *iterator == 99) {
		t_out(true);
	} else {
		t_out(false);
	}
	
	
	//Testcase 2: done
	Vector<String> string_vec(9, "world");
	string_vec.push_back("end2");
	string_vec.push_back("end1");
	std::cout << "size: " << string_vec.size() << std::endl;
	std::cout << "capacity: " << string_vec.capacity() << std::endl;
	std::cout << "free capacity: " << string_vec.free_capacity() << std::endl;
	Vector<Vector<String>> vector_vec(10, string_vec);
	vector_vec.push_back(string_vec);
	

	//Testcase 3: done
	//std::cout << vector_vec[10].pop_back().c_str() << std::endl;
	t_out(0 == strcmp("end1", vector_vec[10].pop_back().c_str()));
	//std::cout << vector_vec.pop_back().pop_back().c_str() << std::endl;
	t_out(0 == strcmp("end2", vector_vec.pop_back().pop_back().c_str()));
	
	//Testcase 4: 
	Vector<String> str_vec(3, "world");
	Vector<String> str_vec2;
	str_vec.push_back("end");
	str_vec2.push_back("first");
	if (vector_vec.pop_back().contains("end")) {
		str_vec2.insert(str_vec2.begin() + 1, string_vec.rbegin() + 1, string_vec.rend());
	}
	std::cout << str_vec2.size() << std::endl;
	for (int i = str_vec2.size(); i > 0; i--) {
		s_out(str_vec2.pop_back());
	}

	//Testcase 5: done
	vector_vec.clear();
	//std::cout << vector_vec.size() << std::endl;
	t_out(vector_vec.size() == 0);
	std::cout << "capacity: "<< vector_vec.capacity() << std::endl;
	std::cout << "free capacity: " << vector_vec.free_capacity() << std::endl;
	t_out(vector_vec.capacity() == vector_vec.free_capacity());
	
	//Testcase 6:
	Vector<String> str_ult;
	/*for (int i = 4; i > -2; i--) {
		str_ult.push_back(std::to_string(i).c_str());
	}*/
	/*str_ult.push_back("4");
	str_ult.push_back("3");
	str_ult.push_back("2");
	str_ult.push_back("1");
	str_ult.push_back("0");
	str_ult.push_back("-1");
	
	if (str_ult.contains("-1")) {
		str_ult.insert(str_ult.rend() + 1, str_ult.begin() + 1, str_ult.end() - 1);
	}
	t_out(str_ult.size() == 11);
	std::cout << "capacity: "<< str_ult.capacity() << std::endl;
	std::cout << "free capacity: " << str_ult.free_capacity() << std::endl;
	for (int i = str_ult.size(); i > 0; i--) {
		s_out(str_ult.pop_back());
	}*/
	
	//Testcase 7: done
	Vector<int> v_empty;
	t_out(0 == v_empty.size());
	t_out(16 == v_empty.capacity());
	t_out(16 == v_empty.free_capacity());
	//Testcase 8: done
	Vector<int> v_0(0);
	t_out(0 == v_0.size());
	t_out(0 == v_0.capacity());
	t_out(0 == v_0.free_capacity());
	
	//Testcase 9: 
	Vector<int*> v_1(1, nullptr);
	t_out(NULL == v_1.find(nullptr));

	
	//Testcase 10:
	Vector<String> mill_vec(std::size_t(1000000));
	Vector<String> p1_vec(std::size_t(250000), "p1");
	Vector<String> p2_vec(std::size_t(250000), "p2");
	Vector<String> p3_vec(std::size_t(250000), "p3");
	Vector<String> p4_vec(std::size_t(250000));
	for (int i = 1; i <= 250000; i++) {
		p4_vec.push_back(std::to_string(i));
	}
	
	mill_vec.insert(mill_vec.begin(), p4_vec.begin(), p4_vec.end());
	mill_vec.insert(mill_vec.begin(), p3_vec.begin(), p3_vec.end());
	mill_vec.insert(mill_vec.begin(), p1_vec.begin(), p1_vec.end());
	mill_vec.insert(mill_vec.begin() + 250000, p2_vec.begin(), p2_vec.end());
	
	
	vector<String> mill_vec_std(std::size_t(1000000));
	std::vector<String> p1_vec_std(std::size_t(250000), "p1");
	std::vector<String> p2_vec_std(std::size_t(250000), "p2");
	std::vector<String> p3_vec_std(std::size_t(250000), "p3");
	std::vector<String> p4_vec_std(std::size_t(250000));
	for (int i = 1; i <= 250000; i++) {
		p4_vec_std.push_back(std::to_string(i));
	}
	
	mill_vec.insert<String>(mill_vec_std.begin(), p4_vec_std.begin(), p4_vec_std.end());
	mill_vec.insert<String>(mill_vec_std.begin(), p3_vec_std.begin(), p3_vec_std.end());
	mill_vec.insert<String>(mill_vec_std.begin(), p1_vec_std.begin(), p1_vec_std.end());
	mill_vec.insert<String>(mill_vec_std.begin() + 250000, p2_vec_std.begin(), p2_vec_std.end());
}
