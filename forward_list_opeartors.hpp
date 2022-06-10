#ifndef _FORWARD_LIST_OPERATORS
#define _FORWARD_LIST_OPERATORS

template <typename T>
Forward_list<T> Forward_list<T>::operator=(const Forward_list<T>& f_list) {
  if (this->_length != 0) {
		this->clear();
	}

	Node<T>* select_ptr = f_list._first_item;

	while (select_ptr != nullptr) {
		this->push_back(select_ptr->value);
		select_ptr = select_ptr->next;
	}

	return this;
}

template <typename T>
Forward_list<T>& Forward_list<T>::operator=(const Forward_list<T>&& f_list) {
	if (this->_length != 0) {
		this->clear();
	}

	this->_length = f_list._length;
	this->_first_item = f_list._first_item;

	f_list._first_item = nullptr;
	f_list._length = 0;

	return this;
}

template <typename T>
Forward_list<T> Forward_list<T>::operator+(const Forward_list<T>& f_list) {
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
Forward_list<T>& Forward_list<T>::operator+=(const Forward_list<T>& f_list) {
	*this = *this + f_list;
	return this;
}

template <typename T>
bool Forward_list<T>::operator==(const Forward_list<T>& f_list) {
	if (this->_first_item == nullptr && f_list._first_item == nullptr) {
		return true;
	}

	if((this->_first_item == nullptr && f_list._first_item != nullptr) || (this->_first_item != nullptr && f_list._first_item == nullptr) || (this->_length != f_list._length)){
		return false;
	}

	Node<T>* this_node = this->_first_item;
	Node<T>* other_node = f_list._first_item;

	for (int i = 0; i < this->_length; ++i) {
		if (this_node->value != other_node->value) {
			return false;
		}

		if(	(this_node->next == nullptr) || 
				(other_node->next == nullptr) && 
				(this_node->next != other_node->next)){
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
bool Forward_list<T>::operator>(const Forward_list<T>& f_list) {
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
bool Forward_list<T>::operator<(const Forward_list<T>& f_list) {
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
bool Forward_list<T>::operator>=(const Forward_list<T>& f_list) {
	return (*this > f_list || *this == f_list);
}

template <typename T>
bool Forward_list<T>::operator<=(const Forward_list<T>& f_list) {
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
		os << (select_ptr->next != nullptr ? ", " : ".\n");
		select_ptr = select_ptr->next;
	}

	return os;
}

#endif //_FORWARD_LIST_OPERATORS