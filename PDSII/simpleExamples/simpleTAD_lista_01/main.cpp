#include <iostream>
#include "List.hpp"

int main(){
    
    int n, k;
    List *L = new List();
    
    //std::cout << "Digite [N,K] - com um ENTER entre eles: " << std::endl;
    std::cin >> n >> k;
    
    for(int i = 0; i <= n; i++){
        L->insert(i);
    }
    L->print();
    std::cout << L->_size << std::endl;

    for(int i = 0; i < k; i++){
        L->removeFirst();
    }
    L->print(); 
    std::cout << L->_size << std::endl;
    

    if(L->_size != 0){
        Node *current = L->_head; 
        Node *next = current->_next;
        
        while(current != nullptr){
            if((current->_value % 2) == 0){
                L->remove(current->_value);
            }
            if(next == nullptr){ break;}
            current = next;
            next = next->_next;
        }
    }
    L->print(); 
    std::cout << L->_size << std::endl;
    
    
    L->clearList();
    delete L;
    L = nullptr;


	return 0;
}

/*
References:

[1]How to detect memory leaks using Valgrind
Acesso: https://www.youtube.com/watch?v=26jYoKkKM8Y
Data acesso: 20/08/2020

*/