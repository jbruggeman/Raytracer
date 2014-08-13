#ifndef SPHERE_H
#define SPHERE_H

#include "Polygon.h"

class Sphere: public Polygon {
    public:
		Sphere(Point*, Colour*, double, bool);
		Point* closestIntersect(Point*, Point*);
 
		double _r;
};

#endif /* SPHERE_H */