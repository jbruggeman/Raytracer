#ifndef PIXELMAP_H
#define PIXELMAP_H

#include "Common.h"

class PixelMap { 
	public:
		PixelMap(double focal_distance, double height, double width, int vsize, int hsize);
		int query_height();
		int query_width();
		Point* query_location(int row, int column);

	private:
		Point _centre; 
		double _height, _width, _focal_distance;
		int _vsize, _hsize;
};

#endif /* PIXELMAP_H */