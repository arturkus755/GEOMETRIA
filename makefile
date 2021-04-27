all:
	g++ main.cpp geometria.cpp ekran.cpp -lallegro -lallegro_font -lallegro_image -lallegro_primitives -Wall -Wextra -fsanitize=address -g -lsfml-system -lsfml-window -lsfml-graphics && ./a.out
