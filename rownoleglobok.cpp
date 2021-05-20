#include <iostream>
#include <cmath>

#include "rownoleglobok.hpp"
#include "ekran.hpp"

rownoleglobok::rownoleglobok(const ekran &e)
{
	ustaw_srod(wektor{e.zwroc_roz_x() / 2.0, e.zwroc_roz_x() / 2.0});
	ustaw_wierzch(wektor{e.zwroc_roz_x() / 2.0, e.zwroc_roz_x() / 2.0});
	ustaw_kat_miedzy_przekatnymi(M_PI / 2.0);
	ustaw_stosunek_przekatnych(1.0);
}

void rownoleglobok::opis() const
{
	std::cout << "rownoleglobok";
}

double rownoleglobok::dlugosc_boku(unsigned int nr_boku) const
{
	wektor a = zwroc_wierzch() - zwroc_srod();
	wektor as = a * (1.0 / zwroc_stosunek_przekatnych());
	wektor aso = as.obrot(zwroc_kat_miedzy_przekatnymi());
	if (!(nr_boku % 2))
		return aso.odleglosc_od(zwroc_wierzch() - zwroc_srod());
	else
		return ((zwroc_wierzch() - zwroc_srod()) * (1.0 / zwroc_stosunek_przekatnych())).obrot(-M_PI + zwroc_kat_miedzy_przekatnymi()).
			odleglosc_od(zwroc_wierzch() - zwroc_srod());
}

double rownoleglobok::obwod() const
{
	return (dlugosc_boku(0) + dlugosc_boku(1)) * 2.0;
}

double rownoleglobok::pole() const
{
	return zwroc_wierzch().odleglosc_od(zwroc_srod()) * 2.0 * zwroc_wierzch().odleglosc_od(zwroc_srod())
		/ zwroc_stosunek_przekatnych() * sin(zwroc_kat_miedzy_przekatnymi());
}