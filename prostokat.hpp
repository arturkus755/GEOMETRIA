#pragma once

#include "kwadrat.hpp"

class prostokat : virtual public kwadrat
{
	public:
		prostokat() = default;
		prostokat(wektor nowy_srodek, wektor nowy_wierzcholek, double kat_miedzy_przekatnymi) :
			m_kat_miedzy_przekatnymi(kat_miedzy_przekatnymi)
		{
			ustaw_wierzch(nowy_wierzcholek);
			ustaw_srod(nowy_srodek);
		}
		prostokat(const ekran &e);

		void opis() const override;

		void ustaw_kat_miedzy_przekatnymi(double kat_miedzy_przekatnymi);
	
		double zwroc_kat_miedzy_przekatnymi() const {return m_kat_miedzy_przekatnymi;};
		
		double dlugosc_boku(unsigned int nr_boku) const;
		double obwod() const;
		double pole() const;

		~prostokat() = default;
	protected:
		double m_kat_miedzy_przekatnymi = M_PI / 2.0;
};