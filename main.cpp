#include <iostream>
#include <cmath>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

#include "wektor.hpp"
#include "wielokat.hpp"
#include "trojkat.hpp"
#include "kwadrat.hpp"
#include "ekran.hpp"


/*
	-lsfml-system -lsfml-window -lsfml-graphics
*/
#include <SFML/Graphics.hpp>
void alt_main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "okienko");

	sf::Texture tex;
	tex.loadFromFile("obrazek.png");

	sf::Sprite spr;
	spr.setTexture(tex);

	while (window.isOpen())
	{
		for (sf::Event ev; window.pollEvent(ev);)
		{
			switch (ev.type)
			{
				case sf::Event::Closed:
					window.close();
					break;

				default:
					break;
			}
		}

		window.clear(sf::Color::Black);

		window.draw(spr);

		// sf::RectangleShape rect(sf::Vector2f{120.f, 140.f});
		// rect.setFillColor(sf::Color(150, 50, 250));
		// rect.setPosition(100, 100);
		// window.draw(rect);

		window.display();
	}

	exit(0);
}

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
	wektor a, b ,c;
	a = wektor(100,100);
	b = wektor(150,150);
	c = wektor(200,250);
	trojkat t3;
	trojkat t(&a, &b, &c);
	std::cout << t << std::endl;
	wektor s, w;
	s = wektor(300,300);
	w = wektor(350, 350);
	wektor s2 = s, w2 = w;
	kwadrat k(&s, &w);
	kwadrat k_kopia(&s2, &w2);
	std::cout << k << std::endl;
	
	ALLEGRO_EVENT_QUEUE *queue = al_create_event_queue();
	if (!queue)
		throw std::runtime_error{"al_create_event_queue() zawiodl!"};

	al_register_event_source(queue, al_get_display_event_source(e.get_wyswietlacz()));

	// Timer 60FPS tyka do kolejki i generuje zdarzenia
	ALLEGRO_TIMER *timer = al_create_timer(1.0 / 60.0);
	if (!timer) throw std::runtime_error{"al_create_timer() zawiodl!"};
	al_register_event_source(queue, al_get_timer_event_source(timer));
	al_start_timer(timer);

	int n = 0;
	for (bool alive = true; alive;)
	{
		// Czekamy na jakieś zdarzenie
		ALLEGRO_EVENT ev;
		al_wait_for_event(queue, &ev);

		// Obsługujemy kolejne zdarzenia
		do
		{
			// ev - wydarzenie, które aktualnie obsługujemy
			switch (ev.type)
			{
				// Obsługa zamknięcia okna
				case ALLEGRO_EVENT_DISPLAY_CLOSE:
					alive = false;
					break;

				default:
					break;
			}
		} while (al_get_next_event(queue, &ev));
		
		// Czyścimy bufor
		al_clear_to_color(al_map_rgb(0, 0, 0));

		// Rysujemy wszystko
		e.rysuj(t, al_map_rgb(255, 0, 0));

		e.rysuj(k, al_map_rgb(0, 255, 0));
		
		// Zamiana buforów
		al_flip_display();

		n++;
	}

	e.usun(k);
	e.usun(t);

	al_destroy_event_queue(queue);
	al_destroy_timer(timer);
}
