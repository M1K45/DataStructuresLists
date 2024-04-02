#pragma once
#include <cmath>
#include "ArrayList.h"
#include <iostream>

struct Node2{
    int value;
    struct Node2 *next; 
    struct Node2 *previous;
};

class DoublyLinkedList: public ArrayList
{

public:

    Node2 *head_;
    Node2 *tail_;
    int size_;

    DoublyLinkedList();
    ~DoublyLinkedList();

    //operacje

	void addBeginning(int element);

	void removeBeginning(); 

    void addEnd(int element); 

    void removeEnd(); 

    void addRandom(int element);

    void removeRandom(); 

    void search(int element);

    void display();

    //funkcje do pomiarów

    void addBeginningMeasure(int numElements);

	void addEndMeasure(int numElements);

	void addRandomMeasure(int numElements);

	void removeBeginningMeasure(int numElements);

	void removeEndMeasure(int numElements);

	void removeRandomMeasure(int numElements);

	void searchMeasure(int numElements);

};

