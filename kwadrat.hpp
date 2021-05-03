#pragma once

#include <iosfwd>

class wektor;
class ekran;

class kwadrat
{
	public:
		kwadrat() = default;
		kwadrat(wektor* nowy_srodek, wektor* nowy_wierzcholek) : srodek(nowy_srodek), wierzcholek(nowy_wierzcholek) {}
		kwadrat(const ekran &e);
		wektor* wsp_wierzch() const {return wierzcholek;};
		wektor* wsp_srod() const {return srodek;};
		void ustaw_srod(const wektor &nowy_srodek);
		void ustaw_wierzch( const wektor &nowy_wierzcholek);
		kwadrat &operator=(const kwadrat &przypisany) = default;
		kwadrat operator+(const wektor &dodajnik);
		kwadrat operator-(const wektor &odjemnik);
		double dlugosc_boku() const;
		double obwod() const;
		double pole() const;
 	private:
 		wektor* srodek;
		wektor* wierzcholek;
};

std::ostream &operator<<(std::ostream &s, const kwadrat &k);
