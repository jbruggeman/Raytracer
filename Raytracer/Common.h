#ifndef COMMON_H
#define COMMON_H

#include <vector>
#include <cmath>

const double PI = 3.141592653589;

typedef unsigned char uint8_t;

class Point {
    public:
		Point();
		Point(double, double, double);
 
   		double _x;
   		double _y;
		double _z;
};

class Colour {
    public:
		Colour();
		Colour(uint8_t, uint8_t, uint8_t);
 
   		uint8_t _r;
   		uint8_t _g;
		uint8_t _b;
};

double point_distance(Point *, Point*);

double dot_product(Point *, Point*);

double calc_illumination(Point *, Point*);

#endif /* COMMON_H */