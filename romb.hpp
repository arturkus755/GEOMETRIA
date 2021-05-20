#pragma once

#include "kwadrat.hpp"

class romb : virtual public kwadrat
{
	public:
		romb() = default;
		romb(wektor nowy_srodek, wektor nowy_wierzcholek, double stosunek_przekatnych) :
			m_stosunek_przekatnych(stosunek_przekatnych)
		{
			ustaw_wierzch(nowy_wierzcholek);
			ustaw_srod(nowy_srodek);
		}
		romb(const ekran &e);

		void opis() const override;

		void ustaw_stosunek_przekatnych(double stosunek_przekatnych);

		double zwroc_stosunek_przekatnych() const {return m_stosunek_przekatnych;};

		double dlugosc_boku() const;
		double obwod() const;
		double pole() const;

		~romb() = default;
	protected:
		double m_stosunek_przekatnych = 1.0;	//stosunek przekotnej, do ktorej nalezy wierzcholek do przeciwnej przekatnej
};