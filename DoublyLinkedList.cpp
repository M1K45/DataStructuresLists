#include "DoublyLinkedList.h"

DoublyLinkedList::DoublyLinkedList(): head_ {nullptr}, tail_ {nullptr}, size_ {0} {}
DoublyLinkedList::~DoublyLinkedList(){
    delete head_, tail_;
}

void DoublyLinkedList::addBeginning(int element){

    // tworzenie nowego elementu
    Node2 *n = new Node2;
    n -> previous = nullptr;
    n -> value = element;
    n -> next = head_; // wzkaznik pierwszego elementu wzkazuje na to, na co pierwotnie wzkazuje head 
    //("pierwotny" pierwszy element)

    // jesli tablica jest pusta to na pierwszy element wzkazuje i head i tail
    if (size_ == 0) {
        head_ = n;
        tail_ = head_;
    }

    // wzkaznik "pierwotnego" pierwszego elementu wzkazuje na "nowy" pierwszy element
    head_ -> previous = n;

    // head wzkazuje na "nowy" pierwszy element
    head_ = n;

    size_ ++;
}

void DoublyLinkedList::removeBeginning(){
    	//zabezpieczenie przed proba usuniecia z pustej struktury
	if (size_ == 0){
		std::cout << "struktura juz jest pusta\n";
		return;
	}
	

    // pomocniczy wzkaznik do usuwania 
    Node2 *old = head_;

    // ustawnienie wzkaznika head na pierwotnie drugi wezel
    head_ = old -> next;

    // przestawienie wzkaznika pierwotnego drugiego wezla na null - po tym nie mozna juz wzkazac na usuwany wezel
    head_ -> previous = nullptr;

    delete old;
    size_ --;

    // jesli oproznimy liste, to head i tail nie wzkazuja na nic
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
    n -> next = nullptr;    // dla ostantiego wezla wzkaznik next nie wzkazuje na nic

    // pierwotnie ostatni element wzkazuje na nowy ostatni (jeśli takowy istniał, tym samym, jesli tablica nie byla pusta)
    if (size_ != 0) tail_ -> next = n;

    // przestawienie taila na nowy ostatni element
    tail_ = n;

    // jeśli dodawany wezel jest pierwszym w liscie, to  wzkazuje na niego zarowno head jak i tail.
    if (size_ == 0) head_ = tail_; 

    size_ ++;

}

void DoublyLinkedList::removeEnd(){
	//zabezpieczenie przed proba usuniecia z pustej struktury
	if (size_ == 0){
		std::cout << "struktura juz jest pusta\n";
		return;
	}

    // tworzenie pomocniczego wezla, ustawienie go na przed ostatniej pozycji. Za jego pomoca:
    struct Node2 *ptr = nullptr;
    ptr = tail_ -> previous;

    // ustawiamy wzkaznik previous usuwanego wezla na null
    ptr -> next -> previous = nullptr;

    // przestawiamy wzkaznik next wezla, ktory staje sie ostatni na null
    ptr -> next = nullptr;

    // i przestawia sie na niego tail
    tail_ = ptr;

    size_ --;
    if (size_ == 0){ // jeśli usunie się ostatni element, to head i tail nie wzkazują na nic
        head_ = nullptr;
        tail_ = nullptr;
    }
}

void DoublyLinkedList::addRandom(int element){

    int index = rand() % size_;
    // losuje do skutku, aż wybrany zostanie indeks, który nie jest ani pierwszy, ani ostatni
	while (index == 0 && index == size_-1) index = rand() %size_; 

    // tworzenie nowego węzła
    Node2 *n = new Node2;
    n -> value = element;  
    n -> previous = nullptr;
    n -> next = nullptr;

    // tworzenie pomocniczego wzkaźnika
    struct Node2 *ptr = nullptr;

    // w zaleznosci od tego, czy wylosowany wezel jest blizej wzkaznika head, czy tail, 
    // wybiera sie wzkaznik od ktorego zaczyna sie przejscie
    if (index <= floor((size_-1) /2) ) {
        
        // przejscie za pomoca wzkaznikow next, zaczynajac od poczatku
        ptr = head_;
        for (int i=1; i<index; i++){
            ptr = ptr -> next; 
        }

        // ustawianie wzkaznikow nowego wezla na sasiadow
        n -> previous = ptr;
        n -> next = ptr -> next;

        // ustawianie wzaznikow sasiadow na nowy wezel
        ptr -> next -> previous = n;
        ptr -> next = n;

    } else {

        //przejscie za pomoca wzkaznikow previous, zaczynajac od konca
        ptr = tail_;
        for (int i=(size_ -1); i>index; i--){
            ptr = ptr -> previous; 
        }
        // ustawianie wzkaznikow nowego wezla na sasiadow (odwrotna kolejnosc z uwagi na zaczynanie od konca)
        n -> next = ptr;
        n -> previous = ptr -> previous;

        // ustawianie wzaznikow sasiadow na nowy wezel
        ptr -> previous -> next = n;
        ptr -> previous = n;
    }

    size_ ++; 

}

void DoublyLinkedList::removeRandom(){

    //zabezpieczenie przed proba usuniecia z pustej struktury
	if (size_ == 0){
		std::cout << "struktura juz jest pusta\n";
		return;
	}

    int index = rand() % size_;
    // losuje do skutku, aż wybrany zostanie indeks, który nie jest ani pierwszy, ani ostatni
	while (index == 0 && index == size_-1) index = rand() %size_; 

    // pomocniczy wzkaznik do przechodzenia przez listę
    struct Node2 *ptr = nullptr;

    // w zaleznosci od tego, czy wylosowany wezel jest blizej wzkaznika head, czy tail, od tego wzkaznika zaczyna sie przejscie,
    // dziala ono analogicznie, jak przy addRandom()
    if (index <= floor((size_-1) /2) ) {
        ptr = head_;

        for (int i=1; i<index; i++){
            ptr = ptr -> next; 
        }

        // przestawianie sasiednich wezlow, tak aby wzkazywaly na siebie nawzajem, tym samym pomijajac ten wezel, ktory chcemy usunac
        ptr -> next = ptr -> next -> next;
        ptr -> next -> previous = ptr;
    } else {
        ptr = tail_;

        for (int i=(size_ -1); i>index; i--){
            ptr = ptr -> previous; 
        }

        // przestawianie sasiednich wezlow, tak aby wzkazywaly na siebie nawzajem, tym samym pomijajac ten wezel, ktory chcemy usunac
        ptr -> previous = ptr -> previous -> previous;
        ptr -> previous -> next = ptr;
    }    
    size_ --;
} 

void DoublyLinkedList::search(int element){ 

    // pomocniczy wzkaznik do przechodzenia przez listę
    struct Node2 *ptr = nullptr;
    ptr = head_;

    // Ostatni element przy użyciu wzkaźnika tail można znaleźć w czasie O(1), zamiast O(n)
    if (tail_ -> value == element){
    std::cout << "Element \"" << element << "\" found in " << size_ -1 << ". Node2.\n"; 
    return;
    }

    // Przechodzenie przez wszystkie wezly i porownywanie zawartych w nich wartosci do szukanej,
    // po znalezieniu, funkcja wypisuje na ekran odpowiednia informacje i konczy dzialanie
    for (int i=0; i <size_; i++){ 
        if (ptr -> value == element) {
            std::cout << "Element \"" << element << "\" found in " << i+1 << ". Node2.\n";
            return;
        }
        ptr = ptr -> next;
    }

    //Jeśli do tego momentu nie nastąpilo wyjscie z funkcji, to elementu nie ma w strukturze
    std::cout << "Element \"" << element << "\" not found.\n";
}

// funkcja na potrzeby poprzednio używanego menu, służąca do wyswietlania zawartosci struktury
void DoublyLinkedList::display(){

    // pomocniczy wzkaznik
    struct Node2 *ptr = nullptr;
    ptr = head_;

    // wyswietlanie wszystkich wartosci po kolei
    while (ptr -> next !=nullptr){
    std::cout << ptr -> value << ", ";
    ptr = ptr -> next; 
    }
    std::cout << ptr -> value << std::endl;
}



