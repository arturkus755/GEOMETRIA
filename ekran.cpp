#include <iostream>
#include <cmath>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

#include "ekran.hpp"
#include "trojkat.hpp"
#include "kwadrat.hpp"
#include "romb.hpp"
#include "prostokat.hpp"
#include "rownoleglobok.hpp"

bool ekran::czy_wektor_w_zakresie(const wektor &w) const
{
	return !(w.zwroc_wsp_x() < 0 || w.zwroc_wsp_y() < 0 || w.zwroc_wsp_x() > x || w.zwroc_wsp_y() > y);
}

bool ekran::czy_trojkat_w_zakresie(const trojkat &t) const
{
	for (int i = 0; i < 3; ++i)
		if (this->czy_wektor_w_zakresie(t.zwroc_pkt(i)))
			return true;
	return false;
}

void ekran::rysuj(const trojkat &t, ALLEGRO_COLOR kolor, bool czy_pelny, float grubosc) const
{
	if (!(this->czy_trojkat_w_zakresie(t)))
		throw std::invalid_argument{"Trojkat nie miesci sie na ekranie!"};
	if (czy_pelny)
		al_draw_filled_triangle(t.zwroc_pkt(0).zwroc_wsp_x(), t.zwroc_pkt(0).zwroc_wsp_y(), t.zwroc_pkt(1).zwroc_wsp_x(),
		t.zwroc_pkt(1).zwroc_wsp_y(), t.zwroc_pkt(2).zwroc_wsp_x(), t.zwroc_pkt(2).zwroc_wsp_y(), kolor);
	else
		al_draw_triangle(t.zwroc_pkt(0).zwroc_wsp_x(), t.zwroc_pkt(0).zwroc_wsp_y(), t.zwroc_pkt(1).zwroc_wsp_x(),
		t.zwroc_pkt(1).zwroc_wsp_y(), t.zwroc_pkt(2).zwroc_wsp_x(), t.zwroc_pkt(2).zwroc_wsp_y(), kolor, grubosc);
}

void ekran::rysuj(const kwadrat &k, ALLEGRO_COLOR kolor, bool czy_pelny, float grubosc) const
{
	float wspolrzedne[8];
	wspolrzedne[6] = k.zwroc_wierzch().zwroc_wsp_x();
	wspolrzedne[7] = k.zwroc_wierzch().zwroc_wsp_y();
	wektor obrot = k.zwroc_wierzch();
	for (int i = 3; i >= 0; i--)
	{
		obrot = (obrot - k.zwroc_srod()).obrot90() + k.zwroc_srod();
		if (!(this->czy_wektor_w_zakresie(obrot)))
			throw std::invalid_argument{"Kwadrat nie miesci sie na ekranie!"};
		wspolrzedne[2 * i] = obrot.zwroc_wsp_x();
		wspolrzedne[2 * i + 1] = obrot.zwroc_wsp_y();
	}
	
	if (czy_pelny)
		al_draw_filled_polygon(wspolrzedne, 4, kolor);
	else
		al_draw_polygon(wspolrzedne, 4, ALLEGRO_LINE_JOIN_MITER, kolor, grubosc, 3);
}

void ekran::rysuj(const romb &rom, ALLEGRO_COLOR kolor, bool czy_pelny, float grubosc) const
{
	float wspolrzedne[8];
	wspolrzedne[6] = rom.zwroc_wierzch().zwroc_wsp_x();
	wspolrzedne[7] = rom.zwroc_wierzch().zwroc_wsp_y();
	wektor obrot = rom.zwroc_wierzch();
	for (int i = 3; i >= 0; i--)
	{
		if (i % 2)
			obrot = ((obrot - rom.zwroc_srod()) * (1.0 / rom.zwroc_stosunek_przekatnych())).obrot90() + rom.zwroc_srod();
		else
			obrot = ((obrot - rom.zwroc_srod()) * rom.zwroc_stosunek_przekatnych()).obrot90() + rom.zwroc_srod();
		if (!(this->czy_wektor_w_zakresie(obrot)))
			throw std::invalid_argument{"Romb nie miesci sie na ekranie!"};
		wspolrzedne[2 * i] = obrot.zwroc_wsp_x();
		wspolrzedne[2 * i + 1] = obrot.zwroc_wsp_y();
	}
	
	if (czy_pelny)
		al_draw_filled_polygon(wspolrzedne, 4, kolor);
	else
		al_draw_polygon(wspolrzedne, 4, ALLEGRO_LINE_JOIN_MITER, kolor, grubosc, 3);
}

void ekran::rysuj(const prostokat &pros, ALLEGRO_COLOR kolor, bool czy_pelny, float grubosc) const
{
	float wspolrzedne[8];
	wspolrzedne[6] = pros.zwroc_wierzch().zwroc_wsp_x();
	wspolrzedne[7] = pros.zwroc_wierzch().zwroc_wsp_y();
	wektor obrot = pros.zwroc_wierzch();
	for (int i = 3; i >= 0; i--)
	{
		if (i % 2)
			obrot = (obrot - pros.zwroc_srod()).obrot(pros.zwroc_kat_miedzy_przekatnymi()) + pros.zwroc_srod();
		else
			obrot = (obrot - pros.zwroc_srod()).obrot(M_PI - pros.zwroc_kat_miedzy_przekatnymi()) + pros.zwroc_srod();
		if (!(this->czy_wektor_w_zakresie(obrot)))
			throw std::invalid_argument{"Romb nie miesci sie na ekranie!"};
		wspolrzedne[2 * i] = obrot.zwroc_wsp_x();
		wspolrzedne[2 * i + 1] = obrot.zwroc_wsp_y();
	}
	
	if (czy_pelny)
		al_draw_filled_polygon(wspolrzedne, 4, kolor);
	else
		al_draw_polygon(wspolrzedne, 4, ALLEGRO_LINE_JOIN_MITER, kolor, grubosc, 3);
}

void ekran::rysuj(const rownoleglobok &row, ALLEGRO_COLOR kolor, bool czy_pelny, float grubosc) const
{
	float wspolrzedne[8];
	wspolrzedne[6] = row.zwroc_wierzch().zwroc_wsp_x();
	wspolrzedne[7] = row.zwroc_wierzch().zwroc_wsp_y();
	wektor obrot = row.zwroc_wierzch();
	for (int i = 3; i >= 0; i--)
	{
		if (i % 2)
			obrot = ((obrot - row.zwroc_srod()) * (1.0 / row.zwroc_stosunek_przekatnych())).obrot(row.zwroc_kat_miedzy_przekatnymi()) + row.zwroc_srod();
		else
			obrot = ((obrot - row.zwroc_srod()) * row.zwroc_stosunek_przekatnych()).obrot(M_PI - row.zwroc_kat_miedzy_przekatnymi()) + row.zwroc_srod();
		if (!(this->czy_wektor_w_zakresie(obrot)))
			throw std::invalid_argument{"Romb nie miesci sie na ekranie!"};
		wspolrzedne[2 * i] = obrot.zwroc_wsp_x();
		wspolrzedne[2 * i + 1] = obrot.zwroc_wsp_y();
	}
	
	if (czy_pelny)
		al_draw_filled_polygon(wspolrzedne, 4, kolor);
	else
		al_draw_polygon(wspolrzedne, 4, ALLEGRO_LINE_JOIN_MITER, kolor, grubosc, 3);
}

void ekran::usun(const kwadrat &k) const
{
	float wspolrzedne[8];
	wspolrzedne[6] = k.zwroc_wierzch().zwroc_wsp_x();
	wspolrzedne[7] = k.zwroc_wierzch().zwroc_wsp_y();
	wektor obrot = k.zwroc_wierzch();
	for (int i = 3; i >= 0; i--)
	{
		obrot = (obrot - k.zwroc_srod()).obrot90();
		wspolrzedne[2 * i] = obrot.zwroc_wsp_x();
		wspolrzedne[2 * i + 1] = obrot.zwroc_wsp_y();
	}
	al_draw_filled_polygon(wspolrzedne, 4, al_map_rgb(0, 0, 0));
}

void ekran::usun(const romb &rom) const
{
	float wspolrzedne[8];
	wspolrzedne[6] = rom.zwroc_wierzch().zwroc_wsp_x();
	wspolrzedne[7] = rom.zwroc_wierzch().zwroc_wsp_y();
	wektor obrot = rom.zwroc_wierzch();
	for (int i = 3; i >= 0; i--)
	{
		if (i % 2)
			obrot = ((obrot - rom.zwroc_srod()) * (1.0 / rom.zwroc_stosunek_przekatnych())).obrot90() + rom.zwroc_srod();
		else
			obrot = ((obrot - rom.zwroc_srod()) * rom.zwroc_stosunek_przekatnych()).obrot90() + rom.zwroc_srod();
		if (!(this->czy_wektor_w_zakresie(obrot)))
			throw std::invalid_argument{"Romb nie miesci sie na ekranie!"};
		wspolrzedne[2 * i] = obrot.zwroc_wsp_x();
		wspolrzedne[2 * i + 1] = obrot.zwroc_wsp_y();
	}
	al_draw_filled_polygon(wspolrzedne, 4, al_map_rgb(0, 0, 0));
}

void ekran::usun(const prostokat &pros) const
{
	float wspolrzedne[8];
	wspolrzedne[6] = pros.zwroc_wierzch().zwroc_wsp_x();
	wspolrzedne[7] = pros.zwroc_wierzch().zwroc_wsp_y();
	wektor obrot = pros.zwroc_wierzch();
	for (int i = 3; i >= 0; i--)
	{
		if (i % 2)
			obrot = (obrot - pros.zwroc_srod()).obrot(pros.zwroc_kat_miedzy_przekatnymi()) + pros.zwroc_srod();
		else
			obrot = (obrot - pros.zwroc_srod()).obrot(M_PI - pros.zwroc_kat_miedzy_przekatnymi()) + pros.zwroc_srod();
		if (!(this->czy_wektor_w_zakresie(obrot)))
			throw std::invalid_argument{"Romb nie miesci sie na ekranie!"};
		wspolrzedne[2 * i] = obrot.zwroc_wsp_x();
		wspolrzedne[2 * i + 1] = obrot.zwroc_wsp_y();
	}
	al_draw_filled_polygon(wspolrzedne, 4, al_map_rgb(0, 0, 0));
}

void ekran::usun(const rownoleglobok &row) const
{
	float wspolrzedne[8];
	wspolrzedne[6] = row.zwroc_wierzch().zwroc_wsp_x();
	wspolrzedne[7] = row.zwroc_wierzch().zwroc_wsp_y();
	wektor obrot = row.zwroc_wierzch();
	for (int i = 3; i >= 0; i--)
	{
		if (i % 2)
			obrot = ((obrot - row.zwroc_srod()) * (1.0 / row.zwroc_stosunek_przekatnych())).obrot(row.zwroc_kat_miedzy_przekatnymi()) + row.zwroc_srod();
		else
			obrot = ((obrot - row.zwroc_srod()) * row.zwroc_stosunek_przekatnych()).obrot(M_PI - row.zwroc_kat_miedzy_przekatnymi()) + row.zwroc_srod();
		if (!(this->czy_wektor_w_zakresie(obrot)))
			throw std::invalid_argument{"Romb nie miesci sie na ekranie!"};
		wspolrzedne[2 * i] = obrot.zwroc_wsp_x();
		wspolrzedne[2 * i + 1] = obrot.zwroc_wsp_y();
	}
	al_draw_filled_polygon(wspolrzedne, 4, al_map_rgb(0, 0, 0));
}

void ekran::usun(const trojkat &t) const
{
	al_draw_filled_triangle(t.zwroc_pkt(0).zwroc_wsp_x(), t.zwroc_pkt(0).zwroc_wsp_y(), t.zwroc_pkt(1).zwroc_wsp_x(), 
		t.zwroc_pkt(1).zwroc_wsp_y(), t.zwroc_pkt(2).zwroc_wsp_x(), t.zwroc_pkt(2).zwroc_wsp_y(), al_map_rgb(0, 0, 0));
}

std::ostream &operator<<(std::ostream &s, const ekran &e)
{
    s << e.zwroc_roz_x() << "x" << e.zwroc_roz_y();
    return s;
}
