#include <iostream>
#include <cmath>


#include "trojkat.hpp"
#include "wektor.hpp"
#include "ekran.hpp"

trojkat::trojkat(const ekran &e)
{
	for (int i = 0; i < 3; i++)
	{
		punkty[i]->x = e.roz_x() / 2;
		punkty[i]->y = e.roz_y() / 2;
	}
}

void trojkat::ustaw_pkt(int nr_punktu, const wektor &nowy_punkt)
{
	*punkty[nr_punktu] = nowy_punkt;
}

trojkat trojkat::operator+(const wektor &dodajnik)
{
	trojkat t{*this};
	for (int i = 0; i < 3; ++i)
	{
		*punkty[i] = *punkty[i] + dodajnik;
	}
	return t;
}

trojkat trojkat::operator-(const wektor &odjemnik)
{
	trojkat t{*this};
	for (int i = 0; i < 3; ++i)
	{
		*t.punkty[i] = *t.punkty[i] - odjemnik;
	}
	return t;
}

double trojkat::dlugosc_boku(unsigned int bok) const
{
	return punkty[bok % 3]->odleglosc_od(*punkty[(bok + 1) % 3]);
}

double trojkat::obwod() const
{
	return dlugosc_boku(0) + dlugosc_boku(1) + dlugosc_boku(2);
}

double trojkat::pole() const
{
	return 0.5 * abs((*punkty[0] - *punkty[1]).wyznacznik(*punkty[0] - *punkty[2]));
}

bool trojkat::czy_prostokatny() const
{
	for (int i = 0; i < 3; ++i)
	{
		if ((*punkty[(i + 2) % 3] - *punkty[i]).iloczyn_skalarny(*punkty[(i + 1) % 3] - *punkty[i]) == 0)
			return true;
	}
	return false;
}

bool trojkat::czy_rownoboczny() const
{
	if ((*punkty[0] - *punkty[1]).kwadrat_dlugosci() == (*punkty[1] - *punkty[2]).kwadrat_dlugosci() &&
	(*punkty[1] - *punkty[2]).kwadrat_dlugosci() == (*punkty[2] - *punkty[0]).kwadrat_dlugosci())
		return true;
	return false;
}

bool trojkat::czy_rownoramienny() const
{
	for (int i = 0; i < 3; ++i)
	{
		if ((*punkty[i] - *punkty[(i + 1) % 3]).kwadrat_dlugosci() == (*punkty[(i + 1) % 3] - *punkty[(i + 2) % 3]).kwadrat_dlugosci())
			return true;
	}
	return false;
}

std::ostream &operator<<(std::ostream &s, const trojkat &t)
{
	s << *t.wsp(0) << ", " << *t.wsp(1) << ", " << *t.wsp(2);
	return s;
}

trojkat *szukaj_trojkata_najblizej_srodka(trojkat *trojkaty, int rozmiar, const ekran wyswietlacz)
{
	wektor srodek_ekranu = wektor{wyswietlacz.roz_x()/2, wyswietlacz.roz_x()/2};
	trojkat *tymczasowe_minimum = &trojkaty[0];
	int indeks_tymczasowego_minimum = 0;
	for (int j = 0; j < rozmiar; ++j)
		for (int i = 0; i < 3; ++i)
				if (trojkaty[j].wsp(i)->odleglosc_od(srodek_ekranu) < 
				tymczasowe_minimum->wsp(indeks_tymczasowego_minimum)->odleglosc_od(srodek_ekranu))
				{
					tymczasowe_minimum = &trojkaty[j];
					indeks_tymczasowego_minimum = i;
				}
	return tymczasowe_minimum;
}
