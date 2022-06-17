#ifndef _FORWARD_LIST
#define _FORWARD_LIST

#include <ostream>
#include <iterator>

template <typename T>
struct Node{
	T value;
	Node *next;

	Node(){
		value = 0;
		next = nullptr;
	}
};

template <typename T>
class Forward_list{
private:
	Node<T> * _first_item;
	int _length;

	void set_zero();
	void error(std::string text = "error");
	bool is_sorted(Forward_list<T>* );
	std::vector<T> quicSort(std::vector<T> vec);
public:
	class Iterator{
		private:
			Node<T>* node;

		public:
			void get(){
				std::cout << node->value;
			}
			Iterator(){
				this->node = nullptr;
			}
			~Iterator(){
				this->node = nullptr;
			}
			Iterator(Node<T>* input_node){
				this->node = input_node;
			}
			Forward_list<T>::Iterator operator=(const constForward_list<T>::Iterator other_it ){
				this->node = other_it;
			}
			Node<T>& operator++(){
				return this->node->next;
			}
			
	};

	Forward_list();
	~Forward_list();
	Forward_list(std::initializer_list<T> );
	Forward_list(const Forward_list& );
	Forward_list(const Forward_list &&);

	Node<T>& begin();
	Node<T>& end();
	Node<T>& front();

	void clear();
	bool is_empty();
	void push_back(T );
	void merge(Forward_list<T>& );
	void pop_front();
	void push_front(T );
	void emplace(T , int );
	void remove(T);
	void erase(Forward_list<T>::Iterator );
	void insert(int );
	void reverse();
	void remove_if();
	void sort();

	Forward_list<T>& operator=(const Forward_list<T>& );
	Forward_list<T>& operator=(Forward_list<T>&& );
	Forward_list operator+(const Forward_list<T>& );
	Forward_list<T>& operator+=(const Forward_list<T>& );
	bool operator==(const Forward_list<T>& );
	bool operator!=(const Forward_list<T>& );
	bool operator>(const Forward_list<T> &);
	bool operator<(const Forward_list<T> &);
	bool operator>=(const Forward_list<T> &);
	bool operator<=(const Forward_list<T> &);
	template <typename U>
	friend std::ostream &operator<<(std::ostream &, const Forward_list<U> &);
};

#include "forward_list_constructors.hpp"
#include "forward_list_methods.hpp"
#include "forward_list_opeartors.hpp"

#endif