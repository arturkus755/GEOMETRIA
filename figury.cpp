#include "figury.hpp"
#include <iostream>
#include <cmath>

void trojkat::zainicjalizuj_trojkat()
{
	std::cout << "\nPodaj wspolrzedne wierzcholkow trojkata:" << std::endl;
	for (int i = 0; i < 3; ++i)
	{
		std::cout << "\nWierzcholek " << i + 1 << ":" << std::endl;
		ustaw_wspolrzedne_punktu(punkty[i]);
		sprawdz_punkt(punkty[i]);
	}
}

void trojkat::wyswietl_wspolrzedne_trojkata()
{
	std::cout << "\nWierzchołki trojkata:\n" << std::endl;
	for (int i = 0; i < 3; ++i)
	{
		std::cout << "Punkt " << i + 1 << ":" << std::endl;
		std::cout << "x = " << punkty[i].x << std::endl;
		std::cout << "y = " << punkty[i].y << std::endl;
		std::cout << std::endl;
	}
}

double trojkat::obwod_trojkata()
{
	return dlugosc_odcinka(punkty[0],punkty[1]) + dlugosc_odcinka(punkty[1],punkty[2]) + dlugosc_odcinka(punkty[2],punkty[0]);
}

double trojkat::pole_trojkata()
{
	return abs((punkty[1].x - punkty[0].x) * (punkty[2].y - punkty[0].y) - (punkty[1].y - punkty[0].y) * (punkty[2].x - punkty[0].x))/2.0;
}

void trojkat::przesun_trojkat(wspolrzedne wektor_przesuniecia)
{
	for (int i = 0; i < 3; ++i)
	{
		std::cout << "\nPrzesuniecie Wierzcholka " << i + 1 << "..." << std::endl;
		przesun_punkt(punkty[i], wektor_przesuniecia);
	}
}

bool trojkat::czy_prostokatny()
{
	bool wynik = false;
	for (int i = 0; i < 3; ++i)
	{
		if (kwadrat_dlugosci_odcinka(punkty[i], punkty[(i + 1) % 3]) + kwadrat_dlugosci_odcinka(punkty[(i + 1) % 3], punkty[(i + 2) % 3]) ==
		kwadrat_dlugosci_odcinka(punkty[(i + 2) % 3], punkty[i]))
			wynik = true;
	}
	return wynik;
}

bool trojkat::czy_rownoboczny()
{
	bool wynik = false;
	if (kwadrat_dlugosci_odcinka(punkty[0], punkty[1]) == kwadrat_dlugosci_odcinka(punkty[1], punkty[2]) && 
	kwadrat_dlugosci_odcinka(punkty[2], punkty[0]) == kwadrat_dlugosci_odcinka(punkty[1], punkty[2]))
		wynik = true;
	return wynik;
}

bool trojkat::czy_rownoramienny()
{
	bool wynik = false;
	for (int i = 0; i < 3; ++i)
	{
		if (kwadrat_dlugosci_odcinka(punkty[i], punkty[(i + 1) % 3]) == kwadrat_dlugosci_odcinka(punkty[(i + 1) % 3], punkty[(i + 2) % 3]))
			wynik = true;
	}
	return wynik;
}
