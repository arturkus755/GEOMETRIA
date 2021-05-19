#pragma once

#include "kwadrat.hpp"

class romb : virtual public kwadrat
{
	public:
	void ustaw_stosunek_przekatnych(double stosunek_przekatnych);

	double zwroc_stosunek_przekatnych() const {return m_stosunek_przekatnych;};

	double dlugosc_boku() const;
	double obwod() const;
	double pole() const;
	protected:
	double m_stosunek_przekatnych = 1.0;	//stosunek przekotnej, do ktorej nalezy wierzcholek do przeciwnej przekatnej
};