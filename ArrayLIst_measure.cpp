#include "ArrayList.h"

void ArrayList::addBeginningMeasure(int numElements){
	double srednia;
	ArrayList arr[10];
    clock_t start, stop;
	double duration;
	std::ofstream file;
	file.open("pomiary_tablica_dynamiczna.csv", std::ios::app);
	file << "Czasy dodawania na poczatku dla tablicy dynamicznej dla punktow pomiarowych: " << numElements << std::endl;
	// for (10 powtorzen iteracja seeedow)
	// for z dodawaniem 4 losowych elementow 
	// mierzymy kazde dodawanie i zapisujemy do pliku .csv + sumujemy
	// usuwamy ten ostatni element, aby dodac kolejny 
	// z sumy robimy srednia, wypisujemy na ekran  
	for (int j = 0; j<10; j++){
		file << "\nZiarno dla wartosci punktu pomiarowego: " << j+1 << std::endl;
		srand(j+1);
		// zapełnienie tablicy pseudolosowymi elementami, poni
		for (int i=0; i<numElements; i++){

			if (arr[j].size_ == arr[j].capacity_) arr[j].doubleSize();
	
	
			for (int i=arr[j].size_-1; i>= 0; i--){
				arr[j].array_[i+1] = arr[j].array_[i];
			}
	
			arr[j].array_[0] = rand();
			arr[j].size_++;
		}
		// dodanie nowego losowego elementu 
		srand (11); // osobne ziarno dla liczb dodawanych do struktury
		for (int k=0; k<4; k++){
			// mierzenie czasu, zapisywanie wyniku do arkusza
			start = clock();
			arr[j].addBeginning(rand());
			duration = clock() - start;
			file << double(duration)/CLOCKS_PER_SEC * pow(10.0, 6.0) << std::endl;

			//dodajemy czasy, aby potem wyciagnac z nich srednia
			srednia += duration;

			//usuwanie dodanego elementu, aby nastepny mogl byc dodatny do tablicy o takim samym rozmiarze
			arr[j]. removeBeginning();
		}
	}
	srednia /= 40;
	file << "srednia: \n" << srednia << std::endl;	 
}

void ArrayList::addEndMeasure(int numElements){
	double srednia;
	ArrayList arr[10];
    clock_t start, stop;
	double duration;
	std::ofstream file;
	file.open("pomiary_tablica_dynamiczna.csv", std::ios::app);
	file << "Czasy dodawania na koncu dla tablicy dynamicznej dla punktow pomiarowych: " << numElements << std::endl;
	for (int j = 0; j<10; j++){
		file << "\nZiarno dla wartosci punktu pomiarowego: " << j+1 << std::endl;
		srand(j+1);
		// zapełnienie tablicy pseudolosowymi elementami, poni
		for (int i=0; i<numElements; i++){

			if (arr[j].size_ == arr[j].capacity_) arr[j].doubleSize();
	
	
			for (int i=arr[j].size_-1; i>= 0; i--){
				arr[j].array_[i+1] = arr[j].array_[i];
			}
	
			arr[j].array_[0] = rand();
			arr[j].size_++;
		}
		// dodanie nowego losowego elementu 
		srand (11); // osobne ziarno dla liczb dodawanych do struktury
		for (int k=0; k<4; k++){
			// mierzenie czasu, zapisywanie wyniku do arkusza
			start = clock();
			arr[j].addEnd(rand());
			duration = clock() - start;
			file << double(duration)/CLOCKS_PER_SEC * pow(10.0, 6.0) << std::endl;

			//dodajemy czasy, aby potem wyciagnac z nich srednia
			srednia += duration;

			//usuwanie dodanego elementu, aby nastepny mogl byc dodatny do tablicy o takim samym rozmiarze
			arr[j]. removeBeginning();
		}
	}
	srednia /= 40;
	file << "srednia: \n" << srednia << std::endl; 
}

void ArrayList::addRandomMeasure(int numElements){
	double srednia;
	ArrayList arr[10];
    clock_t start, stop;
	double duration;
	std::ofstream file;
	file.open("pomiary_tablica_dynamiczna.csv", std::ios::app);
	file << "Czasy dodawania w losowym miejscu dla tablicy dynamicznej dla punktow pomiarowych: " << numElements << std::endl;
	for (int j = 0; j<10; j++){
		file << "\nZiarno dla wartosci punktu pomiarowego: " << j+1 << std::endl;
		srand(j+1);
		// zapełnienie tablicy pseudolosowymi elementami, poni
		for (int i=0; i<numElements; i++){

			if (arr[j].size_ == arr[j].capacity_) arr[j].doubleSize();
	
	
			for (int i=arr[j].size_-1; i>= 0; i--){
				arr[j].array_[i+1] = arr[j].array_[i];
			}
	
			arr[j].array_[0] = rand();
			arr[j].size_++;
		}
		// dodanie nowego losowego elementu 
		srand (11); // osobne ziarno dla liczb dodawanych do struktury
		for (int k=0; k<4; k++){
			// mierzenie czasu, zapisywanie wyniku do arkusza
			start = clock();
			arr[j].addRandom(rand());
			duration = clock() - start;
			file << double(duration)/CLOCKS_PER_SEC * pow(10.0, 6.0) << std::endl;

			//dodajemy czasy, aby potem wyciagnac z nich srednia
			srednia += duration;

			//usuwanie dodanego elementu, aby nastepny mogl byc dodatny do tablicy o takim samym rozmiarze
			arr[j]. removeBeginning();
		}
	}
	srednia /= 40;
	file << "srednia: \n" << srednia << std::endl; 
}

void ArrayList::removeBeginningMeasure(int numElements){
	double srednia;
	ArrayList arr[10];
    clock_t start;
	double duration;
	std::ofstream file;
	file.open("pomiary_tablica_dynamiczna.csv", std::ios::app);
	file << "Czasy usuwania na poczatku dla tablicy dynamicznej dla punktow pomiarowych: " << numElements << std::endl;
	// for (10 powtorzen iteracja seeedow)
	// for z dodawaniem 4 losowych elementow 
	// mierzymy kazde dodawanie i zapisujemy do pliku .csv + sumujemy
	// usuwamy ten ostatni element, aby dodac kolejny 
	// z sumy robimy srednia, wypisujemy na ekran  
	for (int j = 0; j<10; j++){
		file << "\nZiarno dla wartosci punktu pomiarowego: " << j+1 << std::endl;
		srand(j+1);
		// zapełnienie tablicy pseudolosowymi elementami, poni
		for (int i=0; i<numElements; i++){

			if (arr[j].size_ == arr[j].capacity_) arr[j].doubleSize();
	
	
			for (int i=arr[j].size_-1; i>= 0; i--){
				arr[j].array_[i+1] = arr[j].array_[i];
			}
	
			arr[j].array_[0] = rand();
			arr[j].size_++;
		}

		start = clock();
		arr[j].removeBeginning();
		duration = clock() - start;
		file << double(duration)/CLOCKS_PER_SEC * pow(10.0, 6.0) << std::endl;

		//dodajemy czasy, aby potem wyciagnac z nich srednia
		srednia += duration;
		}
	
	srednia /= 10;
	file << "srednia: \n" << srednia << std::endl; 
}

void ArrayList::removeEndMeasure(int numElements){
	double srednia;
	ArrayList arr[10];
    clock_t start;
	double duration;
	std::ofstream file;
	file.open("pomiary_tablica_dynamiczna.csv", std::ios::app);
	file << "Czasy usuwania na koncu dla tablicy dynamicznej dla punktow pomiarowych: " << numElements << std::endl;
	// for (10 powtorzen iteracja seeedow)
	// for z dodawaniem 4 losowych elementow 
	// mierzymy kazde dodawanie i zapisujemy do pliku .csv + sumujemy
	// usuwamy ten ostatni element, aby dodac kolejny 
	// z sumy robimy srednia, wypisujemy na ekran  
	for (int j = 0; j<10; j++){
		file << "\nZiarno dla wartosci punktu pomiarowego: " << j+1 << std::endl;
		srand(j+1);
		// zapełnienie tablicy pseudolosowymi elementami, poni
		for (int i=0; i<numElements; i++){

			if (arr[j].size_ == arr[j].capacity_) arr[j].doubleSize();
	
	
			for (int i=arr[j].size_-1; i>= 0; i--){
				arr[j].array_[i+1] = arr[j].array_[i];
			}
	
			arr[j].array_[0] = rand();
			arr[j].size_++;
		}

		start = clock();
		arr[j].removeEnd();
		duration = clock() - start;
		file << double(duration)/CLOCKS_PER_SEC * pow(10.0, 6.0) << std::endl;

		//dodajemy czasy, aby potem wyciagnac z nich srednia
		srednia += duration;
	}
	
	srednia /= 10;
	file << "srednia: \n" << srednia << std::endl; 
}

void ArrayList::removeRandomMeasure(int numElements){
	double srednia;
	ArrayList arr[10];
    clock_t start;
	double duration;
	std::ofstream file;
	file.open("pomiary_tablica_dynamiczna.csv", std::ios::app);
	file << "Czasy usuwania w losowym miejscu dla tablicy dynamicznej dla punktow pomiarowych: " << numElements << std::endl;
	// for (10 powtorzen iteracja seeedow)
	// for z dodawaniem 4 losowych elementow 
	// mierzymy kazde dodawanie i zapisujemy do pliku .csv + sumujemy
	// usuwamy ten ostatni element, aby dodac kolejny 
	// z sumy robimy srednia, wypisujemy na ekran  
	for (int j = 0; j<10; j++){
		file << "\nZiarno dla wartosci punktu pomiarowego: " << j+1 << std::endl;
		srand(j+1);
		// zapełnienie tablicy pseudolosowymi elementami, poni
		for (int i=0; i<numElements; i++){

			if (arr[j].size_ == arr[j].capacity_) arr[j].doubleSize();
	
	
			for (int i=arr[j].size_-1; i>= 0; i--){
				arr[j].array_[i+1] = arr[j].array_[i];
			}
	
			arr[j].array_[0] = rand();
			arr[j].size_++;
		}

		start = clock();
		arr[j].removeRandom();
		duration = clock() - start;
		file << double(duration)/CLOCKS_PER_SEC * pow(10.0, 6.0) << std::endl;

		//dodajemy czasy, aby potem wyciagnac z nich srednia
		srednia += duration;
	}
	
	srednia /= 10;
	file << "srednia: \n" << srednia << std::endl;
}

// // funkcja uzywana na potrzeby menu, wyswietla cala zawartosc tablicy
// void ArrayList::displayContent() const{
// 	for (int i=0; i<size_; i++){
// 		if (i< size_ -1) std::cout << array_[i] << ", ";
// 		else std::cout << array_[i] << std::endl;
// 	}
// }

void ArrayList::searchMeasure(int numElements){
	double srednia;
	ArrayList arr[10];
    clock_t start;
	double duration;
	std::ofstream file;
	file.open("pomiary_tablica_dynamiczna.csv", std::ios::app);
	file << "Czasy wyszukiwania dla tablicy dynamicznej dla punktow pomiarowych: " << numElements << std::endl;

	for (int j = 0; j<10; j++){
		file << "\nZiarno dla wartosci punktu pomiarowego: " << j+1 << std::endl;
		srand(j+1);
		// zapełnienie tablicy pseudolosowymi elementami, poni
		for (int i=0; i<numElements; i++){

			if (arr[j].size_ == arr[j].capacity_) arr[j].doubleSize();
	
	
			for (int i=arr[j].size_-1; i>= 0; i--){
				arr[j].array_[i+1] = arr[j].array_[i];
			}
	
			arr[j].array_[0] = rand();
			arr[j].size_++;
		}
		srand(11);
		for (int i=0; i<4; i++){
			start = clock();
			arr[j].search(rand());
			duration = clock() - start;
			file << double(duration)/CLOCKS_PER_SEC * pow(10.0, 6.0) << std::endl;
		}
		//dodajemy czasy, aby potem wyciagnac z nich srednia
		srednia += duration;
		}
	
	srednia /= 40;
	file << "srednia: \n" << srednia << std::endl; 
}