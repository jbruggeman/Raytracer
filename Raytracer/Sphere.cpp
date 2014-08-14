#include "Sphere.h"

#include <cmath>
#include <iostream>

using namespace std;

Sphere::Sphere(const Point& center, const Color& color, double radius, bool isLightSource): 
			   Polygon(center, color, isLightSource), 
	           mRadius(radius)
{
}

// see http://wiki.cgsociety.org/index.php/Ray_Sphere_Intersection
Point Sphere::closestIntersect(const Point& origin, const Point& directionVector) {
	//transform to object space. This involves moving the sphere to 0,0 and creating a rayOrigin

	Point rayOrigin = origin - mCenter;

	// create the unit vector
	double dx = directionVector.x();
	double dy = directionVector.y();
	double dz = directionVector.z();

	double ox = rayOrigin.x();
	double oy = rayOrigin.y();
	double oz = rayOrigin.z();
	
	double r = mRadius;

	double a = Point::dot(directionVector, directionVector);
	double b = 2.0 * Point::dot(directionVector, rayOrigin);
	double c = Point::dot(rayOrigin, rayOrigin) - r * r; 

	double discriminant = b*b-4*a*c;

	if(discriminant < 0) {
		return Point();
	}

	float q;
	if(b < 0) { 
		q = (-b - sqrt(discriminant)) / 2.0;
	} else {
		q = (-b + sqrt(discriminant)) / 2.0;
	}

	double t0 = q / a;
	double t1 = c / q; 
		
	if(t0 > t1) {
		double temp = t1;
		t1 = t0;
		t0 = temp;
	}

	if(t1 < 0) {
		return Point();
	}

	double intersect = t0 < 0 ? t1 : t0;

	return Point(dx * intersect + ox, dy * intersect + oy, dz * intersect + oz);
}