#pragma once

#include <iosfwd>

#include "wektor.hpp"

class ekran;

class wielokat
{
	public:
		wielokat() = default;

		virtual double obwod() const = 0;
		virtual double pole() const = 0;

		~wielokat() = default;
};