#include <iostream>
#include <initializer_list>
#include <vector>
#include "forward_list.hpp"

int main(){
  Forward_list<int> a;
  a.push_back(3);
  a.push_back(33);
  a.push_back(333);
  
  // std::cout << &a.front() << std::endl;
  // a.front();

  Forward_list<int>::Iterator aa(&a.front());
  aa.get();
  // std::cout << a;
}
