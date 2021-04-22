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
	std::vector<trojkat> trojkaty;
	std::cout << "\nTrojkaty :" << std::endl;
	for(int i = 0; i < 10; ++i)
		trojkaty.emplace_back(wektor(generuj_liczbe_losowa(), generuj_liczbe_losowa()),
		wektor(generuj_liczbe_losowa(), generuj_liczbe_losowa()),
		wektor(generuj_liczbe_losowa(), generuj_liczbe_losowa()));

	for( const auto &t : trojkaty )
		std::cout << t << std::endl;

	std::cout << "\nTrojkat z wirzcholkiem najblizej srodka ekranu :" << std::endl;
	trojkat najblizszy = *szukaj_trojkata_najblizej_srodka(trojkaty, ekran1);
	std::cout << najblizszy << std::endl;
	std::cout << "\ndlugosc jednego z bokow trojkata\n" << najblizszy.dlugosc_boku(2) << std::endl;
}
