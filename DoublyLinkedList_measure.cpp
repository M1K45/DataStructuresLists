#include "DoublyLinkedList.h"

void DoublyLinkedList::addBeginningMeasure(int numElements){
	//deklaracja porzebynch zmiennych 
    double srednia;
	DoublyLinkedList doubly[10];
    clock_t start, stop;
	double duration;
	std::ofstream file;

	// otworzenie pliku arkusza kalkulacyjnego
	file.open("pomiary_lista_dwukierunkowa.csv", std::ios::app);
	file << "Czasy dodawania na poczatku dla listy dwukierunkowej dla punktow pomiarowych: " << numElements << std::endl;
 
	for (int j = 0; j<10; j++){
		file << "\nZiarno dla wartosci punktu pomiarowego: " << j+1 << std::endl;
		srand(j+1);

		for (int i=0; i<numElements; i++){ // wypęłnianie listy okreslona iloscia liczb
            doubly[j].addBeginning(rand());
		}
		// dodanie nowego losowego elementu 
		srand (11); // osobne ziarno dla liczb dodawanych do struktury
		for (int k=0; k<4; k++){
			// mierzenie czasu, zapisywanie wyniku do arkusza
			start = clock();
			doubly[j].addBeginning(rand());
			duration = clock() - start;
			file << double(duration)/CLOCKS_PER_SEC * pow(10.0, 6.0) << std::endl;

			//dodajemy czasy, aby potem wyciagnac z nich srednia
			srednia += duration;

			//usuwanie dodanego elementu, aby nastepny mogl byc dodatny do tablicy o takim samym rozmiarze
			doubly[j]. removeBeginning();
		}
	}
	srednia /= 40;
	file << "srednia: \n" << srednia << std::endl; 
}

void DoublyLinkedList::addEndMeasure(int numElements){

    double srednia;
	DoublyLinkedList doubly[10];
    clock_t start, stop;
	double duration;
	std::ofstream file;

	file.open("pomiary_lista_dwukierunkowa.csv", std::ios::app);
	file << "Czasy dodawania na koncu dla listy dwukierunkowej dla punktow pomiarowych: " << numElements << std::endl;
 
	for (int j = 0; j<10; j++){
		file << "\nZiarno dla wartosci punktu pomiarowego: " << j+1 << std::endl;
		srand(j+1);

		for (int i=0; i<numElements; i++){ // wypęłnianie listy okreslona iloscia liczb
            doubly[j].addBeginning(rand());
		}
		// dodanie nowego losowego elementu 
		srand (11); // osobne ziarno dla liczb dodawanych do struktury
		for (int k=0; k<4; k++){
			// mierzenie czasu, zapisywanie wyniku do arkusza
			start = clock();
			doubly[j].addEnd(rand());
			duration = clock() - start;
			file << double(duration)/CLOCKS_PER_SEC * pow(10.0, 6.0) << std::endl;

			//dodajemy czasy, aby potem wyciagnac z nich srednia
			srednia += duration;

			//usuwanie dodanego elementu, aby nastepny mogl byc dodatny do tablicy o takim samym rozmiarze
			doubly[j]. removeBeginning();
		}
	}
	srednia /= 40;
	file << "srednia: \n" << srednia << std::endl; 
}

void DoublyLinkedList::addRandomMeasure(int numElements){

    double srednia;
	DoublyLinkedList doubly[10];
    clock_t start, stop;
	double duration;
	std::ofstream file;
	file.open("pomiary_lista_dwukierunkowa.csv", std::ios::app);
	file << "Czasy dodawania w losowym miejscu dla listy dwukierunkowej dla punktow pomiarowych: " << numElements << std::endl;
 
	for (int j = 0; j<10; j++){
		file << "\nZiarno dla wartosci punktu pomiarowego: " << j+1 << std::endl;
		srand(j+1);

		for (int i=0; i<numElements; i++){ 
            doubly[j].addBeginning(rand());
		}
		 
		srand (11); 
		for (int k=0; k<4; k++){
			
			start = clock();
			doubly[j].addRandom(rand());
			duration = clock() - start;
			file << double(duration)/CLOCKS_PER_SEC * pow(10.0, 6.0) << std::endl;

			
			srednia += duration;

		
			doubly[j]. removeBeginning();
		}
	}
	srednia /= 40;
	file << "srednia: \n" << srednia << std::endl; 
}

void DoublyLinkedList::removeBeginningMeasure(int numElements){
	double srednia;
	DoublyLinkedList doubly[10];
    clock_t start;
	double duration;
	std::ofstream file;
	file.open("pomiary_lista_dwukierunkowa.csv", std::ios::app);
	file << "Czasy usuwania na początku dla listy dwukierunkowej dla punktow pomiarowych: " << numElements << std::endl;

	for (int j = 0; j<10; j++){
		file << "\nZiarno dla wartosci punktu pomiarowego: " << j+1 << std::endl;
		srand(j+1);
		
		for (int i=0; i<numElements; i++){
            doubly[j].addBeginning(rand());
		}

		start = clock();
		doubly[j].removeBeginning();
		duration = clock() - start;
		file << double(duration)/CLOCKS_PER_SEC * pow(10.0, 6.0) << std::endl;

		
		srednia += duration;
	}
	srednia /= 10;
	file << "srednia: \n" << srednia << std::endl; 
}	

void DoublyLinkedList::removeEndMeasure(int numElements){
	double srednia;
	DoublyLinkedList doubly[10];
    clock_t start;
	double duration;
	std::ofstream file;
	file.open("pomiary_lista_dwukierunkowa.csv", std::ios::app);
	file << "Czasy usuwania na koncu dla listy dwukierunkowej dla punktow pomiarowych: " << numElements << std::endl;

	for (int j = 0; j<10; j++){
		file << "\nZiarno dla wartosci punktu pomiarowego: " << j+1 << std::endl;
		srand(j+1);
		
		for (int i=0; i<numElements; i++){
            doubly[j].addBeginning(rand());
		}

		start = clock();
		doubly[j].removeEnd();
		duration = clock() - start;
		file << double(duration)/CLOCKS_PER_SEC * pow(10.0, 6.0) << std::endl;

		srednia += duration;
	}

	srednia /= 10;
	file << "srednia: \n" << srednia << std::endl;
}

void DoublyLinkedList::removeRandomMeasure(int numElements){
	double srednia;
	DoublyLinkedList doubly[10];
    clock_t start;
	double duration;
	std::ofstream file;
	file.open("pomiary_lista_dwukierunkowa.csv", std::ios::app);
	file << "Czasy usuwania w losowym miejscu dla listy dwukierunkowej dla punktow pomiarowych: " << numElements << std::endl;

	for (int j = 0; j<10; j++){
		file << "\nZiarno dla wartosci punktu pomiarowego: " << j+1 << std::endl;
		srand(j+1);

		for (int i=0; i<numElements; i++){
            doubly[j].addBeginning(rand());
		}

		start = clock();
		doubly[j].removeRandom();
		duration = clock() - start;
		file << double(duration)/CLOCKS_PER_SEC * pow(10.0, 6.0) << std::endl;

		srednia += duration;
	}
	srednia /= 10;
	file << "srednia: \n" << srednia << std::endl; 
}

void DoublyLinkedList::searchMeasure(int numElements){
	double srednia;
	DoublyLinkedList doubly[10];
    clock_t start;
	double duration;
	std::ofstream file;
	file.open("pomiary_lista_dwukierunkowa.csv", std::ios::app);
	file << "Czasy wyszukiwania dla listy dwukierunkowej dla punktow pomiarowych: " << numElements << std::endl;

	for (int j = 0; j<10; j++){
		file << "\nZiarno dla wartosci punktu pomiarowego: " << j+1 << std::endl;
		srand(j+1);

		for (int i=0; i<numElements; i++){
            doubly[j].addBeginning(rand());
		}
		srand(11);
		for (int i=0; i<4; i++){
			start = clock();
			doubly[j].search(rand());
			duration = clock() - start;
			file << double(duration)/CLOCKS_PER_SEC * pow(10.0, 6.0) << std::endl;
		}

		srednia += duration;
		}
	
	srednia /= 40;
	file << "srednia: \n" << srednia << std::endl; 
}
