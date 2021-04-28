#include"ekran.hpp"
#include"geometria.hpp"

#include<iostream>
#include <allegro5/allegro.h>
#include<allegro5/allegro_primitives.h>

bool ekran::czy_wektor_w_zakresie(const wektor &w) const
{
	return !(w.x < 0 || w.y < 0 || w.x > x || w.y > y);
}

bool ekran::czy_trojkat_w_zakresie(const trojkat &t) const
{
	for (int i = 0; i < 3; ++i)
		if (this->czy_wektor_w_zakresie(t.wsp(i)))
			return true;
	return false;
}

void ekran::rysuj(const trojkat &t, ALLEGRO_COLOR kolor, bool czy_pelny, float grubosc) const
{
	if (!(this->czy_trojkat_w_zakresie(t)))
		throw std::invalid_argument{"Trojkat nie miesci sie na ekranie!"};
	if (czy_pelny)
		al_draw_filled_triangle(t.wsp(0).x, t.wsp(0).y, t.wsp(1).x, t.wsp(1).y, t.wsp(2).x, t.wsp(2).y, kolor);
	else
		al_draw_triangle(t.wsp(0).x, t.wsp(0).y, t.wsp(1).x, t.wsp(1).y, t.wsp(2).x, t.wsp(2).y, kolor, grubosc);
}

void ekran::rysuj(const kwadrat &k, ALLEGRO_COLOR kolor, bool czy_pelny, float grubosc) const
{
	float wspolrzedne[8];
	wspolrzedne[6] = k.wsp_wierzch().x;
	wspolrzedne[7] = k.wsp_wierzch().y;
	wektor obrot = k.wsp_wierzch();
	for (int i = 3; i >= 0; i--)
	{
		obrot = (obrot - k.wsp_srod()).obrot90() + k.wsp_srod();
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

std::ostream &operator<<(std::ostream &s, const ekran &e)
{
    s << e.roz_x() << "x" << e.roz_y();
    return s;
}
