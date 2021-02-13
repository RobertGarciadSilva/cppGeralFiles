#include "List.hpp"

List::List(){
	_size = 0;
	_head = nullptr; 
}

void List::insert(int value){
    if(_size == 0){
        Node *n = new Node();
        _head = n;
        _head->_value = value;
        _head->_next = nullptr;
        _size++;
    }else{
        Node *newNode = new Node();
        newNode->_value = value;
        newNode->_next = _head;
        _head = newNode;
        _size++;
    }
}

void List::clearList() {
    if(_size > 0){
    Node *h = nullptr;
        while(_head != nullptr){
            h = _head;
            _head = _head->_next;
            delete h;
        }
    }
    _head = nullptr;
    _size = 0; 
}

void List::print(){
	Node* head = _head;
	if (_size > 0){
		while(head){
			std::cout << head->_value << " ";
			head = head->_next;
		}
		std::cout<<std::endl;
	}
	else{
	    std::cout<< "-" << std::endl;
	}
}

int List::removeFirst(){
    if(_size == 0){
        return 0;
    }
	Node* current = _head;
	_head = _head->_next;
	delete current;
    _size--;
	return current->_value;
}

int List::indexOf(int value){
	if (_size > 0){
		Node* head = _head;
		int index = 0;
		while(head && head->_value != value){
			index++;
			head = head->_next;
		}
		if (head->_value == value)
			return index; 
		return -1;
	}
	else{
		return -1;
	}
}

void List::remove(int value){
	if(_size == 0){
		return;
	}
	else if(_head->_value == value){
		Node* current = _head;
		_head = _head->_next;
		delete current;
        _size--;
	}
	else{
		Node* previous = _head;
		Node* current = _head->_next;
		while(current != nullptr) {
			if(current->_value == value) {
				break;
			}
			else {
				previous = current;
				current = current->_next;
			}
		}
		if(current == nullptr) {
			return;
		}
		else {
			previous->_next = current->_next;
			delete current;
		}
        _size--;
	}
}