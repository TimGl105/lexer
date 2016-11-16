/*
 * vetortest.cpp
 *
 *  Created on: 14.11.2016
 *      Author: Tim
 */
#include "vector.h"
#include <iostream>
#include "string.h"

int main() {

	//first test case
	/*Vector<int> random_vec(100, (const int) 1);
	random_vec[99] = 99;
	const Vector<int> const_random_vec = random_vec;
	auto iterator = const_random_vec.find(99);
	if(iterator != const_random_vec.cend() && *iterator == 99) {
		std::cout << "Position 99 found" << std::endl;
	} else {
		std::cout << "Position 99 not found" << std::endl;
	}*/

	//second test case
	Vector<String> string_vec(10, "world");
	Vector<Vector<String>> vector_vec(10);
	vector_vec.push_back(string_vec);
	//std::cout << (*vector_vec.find(string_vec)).pop_back().c_str();

	Vector<Vector<String>> vector2_vec(10, string_vec);
	Vector<String> string2_vec(20, "end");
	vector2_vec[9].push_back("resize worked");
	std::cout << vector2_vec.pop_back().pop_back().c_str();

	//third test case
	Vector<int> v_empty;
	//Vector<int> v_0(0, 2);
	Vector<int*> v_1(1, nullptr);

	//v_vector.push_back(v_string);
	
	//std::cout << v_string[2] << std::endl;
	//std::cout << *v_vector[2].find("world") << std::endl;

	
}
