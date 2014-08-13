#include "PixelMap.h"

#include <cstdio>
#include <iostream>

#include "EasyBMP.h"

using namespace std;

vector<Polygon *> polygons;

int main() {

	int vsize = 1280, hsize = 720;
	double height = 16.0, width = 9.0;
	double distance = -5;
	Point* origin = new Point(-10, 0, 0);
	
	PixelMap* map = new PixelMap(distance, height, width, vsize, hsize);

	polygons.push_back(new Sphere(new Point(20, 2, 2), new Colour(80, 0, 0), 2, false));
	polygons.push_back(new Sphere(new Point(18, 0, 2), new Colour(0, 80, 0), 2, false));
	polygons.push_back(new Sphere(new Point(16, 0, 0), new Colour(0, 0, 80), 2, false));
	polygons.push_back(new Sphere(new Point(16, 0, 1), new Colour(80, 0, 80), 2, false));
	polygons.push_back(new Sphere(new Point(-10, -30, -30), new Colour(127, 127, 127), 0, true));

	BMP Output;
	Output.SetSize( vsize , hsize);
	Output.SetBitDepth( 32 );

	char stopper;

	int hit_count=0;
	for(int i=0;i<vsize;i++) {
		for(int j=0;j<hsize;j++) {
			Point * temp = map->query_location(i,j);

			double t_dist = -1;
			double dist = -1;
			Polygon* closest_polygon = 0;
			Point* closest_point = 0;
			for(unsigned int k=0;k<polygons.size();k++) {
				Point * p = polygons[k]->closestIntersect(origin, temp);
			
				//getting the distance to the point
				if(p != 0) {
					t_dist = point_distance(p, origin);
				} else {
					t_dist = -1;
				}

				//finding the nearest point
				if(t_dist != -1 && ((dist == -1) || (t_dist < dist))) {
					dist = t_dist;
					closest_polygon = polygons[k];
					
					if(closest_point != 0) {
						delete closest_point;
					}
					closest_point = p;
				} else if(p != 0){
					delete p;
				}
			}

			//We've got the polygon, the closest point on it, and access to the light sources, illumination time.
			double illumination_const = 0.0;
			if(closest_polygon != 0) {
				for(unsigned int k=0;k<polygons.size();k++) {
					if(polygons[k]->_ls) {
						Point* light_centre = polygons[k]->_p;
						
						Point* directionVector = new Point(closest_point->_x-closest_polygon->_p->_x, 
														   closest_point->_y-closest_polygon->_p->_y,
														   closest_point->_z-closest_polygon->_p->_z); 
						
						Point* lightVector = new Point(light_centre->_x-closest_point->_x, 
													   light_centre->_y-closest_point->_y,
													   light_centre->_z-closest_point->_z); 

						illumination_const += calc_illumination(directionVector, lightVector);
					}
				}
			}

			//at this point, we have all of the information to colour the pixel.
			RGBApixel Temp;
			if(dist != -1) {
				hit_count++;
				Temp.Red = uint8_t(illumination_const*(float)closest_polygon->_c->_r);
				Temp.Green = uint8_t(illumination_const*(float)closest_polygon->_c->_g);
				Temp.Blue = uint8_t(illumination_const*(float)closest_polygon->_c->_b);
			} else {
				Temp.Red = 0;
				Temp.Green = 0;
				Temp.Blue = 0;
			}

			Output.SetPixel(i,j,Temp);

			delete temp;
		}
	}

	cout << hit_count << " of " << vsize*hsize << endl;
 
	Output.WriteToFile( "output.bmp" );

	//cin >> stopper;

	delete origin;

	return 0;
}