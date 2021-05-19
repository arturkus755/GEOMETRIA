#include <iostream>
#include <cmath>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

#include "wektor.hpp"
#include "trojkat.hpp"
#include "kwadrat.hpp"
#include "romb.hpp"
#include "prostokat.hpp"
#include "rownoleglobok.hpp"
#include "ekran.hpp"



int main()
{

	if (!al_init())
		throw std::runtime_error{"al_init() zawiodl!"};

	if (!al_install_keyboard())
		throw std::runtime_error{"al_install_keyboard() zawiodl!"};

	if (!al_init_primitives_addon())
		throw std::runtime_error{"al_init_primitives_addon() zawiodl!"};
	ekran e{1920, 1080};
	std::cout << e << std::endl;

	romb rom;
	rom.ustaw_srod(wektor{4,4});
	rom.ustaw_wierzch(wektor{4,0});
	rom.ustaw_stosunek_przekatnych(4.0/3.0);
	std::cout << "srodek:" << rom.zwroc_srod() << std::endl;
	std::cout << "wierzcholek:" << rom.zwroc_wierzch() << std::endl;
	std::cout << "stosunek przekatnych:" << rom.zwroc_stosunek_przekatnych() << std::endl << std::endl;
	std::cout << "dlugosc boku:" << rom.dlugosc_boku() << std::endl;
	std::cout << "obwod:" << rom.obwod() << std::endl;
	std::cout << "pole:" << rom.pole() << std::endl << std::endl;

	prostokat pros;
	pros.ustaw_srod(wektor{4,5});
	pros.ustaw_wierzch(wektor{7,1});
	pros.ustaw_kat_miedzy_przekatnymi(2.0 * 0.6435011087932843868028092287173226380415105911153123828656061187);
	std::cout << "sin kata = " << sin(pros.zwroc_kat_miedzy_przekatnymi() / 2.0) << std::endl;
	std::cout << "srodek:" << pros.zwroc_srod() << std::endl;
	std::cout << "wierzcholek:" << pros.zwroc_wierzch() << std::endl;
	std::cout << "kat_miedzy_przekatnymi:" << pros.zwroc_kat_miedzy_przekatnymi() << std::endl << std::endl;
	std::cout << "dlugosc boku 0:" << pros.dlugosc_boku(0) << std::endl;
	std::cout << "dlugosc boku 1:" << pros.dlugosc_boku(1) << std::endl;
	std::cout << "obwod:" << pros.obwod() << std::endl;
	std::cout << "pole:" << pros.pole() << std::endl << std::endl;

	rownoleglobok row;
	row.kwadrat::ustaw_srod(wektor{14,5});
	row.kwadrat::ustaw_wierzch(wektor{21,1});
	row.ustaw_stosunek_przekatnych(sqrt(14.0 * 14.0 + 8.0 * 8.0) / sqrt(26.0 * 26.0 + 8.0 * 8.0) );
	row.ustaw_kat_miedzy_przekatnymi(0.817645045833);
	std::cout << "sin kata = " << sin(row.zwroc_kat_miedzy_przekatnymi()) << std::endl;
	std::cout << "srodek:" << row.kwadrat::zwroc_srod() << std::endl;
	std::cout << "wierzcholek:" << row.kwadrat::zwroc_wierzch() << std::endl;
	std::cout << "stosunek przekatnych:" << row.zwroc_stosunek_przekatnych() << std::endl;
	std::cout << "kat_miedzy_przekatnymi:" << row.zwroc_kat_miedzy_przekatnymi() << std::endl << std::endl;
	std::cout << "dlugosc boku 0:" << row.dlugosc_boku(0) << std::endl;
	std::cout << "dlugosc boku 1:" << row.dlugosc_boku(1) << std::endl;
	std::cout << "obwod:" << row.obwod() << std::endl;
	std::cout << "pole:" << row.pole() << std::endl;

	// rom = rom + wektor{4,5};
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
		
	// 	// Zamiana buforów
	// 	al_flip_display();

	// 	n++;
	// }

	// e.usun(k);
	// e.usun(t);

	// al_destroy_event_queue(queue);
	// al_destroy_timer(timer);
}
