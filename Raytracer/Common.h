#ifndef COMMON_H
#define COMMON_H

#include <vector>
#include <cmath>

#include "Point.h"

const double PI = 3.141592653589;

typedef unsigned char uint8_t;

class Color {
    public:
		Color();
		Color(uint8_t r, uint8_t g, uint8_t b);
 
   		uint8_t _r;
   		uint8_t _g;
		uint8_t _b;
};

double point_distance(Point p1, Point p2);

double dot_product(Point p1, Point p2);

double calc_illumination(Point p1, Point p2);

#endif /* COMMON_H */