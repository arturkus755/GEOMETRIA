#pragma once

#include <iosfwd>

#include "wielokat.hpp"

class kwadrat : protected wielokat
{
	public:
		kwadrat() = default;
		kwadrat(wektor* nowy_srodek, wektor* nowy_wierzcholek) : srodek(nowy_srodek), wierzcholek(nowy_wierzcholek) {}
		kwadrat(const ekran &e);
		wektor* zwroc_wierzch() const {return wierzcholek;};
		wektor* zwroc_srod() const {return srodek;};
		void ustaw_srod(const wektor &nowy_srodek);
		void ustaw_wierzch( const wektor &nowy_wierzcholek);
		kwadrat &operator=(const kwadrat &przypisany) = default;
		kwadrat operator+(const wektor &dodajnik);
		kwadrat operator-(const wektor &odjemnik);
		double dlugosc_boku() const;
		double obwod() const;
		double pole() const;
		using wielokat::zwroc_wsp;
 	private:
 		wektor* srodek = zwroc_wsp();
		wektor* wierzcholek = nullptr;
};

std::ostream &operator<<(std::ostream &s, const kwadrat &k);
