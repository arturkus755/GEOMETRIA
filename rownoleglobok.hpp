#pragma once

#include "romb.hpp"
#include "prostokat.hpp"

class rownoleglobok final : public romb, protected prostokat
{
	public:
		double dlugosc_boku(unsigned int nr_boku) const;
		double obwod() const;
		double pole() const;
		
		using prostokat::ustaw_kat_miedzy_przekatnymi;
		using prostokat::zwroc_kat_miedzy_przekatnymi;
};