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
	wektor srodek_ekranu = {ekran1.x/2, ekran1.y/2};
	std::cout << srodek_ekranu << std::endl;
	std::vector<trojkat> trojkaty;
	
	for(int i = 0; i < 10; ++i)
		trojkaty.emplace_back(wektor(generuj_liczbe_losowa(), generuj_liczbe_losowa()),
		wektor(generuj_liczbe_losowa(), generuj_liczbe_losowa()),
		wektor(generuj_liczbe_losowa(), generuj_liczbe_losowa()));

	for( const auto &t : trojkaty )
		std::cout << t << std::endl;

	std::cout << "\n" << *szukaj_trojkata_najblizej_srodka(trojkaty, ekran1) << std::endl;
}