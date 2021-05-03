#include <iostream>
#include <cmath>

#include "wektor.hpp"

wektor wektor::operator+(const wektor &dodajnik) const
{
	return wektor(x + dodajnik.x, y + dodajnik.y);
}

wektor wektor::operator-(const wektor &odjemnik) const
{
	return wektor(x - odjemnik.x, y - odjemnik.y);
}

wektor wektor::obrot(float t) const
{
	return wektor{std::round(this->x * std::cos(t) - this->y * std::sin(t)),
		std::round(this->x * std::sin(t) + this->y * std::cos(t))};
}

wektor wektor::obrot90() const
{
	return wektor{-y, x};
}

int wektor::wyznacznik(const wektor &w) const
{
	return x * w.y - w.x * y;
}

long wektor::iloczyn_skalarny(const wektor &w) const
{
	return x * w.x + y * w.y;
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
    s << "[" << w.x << ", " << w.y << "]";
    return s;
}
