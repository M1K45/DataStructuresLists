#pragma once 

#include "ArrayList.h"
#include "SinglyLinkedList.h"
#include "SinglyLinkedList_b.h"
#include "DoublyLinkedList.h"

// menu sluzace do mierzenia operacji na strukturach
template <class Structure> void operatingMenu(Structure s){
	int numElements;
	std::cout << "\nPodaj liczbe elementow na potrzeby badan:"; 

	std::cin >> numElements;
	
	char operation;
	std::cout << "\nWybierz operacje do zmierzenia:\n";
	std::cout << "(W konsoli zostanie wyświetlony średni wynik ze wszystkich przeporowadzonych pomiarow danej operacji.\n";
	std::cout << "Wszystkie zmierzone czasy zostaną zapisane do pliku .csv, który zostanie utworzony przy pierwszej wykonanej operacji na danej strukturze)\n";

	std::cout << "a) Dodaj liczbę na początek\n";
	std::cout << "b) Dodaj liczbę na koniec\n";
	std::cout << "c) Dodaj liczbe w losowe miejce\n";
	std::cout << "d) Usun pierwsza liczbe\n";
	std::cout << "e) Usun ostatnia liczbe\n";
	std::cout << "f) Usun liczbe w losowym miejscu (poza pierwszym i ostatnim)\n";
	std::cout << "g) Wyszukaj w strukturze wygenerowana uprzednio liczbe\n";
	std::cout << "h) Zmierz wszystko, co trzeba zmierzyc, w ramach danego punktu pomiarowego po kolei\n";
	std::cout << "i) Zmierz wszystko, co trzeba zmierzyc we wszystkich punktach pomiarowych, po kolei\n";

	std::cout << "Wybierz operacje, ktora chcesz wykonac (wpisz litere od \"a\" do \"i\"): ";

	std::cin >> operation;
	switch (operation)
	{
		case 'a': 
	{
		s.addBeginningMeasure(numElements);
		operatingMenu<Structure>(s);
		break;
	}
	case 'b':
	{
		s.addEndMeasure(numElements);
		operatingMenu<Structure>(s);
		break;
	}
	case 'c':
	{
		s.addRandomMeasure(numElements);
		operatingMenu<Structure>(s);
		break;
	}

	case 'd':
	{
		s.removeBeginningMeasure(numElements);
		operatingMenu<Structure>(s);
		break;
	}

	case 'e':
	{
		s.removeEndMeasure(numElements);
		operatingMenu<Structure>(s);
		break;
	}

	case 'f':
	{
		s.removeRandomMeasure(numElements);
		operatingMenu<Structure>(s);
		break;
	}

	case 'g':
	{
		s.searchMeasure(numElements);
		operatingMenu<Structure>(s);
		break;
	}
	case 'h':
	{
		s.addBeginningMeasure(numElements);

		s.addEndMeasure(numElements);

		s.addRandomMeasure(numElements);

		s.removeBeginningMeasure(numElements);

		s.removeEndMeasure(numElements);

		s.removeRandomMeasure(numElements);

		s.searchMeasure(numElements);

		operatingMenu<Structure>(s);
		break;
	}

		case 'i':
	{
		for (int i=20000; i<= 160000; i+=20000){
			s.addBeginningMeasure(i);

			s.addEndMeasure(i);

			s.addRandomMeasure(i);

			s.removeBeginningMeasure(i);

			s.removeEndMeasure(i);

			s.removeRandomMeasure(i);

			s.searchMeasure(i);
		}
		operatingMenu<Structure>(s);
		break;
	}

	default:
		std::cout << "\nPodano nieprawidlowa opcje. Wybierz litere od \"a\" do \"i\" odpowiadajaca operacji, ktora chcesz wykonac.\n";
		operatingMenu<Structure>(s);
		break;
	}
}