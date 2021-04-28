#pragma once

#include <iosfwd>

class ekran;

class wektor
{
	public:
		int x = 0;
		int y = 0;
		int wsp_x() { return x;};
		int wsp_y() { return y;};
		wektor() = default;
		wektor(int nowy_x, int nowy_y) : x(nowy_x), y(nowy_y) {}
		explicit wektor(int nowy_xy) : wektor(nowy_xy, nowy_xy) {}
		wektor &operator=(const wektor &przypisany) = default;
		wektor operator+(const wektor &dodatnik) const;
		wektor operator-(const wektor &odjemnik) const;
		wektor obrot(float t) const;
		wektor obrot90() const;
		int wyznacznik(const wektor &w) const;
		long iloczyn_skalarny(const wektor &w) const;
		long kwadrat_dlugosci() const;
		double dlugosc() const;
		double odleglosc_od(const wektor &w) const;
};

class trojkat
{
	public:
		trojkat() = default;
		trojkat(wektor a, wektor b, wektor c) : punkty{a, b, c} {}
		trojkat(wektor wektor) : punkty{wektor,wektor,wektor} {}
		trojkat(const ekran &e);
		wektor wsp(int nr_punktu) const {return punkty[nr_punktu];};
		void ustaw_pkt(int nr_punktu, const wektor &nowy_punkt);
		trojkat &operator=(const trojkat &rzypisany) = default;
		trojkat operator+(const wektor &dodajnik);
		trojkat operator-(const wektor &odjemnik);
		double dlugosc_boku(unsigned int bok) const;
		double obwod() const;
		double pole() const;
		bool czy_prostokatny() const;
		bool czy_rownoboczny() const;
		bool czy_rownoramienny() const;
	private:
		wektor punkty[3];
};

class kwadrat
{
	public:
		kwadrat() = default;
		kwadrat(wektor nowy_srodek, wektor nowy_wierzcholek) : srodek(nowy_srodek), wierzcholek(nowy_wierzcholek) {}
		kwadrat(const ekran &e);
		wektor wsp_wierzch() const {return wierzcholek;};
		wektor wsp_srod() const {return srodek;};
		void ustaw_srod( const wektor &nowy_srodek);
		void ustaw_wierzch( const wektor &nowy_wierzcholek);
		kwadrat &operator=(const kwadrat &przypisany) = default;
		kwadrat operator+(const wektor &dodajnik);
		kwadrat operator-(const wektor &odjemnik);
		double dlugosc_boku() const;
		double obwod() const;
		double pole() const;
 	private:
 		wektor srodek;
		wektor wierzcholek;
};

std::ostream &operator<<(std::ostream &s, const wektor &w);
std::ostream &operator<<(std::ostream &s, const trojkat &t);
std::ostream &operator<<(std::ostream &s, const kwadrat &k);

trojkat *szukaj_trojkata_najblizej_srodka(trojkat *trojkaty, int rozmiar, const ekran wyswietlacz);
