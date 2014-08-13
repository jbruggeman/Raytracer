#include "Polygon.h"

Polygon::Polygon(Point* p, Colour* c, bool ls):
	_p(p), _c(c), _ls(ls)
{
}

Polygon::~Polygon() {
	delete _p;
	delete _c;
}
