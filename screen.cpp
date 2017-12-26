#include "screen.hpp"
#include "vector3D.hpp"

Screen::Screen(Point3D top_left, Point3D top_right, Point3D bottom_left, int horizontal_res, Color background)
{
	int vertical_res = ((bottom_left - top_left).getNorm() / (top_right - top_left).getNorm()) * horizontal_res;

	_screen.resize()

}



    mSensor.resize(vResolution);
    for(auto& column: mSensor){
        column.resize(hResolution);
    }

    for(size_t y{0} ; y < mSensor.size() ; ++y){
        for(size_t x{0} ; x < mSensor[y].size() ; ++x){
            mSensor[y][x] = Pixel(Point(topLeft + h * x + v * y));
        }
    }
