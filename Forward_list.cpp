#include <iostream>
#include <initializer_list>
#include <vector>
#include "forward_list.hpp"

int main(){
	Forward_list<int> a{1,2,3,4};
	std::cout << a;

	a.sort();

	std::cout << a;

	a.reverse();

	std::cout << a;
}
