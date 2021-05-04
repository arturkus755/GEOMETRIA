#pragma once

#include <iosfwd>

class wektor;
class ekran;

class wielokat
{
	public:
		wielokat() = default;
		wielokat(wektor* w) : punkt{w} {}
		wielokat(const ekran& e);
		wektor* zwroc_wsp() const {return punkt;}
		void ustaw_wsp(const wektor &w);
	protected:
		wektor* punkt;
};

std::ostream &operator<<(std::ostream &s, const wielokat &f);