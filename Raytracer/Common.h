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

class Polygon { 
	public: 
		Polygon(Point*, Colour*, bool);
		~Polygon();
		virtual Point* closestIntersect(Point *, Point *) =0;

   		Point* _p;
		Colour* _c;
		bool _ls;
};

class Sphere:public Polygon {
    public:
		Sphere(Point*, Colour*, double, bool);
		Point* closestIntersect(Point*, Point*);
 
		double _r;
};

double point_distance(Point *, Point*);

double dot_product(Point *, Point*);

double calc_illumination(Point *, Point*);