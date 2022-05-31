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
	Node<T> *_first_item;
	int _length;

	void set_zero();
	void error(std::string text = "error");
	bool is_sorted(Forward_list<T>* );
	std::vector<T> quicSort(std::vector<T> vec);
public:
	Forward_list();
	~Forward_list();
	Forward_list(std::initializer_list<T> );
	Forward_list(const Forward_list& );
	Forward_list(Forward_list &&);
	Node<T> front();
	void clear();
	bool is_empty();
	void push_back(T );
	void merge(Forward_list<T>& );
	void pop_front();
	void push_front(T );
	void emplace(T , int );
	void remove(T);
	void erase(int );
	void insert(int );
	void reverse();
	void remove_if();
	void sort();

	Forward_list operator=(Forward_list<T>& );
	Forward_list operator=(Forward_list<T>&& );
	Forward_list operator+(Forward_list<T>& );
	void operator+=(Forward_list<T>& );
	bool operator==(const Forward_list<T>& );
	bool operator!=(const Forward_list<T>& );
	bool operator>(Forward_list<T> &);
	bool operator<(Forward_list<T> &);
	bool operator>=(Forward_list<T> &);
	bool operator<=(Forward_list<T> &);
	template <typename U>
	friend std::ostream &operator<<(std::ostream &, const Forward_list<U> &);
};

template <typename T>
Forward_list<T>::Forward_list(){
	set_zero();
}

template <typename T>
Forward_list<T>::~Forward_list(){
	clear();
}

template<typename T>
Forward_list<T>::Forward_list(std::initializer_list<T> list) {
	for (auto& i : list) {
		this->push_back(i);
	}
}

template <typename T>
Forward_list<T>::Forward_list(Forward_list &&move_obj){
	if (move_obj._first_item == nullptr){
		error("1");
	}

	this->_first_item = move_obj._first_item;
	this->_length = move_obj._length;

	move_obj._length = 0;
	move_obj._first_item = nullptr;
}

template<typename T>
Forward_list<T>::Forward_list(const Forward_list& other) {
	Node<T>* select_ptr = other._first_item;
	while (select_ptr != nullptr) {
		this->push_back(select_ptr->value);
		select_ptr = select_ptr->next;
	}
}

template <typename T>
void Forward_list<T>::set_zero(){
	this->_first_item = nullptr;
	this->_length = 0;
}

template <typename T>
void Forward_list<T>::error(std::string text){
	std::cout << text << std::endl;
	exit(0);
}

template <typename T>
bool Forward_list<T>::is_sorted(Forward_list<T>* f_list){
		if(f_list->_first_item == nullptr){
			return false;
		}

		Node<T>* select_ptr = f_list->_first_item;
		T max_item = select_ptr->value;

		while(select_ptr != nullptr){
			if(max_item > select_ptr->value){
				return false;
			}

			max_item = select_ptr->value;
			select_ptr = select_ptr->next;
		}
	
		return true;
	}

template<typename T>
std::vector<T> Forward_list<T>::quicSort(std::vector<T> vec){
  if(vec.size() <= 1){
    return vec;
  }

  int pivotIndex = vec.size() / 2;
  int pivot = vec[pivotIndex];
  std::vector<T> less;
  std::vector<T> greater;


  for(int i = 0; i < vec.size(); ++i) {
    if(i == pivotIndex) {
      continue;
    }

    if(vec[i] < pivot) {
      less.push_back(vec[i]);
    } else {
      greater.push_back(vec[i]);
    }
  }

  std::vector<T> return_vec;
  less = quicSort(less);
  greater = quicSort(greater);

  for(int i = 0; i < less.size(); ++i){
    return_vec.push_back(less[i]);
  }

  return_vec.push_back(pivot);

  for(int i = 0; i < greater.size(); ++i){
    return_vec.push_back(greater[i]);
  }

  return return_vec;
}


template <typename T>
Node<T> Forward_list<T>::front(){
	return _first_item;
}

template <typename T>
void Forward_list<T>::clear(){
	if (_first_item == nullptr || _length == 0){
		return;
	}

	Node<T> *select_ptr = _first_item;
	while (select_ptr != nullptr){
		Node<T> *tmp = select_ptr->next;
		delete select_ptr;
		select_ptr = tmp;
	}

	set_zero();
}

template <typename T>
bool Forward_list<T>::is_empty(){
	if (_first_item == nullptr || _length == 0){
		return true;
	}
	return false;
}

template <typename T>
void Forward_list<T>::push_back(T val){
	Node<T> *new_node = new Node<T>;
	new_node->value = val;

	if (_length == 0 || _first_item == nullptr){
		_first_item = new_node;
	}
	else{
		Node<T> *select_ptr = this->_first_item;
		while (select_ptr->next != nullptr){
			select_ptr = select_ptr->next;
		}
		select_ptr->next = new_node;
	}

	_length++;
}

template<typename T>
void Forward_list<T>::merge(Forward_list<T>& f_list) {
	//std::cout << "is_sorted ? : " << std::boolalpha << is_sorted(this) << "\n";
	//std::cout << "is_sorted ? : " << std::boolalpha << is_sorted(&f_list) << "\n";

	if (this->_first_item == nullptr || f_list._first_item == nullptr) {
		return;
	}

	Node<T>* left_list_node = this->_first_item;
	Node<T>* right_list_node = f_list._first_item;

	Forward_list<T>* temp_list = new Forward_list<T>;

	if (left_list_node == nullptr && right_list_node != nullptr) {
		while (right_list_node != nullptr) {
			temp_list->push_back(right_list_node->value);
			right_list_node = right_list_node->next;
		}
	}
	else
		if (right_list_node == nullptr && left_list_node != nullptr) {
			while (left_list_node != nullptr) {
				temp_list->push_back(left_list_node->value);
				left_list_node = left_list_node->next;
			}
		}
		else
			while (left_list_node != nullptr && right_list_node != nullptr) {
				if (left_list_node->value < right_list_node->value) {
					temp_list->push_back(left_list_node->value);
					left_list_node = left_list_node->next;
				}
				else {
					temp_list->push_back(right_list_node->value);
					right_list_node = right_list_node->next;
				}
			}

	*this = *temp_list;
	temp_list->clear();
}

template <typename T>
void Forward_list<T>::pop_front(){
	if (_length == 0 && _first_item == nullptr){
		return;
	}
	Node<T> *tmp_node = _first_item->next;
	delete _first_item;
	_first_item = tmp_node;
	_length--;
}

template <typename T>
void Forward_list<T>::push_front(T value){
	Node<T> *node = new Node<T>;
	node->value = value;
	node->next = _first_item;
	_first_item = node;
	_length++;
}

template <typename T>
void Forward_list<T>::emplace(T value, int position){
	// position poxaren piti lini iterator
	if (position < 1 || position > _length + 1){
		error("6");
		return;
	}

	int i = 1; // index

	if (i == position){
		Node<T> *insert_node = new Node<int>;
		insert_node->value = value;
		insert_node->next = _first_item;
		_first_item = insert_node;
		_length++;
		return;
	}

	i++;

	Node<T> *ptr = _first_item->next;
	Node<T> *prev_ptr = _first_item;

	while (ptr != nullptr){
		if (i == position){
			Node<T> *insert_node = new Node<int>;
			insert_node->value = value;
			prev_ptr->next = insert_node;
			insert_node->next = ptr;
			_length++;
			return;
		}

		i++;
		prev_ptr = ptr;
		ptr = ptr->next;
	}
}

template <typename T>
void Forward_list<T>::remove(T del_value){
	Node<T> * select_ptr = this->_first_item;
	Node<T>* prev_node = nullptr;


	while(select_ptr->next != nullptr){
		if(select_ptr->value == del_value){

			if (select_ptr == this->_first_item) {
				this->pop_front();
			}
			else {
				Node<T>* temp_node = select_ptr->next;
				
				delete select_ptr;
				select_ptr = temp_node;
				temp_node = nullptr;
				prev_node->next = select_ptr;
			}

		}

		prev_node = select_ptr;
		select_ptr = select_ptr->next;
	}
}

template <typename T>
void Forward_list<T>::erase(int position){
	// petqa stana iterator
	if (position > _length){
		error("7");
		return;
	}

	int i = 1; // index

	Node<T> *select_ptr = _first_item;
	while (i != position){
		select_ptr = select_ptr->next;
		i++;
	}

	Node<T> *tmp_node = select_ptr;
	select_ptr = select_ptr->next;
	tmp_node->next = nullptr;

	while (select_ptr != nullptr){
		Node<T> *tmp = select_ptr->next;
		delete select_ptr;
		select_ptr = tmp;
		_length--;
	}
}

template <typename T>
void Forward_list<T>::insert(int position){
	// stana iterator
}

template <typename T>
void Forward_list<T>::reverse(){
	if(this->_length <= 1){
		return;
	}

	std::vector<Node<T>*> all_nodes;

	Node<T>* selected_ptr = this->_first_item;

	while(selected_ptr != nullptr){
		all_nodes.push_back(selected_ptr);
		selected_ptr = selected_ptr->next;
	}

	int end_index = all_nodes.size() - 1;

	for(int i = 0; i < all_nodes.size() / 2; ++i){
		if(i >= end_index){
			selected_ptr = nullptr;
			return;
		}

		std::swap(all_nodes[i]->value, all_nodes[end_index]->value);

		end_index--;
	}
}

template <typename T>
void Forward_list<T>::remove_if(){
}

template <typename T>
void Forward_list<T>::sort(){	// Khoar sort
	std::vector<T> all_elems;

	Node<T>* select_ptr = this->_first_item;

	while(select_ptr != nullptr){
		all_elems.push_back(select_ptr->value);

		select_ptr = select_ptr->next;
	}

	all_elems = quicSort(all_elems);

	select_ptr = this->_first_item;
	int i = 0;
	while(select_ptr != nullptr){
		select_ptr->value = all_elems[i++];
		select_ptr = select_ptr->next;
	}
}

template <typename T>
Forward_list<T> Forward_list<T>::operator=(Forward_list<T>& f_list) {
	this->clear();
	Node<T>* select_ptr = f_list._first_item;

	while (select_ptr != nullptr) {
		this->push_back(select_ptr->value);
		select_ptr = select_ptr->next;
	}

	return *this;
}

template <typename T>
Forward_list<T> Forward_list<T>::operator=(Forward_list<T>&& f_list) {
	if (this->_length != 0) {
		this->clear();
	}

	this->_length = f_list._length;
	this->_first_item = f_list._first_item;

	f_list._first_item = nullptr;

	return *this;
}

template <typename T>
Forward_list<T> Forward_list<T>::operator+(Forward_list<T>& f_list) {
	int max_size = this->_length > f_list._length ? this->_length : f_list._length;
	int min_size = this->_length < f_list._length ? this->_length : f_list._length;

	Forward_list<T> temp;

	Node<T>* this_ptr = this->_first_item;
	Node<T>* other_ptr = f_list._first_item;

	int i = 0;
	for (; i < min_size; ++i) {
		T tmp_value = other_ptr->value + this_ptr->value;
		temp.push_back(tmp_value);

		this_ptr = this_ptr->next;
		other_ptr = other_ptr->next;
	}

	Node<T>* select_node = this->_length > f_list._length ? this_ptr : other_ptr;

	for (; i < max_size; ++i) {
		temp.push_back(select_node->value);

		select_node = select_node->next;
	}

	return temp;
}

template <typename T>
void Forward_list<T>::operator+=(Forward_list<T>& f_list) {
	*this = *this + f_list;
}

template <typename T>
bool Forward_list<T>::operator==(const Forward_list<T>& f_list) {
	if (this == nullptr && f_list._first_item == nullptr) {
		return true;
	}

	if(this == nullptr && f_list != nullptr || this != nullptr && f_list == nullptr || this->_length != f_list._length){
		return false;
	}

	Node<T>* this_node = this->_first_item;
	Node<T>* other_node = f_list._first_item;

	for (int i = 0; i < this->_length; ++i) {
		if (this_node->value != other_node->value) {
			return false;
		}

		this_node = this_node->next;
		other_node = other_node->next;
	}

	return true;
}

template <typename T>
bool Forward_list<T>::operator!=(const Forward_list<T>& f_list) {
	return !(*this == f_list);
}

template <typename T>
bool Forward_list<T>::operator>(Forward_list<T>& f_list) {
	Node<T>* this_node = this->_first_item;
	Node<T>* other_node = f_list._first_item;

	while (this_node != nullptr && other_node != nullptr) {
		T this_val = this_node->value;
		T other_val = other_node->value;

		if(this_val != other_val){
			if (this_val > other_val) {
				return true;
			}
			return false;
		}

		if (this_node->next != nullptr) {
			this_node = this_node->next;
		}

		if (other_node->next != nullptr) {
			other_node = other_node->next;
		}
	}

	return false;
}

template <typename T>
bool Forward_list<T>::operator<(Forward_list<T>& f_list) {
	Node<T>* this_node = this->_first_item;
	Node<T>* other_node = f_list._first_item;

	while (this_node != nullptr && other_node != nullptr) {
		T this_val = this_node->value;
		T other_val = other_node->value;

		if (this_val != other_val) {
			if (this_val < other_val) {
				return true;
			}
			return false;
		}

		if (this_node->next != nullptr) {
			this_node = this_node->next;
		}

		if (other_node->next != nullptr) {
			other_node = other_node->next;
		}
	}

	return false;
}

template <typename T>
bool Forward_list<T>::operator>=(Forward_list<T>& f_list) {
	return (*this > f_list || *this == f_list);
}

template <typename T>
bool Forward_list<T>::operator<=(Forward_list<T>& f_list) {
	return (*this < f_list || *this == f_list);
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const Forward_list<T> &f_list){
	if (f_list._first_item == nullptr){
		os << "is empty\n";
		return os;
	}

	Node<T> *select_ptr = f_list._first_item;

	while (select_ptr != nullptr){
		os << select_ptr->value;
		std::cout << (select_ptr->next != nullptr ? ", " : ".\n");
		select_ptr = select_ptr->next;
	}

	return os;
}


#endif