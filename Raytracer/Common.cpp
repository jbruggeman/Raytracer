#include "Common.h"

#include <cstdio>
#include <iostream>

Point::Point()
	{}

Point::Point(double x, double y, double z):
	_x(x), _y(y), _z(z) 
	{}

Colour::Colour()
	{}

Colour::Colour(uint8_t r, uint8_t g, uint8_t b):
	_r(r), _g(g), _b(b) 
	{}

Polygon::Polygon(Point* p, Colour* c, bool ls):
	_p(p), _c(c), _ls(ls)
	{}

Polygon::~Polygon() {
	delete _p;
	delete _c;
}

Sphere::Sphere(Point* p, Colour* c, double r, bool ls): 
	Polygon(p, c, ls), _r(r)
	{}

//returns 0 if there is no point of intersection.
Point* Sphere::closestIntersect(Point* p0, Point* p1) {
	//determining the vector
	double dx0 = p1->_x - p0->_x;
	double dy0 = p1->_y - p0->_y;
	double dz0 = p1->_z - p0->_z;

	//creating the unit vectors
	double divisor = abs(dx0) + abs(dy0) + abs(dz0);
	double dx = dx0/divisor;
	double dy = dy0/divisor;
	double dz = dz0/divisor;

	//origin coords
	double x0 = p0->_x;
	double y0 = p0->_y;
	double z0 = p0->_z;

	//centre of the sphere
	double cx = _p->_x;
	double cy = _p->_y; 
	double cz = _p->_z; 

	//radius of the sphere
	double r = _r;

	double a = dx*dx + dy*dy + dz*dz;
	double b = 2*dx*(x0-cx) +  2*dy*(y0-cy) +  2*dz*(z0-cz);
	double c = cx*cx + cy*cy + cz*cz + x0*x0 + y0*y0 + z0*z0 
		+ (-2)*(cx*x0 + cy*y0 + cz*z0) - r*r;

	double inner = b*b-4*a*c;

	if(inner < 0)
		return 0;
	
	double t = (-b-sqrt(inner)) / 2*a;

	if(t<0) {
		return 0;
	} else {
		return new Point(x0+t*dx, y0+t*dy, z0+t*dz);
	}
}

double point_distance(Point* p1, Point* p2) { 
	return sqrt(pow((p1->_x - p2->_x),2) + pow((p1->_y - p2->_y),2) + pow((p1->_z - p2->_z),2));
}

double dot_product(Point* p1, Point* p2) { 
	return p1->_x*p2->_x + p1->_y*p2->_y + p1->_z*p2->_z;
}

double calc_illumination(Point* p1, Point* p2) { 
	double dp =  dot_product(p1, p2);
	double mag_p1 = sqrt(pow((p1->_x),2) + pow((p1->_y),2) + pow((p1->_z),2));
	double mag_p2 = sqrt(pow((p2->_x),2) + pow((p2->_y),2) + pow((p2->_z),2));

	double rad = acos(dp/(mag_p1*mag_p2));

	double illum_factor = ((PI/2.0) - rad)/( PI/2.0);

	if(illum_factor < 0) {
		return 0;
	}

	return illum_factor;
}