#pragma once
#include "SinglyLinkedList.h"


class SinglyLinkedList_b{
private: 
    Node *head_;
    Node *tail_;
    int size_;
public:

    SinglyLinkedList_b();
    ~SinglyLinkedList_b();

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

SinglyLinkedList_b::SinglyLinkedList_b(): head_ {nullptr}, tail_ {nullptr}, size_ {0} {}
SinglyLinkedList_b::~SinglyLinkedList_b(){
    delete head_, tail_;
}

void SinglyLinkedList_b::display(){
    std::cout << tail_ -> value << std::endl;
}

void SinglyLinkedList_b::addBeginning(int element){
    
    // tworzenie nowego elementu
    Node *n = new Node;
    n -> value = element;
    n -> next = head_; // wzkaznik pierwszego elementu wzkazuje na to, na co pierwotnie wzkazuje head...

    head_ = n;         // ...a po tej zmianie można już przypisac head do nowego, pierwszego elementu

    if (size_ == 0) tail_ = n; // jeśli tablica jest pusta, to head i tail wzkazują na to samo.
    size_ ++;
}

void SinglyLinkedList_b::removeBeginning(){

    Node *old = head_;
    head_ = old -> next;
    delete old;
    size_ --;
    if (size_ == 0){
        head_ = nullptr;
        tail_ = nullptr;
    }
}

void SinglyLinkedList_b::addEnd(int element){
    Node *n = new Node;
    n -> value = element;
    n -> next = nullptr;

    if (size_ == 0) {
        tail_ = n;
        head_ = n;
        size_ ++;
        return;
    }
    tail_ -> next = n;
    tail_ = n;
    size_ ++;

}

void SinglyLinkedList_b::removeEnd(){

    struct Node *ptr = nullptr;
    ptr = head_;
    while (ptr -> next -> next !=nullptr){
        ptr = ptr -> next; 
    }
    tail_ = ptr;
    ptr -> next = nullptr;
    size_ --;
    if (size_ == 0){ // jeśli usunie się ostatni element, to head i tail nie wzkazują na nic
        head_ = nullptr;
        tail_ = nullptr;
    }
}

void SinglyLinkedList_b::addRandom(int element){
    int index = rand() % size_;
    // losuje do skutku, aż wybrany zostanie indeks, który nie jest ani pierwszy, ani ostatni
	while (index == 0 && index == size_-1) index = rand() %size_; 

    // pomocniczy wzkaznik do przechodzenia przez listę
    struct Node *ptr = nullptr;
    ptr = head_;

    // przejscie przez liste
    for (int i=1; i<index; i++){
        ptr = ptr -> next; 
    }

    Node *n = new Node;
    n -> value = element;
    n -> next = ptr -> next;
    ptr -> next = n;

}

void SinglyLinkedList_b::removeRandom(){
    int index = rand() % size_;
    // losuje do skutku, aż wybrany zostanie indeks, który nie jest ani pierwszy, ani ostatni
	while (index == 0 && index == size_-1) index = rand() %size_; 
    
    // pomocniczy wzkaznik do przechodzenia przez listę
    struct Node *ptr = nullptr;
    ptr = head_;

    // przejscie przez liste
    for (int i=1; i<index; i++){
        ptr = ptr -> next; 
    }

    // pomijanie wezla, ktorego chcemy usunac
    ptr -> next = ptr -> next -> next;
} 

// pomocnicza funkcja, wyswietla zawartosc struktur 
void SinglyLinkedList_b::testDisplay(){

    // pomocniczy wzkaznik do przechodzenia przez listę
    struct Node *ptr = nullptr;
    ptr = head_;

    while (ptr -> next !=nullptr){
    std::cout << ptr -> value << ", ";
    ptr = ptr -> next; 
    }
    std::cout << ptr -> value << std::endl;
}

int SinglyLinkedList_b::displaySize() const{
    return size_;
}

void SinglyLinkedList_b::search(int element){ 

    // pomocniczy wzkaznik do przechodzenia przez listę
    struct Node *ptr = nullptr;
    ptr = head_;

    // Ostatni element przy użyciu wzkaźnika tail można znaleźć w czasie O(1), zamiast O(n)...
    if (tail_ -> value == element){ 
        std::cout << "Element \"" << element << "\" found in " << size_ -1 << ". node.\n"; 
        return;     // ...  wtedy oczywiscie funkcja konczy dzialac wczesniej
    }

    // Przechodzenie przez wszystkie wezly i porownywanie zawartych w nich wartosci do szukanej,
    // po znalezieniu, funkcja wypisuje na ekran odpowiednia informacje i konczy dzialanie
    for (int i=0; i < size_; i++){ 
        if (ptr -> value == element) {
            std::cout << "Element \"" << element << "\" found in " << i+1 << ". node.\n";
            return;
        }
        ptr = ptr -> next;
    }

    //Jeśli do tego momentu nie nastąpilo wyjscie z funkcji, to elementu nie ma w strukturze
    std::cout << "Element \"" << element << "\" not found.\n";
}


