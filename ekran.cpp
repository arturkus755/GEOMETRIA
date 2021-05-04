#include<iostream>
#include <allegro5/allegro.h>
#include<allegro5/allegro_primitives.h>

#include"ekran.hpp"
#include"wektor.hpp"
#include"trojkat.hpp"
#include"kwadrat.hpp"

bool ekran::czy_wektor_w_zakresie(const wektor &w) const
{
	return !(w.x < 0 || w.y < 0 || w.x > x || w.y > y);
}

bool ekran::czy_trojkat_w_zakresie(const trojkat &t) const
{
	for (int i = 0; i < 3; ++i)
		if (this->czy_wektor_w_zakresie(*t.zwroc_wsp(i)))
			return true;
	return false;
}

void ekran::rysuj(const trojkat &t, ALLEGRO_COLOR kolor, bool czy_pelny, float grubosc) const
{
	if (!(this->czy_trojkat_w_zakresie(t)))
		throw std::invalid_argument{"Trojkat nie miesci sie na ekranie!"};
	if (czy_pelny)
		al_draw_filled_triangle(t.zwroc_wsp(0)->x, t.zwroc_wsp(0)->y, t.zwroc_wsp(1)->x, t.zwroc_wsp(1)->y, t.zwroc_wsp(2)->x, t.zwroc_wsp(2)->y, kolor);
	else
		al_draw_triangle(t.zwroc_wsp(0)->x, t.zwroc_wsp(0)->y, t.zwroc_wsp(1)->x, t.zwroc_wsp(1)->y, t.zwroc_wsp(2)->x, t.zwroc_wsp(2)->y, kolor, grubosc);
}

void ekran::rysuj(const kwadrat &k, ALLEGRO_COLOR kolor, bool czy_pelny, float grubosc) const
{
	float wspolrzedne[8];
	wspolrzedne[6] = k.zwroc_wierzch()->x;
	wspolrzedne[7] = k.zwroc_wierzch()->y;
	wektor obrot = *k.zwroc_wierzch();
	for (int i = 3; i >= 0; i--)
	{
		obrot = (obrot - *k.zwroc_srod()).obrot90() + *k.zwroc_srod();
		if (!(this->czy_wektor_w_zakresie(obrot)))
			throw std::invalid_argument{"Kwadrat nie miesci sie na ekranie!"};
		wspolrzedne[2 * i] = obrot.x;
		wspolrzedne[2 * i + 1] = obrot.y;
	}
	
	if (czy_pelny)
		al_draw_filled_polygon(wspolrzedne, 4, kolor);
	else
		al_draw_polygon(wspolrzedne, 4, ALLEGRO_LINE_JOIN_MITER, kolor, grubosc, 3);
}

void ekran::usun(const kwadrat &k) const
{
	float wspolrzedne[8];
	wspolrzedne[6] = k.zwroc_wierzch()->x;
	wspolrzedne[7] = k.zwroc_wierzch()->y;
	wektor obrot = *k.zwroc_wierzch();
	for (int i = 3; i >= 0; i--)
	{
		obrot = (obrot - *k.zwroc_srod()).obrot90() + *k.zwroc_srod();
		if (!(this->czy_wektor_w_zakresie(obrot)))
			throw std::invalid_argument{"Kwadrat nie miesci sie na ekranie!"};
		wspolrzedne[2 * i] = obrot.x;
		wspolrzedne[2 * i + 1] = obrot.y;
	}
	al_draw_filled_polygon(wspolrzedne, 4, al_map_rgb(0, 0, 0));
}

void ekran::usun(const trojkat &t) const
{
	if (!(this->czy_trojkat_w_zakresie(t)))
		throw std::invalid_argument{"Trojkat nie miesci sie na ekranie!"};
	al_draw_filled_triangle(t.zwroc_wsp(0)->x, t.zwroc_wsp(0)->y, t.zwroc_wsp(1)->x, t.zwroc_wsp(1)->y, t.zwroc_wsp(2)->x, t.zwroc_wsp(2)->y, al_map_rgb(0, 0, 0));
}

std::ostream &operator<<(std::ostream &s, const ekran &e)
{
    s << e.roz_x() << "x" << e.roz_y();
    return s;
}
