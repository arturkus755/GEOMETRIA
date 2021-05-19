#pragma once

#include "kwadrat.hpp"

class prostokat : virtual public kwadrat
{
	public:
		void ustaw_kat_miedzy_przekatnymi(double kat_miedzy_przekatnymi);
	
		double zwroc_kat_miedzy_przekatnymi() const {return m_kat_miedzy_przekatnymi;};
		
		double dlugosc_boku(unsigned int nr_boku) const;
		double obwod() const;
		double pole() const;
	protected:
		double m_kat_miedzy_przekatnymi = M_PI / 2.0;
};