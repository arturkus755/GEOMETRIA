#include "geometria.hpp"
#include <iostream>
#include <cmath>

wektor wektor::operator+(const wektor &dodajnik) const
{
	return wektor(x + dodajnik.x, y + dodajnik.y);
}

wektor wektor::operator+(const int &dodajnik) const
{
	return wektor(x + dodajnik, y + dodajnik);
}

wektor wektor::operator-(const wektor &odjemnik) const
{
	return wektor(x - odjemnik.x, y - odjemnik.y);
}

wektor wektor::operator-(const int &odjemnik) const
{
	return wektor(x - odjemnik, y - odjemnik);
}

int wektor::wyznacznik(const wektor &w) const
{
	return this->x * w.y - w.x * this->y;
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
	wektor roznica;
	roznica = *this - w;
	return roznica.dlugosc();
}

trojkat trojkat::operator+(const wektor &dodajnik)
{
	for (int i = 0; i < 3; ++i)
	{
		this->punkty[i] = this->punkty[i] + dodajnik;
	}
	return *this;
}

trojkat trojkat::operator+(const int &dodajnik)
{
	for (int i = 0; i < 3; ++i)
	{
		this->punkty[i] = this->punkty[i] + dodajnik;
	}
	return *this;
}

trojkat trojkat::operator-(const wektor &odjemnik)
{
	for (int i = 0; i < 3; ++i)
	{
		this->punkty[i] = this->punkty[i] - odjemnik;
	}
	return *this;
}

trojkat trojkat::operator-(const int &odjemnik)
{
	for (int i = 0; i < 3; ++i)
	{
		this->punkty[i] = this->punkty[i] - odjemnik;
	}
	return *this;
}

double trojkat::obwod() const
{
	return punkty[0].odleglosc_od(punkty[1]) + punkty[1].odleglosc_od(punkty[2]) + punkty[0].odleglosc_od(punkty[2]);
}

double trojkat::pole() const
{
	return 0.5 * abs((punkty[0] - punkty[1]).wyznacznik(punkty[0] - punkty[2]));
}

bool trojkat::czy_prostokatny() const
{
	for (int i = 0; i < 3; ++i)
	{
		if ((punkty[(i + 2) % 3] - punkty[i]).iloczyn_skalarny(punkty[(i + 1) % 3] - punkty[i]) == 0)
			return true;
	}
	return false;
}

bool trojkat::czy_rownoboczny() const
{
	if (punkty[0].kwadrat_dlugosci() == punkty[1].kwadrat_dlugosci() &&
	punkty[1].kwadrat_dlugosci() == punkty[2].kwadrat_dlugosci())
		return true;
	return false;
}

bool trojkat::czy_rownoramienny() const
{
	for (int i = 0; i < 3; ++i)
	{
		if (punkty[i % 3].kwadrat_dlugosci() == punkty[(i + 1) % 3].kwadrat_dlugosci())
			return true;
	}
	return false;
}

bool ekran::czy_wektor_w_zakresie(const wektor &w) const
{
	return !(w.x < 0 || w.y < 0 || w.x > x || w.y > y);
}

bool ekran::czy_trojkat_w_zakresie(const trojkat &t) const
{
	for (int i = 0; i < 3; ++i)
		if (this->czy_trojkat_w_zakresie(t.punkty[i]))
			return true;
	return false;
}

trojkat *szukaj_trojkata_najblizej_srodka(std::vector<trojkat> &trojkaty, const ekran wyswietlacz)
{
	wektor srodek_ekranu = {wyswietlacz.x/2, wyswietlacz.y/2};
	trojkat *tymczasowe_minimum = &trojkaty[0];
	int indeks_tymczasowego_minimum = 0;
	for (auto &t : trojkaty)
		for (int i = 0; i < 3; ++i)
				if (t.punkty[i].odleglosc_od(srodek_ekranu) < 
				tymczasowe_minimum->punkty[indeks_tymczasowego_minimum].odleglosc_od(srodek_ekranu))
				{
					tymczasowe_minimum = &t;
					indeks_tymczasowego_minimum = i;
				}
	return tymczasowe_minimum;

}

std::ostream &operator<<(std::ostream &s, const wektor &w)
{
    s << "[" << w.x << ", " << w.y << "]";
    return s;
}

std::ostream &operator<<(std::ostream &s, const trojkat &t)
{
	s << t.punkty[0] << ", " << t.punkty[1] << ", " << t.punkty[2];
	return s;
}
