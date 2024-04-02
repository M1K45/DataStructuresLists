#include "ArrayList.h"

//Konstruktor tworzy pusta liste (size =0) o zadanej po utworzeniu pojemnosci...
ArrayList::ArrayList(unsigned capacity): size_{0}, capacity_{capacity}, array_{nullptr}
{
	array_ = new int[capacity_];
}

// ... lub gdy jej nie poda ustawia ja domyslnie na 5 
ArrayList::ArrayList() : size_{ 0 }, capacity_{ 5 }, array_{ nullptr }
{
	array_ = new int[capacity_];
}

// Destruktor usuwa tablice i ustawia wskaznik na nullptr
ArrayList::~ArrayList()
{
	if (array_ != nullptr) {
		delete[] array_;
		array_ = nullptr;
	}
}

void ArrayList::addBeginning(int element) {

	// zwiekszenie rozmiaru w przypadku przekroczenia zakresu
	if (size_ == capacity_) doubleSize();
	
	// petla odpowiedzialna za zrobienie miejsca w tablicy dla nowego elementu
	for (int i=size_-1; i>= 0; i--){
		array_[i+1] = array_[i];
	}
	
	// dodanie nowego elementu i inkrementacja zmiennej przechowywującej informacje o rozmiarze
	array_[0] = element;
	size_++;
}

void ArrayList::removeBeginning() {
	//zabezpieczenie przed proba usuniecia z pustej struktury
	if (size_ == 0){
		std::cout << "struktura juz jest pusta\n";
		return;
	}

	//zastepywanie kazdego elementu wartoscia nastepnego, jesli rozmiar jest równy 1 to funkcja removeBeginning przejdzie od 
	//razu do wywolania rmeoveEnd - jedyny elemeny tablicy jest również ostatnim
	if (size_ > 1){
		for (int i=1; i<size_; i++) array_[i-1] = array_[i];
	}

	//usuwanie ostatniego elementu (jego kopia jest elementem przedostatnim)
	removeEnd();
	// dekrementacja zmiennej size zawiera sie w tej funkcji
}

void ArrayList::addEnd(int element) {

	// zwiekszenie rozmiaru w przypadku przekroczenia zakresu
	if (size_  == capacity_) doubleSize();

	//dodawanie nowego elementu i inkrementacja zmiennej przechowywującej informacje o rozmiarze
	array_[size_] = element;
	size_++;
}

void ArrayList::removeEnd() {

	//zabezpieczenie przed proba usuniecia z pustej struktury
	if (size_ == 0){
		std::cout << "struktura juz jest pusta\n";
		return;
	}
	
	// stworzenie nowej tablicy o takiej samej pojemnosci co stara
	int *tempArray = new int [capacity_];

	// przeniesienie do nowej tablicy wszystkie elementy poza ostatnim
	std::memcpy(tempArray, array_, sizeof(int) * (size_ -1));

	// usuniecie starej tablicy i zmiana nazwy nowej
    delete[] array_;
	array_ = tempArray;

	//dekrementacja zmiennej przechowywującej informacje o rozmiarze
	size_ --;
}

void ArrayList::addRandom(int element) {

	// zwiekszenie rozmiaru w przypadku przekroczenia zakresu
	if (size_ == capacity_) doubleSize();

	// losowanie indeksu w ktorym ma znalezc sie nowy element, ktore dziala do skutku, az wybrany zostanie indeks, który nie jest pierwszy, ani ostatni
	int index = rand() %size_;
	while (index == 0 && index == size_-1) index = rand() %size_; 

	// petla odpowiedzialna za zrobienie miejsca w tablicy dla nowego elementu
		for (int i=size_-1; i>= index; i--){
		array_[i+1] = array_[i];
	}

	// dodanie nowego elementu i inkrementacja zmiennej przechowywującej informacje o rozmiarze
	array_[index] = element;
	size_++;
}

void ArrayList::removeRandom() {
	//zabezpieczenie przed proba usuniecia z pustej struktury
	if (size_ == 0){
		std::cout << "struktura juz jest pusta\n";
		return;
	}
	
	// losowanie indeksu w ktorym ma znalezc sie nowy element, ktore dziala do skutku, az wybrany zostanie indeks, który nie jest pierwszy, ani ostatni
	int index = rand() %size_;
	while (index == 0 && index == size_-1) index = rand() %size_; 

	//zastepywanie kazdego elementu wartoscia nastepnego, poczynając od indeksu wylosowanego powyzej
		for (int i= index+1; i<size_; i++){
		array_[i-1] = array_[i];
	}

	//usuwanie ostatniego elementu (jego kopia jest elementem przedostatnim)
	removeEnd(); // dekrementacja zmiennej size zawiera sie w tej funkcji
}

void ArrayList::search(int element) const {


	// petla przeszukujaca tablice w poszukiwaniu pasujacego elementu
	for (int i = 0; i < size_; i++) {
		if (array_[i] == element) {
			std::cout << "\nelement " << element << " was found at index: " << i << std::endl;
			return;
		}
	}

	// jesli funkcja w tym momencie sie nie skonczyla, to nie ma elementu w strukturze
	std::cout << "\nno element \"" << element << "\" found\n";
	return;
}

void ArrayList::doubleSize() {

	// stworzenie tablicy o dwukrotnie wiekszym rozmiarze
	capacity_ *=2;	
	int *tempArray = new int [capacity_];  

	//przeniesienie zawartosci starej tablicy do nowej i zmiana nazw
	std::memcpy(tempArray, array_, sizeof(int) * size_); 
	delete[] array_; 	
	array_ = tempArray;
}







