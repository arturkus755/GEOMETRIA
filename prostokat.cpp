#include <iostream>
#include <cmath>

#include "prostokat.hpp"
#include "ekran.hpp"

prostokat::prostokat(const ekran &e)
{
	m_srodek = wektor{e.zwroc_roz_x() / 2.0, e.zwroc_roz_x() / 2.0};
	m_wierzcholek = wektor{e.zwroc_roz_x() / 2.0, e.zwroc_roz_x() / 2.0};
	m_kat_miedzy_przekatnymi = M_PI / 2.0;
}

void prostokat::opis() const
{
	std::cout << "prostokat";
}

void prostokat::ustaw_kat_miedzy_przekatnymi(double kat_miedzy_przekatnymi)
{
	m_kat_miedzy_przekatnymi = kat_miedzy_przekatnymi;
}

double prostokat::dlugosc_boku(unsigned int nr_boku) const
{
	nr_boku %= 2;
	if (!nr_boku)
		return 2.0 * zwroc_wierzch().odleglosc_od(zwroc_srod()) * sin(m_kat_miedzy_przekatnymi / 2.0);
	else
		return 2.0 * zwroc_wierzch().odleglosc_od(zwroc_srod()) * cos(m_kat_miedzy_przekatnymi / 2.0);
}

double prostokat::obwod() const
{
	return (dlugosc_boku(0) + dlugosc_boku(1)) * 2.0;
}

double prostokat::pole() const
{
	return dlugosc_boku(0) * dlugosc_boku(1);
}