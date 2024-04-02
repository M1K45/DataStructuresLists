#pragma once

#include <iostream>
#include "SinglyLinkedList.h"
#include "ArrayList.h"

class SinglyLinkedList_b: public ArrayList
{
private: 
    Node *head_;
    Node *tail_;
    int size_;
public:

    SinglyLinkedList_b();

    ~SinglyLinkedList_b();

	void addBeginning(int element); 

	void removeBeginning(); 

    void addEnd(int element); 

    void removeEnd(); 

    void addRandom(int element); 

    void removeRandom(); 

    void search(int element);

    void display();

    void addBeginningMeasure(int numElements);

	void addEndMeasure(int numElements);

	void addRandomMeasure(int numElements);

	void removeBeginningMeasure(int numElements);

	void removeEndMeasure(int numElements);

	void removeRandomMeasure(int numElements);

	void searchMeasure(int numElements);

};



