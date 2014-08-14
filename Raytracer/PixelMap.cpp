#include "PixelMap.h"

PixelMap::PixelMap(double focalDistance, double height, double width, int verticalPixels, int horizontalPixels):
					mFocalDistance(focalDistance),  
					mHeight(height), 
					mWidth(width), 
					mVerticalPixels(verticalPixels), 
					mHorizontalPixels(horizontalPixels), 
					mCenter(Point(0.0, 0.0, 0.0)) 
{
}

Point PixelMap::queryLocation(int row, int column) {
	if(row >= mVerticalPixels || column >= mHorizontalPixels) {
		return Point();
	}
	
	double horizontalSteps = double(mHorizontalPixels) - 1;
	double verticalSteps = double(mVerticalPixels) - 1;
	
	double horizontalStepSize = mWidth / horizontalSteps;
	double verticalStepSize = mHeight / verticalSteps;
	
	double bottomLeftZCoord = -mWidth / 2.0;
	double bottomLeftYCoord = -mHeight / 2.0;
	
	double x = mFocalDistance;
	double y = bottomLeftYCoord + double(row) * verticalStepSize;
	double z = bottomLeftZCoord + double(column) * horizontalStepSize;

	return Point(x, y, z);
}