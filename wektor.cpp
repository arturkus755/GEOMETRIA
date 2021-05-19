#include <iostream>
#include <cmath>

#include "wektor.hpp"

wektor wektor::operator+(const wektor &dodajnik) const
{
	return wektor(m_x + dodajnik.m_x, m_y + dodajnik.m_y);
}

wektor wektor::operator-(const wektor &odjemnik) const
{
	return wektor(m_x - odjemnik.m_x, m_y - odjemnik.m_y);
}

wektor wektor::operator*(double mnoznik) const
{
	return wektor(m_x * mnoznik, m_y * mnoznik);
}

wektor wektor::obrot(double t) const
{
	return wektor{std::round(m_x * std::cos(t) - m_y * std::sin(t)),
		std::round(m_x * std::sin(t) + m_y * std::cos(t))};
}

wektor wektor::obrot90() const
{
	return wektor{-m_y, m_x};
}

int wektor::wyznacznik(const wektor &w) const
{
	return m_x * w.m_y - w.m_x * m_y;
}

long wektor::iloczyn_skalarny(const wektor &w) const
{
	return m_x * w.m_x + m_y * w.m_y;
}
		
long wektor::kwadrat_dlugosci() const
{
	return this->iloczyn_skalarny(*this);
}

double wektor::dlugosc() const
{
	return sqrt(kwadrat_dlugosci());
}

double wektor::odleglosc_od(const wektor &w) const
{
	return (*this - w).dlugosc();
}

std::ostream &operator<<(std::ostream &s, const wektor &w)
{
    s << "[" << w.zwroc_wsp_x() << ", " << w.zwroc_wsp_y() << "]";
    return s;
}
