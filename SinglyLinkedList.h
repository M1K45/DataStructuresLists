#pragma once
#include "ArrayList.h"    
#include <iostream>
#include <cstring>
#include <cstdlib>

// implementacja wezla zawierajacego zmienna przechowujaca wartosc i wzkaznik na nastepny wezel
struct Node{
    int value;
    struct Node *next;
};

class SinglyLinkedList: public ArrayList 
{
private: 
    Node *head_;
    int size_;

public:

    SinglyLinkedList();

    ~SinglyLinkedList();
  
	void addBeginning(int element); 

	void removeBeginning();

    void addEnd(int element); 

    void removeEnd(); 

    void addRandom(int element); 

    void removeRandom(); 

    void search(int element);

    void displayContent();

    void addBeginningMeasure(int numElements);

	void addEndMeasure(int numElements);

	void addRandomMeasure(int numElements);

	void removeBeginningMeasure(int numElements);

	void removeEndMeasure(int numElements);

	void removeRandomMeasure(int numElements);

	void searchMeasure(int numElements);
};





