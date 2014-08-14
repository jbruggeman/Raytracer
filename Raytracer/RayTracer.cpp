#include "PixelMap.h"
#include "Sphere.h"

#include <cstdio>
#include <iostream>

#include "EasyBMP.h"

using namespace std;

// size of the resulting image
static const int horizontalPixels = 1000;
static const int verticalPixels = 750;

// input 
static const double width = 16.0;
static const double height = 12.0;

static const double focalLength = 5;

int main() {
	vector<Polygon *> polygons;

	Point origin(0, 0, 0);
	
	PixelMap* map = new PixelMap(focalLength, height, width, verticalPixels, horizontalPixels);

	polygons.push_back(new Sphere(Point(15, 5, 5), Color(80, 0, 0), 5.0, false));
	polygons.push_back(new Sphere(Point(15, 5, -5), Color(0, 80, 0), 5.0, false));
	polygons.push_back(new Sphere(Point(15, -5, 5), Color(0, 0, 80), 5.0, false));
	polygons.push_back(new Sphere(Point(-15, 20, -20), Color(127, 127, 127), 0, true));

	BMP Output;
	Output.SetSize(horizontalPixels, verticalPixels);
	Output.SetBitDepth( 24 );

	char stopper;

	int hit_count=0;
	for(int i=0; i < verticalPixels; i++) {
		for(int j=0; j < horizontalPixels; j++) {
			Point pixelMapPoint = map->queryLocation(i,j);

			if(!pixelMapPoint.valid()) {
				cout << "Error - point is not valid!" << endl;
				continue;
			}

			double t_dist = -1;
			double dist = -1;

			Polygon* closest_polygon = 0;
			Point closest_point;

			for(unsigned int k=0; k < polygons.size(); k++) {
				Point p = polygons[k]->closestIntersect(origin, pixelMapPoint);
			
				//getting the distance to the point
				if(p.valid()) {
					t_dist = point_distance(p, origin);
				} else {
					t_dist = -1;
				}

				//finding the nearest point
				if(t_dist != -1 && ((dist == -1) || (t_dist < dist))) {
					dist = t_dist;
					closest_polygon = polygons[k];
					closest_point = p;
				}
			}

			//We've got the polygon, the closest point on it, and access to the light sources, illumination time.
			double illumination_const = 0.0;
			if(closest_polygon != 0) {
				for(unsigned int k=0; k < polygons.size(); k++) {
					if(polygons[k]->isLightSource()) {
						Point centerOfLight = polygons[k]->center();

						Point centerOfClosesPolygon = closest_polygon->center();
						
						Point directionVector(closest_point.x() - centerOfClosesPolygon.x(), 
										      closest_point.y() - centerOfClosesPolygon.y(),
										      closest_point.z() - centerOfClosesPolygon.z()); 
						
						Point lightVector(centerOfLight.x() - closest_point.x(), 
										  centerOfLight.y() - closest_point.y(),
										  centerOfLight.z() - closest_point.z()); 

						illumination_const += calc_illumination(directionVector, lightVector);
						//cout << "illumination_const: " << illumination_const << endl;
					}
				}
			}

			//at this point, we have all of the information to Color the pixel.
			RGBApixel Temp;
			if(dist != -1) {
				hit_count++;
				Temp.Red = uint8_t(illumination_const*(float)closest_polygon->color()._r);
				Temp.Green = uint8_t(illumination_const*(float)closest_polygon->color()._g);
				Temp.Blue = uint8_t(illumination_const*(float)closest_polygon->color()._b);
			} else {
				Temp.Red = 0;
				Temp.Green = 0;
				Temp.Blue = 0;
			}

			Output.SetPixel(j,i,Temp);
		}
	}

	cout << hit_count << " of " << horizontalPixels * verticalPixels << endl;
 
	Output.WriteToFile( "output.bmp" );

	//cin >> stopper;

	return 0;
}