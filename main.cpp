#include <iostream>
#include <cmath>
#include <ctime>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

#include "wektor.hpp"
#include "wielokat.hpp"
#include "trojkat.hpp"
#include "kwadrat.hpp"
#include "romb.hpp"
#include "prostokat.hpp"
#include "rownoleglobok.hpp"
#include "ekran.hpp"

int losuj_nr_figury()
{
	return (rand() % 5);
}

int losuj_wsp_wektora()
{
	return (rand() % 300) + 900;
}

double losuj_kat_miedzy_przekatnymi()
{
	return (rand() + RAND_MAX / 6.0) / (RAND_MAX + 2.0) * M_PI;
}

double losuj_stosunek_przekatnych()
{
	return 1 + (rand() + 1) / (RAND_MAX + 2.0) * 9.0;
}

void wypisz_pola_i_obwody(wielokat** wiel, const int rozmiar)
{
	std::cout << "typ figury\t" << "pole figury\t" << "obwod figury\t" << std::endl;
	for (int i = 0; i < rozmiar; ++i)
	{
		wiel[i]->opis();
		std::cout << "\t" << wiel[i]->pole() << "    \t" << wiel[i]->obwod() << std::endl;
	}
}

int main()
{
	srand(time(NULL));

	int rozmiar = 100;
	wielokat **wiel = new wielokat* [rozmiar];

	for (int i = 0; i < rozmiar; ++i)
	{
		switch(losuj_nr_figury())
		{
			case 0 :
				wiel[i] = new trojkat 
				{
					wektor{losuj_wsp_wektora(), losuj_wsp_wektora()},
					wektor{losuj_wsp_wektora(), losuj_wsp_wektora()},
					wektor{losuj_wsp_wektora(), losuj_wsp_wektora()}
				};
				break;
			case 1 :
				wiel[i] = new kwadrat
				{
					wektor{losuj_wsp_wektora(), losuj_wsp_wektora()},
					wektor{losuj_wsp_wektora(), losuj_wsp_wektora()}
				};
				break;
			case 2 :
				wiel[i] = new romb
				{
					wektor{losuj_wsp_wektora(), losuj_wsp_wektora()},
					wektor{losuj_wsp_wektora(), losuj_wsp_wektora()},
					losuj_stosunek_przekatnych()
				};
				break;
			case 3 :
				wiel[i] = new prostokat
				{
					wektor{losuj_wsp_wektora(), losuj_wsp_wektora()},
					wektor{losuj_wsp_wektora(), losuj_wsp_wektora()},
					losuj_kat_miedzy_przekatnymi()
				};
				break;
			case 4 :
				wiel[i] = new rownoleglobok
				{
					wektor{losuj_wsp_wektora(), losuj_wsp_wektora()},
					wektor{losuj_wsp_wektora(), losuj_wsp_wektora()},
					losuj_kat_miedzy_przekatnymi(),
					losuj_stosunek_przekatnych()
				};
				break;
		}
	}
	
	wypisz_pola_i_obwody(wiel, rozmiar);

	for (int i = 0; i < rozmiar; ++i)
		delete wiel[i];
	delete[] wiel;

	// if (!al_init())
	// 	throw std::runtime_error{"al_init() zawiodl!"};

	// if (!al_install_keyboard())
	// 	throw std::runtime_error{"al_install_keyboard() zawiodl!"};

	// if (!al_init_primitives_addon())
	// 	throw std::runtime_error{"al_init_primitives_addon() zawiodl!"};
	// ekran e{1920, 1080};
	// std::cout << e << std::endl;

	// romb rom;
	// rom.ustaw_srod(wektor{1000,500});
	// rom.ustaw_wierzch(wektor{1100,780});
	// rom.ustaw_stosunek_przekatnych(4.0/3.0);
	// std::cout << std::endl << "srodek:" << rom.zwroc_srod() << std::endl;
	// std::cout << "wierzcholek:" << rom.zwroc_wierzch() << std::endl;
	// std::cout << "stosunek przekatnych:" << rom.zwroc_stosunek_przekatnych() << std::endl << std::endl;
	// std::cout << "dlugosc boku:" << rom.dlugosc_boku() << std::endl;
	// std::cout << "obwod:" << rom.obwod() << std::endl;
	// std::cout << "pole:" << rom.pole() << std::endl << std::endl;

	// prostokat pros;
	// pros.ustaw_srod(wektor{500,200});
	// pros.ustaw_wierzch(wektor{420,380});
	// pros.ustaw_kat_miedzy_przekatnymi(2.0 * 0.6435011087932843868028092287173226380415105911153123828656061187);
	// std::cout << "sin kata = " << sin(pros.zwroc_kat_miedzy_przekatnymi() / 2.0) << std::endl;
	// std::cout << "srodek:" << pros.zwroc_srod() << std::endl;
	// std::cout << "wierzcholek:" << pros.zwroc_wierzch() << std::endl;
	// std::cout << "kat_miedzy_przekatnymi:" << pros.zwroc_kat_miedzy_przekatnymi() << std::endl << std::endl;
	// std::cout << "dlugosc boku 0:" << pros.dlugosc_boku(0) << std::endl;
	// std::cout << "dlugosc boku 1:" << pros.dlugosc_boku(1) << std::endl;
	// std::cout << "obwod:" << pros.obwod() << std::endl;
	// std::cout << "pole:" << pros.pole() << std::endl << std::endl;

	// rownoleglobok row;
	// row.kwadrat::ustaw_srod(wektor{1500,200});
	// row.kwadrat::ustaw_wierzch(wektor{1700,100});
	// row.ustaw_stosunek_przekatnych(sqrt(14.0 * 14.0 + 8.0 * 8.0) / sqrt(26.0 * 26.0 + 8.0 * 8.0) );
	// row.ustaw_kat_miedzy_przekatnymi(0.817645045833);
	// std::cout << "sin kata = " << sin(row.zwroc_kat_miedzy_przekatnymi()) << std::endl;
	// std::cout << "srodek:" << row.kwadrat::zwroc_srod() << std::endl;
	// std::cout << "wierzcholek:" << row.kwadrat::zwroc_wierzch() << std::endl;
	// std::cout << "stosunek przekatnych:" << row.zwroc_stosunek_przekatnych() << std::endl;
	// std::cout << "kat_miedzy_przekatnymi:" << row.zwroc_kat_miedzy_przekatnymi() << std::endl << std::endl;
	// std::cout << "dlugosc boku 0:" << row.dlugosc_boku(0) << std::endl;
	// std::cout << "dlugosc boku 1:" << row.dlugosc_boku(1) << std::endl;
	// std::cout << "obwod:" << row.obwod() << std::endl;
	// std::cout << "pole:" << row.pole() << std::endl;

	// wektor a, b ,c;
	// a = wektor(100,100);
	// b = wektor(150,150);
	// c = wektor(200,250);
	// trojkat t(a, b, c);
	// std::cout << t << std::endl;
	// wektor s, w;
	// s = wektor(300,300);
	// w = wektor(350, 370);
	// wektor s2 = s, w2 = w;
	// kwadrat k(s, w);
	// kwadrat k_kopia(s2, w2);
	// std::cout << k << std::endl;
	// ALLEGRO_EVENT_QUEUE *queue = al_create_event_queue();
	// if (!queue)
	// 	throw std::runtime_error{"al_create_event_queue() zawiodl!"};

	// al_register_event_source(queue, al_get_display_event_source(e.zwroc_wyswietlacz()));

	// // Timer 60FPS tyka do kolejki i generuje zdarzenia
	// ALLEGRO_TIMER *timer = al_create_timer(1.0 / 60.0);
	// if (!timer) throw std::runtime_error{"al_create_timer() zawiodl!"};
	// al_register_event_source(queue, al_get_timer_event_source(timer));
	// al_start_timer(timer);

	// int n = 0;
	// for (bool alive = true; alive;)
	// {
	// 	// Czekamy na jakieś zdarzenie
	// 	ALLEGRO_EVENT ev;
	// 	al_wait_for_event(queue, &ev);

	// 	// Obsługujemy kolejne zdarzenia
	// 	do
	// 	{
	// 		// ev - wydarzenie, które aktualnie obsługujemy
	// 		switch (ev.type)
	// 		{
	// 			// Obsługa zamknięcia okna
	// 			case ALLEGRO_EVENT_DISPLAY_CLOSE:
	// 				alive = false;
	// 				break;

	// 			default:
	// 				break;
	// 		}
	// 	} while (al_get_next_event(queue, &ev));
		
	// 	// Czyścimy bufor
	// 	al_clear_to_color(al_map_rgb(0, 0, 0));

	// 	// Rysujemy wszystko
	// 	e.rysuj(t, al_map_rgb(255, 0, 0));

	// 	e.rysuj(k, al_map_rgb(0, 255, 0));
		
	// 	e.rysuj(rom, al_map_rgb(0, 0, 255));

	// 	e.rysuj(pros, al_map_rgb(100, 100, 100));

	// 	e.rysuj(row, al_map_rgb(255, 255, 255));

	// 	// Zamiana buforów
	// 	al_flip_display();

	// 	n++;
	// }

	// e.usun(k);
	// al_flip_display();
	// al_rest(2.0);
	// e.usun(t);
	// al_flip_display();
	// al_rest(2.0);
	// e.usun(rom);
	// al_flip_display();
	// al_rest(2.0);
	// e.usun(pros);
	// al_flip_display();
	// al_rest(2.0);
	// e.usun(row);
	// al_flip_display();
	// al_rest(2.0);

	// al_destroy_event_queue(queue);
	// al_destroy_timer(timer);
}
