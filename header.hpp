#pragma once

struct wspolrzedne
{
	int x;
	int y;
};

void sprawdz_punkt(wspolrzedne &punkt);

void wyswietl_wspolrzedne_punktu(wspolrzedne punkt);

wspolrzedne przesun_punkt(wspolrzedne &punkt, wspolrzedne wektor_przesuniecia);

void ustaw_wspolrzedne_punktu(wspolrzedne &punkt);

unsigned long kwadrat_dlugosci_odcinka(wspolrzedne punkt1, wspolrzedne punkt2);

double dlugosc_odcinka(wspolrzedne punkt1, wspolrzedne punkt2);
