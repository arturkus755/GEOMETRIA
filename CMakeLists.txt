cmake_minimum_required(VERSION 3.3)
project(GEOMETRIA)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3 -flto -march=native -DNDEBUG -s")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DDEBUG -g -fsanitize=address -fsanitize=undefined -fno-builtin -fno-omit-frame-pointer")

find_package(SFML 2 COMPONENTS system window graphics REQUIRED)

add_executable(
	geometria
	ekran.cpp
	wektor.cpp
	kwadrat.cpp
	romb.cpp
	prostokat.cpp
	rownoleglobok.cpp
	trojkat.cpp
	main.cpp
)

target_link_libraries(
	geometria

	allegro
	allegro_font
	allegro_image
	allegro_primitives

	sfml-system
	sfml-window
	sfml-graphics
)

# cmake .. -DCMAKE_BUILD_TYPE=Debug/Release // to trzeba za pierwszym razem po stworzeniu build
# make [VERBOSE=1]
# ./geometria

# make && ./geometria

# nlohmann-json
