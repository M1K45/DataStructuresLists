#pragma once
#include <iostream>
#include <cstring>
#include <cstdlib>

// node implementation containig value and pointer to a next node
struct Node{
    int value;
    struct Node *next;
};

class SinglyLinkedList{
private: 
    Node *head_;
    int size_;
public:

    SinglyLinkedList();
    ~SinglyLinkedList();

	int  displaySize() const;
    

	void addBeginning(int element); // ok

	void removeBeginning(); // ok

    void addEnd(int element); // ok

    void removeEnd(); // ok

    void addRandom(int element); // ok? 

    void removeRandom(); 

    // Node reachNode(int index);

    void display();

    void testDisplay();

    void search(int element);
 
};




SinglyLinkedList::SinglyLinkedList(): head_ {nullptr}, size_ {0} {}

SinglyLinkedList::~SinglyLinkedList(){
    delete head_;
}

void SinglyLinkedList::display(){
    // std::cout <<  std::endl;
}

void SinglyLinkedList::addBeginning(int element){
    Node *n = new Node;
    n -> value = element;
    n -> next = head_;
    head_ = n;
    size_ ++;
}

void SinglyLinkedList::removeBeginning(){
    Node *old = head_;
    head_ = old -> next;
    delete old;
    size_ --;
}

void SinglyLinkedList::addEnd(int element){

    Node *n = new Node;
    n -> value = element;
    n -> next = nullptr;


    if (size_ == 0){
        head_ = n;
        size_ ++;
        return;
    }
    struct Node *ptr = nullptr;
    ptr = head_;
    while (ptr -> next !=nullptr){
        ptr = ptr -> next; 
    }

    ptr -> next = n;
    size_ ++;
}

void SinglyLinkedList::removeEnd(){
    struct Node *ptr = nullptr;
    ptr = head_;
    while (ptr -> next -> next !=nullptr){
        ptr = ptr -> next; 
    }
    ptr -> next = nullptr;
    size_ --;
}

void SinglyLinkedList::addRandom(int element){
    int index = rand() % size_;
	while (index == 0 && index == size_-1) index = rand() %size_; // losuje do skutku, aż wybrany zostanie indeks, który nie jest ani pierwszy, ani ostatni
    struct Node *ptr = nullptr;
    ptr = head_;
    for (int i=1; i<index; i++){
        ptr = ptr -> next; 
    }
    Node *n = new Node;
    n -> value = element;
    n -> next = ptr -> next;
    ptr -> next = n;

}

void SinglyLinkedList::removeRandom(){
    int index = rand() % size_;
	while (index == 0 && index == size_-1) index = rand() %size_; // losuje do skutku, aż wybrany zostanie indeks, który nie jest ani pierwszy, ani ostatni
    struct Node *ptr = nullptr;
    ptr = head_;
    for (int i=1; i<index; i++){
        ptr = ptr -> next; 
    }
    ptr -> next = ptr -> next -> next;
} 


void SinglyLinkedList::testDisplay(){
    struct Node *ptr = nullptr;
    ptr = head_;
    while (ptr -> next !=nullptr){
    std::cout << ptr -> value << ", ";
    ptr = ptr -> next; 
    }
    std::cout << ptr -> value << std::endl;
}

int SinglyLinkedList::displaySize() const{
    return size_;
}

void SinglyLinkedList::search(int element){
    struct Node *ptr = nullptr;
    ptr = head_;
    for (int i=0; i <size_; i++){ 
        if (ptr -> value == element) {
            std::cout << "Element \"" << element << "\" found in " << i+1 << ". node.\n";
            return;
        }
        ptr = ptr -> next;
    }
    std::cout << "Element \"" << element << "\" not found.\n";
}


