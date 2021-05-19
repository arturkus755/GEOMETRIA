#pragma once

#include <iosfwd>

#include "wielokat.hpp"

class kwadrat : public wielokat
{
	public:
		kwadrat() = default;
		kwadrat(wektor nowy_srodek, wektor nowy_wierzcholek) : m_srodek(nowy_srodek), m_wierzcholek(nowy_wierzcholek) {}
		kwadrat(const ekran &e);

		wektor zwroc_wierzch() const;
		wektor zwroc_srod() const;

		void ustaw_srod(const wektor &nowy_srodek);
		void ustaw_wierzch( const wektor &nowy_wierzcholek);

		kwadrat &operator=(const kwadrat &przypisany) = default;
		kwadrat operator+(const wektor &dodajnik);
		kwadrat operator-(const wektor &odjemnik);

		double dlugosc_boku() const;
		double obwod() const override;
		double pole() const override;

		~kwadrat() = default;
 	protected:
 		wektor m_srodek;
		wektor m_wierzcholek;
};

std::ostream &operator<<(std::ostream &s, const kwadrat &k);
