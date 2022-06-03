#ifndef _FORWARD_LIST_CONSTRUCTORS
#define _FORWARD_LIST_CONSTRUCTORS


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
Forward_list<T>::Forward_list(const Forward_list &&move_obj){
	if (move_obj._first_item == nullptr){
		this->_first_item = nullptr;
		this->_length = 0;
		return;
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


#endif // _FORWARD_LIST_CONSTRUCTORS