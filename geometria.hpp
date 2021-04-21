#pragma once

#include <iosfwd>
#include <vector>

class wektor
{
	public:
		int x = 0;
		int y = 0;
		
		wektor() = default;
		wektor(int nowy_x, int nowy_y) : x(nowy_x), y(nowy_y) {}
		wektor(int nowy_xy) : wektor(nowy_xy, nowy_xy) {}
		wektor &operator=(const wektor &przypisany) = default;
		wektor operator+(const wektor &dodatnik) const;
		wektor operator+(const int &dodatnik) const;
		wektor operator-(const wektor &odjemnik) const;
		wektor operator-(const int &odjemnik) const;
		int wyznacznik(const wektor &w) const;
		long iloczyn_skalarny(const wektor &w) const;
		long kwadrat_dlugosci() const;
		double dlugosc() const;
		double odleglosc_od(const wektor &w) const;
};

class trojkat
{
	public:
		wektor punkty[3];

		trojkat() = default;
		trojkat(wektor a, wektor b, wektor c) : punkty{a, b, c} {}
		trojkat(wektor wektor) : punkty{wektor,wektor,wektor} {}
		trojkat &operator=(const trojkat &przypisany) = default;
		trojkat operator+(const wektor &dodatnik);
		trojkat operator+(const int &dodatnik);
		trojkat operator-(const wektor &odjemnik);
		trojkat operator-(const int &odjemnik);
		double obwod() const;
		double pole() const;
		bool czy_prostokatny() const;
		bool czy_rownoboczny() const;
		bool czy_rownoramienny() const;
};

class ekran
{
	public:
	int x = 640;
	int y = 480;
	
	ekran() = default;
	ekran(int nowy_x, int nowy_y) : x(nowy_x), y(nowy_y) {}
	ekran(int nowy_xy) : ekran(nowy_xy, nowy_xy) {}	
	bool czy_wektor_w_zakresie(const wektor &w) const;
	bool czy_trojkat_w_zakresie(const trojkat &t) const;
};

std::ostream &operator<<(std::ostream &s, const wektor &w);
std::ostream &operator<<(std::ostream &s, const trojkat &t);
std::ostream &operator<<(std::ostream &s, const ekran &e);

trojkat *szukaj_trojkata_najblizej_srodka(std::vector<trojkat> &trojkaty, const ekran wyswietlacz);
