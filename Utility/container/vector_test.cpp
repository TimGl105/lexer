/*
 * vetortest.cpp
 *
 *  Created on: 14.11.2016
 *      Author: Tim
 */
#include "vector.h"
#include <iostream>
#include "string.h"

void t_out(bool t) { std::cout << t << std::endl; }

void s_out(const String& string) { std::cout << string.c_str() << std::endl; }

int main() {

	// CONTAINS != CEND() und STRING += und CLEAR Vector<value_type>&
	/*
	Vector<int> random_vec(100, 1);
	random_vec[99] = 99;
	const Vector<int> const_random_vec = random_vec;
	auto iterator = const_random_vec.find(99);
	if(iterator != const_random_vec.cend() && *iterator == 99) {
		t_out(true);
	} else {
		t_out(false);
	}
	*/

	Vector<String> string_vec(9, "world");
	string_vec.push_back("end2");
	string_vec.push_back("end1");
	std::cout << string_vec.size() << std::endl;
	std::cout << string_vec.capacity() << std::endl;
	std::cout << string_vec.free_capacity() << std::endl;
	Vector<Vector<String>> vector_vec(10);
	vector_vec.push_back(string_vec);
	Vector<String> str_vec2;
	std::cout << "what" << std::endl;
	if (vector_vec.pop_back().contains("end")) {
		str_vec2.insert(str_vec2.begin()+1, string_vec.rend(), string_vec.rbegin()+1);
	}
	//std::cout << str_vec2.
	
	//done
	//std::cout << vector_vec[10].pop_back().c_str() << std::endl;
	t_out(0 == strcmp("end1", vector_vec[10].pop_back().c_str()));
	//std::cout << vector_vec.pop_back().pop_back().c_str() << std::endl;
	t_out(0 == strcmp("end2", vector_vec.pop_back().pop_back().c_str()));

	//done
	vector_vec.clear();
	std::cout << vector_vec.size() << std::endl;
	t_out(vector_vec.size() == 0);
	std::cout << vector_vec.capacity() << std::endl;
	std::cout << vector_vec.free_capacity() << std::endl;
	t_out(vector_vec.capacity() == vector_vec.free_capacity());
	
	
	Vector<String> str_ult(5);
	str_ult.push_back("4");
	str_ult.push_back("3");
	str_ult.push_back("2");
	str_ult.push_back("1");
	str_ult.push_back("0");
	str_ult.push_back("-1");
	if (str_ult.contains("-1")) {
		str_ult.insert(str_ult.begin()+1, str_ult.rend(), str_ult.rbegin()+1);
	}
	s_out(str_ult.pop_back());
	s_out(str_ult.pop_back());
	s_out(str_ult.pop_back());
	s_out(str_ult.pop_back());
	s_out(str_ult.pop_back());
	s_out(str_ult.pop_back());
	s_out(str_ult.pop_back());
	s_out(str_ult.pop_back());
	s_out(str_ult.pop_back());
	s_out(str_ult.pop_back());
	s_out(str_ult.pop_back());
	
	Vector<int> v_empty;
	//Vector<int> v_0(0, 2);
	Vector<int*> v_1(1, nullptr);

	//v_vector.push_back(v_string);
	
	//std::cout << v_string[2] << std::endl;
	//std::cout << *v_vector[2].find("world") << std::endl;

	
	/* iterator find(const value_type& value)
	
	/** bool contains(const value_type& value) const 
	
	/** clear()
	
	/** iterator begin()/ end()
	
	/** template<typename InputIterator> iterator insert(iterator target, InputIterator begin, InputIterator end)
	
	/** std::size_t size() const
	
	/** std::size_t capacity() const
	
	/** std::size_t free_capacity() const 
	
	/** void push_back(const value_type& object)
	
	*/
}
