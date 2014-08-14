#ifndef SPHERE_H
#define SPHERE_H

#include "Polygon.h"

class Sphere: public Polygon {
    public:
		Sphere(Point center, Color color, double radius, bool isLightSource);
		Point closestIntersect(Point p0, Point p1);
		
	protected:
		double mRadius;
};

#endif /* SPHERE_H */