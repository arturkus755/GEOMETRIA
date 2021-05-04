#pragma once

#include <iosfwd>

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

std::ostream &operator<<(std::ostream &s, const wektor &w);
