#pragma once

#include "header.hpp"

class trojkat
{
	private:
		wspolrzedne punkty[3] = {};
	public:
		void zainicjalizuj_trojkat();
		void przesun_trojkat(wspolrzedne wektor_przesuniecia);
		void wyswietl_wspolrzedne_trojkata();
		double obwod_trojkata();
		double pole_trojkata();
		bool czy_prostokatny();
		bool czy_rownoboczny();
		bool czy_rownoramienny();
};
