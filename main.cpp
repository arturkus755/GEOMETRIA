#include <iostream>
#include <cmath>
#include "header.hpp"
#include "figury.hpp"

void sprawdz_punkt(wspolrzedne &punkt)
{
	if (punkt.x < 0)
	{
		punkt.x = 0;
		std::cerr << "\nWspolrzedna x < 0 - zresetowano wspolrzedna do 0!!!" << std::endl;
	}
	if (punkt.y < 0)
	{
		punkt.y = 0;
		std::cerr << "\nWspolrzedna y < 0 - zresetowano wspolrzedna do 0!!!" << std::endl;
	}
}

void wyswietl_wspolrzedne_punktu(wspolrzedne punkt)
{
	std::cout << "\nWspolrzedne punktu:\n" << std::endl;
	std::cout << "x = " << punkt.x << std::endl;
	std::cout << "y = " << punkt.y << std::endl;
	std::cout << std::endl;
}

wspolrzedne przesun_punkt(wspolrzedne &punkt, wspolrzedne wektor_przesuniecia)
{
	punkt.x += wektor_przesuniecia.x;
	punkt.y += wektor_przesuniecia.y;
	sprawdz_punkt(punkt);
	return punkt;
}

void ustaw_wspolrzedne_punktu(wspolrzedne &punkt)
{
	std::cout << "\nPodaj wspolrzedna x punktu/wektora: " << std::endl;
	std::cin >> punkt.x;
	std::cout << "\nPodaj wspolrzedna y punktu/wektora: " << std::endl;
	std::cin >> punkt.y;
}

unsigned long kwadrat_dlugosci_odcinka(wspolrzedne punkt1, wspolrzedne punkt2)
{
	return (punkt1.x - punkt2.x) * (punkt1.x - punkt2.x) + (punkt1.y - punkt2.y) * (punkt1.y - punkt2.y);
}

double dlugosc_odcinka(wspolrzedne punkt1, wspolrzedne punkt2)
{
	return sqrt(kwadrat_dlugosci_odcinka(punkt1, punkt2));
}

int main()
{
	trojkat t;
	t.wyswietl_wspolrzedne_trojkata();
	t.zainicjalizuj_trojkat();
	t.wyswietl_wspolrzedne_trojkata();
	std::cout << "Czy trojkat jest prostokatny? : " << t.czy_prostokatny() << std::endl;
	std::cout << "Czy trojkat jest rownoboczny? : " << t.czy_rownoboczny() << std::endl;
	std::cout << "Czy trojkat jest rownoramienny? : " << t.czy_rownoramienny() << std::endl;
	std::cout << "Obwod trojkata = " << t.obwod_trojkata() << std::endl;
	std::cout << "Pole trojkata = " << t.pole_trojkata() << std::endl;
	wspolrzedne u;
	std::cout << "Utworzono wektor u..." << std::endl;
	ustaw_wspolrzedne_punktu(u);
	wyswietl_wspolrzedne_punktu(u);
	std::cout << "Przesuniecie trojkata o wektor u..." << std::endl;
	t.przesun_trojkat(u);
	t.wyswietl_wspolrzedne_trojkata();
	std::cout << "Czy trojkat jest prostokatny? : " << t.czy_prostokatny() << std::endl;
	std::cout << "Czy trojkat jest rownoboczny? : " << t.czy_rownoboczny() << std::endl;
	std::cout << "Czy trojkat jest rownoramienny? : " << t.czy_rownoramienny() << std::endl;
	std::cout << "Obwod trojkata = " << t.obwod_trojkata() << std::endl;
	std::cout << "Pole trojkata = " << t.pole_trojkata() << std::endl;
}
//aaabbbccc
