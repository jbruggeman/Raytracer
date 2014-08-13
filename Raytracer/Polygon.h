#ifndef POLYGON_H
#define POLYGON_H

#include "Common.h"

class Polygon { 
	public: 
		Polygon(Point*, Colour*, bool);
		~Polygon();
		virtual Point* closestIntersect(Point *, Point *) =0;

   		Point* _p;
		Colour* _c;
		bool _ls;
};

#endif /* POLYGON_H */