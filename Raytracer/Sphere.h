#ifndef SPHERE_H
#define SPHERE_H

#include "Polygon.h"

class Sphere: public Polygon {
    public:
		Sphere(const Point& center, const Color& color, double radius, bool isLightSource);
		Point closestIntersect(const Point& origin, const Point& directionVector);
		
	protected:
		double mRadius;
};

#endif /* SPHERE_H */