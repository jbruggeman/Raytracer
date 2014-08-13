#include "Common.h"

class PixelMap { 
	public:
		PixelMap(double, double, double, int, int );
		int query_height();
		int query_width();
		Point* query_location(int, int);

	private:
		Point _centre; 
		double _height, _width, _focal_distance;
		int _vsize, _hsize;
};