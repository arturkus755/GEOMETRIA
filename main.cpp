#include <iostream>
#include <cmath>
#include <ctime>

#include "geometria.hpp"

int generuj_liczbe_losowa()
{
	return rand() % 1001; 
}

int main()
{
	srand(time(NULL));
	ekran ekran1;
	std::cout << "\nRozdzelczosc ekranu : " << ekran1 << std::endl;
	int rozmiar = 10;
	trojkat *tablica_trojkatow = new trojkat [rozmiar];
	std::cout << "\nTrojkaty :" << std::endl;
	for(int i = 0; i < rozmiar; ++i)
		tablica_trojkatow[i] = 
		{
			wektor(generuj_liczbe_losowa(), generuj_liczbe_losowa()),
			wektor(generuj_liczbe_losowa(), generuj_liczbe_losowa()),
			wektor(generuj_liczbe_losowa(), generuj_liczbe_losowa())
		};

	for(int i = 0; i < rozmiar; ++i)
		std::cout << tablica_trojkatow[i] << std::endl;

	std::cout << "\nTrojkat z wirzcholkiem najblizej srodka ekranu :" << std::endl;
	trojkat najblizszy = *szukaj_trojkata_najblizej_srodka(tablica_trojkatow, rozmiar, ekran1);
	std::cout << najblizszy << std::endl;
	std::cout << "\ndlugosc jednego z bokow trojkata\n" << najblizszy.dlugosc_boku(2) << std::endl;
}
