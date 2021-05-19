#pragma once

#include <iosfwd>

class wektor
{
	public:
		int zwroc_wsp_x() const { return m_x;};
		int zwroc_wsp_y() const { return m_y;};
		int ustaw_wsp(int x, int y);
		wektor() = default;
		wektor(int nowy_x, int nowy_y) : m_x(nowy_x), m_y(nowy_y) {}
		explicit wektor(int nowy_xy) : wektor(nowy_xy, nowy_xy) {}
		wektor &operator=(const wektor &przypisany) = default;
		wektor operator+(const wektor &dodatnik) const;
		wektor operator-(const wektor &odjemnik) const;
		wektor operator*(double mnoznik) const;
		wektor obrot(double t) const;
		wektor obrot90() const;
		int wyznacznik(const wektor &w) const;
		long iloczyn_skalarny(const wektor &w) const;
		long kwadrat_dlugosci() const;
		double dlugosc() const;
		double odleglosc_od(const wektor &w) const;
	private:
		int m_x = 0;
		int m_y = 0;
};

std::ostream &operator<<(std::ostream &s, const wektor &w);
