#pragma once

#include <math.h>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <time.h>
#include <fstream>
#include <string>

class ArrayList
{
private:
	int *array_;
	unsigned size_;
	unsigned capacity_;

public:

	ArrayList();
	ArrayList(unsigned capacity); // za pomoca drugiego konstruktora mozna ustawic od razu pojemnosc tablicy

	~ArrayList();

	// definicje funkcji odpowiedzialnych za badane operacje
	void addBeginning(int element);

	void removeBeginning();

	void addEnd(int element);

	void removeEnd();

	void addRandom(int element);

	void removeRandom();

	void search(int element) const;

	void doubleSize();

	// funkcje sluzace do mierzenia danych operacji 

	void addBeginningMeasure(int numElements);

	void addEndMeasure(int numElements);

	void addRandomMeasure(int numElements);

	void removeBeginningMeasure(int numElements);

	void removeEndMeasure(int numElements);

	void removeRandomMeasure(int numElements);

	void searchMeasure(int numElements);

};
