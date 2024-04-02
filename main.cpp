#include "ArrayList.h"
#include "SinglyLinkedList.h"
#include "SinglyLinkedList_b.h"
#include "DoublyLinkedList.h"
#include "OperatingMenu.h"
#include <iostream>
#include <cstdlib>


//menu glowne 
void displayMainMenu(){
	std::cout << "\nJaka strukture chcesz zbadac?\n";
	std::cout << "1. Tablice dynamiczna\n";
	std::cout << "2. Lista jednokiedunkowa (bez wzkaznika tail)\n";
	std::cout << "3. Lista jednokiedunkowa (ze wzkaznikiem tail)\n";
	std::cout << "4. Dwukierunkowa liste wiazana\n";
	std::cout << "Wybierz numer struktury: ";
}



void menu(){
	int option;

	// wybor struktury do badan
	displayMainMenu();
	std::cin >> option;
	switch (option)
	{
	case 1:
	{
		std::cout << "\nWybrano tablice dynamiczna";
		ArrayList arr;
		operatingMenu<ArrayList>(arr);
		break;
	}
	case 2:
	{
		std::cout << "\nWybrano liste jednokierunkowa (bez wzkaznika tail)";
		SinglyLinkedList sl_a;
		operatingMenu<SinglyLinkedList>(sl_a);
		break;
	}
	case 3:
	{
		std::cout << "\nWybrano liste jednokierunkowa (ze wzkaznikiem tail)";
		SinglyLinkedList_b sl_b;
		operatingMenu<SinglyLinkedList_b>(sl_b);
		break;
	}
	case 4:
	{
		std::cout << "\nWybrano liste dwukierunkowa";
		DoublyLinkedList dl;
		operatingMenu<DoublyLinkedList>(dl);
		break;
	}
	default: 
	{
		std::cout << "\nWybrano nieprawidlowa opcje. Wybierz numer od 1 do 4 odpowiadający strukturze, ktora chcesz zbadac\n";
		menu();
		break;
	}
	}
}
int main() {
	menu();
	return 0;
}	