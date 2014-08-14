#ifndef PIXELMAP_H
#define PIXELMAP_H

#include "Point.h"

class PixelMap { 
	public:
		PixelMap(double focalDistance, double height, double width, int verticalPixels, int horizontalPixels);
		Point queryLocation(int row, int column);

	private:
		double mFocalDistance;
		double mWidth;
		double mHeight;
		int mVerticalPixels;
		int mHorizontalPixels;

		Point mCenter; 
};

#endif /* PIXELMAP_H */