#include <iostream>

#include "wielokat.hpp"
#include "wektor.hpp"
#include "ekran.hpp"

wielokat::wielokat(const ekran& e)
{
	punkt->x = e.roz_x() / 2;
	punkt->y = e.roz_x() / 2;
}

void wielokat::ustaw_wsp(const wektor &w)
{
	*punkt = w;
}

std::ostream &operator<<(std::ostream &s, const wielokat &f)
{
    s << "[" << f.zwroc_wsp()->x << ", " << f.zwroc_wsp()->y << "]";
    return s;
}