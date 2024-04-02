#include "SinglyLinkedList.h"

void SinglyLinkedList::addBeginningMeasure(int numElements){

    double srednia;
	SinglyLinkedList list_a[10];
    clock_t start, stop;
	double duration;
	std::ofstream file;

	// otwieranie pliku .csv
	file.open("pomiary_lista_jednokierunkowa_a.csv", std::ios::app);
	file << "Czasy dodawania na poczatku dla listy jednokierunkowej bez wzkaznika tail dla punktow pomiarowych: " << numElements << std::endl;
 
	for (int j = 0; j<10; j++){
		file << "\nZiarno dla wartosci punktu pomiarowego: " << j+1 << std::endl;
		srand(j+1);

		for (int i=0; i<numElements; i++){ // wypęłnianie listy okreslona iloscia liczb
            list_a[j].addBeginning(rand());
		}
		// dodanie nowego losowego elementu 
		srand (11); // osobne ziarno dla liczb dodawanych do struktury
		for (int k=0; k<4; k++){
			// mierzenie czasu, zapisywanie wyniku do arkusza
			start = clock();
			list_a[j].addBeginning(rand());
			duration = clock() - start;
			file << double(duration)/CLOCKS_PER_SEC * pow(10.0, 6.0) << std::endl;

			//dodajemy czasy, aby potem wyciagnac z nich srednia
			srednia += duration;

			//usuwanie dodanego elementu, aby nastepny mogl byc dodatny do tablicy o takim samym rozmiarze
			list_a[j]. removeBeginning();
		}
	}
	srednia /= 40;
	file << "srednia: \n" << srednia << std::endl; 
}

void SinglyLinkedList::addEndMeasure(int numElements){
    double srednia;
	SinglyLinkedList list_a[10];
    clock_t start, stop;
	double duration;
	std::ofstream file;
	file.open("pomiary_lista_jednokierunkowa_a.csv", std::ios::app);
	file << "Czasy dodawania na koncu dla listy jednokierunkowej bez wzkaznika tail dla punktow pomiarowych: " << numElements << std::endl;
 
	for (int j = 0; j<10; j++){
		file << "\nZiarno dla wartosci punktu pomiarowego: " << j+1 << std::endl;
		srand(j+1);

		for (int i=0; i<numElements; i++){ // wypęłnianie listy okreslona iloscia liczb
            list_a[j].addBeginning(rand());
		}
		// dodanie nowego losowego elementu 
		srand (11); // osobne ziarno dla liczb dodawanych do struktury
		for (int k=0; k<4; k++){
			// mierzenie czasu, zapisywanie wyniku do arkusza
			start = clock();
			list_a[j].addEnd(rand());
			duration = clock() - start;
			file << double(duration)/CLOCKS_PER_SEC * pow(10.0, 6.0) << std::endl;

			//dodajemy czasy, aby potem wyciagnac z nich srednia
			srednia += duration;

			//usuwanie dodanego elementu, aby nastepny mogl byc dodatny do tablicy o takim samym rozmiarze
			list_a[j]. removeBeginning();
		}
	}
	srednia /= 40;
	file << "srednia: \n" << srednia << std::endl; 
}

void SinglyLinkedList::addRandomMeasure(int numElements){

    double srednia;
	SinglyLinkedList list_a[10];
    clock_t start, stop;
	double duration;
	std::ofstream file;
	file.open("pomiary_lista_jednokierunkowa_a.csv", std::ios::app);
	file << "Czasy dodawania w losowym miejscu dla listy jednokierunkowej bez wzkaznika tail dla punktow pomiarowych: " << numElements << std::endl;
 
	for (int j = 0; j<10; j++){
		file << "\nZiarno dla wartosci punktu pomiarowego: " << j+1 << std::endl;
		srand(j+1);

		for (int i=0; i<numElements; i++){ 
            list_a[j].addBeginning(rand());
		}
		
		srand (11); 
		for (int k=0; k<4; k++){

			start = clock();
			list_a[j].addRandom(rand());
			duration = clock() - start;
			file << double(duration)/CLOCKS_PER_SEC * pow(10.0, 6.0) << std::endl;

			srednia += duration;

			list_a[j]. removeBeginning();
		}
	}
	srednia /= 40;
	file << "srednia: \n" << srednia << std::endl; 
}

void SinglyLinkedList::removeBeginningMeasure(int numElements){
	double srednia;
	SinglyLinkedList list_a[10];
    clock_t start;
	double duration;
	std::ofstream file;
	file.open("pomiary_lista_jednokierunkowa_a.csv", std::ios::app);
	file << "Czasy usuwania na początku dla listy jednokierunkowej bez wzkaznika tail dla punktow pomiarowych: " << numElements << std::endl;

	for (int j = 0; j<10; j++){
		file << "\nZiarno dla wartosci punktu pomiarowego: " << j+1 << std::endl;
		srand(j+1);
		
		for (int i=0; i<numElements; i++){
            list_a[j].addBeginning(rand());
		}

		start = clock();
		list_a[j].removeBeginning();
		duration = clock() - start;
		file << double(duration)/CLOCKS_PER_SEC * pow(10.0, 6.0) << std::endl;

		srednia += duration;
	}
	srednia /= 10;
	file << "srednia: \n" << srednia << std::endl; 
}	

void SinglyLinkedList::removeEndMeasure(int numElements){
	double srednia;
	SinglyLinkedList list_a[10];
    clock_t start;
	double duration;
	std::ofstream file;
	file.open("pomiary_lista_jednokierunkowa_a.csv", std::ios::app);
	file << "Czasy usuwania na koncu dla listy jednokierunkowej bez wzkaznika tail dla punktow pomiarowych: " << numElements << std::endl;

	for (int j = 0; j<10; j++){
		file << "\nZiarno dla wartosci punktu pomiarowego: " << j+1 << std::endl;
		srand(j+1);

		for (int i=0; i<numElements; i++){
            list_a[j].addBeginning(rand());
		}

		start = clock();
		list_a[j].removeEnd();
		duration = clock() - start;
		file << double(duration)/CLOCKS_PER_SEC * pow(10.0, 6.0) << std::endl;

		srednia += duration;
	}

	srednia /= 10;
	file << "srednia: \n" << srednia << std::endl;
}

void SinglyLinkedList::removeRandomMeasure(int numElements){
	double srednia;
	SinglyLinkedList list_a[10];
    clock_t start;
	double duration;
	std::ofstream file;
	file.open("pomiary_lista_jednokierunkowa_a.csv", std::ios::app);
	file << "Czasy usuwania w losowym miejscu dla listy jednokierunkowej bez wzkaznika tail dla punktow pomiarowych: " << numElements << std::endl;

	for (int j = 0; j<10; j++){
		file << "\nZiarno dla wartosci punktu pomiarowego: " << j+1 << std::endl;
		srand(j+1);

		for (int i=0; i<numElements; i++){
            list_a[j].addBeginning(rand());
		}

		start = clock();
		list_a[j].removeRandom();
		duration = clock() - start;
		file << double(duration)/CLOCKS_PER_SEC * pow(10.0, 6.0) << std::endl;

		srednia += duration;
	}
	srednia /= 10;
	file << "srednia: \n" << srednia << std::endl; 
}

void SinglyLinkedList::searchMeasure(int numElements){
	double srednia;
	SinglyLinkedList list_a[10];
    clock_t start;
	double duration;
	std::ofstream file;
	file.open("pomiary_lista_jednokierunkowa_a.csv", std::ios::app);
	file << "Czasy wyszukiwania dla listy jednokierunkowej bez wzkaznika tails dla punktow pomiarowych: " << numElements << std::endl;

	for (int j = 0; j<10; j++){
		file << "\nZiarno dla wartosci punktu pomiarowego: " << j+1 << std::endl;
		srand(j+1);

		for (int i=0; i<numElements; i++){
            list_a[j].addBeginning(rand());
		}
		srand(11);
		for (int i=0; i<4; i++){
			start = clock();
			list_a[j].search(rand());
			duration = clock() - start;
			file << double(duration)/CLOCKS_PER_SEC * pow(10.0, 6.0) << std::endl;
		}

		srednia += duration;
		}
	
	srednia /= 40;
	file << "srednia: \n" << srednia << std::endl; 
}