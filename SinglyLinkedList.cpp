#include <SinglyLinkedList.h>

SinglyLinkedList::SinglyLinkedList(): head_ {nullptr}, size_ {0} {}
SinglyLinkedList::~SinglyLinkedList(){
    delete head_;
}

void SinglyLinkedList::addBeginning(int element){

    // dodanie nowego wezla; przypisanie wartosci oraz ustawienie wzkaznika, 
    // na to, na co wzkazuje obecnie head - na element, ktory ostatecnie bedzie tym nastepnym
    Node *n = new Node;
    n -> value = element;
    n -> next = head_;

    // ustawienie head'a na nowy pierwszy elememnt
    head_ = n;

    size_ ++;
}

void SinglyLinkedList::removeBeginning(){

	//zabezpieczenie przed proba usuniecia z pustej struktury
	if (size_ == 0){
		std::cout << "struktura juz jest pusta\n";
		return;
	}

    // pomocniczy wzkaznik, sluzacy do przestawienia wzkaznika head
    Node *old = head_;
    head_ = old -> next;

    //usuniecie pomocniczego wzkaznika
    delete old;
    size_ --;

    if (size_ == 0) head_ = nullptr;
}

void SinglyLinkedList::addEnd(int element){

    // // dodanie nowego wezla; przypisanie wartosci oraz ustawienie wzkaznika, 
    // na to, na co ma ostatecznie wzkazywac (jako ostatni wezel, na null)
    Node *n = new Node;
    n -> value = element;
    n -> next = nullptr;

    // jesli tablica na poczatku jest pusta to nalezy ustawic wzkaznik head na nowy wezel
    if (size_ == 0){
        head_ = n;
        size_ ++;
        return;
    }

    // tworzenie pomocniczego wzkaznia, sluzacego do przechodzenia przez liste
    struct Node *ptr = nullptr;
    ptr = head_;
    while (ptr -> next !=nullptr){
        ptr = ptr -> next; 
    }

    // przestawienie wzkaznika "starego" ostatniego elementu tak, aby wzkazywal na nowy ostatni element
    ptr -> next = n;

    size_ ++;
}

void SinglyLinkedList::removeEnd(){

	//zabezpieczenie przed proba usuniecia z pustej struktury
	if (size_ == 0){
		std::cout << "struktura juz jest pusta\n";
		return;
	}

    // tworzenie pomocniczego wzkaznia, sluzacego do przechodzenia przez liste
    struct Node *ptr = nullptr;
    ptr = head_;
    while (ptr -> next -> next !=nullptr){
        ptr = ptr -> next; 
    }

    // przestawienie wskaznika przedostatniego elementu, ktory do teraz wzkazywal na ostani, na null
    ptr -> next = nullptr;

    size_ --;

    if (size_ == 0) head_ = nullptr;
}

void SinglyLinkedList::addRandom(int element){

	// losowanie kolejnosci dla nowego elementu, ktore dziala do skutku, az wybrany zostanie indeks, który nie jest pierwszy, ani ostatni
    int index = rand() % size_;
	while (index == 0 && index == size_-1) index = rand() %size_; 

    // pomocniczy wzkaznik, ktory przechodzi przez liste i ostatecznie wzkazuje na element,
    // ktory jest jedno miejsce przed wylosowana kolejnoscia
    struct Node *ptr = nullptr;
    ptr = head_;
    for (int i=1; i<index; i++){
        ptr = ptr -> next; 
    }

    // Stworzenie nowego wezla, inicjalizacja wartoci
    Node *n = new Node;
    n -> value = element;

    // przestawianie wzkaznikow: nowy element wzkazuje na ten element, ktory poprzednio był w jego "indeksie"
    // a element, ktory ma byc przed nowym, wzkazuje na niego
    n -> next = ptr -> next;
    ptr -> next = n;

    size_ ++;
}

void SinglyLinkedList::removeRandom(){

	//zabezpieczenie przed proba usuniecia z pustej struktury
	if (size_ == 0){
		std::cout << "struktura juz jest pusta\n";
		return;
	}

    // losowanie "indeks" usuwanego elementu, ktore dziala do skutku, az wybrany zostanie "indeks", który nie jest pierwszy, ani ostatni
    int index = rand() % size_;
	while (index == 0 && index == size_-1) index = rand() %size_; 

    // pomocniczy wzkaznik, ktory przechodzi przez liste i ostatecznie wzkazuje na element,
    // ktory jest jedno miejsce przed wylosowana kolejnoscia   
    struct Node *ptr = nullptr;
    ptr = head_;
    for (int i=1; i<index; i++){
        ptr = ptr -> next; 
    }

    // przestawienie pomocniczego wzkaznika tak, aby wezel, na ktory wzkazuje wzkazal na wezel dalej, 
    // pomijajac element, ktory chcemy usunac
    ptr -> next = ptr -> next -> next;

} 

void SinglyLinkedList::search(int element){

    // utworzenie pomocniczego wzkaznika, ustawionego na poczatek listy
    struct Node *ptr = nullptr;
    ptr = head_;

    // przestawianie wzkaznika na kolejne elementy do momentu znalezienia pasujacego elementu. Wtedy funkcja sie konczy
    for (int i=0; i <size_; i++){ 
        if (ptr -> value == element) {
            std::cout << "Element \"" << element << "\" found in " << i+1 << ". node.\n";
            return;
        }
        ptr = ptr -> next;
    }

    // Jesli fnkcja do tego momentu sie nie skonczyla, to elementu nie ma w strukturze
    std::cout << "Element \"" << element << "\" not found.\n";
}

void SinglyLinkedList::displayContent(){

    // pomocniczy wzkaznik ptr wzkazuje na pierwszy wezel
    struct Node *ptr = nullptr;
    ptr = head_;

    // ptr po kolei wzkazuje na nastepne wezly i wyswietla wartosci w nich przechowywane
    while (ptr -> next !=nullptr){
    std::cout << ptr -> value << ", ";
    ptr = ptr -> next; 
    }
    std::cout << ptr -> value << std::endl;
}


