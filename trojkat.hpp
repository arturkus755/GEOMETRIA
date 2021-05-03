#include <iosfwd>

class wektor;
class ekran;

class trojkat
{
	public:
		trojkat() = default;
		trojkat(wektor* a, wektor* b, wektor* c) : punkty{a, b, c} {}
		trojkat(wektor* wektor) : punkty{wektor,wektor,wektor} {}
		trojkat(const ekran &e);
		wektor* wsp(int nr_punktu) const {return punkty[nr_punktu];};
		void ustaw_pkt(int nr_punktu, const wektor &nowy_punkt);
		trojkat &operator=(const trojkat &rzypisany) = default;
		trojkat operator+(const wektor &dodajnik);
		trojkat operator-(const wektor &odjemnik);
		double dlugosc_boku(unsigned int bok) const;
		double obwod() const;
		double pole() const;
		bool czy_prostokatny() const;
		bool czy_rownoboczny() const;
		bool czy_rownoramienny() const;
	private:
		wektor* punkty[3];
};

std::ostream &operator<<(std::ostream &s, const trojkat &t);

trojkat *szukaj_trojkata_najblizej_srodka(trojkat *trojkaty, int rozmiar, const ekran wyswietlacz);
