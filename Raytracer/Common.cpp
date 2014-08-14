#include "Common.h"

#include <cstdio>
#include <iostream>

Color::Color()
{
}

Color::Color(uint8_t r, uint8_t g, uint8_t b):
	_r(r), _g(g), _b(b) 
{
}

double point_distance(Point p1, Point p2) { 
	return sqrt(pow((p1.x() - p2.x()),2) + pow((p1.y() - p2.y()),2) + pow((p1.z() - p2.z()),2));
}

double dot_product(Point p1, Point p2) { 
	return p1.x()*p2.x() + p1.y()*p2.y() + p1.z()*p2.z();
}

double calc_illumination(Point p1, Point p2) { 
	double dp =  dot_product(p1, p2);
	double mag_p1 = sqrt(pow((p1.x()),2) + pow((p1.y()),2) + pow((p1.z()),2));
	double mag_p2 = sqrt(pow((p2.x()),2) + pow((p2.y()),2) + pow((p2.z()),2));

	double rad = acos(dp/(mag_p1*mag_p2));

	double illum_factor = ((PI/2.0) - rad)/( PI/2.0);

	if(illum_factor < 0) {
		return 0;
	}

	return illum_factor;
}