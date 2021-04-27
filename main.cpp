#include <iostream>
#include <cmath>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include "geometria.hpp"
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
		throw std::runtime_error{"al_init() failed!"};

	if (!al_install_keyboard())
		throw std::runtime_error{"al_install_keyboard() failed!"};

	if (!al_init_primitives_addon())
		throw std::runtime_error{"al_init_primitives_addon() failed!"};
	ekran e{1920, 1080};
	std::cout << e << std::endl;
	trojkat t(wektor(100,100), wektor(150,150), wektor(200,250));
	std::cout << t << std::endl;
	
	ALLEGRO_EVENT_QUEUE *queue = al_create_event_queue();
	if (!queue)
		throw std::runtime_error{"al_create_event_queue() failed!"};

	al_register_event_source(queue, al_get_display_event_source(e.get_wyswietlacz()));

	// Timer 60FPS tyka do kolejki i generuje zdarzenia
	ALLEGRO_TIMER *timer = al_create_timer(1.0 / 60.0);
	if (!timer) throw std::runtime_error{"al_create_timer() failed!"};
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
		e.rysuj(t,al_map_rgb(255, 0, 0));

		e.rysuj(kwadrat{wektor(300,300), wektor(100, 150 + 200 * std::sin(n / 80.f))}, al_map_rgb(254, 40, 180));

		// Zamiana buforów
		al_flip_display();
		n++;
	}

	al_destroy_event_queue(queue);
	al_destroy_timer(timer);
}
