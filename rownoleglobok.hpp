#pragma once

#include "romb.hpp"
#include "prostokat.hpp"

class rownoleglobok final : public romb, public prostokat
{
	public:
		rownoleglobok() = default;
		rownoleglobok(wektor nowy_srodek, wektor nowy_wierzcholek,
			double kat_miedzy_przekatnymi, double stosunek_przekatnych)
		{
			ustaw_srod(nowy_srodek);
			ustaw_wierzch(nowy_wierzcholek);
			ustaw_kat_miedzy_przekatnymi(kat_miedzy_przekatnymi);
			ustaw_stosunek_przekatnych(stosunek_przekatnych);
		}
		rownoleglobok(const ekran &e);

		void opis() const override;

		double dlugosc_boku(unsigned int nr_boku) const;
		double obwod() const;
		double pole() const;

		~rownoleglobok() = default;
};