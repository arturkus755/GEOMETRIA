#include <iostream>
#include <cmath>

#include "romb.hpp"
#include "ekran.hpp"

romb::romb(const ekran &e)
{
	m_srodek = wektor{e.zwroc_roz_x() / 2, e.zwroc_roz_x() / 2};
	m_wierzcholek = wektor{e.zwroc_roz_x() / 2, e.zwroc_roz_x() / 2};
	m_stosunek_przekatnych = 1.0;
}

void romb::opis() const
{
	std::cout << "romb      ";
}

void romb::ustaw_stosunek_przekatnych(double stosunek_przekatnych)
{
	m_stosunek_przekatnych = stosunek_przekatnych;
}

double romb::dlugosc_boku() const
{
	return sqrt(zwroc_wierzch().odleglosc_od(zwroc_srod()) * zwroc_wierzch().odleglosc_od(zwroc_srod()) +
		zwroc_wierzch().odleglosc_od(zwroc_srod()) * 1.0/m_stosunek_przekatnych *
		zwroc_wierzch().odleglosc_od(zwroc_srod()) * 1.0/m_stosunek_przekatnych);
}

double romb::obwod() const
{
	return dlugosc_boku() * 4.0;
}

double romb::pole() const
{
	return (zwroc_wierzch().odleglosc_od(zwroc_srod()) * zwroc_wierzch().odleglosc_od(zwroc_srod())
		* 1/m_stosunek_przekatnych * 2.0);
}