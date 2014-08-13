#include "Sphere.h"

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