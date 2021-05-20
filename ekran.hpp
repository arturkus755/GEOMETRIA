#pragma once

#include <allegro5/allegro.h>
#include <stdexcept>

class wektor;
class trojkat;
class kwadrat;
class romb;
class prostokat;
class rownoleglobok;

class ekran
{
    public:
		void ustaw_rozdzielczosc(int nowy_x ,int nowy_y)
		{
			x = nowy_x;
			x = nowy_y;
		}

		int zwroc_roz_x() const {return x;}
		int zwroc_roz_y() const {return y;}
		ALLEGRO_DISPLAY* zwroc_wyswietlacz() {return wyswietlacz;}
		
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

    	void rysuj(const trojkat &t, ALLEGRO_COLOR kolor, bool czy_pelny = true, float grubosc = 4.0) const;
		void rysuj(const kwadrat &k, ALLEGRO_COLOR kolor, bool czy_pelny = true, float grubosc = 4.0) const;
		void rysuj(const romb &rom, ALLEGRO_COLOR kolor, bool czy_pelny = true, float grubosc = 4.0) const;
		void rysuj(const prostokat &pros, ALLEGRO_COLOR kolor, bool czy_pelny = true, float grubosc = 4.0) const;
		void rysuj(const rownoleglobok &row, ALLEGRO_COLOR kolor, bool czy_pelny = true, float grubosc = 4.0) const;
		void usun(const kwadrat &k) const;
		void usun(const trojkat &t) const;
		void usun(const romb &rom) const;
		void usun(const prostokat &pros) const;
		void usun(const rownoleglobok &row) const;
		
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

