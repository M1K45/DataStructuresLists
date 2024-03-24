#pragma once
#include <cmath>

struct Node2{
    int value;
    struct Node2 *next; 
    struct Node2 *previous;
};


class DoublyLinkedList{
private: 
    Node2 *head_;
    Node2 *tail_;
    int size_;
public:

    DoublyLinkedList();
    ~DoublyLinkedList();

	int  displaySize() const;

	void addBeginning(int element); // ok

	void removeBeginning(); // ok

    void addEnd(int element); // ok

    void removeEnd(); // ok

    void addRandom(int element); // ok? 

    void removeRandom(); 

    // Node2 reachNode2(int index);

    void display();

    void testDisplay();

    void search(int element);
 
};

DoublyLinkedList::DoublyLinkedList(): head_ {nullptr}, tail_ {nullptr}, size_ {0} {}
DoublyLinkedList::~DoublyLinkedList(){
    delete head_, tail_;
}

void DoublyLinkedList::display(){ // funkcja na brudno, usunie się ją
    std::cout << tail_ -> value << std::endl;
}

void DoublyLinkedList::addBeginning(int element){
    Node2 *n = new Node2;
    n -> previous = nullptr;
    n -> value = element;
    n -> next = head_;
    if (size_ == 0) {
        head_ = n;
        tail_ = head_;
    }
    head_ -> previous = n;
    head_ = n;
    size_ ++;
}

void DoublyLinkedList::removeBeginning(){
    Node2 *old = head_;
    head_ = old -> next;
    head_ -> previous = nullptr;
    delete old;
    size_ --;
    if (size_ == 0){
        head_ = nullptr;
        tail_ = nullptr;
    }
}

void DoublyLinkedList::addEnd(int element){

    // nowy węzeł
    Node2 *n = new Node2;
    n -> previous = tail_;
    n -> value = element;
    n -> next = nullptr;

    if (size_ != 0) tail_ -> next = n;
    tail_ = n;
    if (size_ == 0) head_ = tail_; // jeśli tablica jest pusta, to head i tail wzkazują na to samo.
    size_ ++;

}

void DoublyLinkedList::removeEnd(){
    struct Node2 *ptr = nullptr;
    ptr = tail_ -> previous;
    ptr -> next -> previous = nullptr;
    ptr -> next = nullptr;
    tail_ = ptr;

    size_ --;
    if (size_ == 0){ // jeśli usunie się ostatni element, to head i tail nie wzkazują na nic
        head_ = nullptr;
        tail_ = nullptr;
    }
}

void DoublyLinkedList::addRandom(int element){
    int index = rand() % size_;
	while (index == 0 && index == size_-1) index = rand() %size_; // losuje do skutku, aż wybrany zostanie indeks, który nie jest ani pierwszy, ani ostatni
  
    // tworzenie nowego węzła
    Node2 *n = new Node2;
    n -> value = element;  
    n -> previous = nullptr;
    n -> next = nullptr;

    // tworzenie pomocniczego wzkaźnika
    struct Node2 *ptr = nullptr;

    if (index <= floor((size_-1) /2) ) {

        ptr = head_;
        for (int i=1; i<index; i++){
            ptr = ptr -> next; 
        }

        n -> previous = ptr;
        n -> next = ptr -> next;

        ptr -> next -> previous = n;
        ptr -> next = n;

    } else {
        ptr = tail_;
        for (int i=(size_ -1); i>index; i--){
            ptr = ptr -> previous; 
        }
        
        n -> next = ptr;
        n -> previous = ptr -> previous;

        ptr -> previous -> next = n;
        ptr -> previous = n;
    }

    size_ ++; 

}

void DoublyLinkedList::removeRandom(){
    int index = rand() % size_;
	while (index == 0 && index == size_-1) index = rand() %size_; // losuje do skutku, aż wybrany zostanie indeks, który nie jest ani pierwszy, ani ostatni
    struct Node2 *ptr = nullptr;
    if (index <= floor((size_-1) /2) ) {
        ptr = head_;
        for (int i=1; i<index; i++){
            ptr = ptr -> next; 
        }
        ptr -> next = ptr -> next -> next;
        ptr -> next -> previous = ptr;
    } else {
        ptr = tail_;
        for (int i=(size_ -1); i>index; i--){
            ptr = ptr -> previous; 
        }
        ptr -> previous = ptr -> previous -> previous;
        ptr -> previous -> next = ptr;
    }    
    size_ --;
} 


void DoublyLinkedList::testDisplay(){
    struct Node2 *ptr = nullptr;
    ptr = head_;
    while (ptr -> next !=nullptr){
    std::cout << ptr -> value << ", ";
    ptr = ptr -> next; 
    }
    std::cout << ptr -> value << std::endl;
}

int DoublyLinkedList::displaySize() const{
    return size_;
}

void DoublyLinkedList::search(int element){ 
    struct Node2 *ptr = nullptr;

    ptr = head_;
    // Ostatni element przy użyciu wzkaźnika tail można znaleźć w czasie O(1), zamiast O(n)
    if (tail_ -> value == element){
    std::cout << "Element \"" << element << "\" found in " << size_ -1 << ". Node2.\n"; 
    return;
    }
    for (int i=0; i <size_; i++){ 
        if (ptr -> value == element) {
            std::cout << "Element \"" << element << "\" found in " << i+1 << ". Node2.\n";
            return;
        }
        ptr = ptr -> next;
    }
    std::cout << "Element \"" << element << "\" not found.\n";
}


