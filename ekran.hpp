#pragma once

#include "geometria.hpp"

#include <allegro5/allegro.h>
#include <stdexcept>

class ekran
{
    public:
		void ustaw_rozdzielczosc(int nowy_x ,int nowy_y)
		{
			x = nowy_x;
			x = nowy_y;
		}
		int roz_x() const {return x;}
		int roz_y() const {return y;}
		ALLEGRO_DISPLAY* get_wyswietlacz() {return wyswietlacz;}
    	ekran(int nowy_x, int nowy_y) : x(nowy_x), y(nowy_y)
    	{
    	    wyswietlacz = al_create_display(nowy_x ,nowy_y);
			if (!wyswietlacz)
        		throw std::runtime_error{"al_create_display() failed!"};
			al_clear_to_color(al_map_rgb(0, 0, 0));
   		}

		ekran() : ekran(640, 480) {}
   		explicit ekran(int nowy_xy) : ekran(nowy_xy, nowy_xy) {}

    	bool czy_wektor_w_zakresie(const wektor &w) const;
    	bool czy_trojkat_w_zakresie(const trojkat &t) const;
    	void rysuj(const wektor &t, ALLEGRO_COLOR kolor) const;
    	void rysuj(const trojkat &t, ALLEGRO_COLOR kolor, bool czy_pelny = true, float grubosc = 4.0) const;
		void rysuj(const kwadrat &k, ALLEGRO_COLOR kolor, bool czy_pelny = true, float grubosc = 4.0) const;
    	~ekran()
    	{
    	    al_destroy_display(wyswietlacz);
		}
    private:
    	ALLEGRO_DISPLAY *wyswietlacz;
		int x = 640;
    	int y = 480;
};

std::ostream &operator<<(std::ostream &s, const ekran &e);

