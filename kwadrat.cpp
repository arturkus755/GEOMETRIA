#include <iostream>
#include <cmath>

#include "kwadrat.hpp"
#include "wektor.hpp"

void kwadrat::ustaw_srod(const wektor &nowy_srodek)
{
	*srodek = nowy_srodek;
}

void kwadrat::ustaw_wierzch( const wektor &nowy_wierzcholek)
{
	*wierzcholek = nowy_wierzcholek;
}

kwadrat kwadrat::operator+(const wektor &dodajnik)
{
	kwadrat k{*this};
	*k.wierzcholek = *k.wierzcholek + dodajnik;
	*k.srodek = *k.srodek + dodajnik;
	return k;
}

kwadrat kwadrat::operator-(const wektor &odjemnik)
{
	kwadrat k{*this};
	*k.wierzcholek = *k.wierzcholek - odjemnik;
	*k.srodek = *k.srodek - odjemnik;
	return k;
}

double kwadrat::dlugosc_boku() const
{
	return (2.0 * srodek->odleglosc_od(*wierzcholek)) / sqrt(2);
}

double kwadrat::obwod() const
{
	return 4.0 * dlugosc_boku();
}
double kwadrat::pole() const
{
	return dlugosc_boku() * dlugosc_boku();
}


std::ostream &operator<<(std::ostream &s, const kwadrat &k)
{
	s << *k.wsp_srod() << ", " << *k.wsp_wierzch();
	return s;
}

