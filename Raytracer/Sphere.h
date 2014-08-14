#ifndef SPHERE_H
#define SPHERE_H

#include "Polygon.h"

class Sphere: public Polygon {
    public:
		Sphere(const Point& center, const Color& color, double radius, bool isLightSource);
		Point closestIntersect(const Point& p0, const Point& p1);
		
	protected:
		double mRadius;
};

#endif /* SPHERE_H */