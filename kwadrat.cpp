#include <iostream>
#include <cmath>

#include "kwadrat.hpp"
#include "ekran.hpp"

kwadrat::kwadrat(const ekran &e)
{
	m_srodek = wektor{e.zwroc_roz_x() / 2, e.zwroc_roz_x() / 2};
	m_wierzcholek = wektor{e.zwroc_roz_x() / 2, e.zwroc_roz_x() / 2};
}

void kwadrat::opis() const
{
	std::cout << "kwadrat   ";
}

wektor kwadrat::zwroc_wierzch() const
{
	return m_wierzcholek;
}
wektor kwadrat::zwroc_srod() const
{
	return m_srodek;
}

void kwadrat::ustaw_srod(const wektor &nowy_srodek)
{
	m_srodek = nowy_srodek;
}

void kwadrat::ustaw_wierzch( const wektor &nowy_wierzcholek)
{
	m_wierzcholek = nowy_wierzcholek;
}

kwadrat kwadrat::operator+(const wektor &dodajnik)
{
	kwadrat k{*this};
	k.m_wierzcholek = k.m_wierzcholek + dodajnik;
	k.m_srodek = k.m_srodek + dodajnik;
	return k;
}

kwadrat kwadrat::operator-(const wektor &odjemnik)
{
	kwadrat k{*this};
	k.m_wierzcholek = k.m_wierzcholek - odjemnik;
	k.m_srodek = k.m_srodek - odjemnik;
	return k;
}

double kwadrat::dlugosc_boku() const
{
	return (2.0 * m_srodek.odleglosc_od(m_wierzcholek)) / sqrt(2);
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
	s << k.zwroc_srod() << ", " << k.zwroc_wierzch();
	return s;
}

