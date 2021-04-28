#include "geometria.hpp"
#include "ekran.hpp"
#include <iostream>
#include <cmath>

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

trojkat::trojkat(const ekran &e)
{
	for (int i = 0; i < 3; i++)
	{
		this->punkty[i].x = e.roz_x() / 2;
		this->punkty[i].y = e.roz_y() / 2;
	}
}

void trojkat::ustaw_pkt(int nr_punktu, const wektor &nowy_punkt)
{
	punkty[nr_punktu] = nowy_punkt;
}

trojkat trojkat::operator+(const wektor &dodajnik)
{
	for (int i = 0; i < 3; ++i)
	{
		this->punkty[i] = this->punkty[i] + dodajnik;
	}
	return *this;
}

trojkat trojkat::operator-(const wektor &odjemnik)
{
	trojkat t{*this};
	for (int i = 0; i < 3; ++i)
	{
		t.punkty[i] = t.punkty[i] - odjemnik;
	}
	return t;
}

double trojkat::dlugosc_boku(unsigned int bok) const
{
	return punkty[bok % 3].odleglosc_od(punkty[(bok + 1) % 3]);
}

double trojkat::obwod() const
{
	return dlugosc_boku(0) + dlugosc_boku(1) + dlugosc_boku(2);
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
	if ((punkty[0] - punkty[1]).kwadrat_dlugosci() == (punkty[1] - punkty[2]).kwadrat_dlugosci() &&
	(punkty[1] - punkty[2]).kwadrat_dlugosci() == (punkty[2] - punkty[0]).kwadrat_dlugosci())
		return true;
	return false;
}

bool trojkat::czy_rownoramienny() const
{
	for (int i = 0; i < 3; ++i)
	{
		if ((punkty[i] - punkty[(i + 1) % 3]).kwadrat_dlugosci() == (punkty[(i + 1) % 3] - punkty[(i + 2) % 3]).kwadrat_dlugosci())
			return true;
	}
	return false;
}

void kwadrat::ustaw_srod(const wektor &nowy_srodek)
{
	srodek = nowy_srodek;
}

void kwadrat::ustaw_wierzch( const wektor &nowy_wierzcholek)
{
	wierzcholek = nowy_wierzcholek;
}

kwadrat kwadrat::operator+(const wektor &dodajnik)
{
	kwadrat k{*this};
	k.wierzcholek = k.wierzcholek + dodajnik;
	k.srodek = k.srodek + dodajnik;
	return k;
}

kwadrat kwadrat::operator-(const wektor &odjemnik)
{
	kwadrat k{*this};
	k.wierzcholek = k.wierzcholek - odjemnik;
	k.srodek = k.srodek - odjemnik;
	return k;
}

double kwadrat::dlugosc_boku() const
{
	return (2.0 * srodek.odleglosc_od(wierzcholek)) / sqrt(2);
}

double kwadrat::obwod() const
{
	return 4.0 * dlugosc_boku();
}
double kwadrat::pole() const
{
	return dlugosc_boku() * dlugosc_boku();
}

std::ostream &operator<<(std::ostream &s, const wektor &w)
{
    s << "[" << w.x << ", " << w.y << "]";
    return s;
}

std::ostream &operator<<(std::ostream &s, const trojkat &t)
{
	s << t.wsp(0) << ", " << t.wsp(1) << ", " << t.wsp(2);
	return s;
}

std::ostream &operator<<(std::ostream &s, const kwadrat &k)
{
	s << k.wsp_srod() << ", " << k.wsp_wierzch();
	return s;
}

trojkat *szukaj_trojkata_najblizej_srodka(trojkat *trojkaty, int rozmiar, const ekran wyswietlacz)
{
	wektor srodek_ekranu = wektor{wyswietlacz.roz_x()/2, wyswietlacz.roz_x()/2};
	trojkat *tymczasowe_minimum = &trojkaty[0];
	int indeks_tymczasowego_minimum = 0;
	for (int j = 0; j < rozmiar; ++j)
		for (int i = 0; i < 3; ++i)
				if (trojkaty[j].wsp(i).odleglosc_od(srodek_ekranu) < 
				tymczasowe_minimum->wsp(indeks_tymczasowego_minimum).odleglosc_od(srodek_ekranu))
				{
					tymczasowe_minimum = &trojkaty[j];
					indeks_tymczasowego_minimum = i;
				}
	return tymczasowe_minimum;
}
