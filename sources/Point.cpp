#include "Point.hpp"

using namespace std;
using namespace ariel;
#include <cmath>

Point::Point(double x_ptr,double y_ptr): _x(x_ptr),_y(y_ptr){

}

double Point::distance(const Point point) const{
    return sqrt(pow(this->_x - point._x,2) + pow(this->_y - point._y,2) );

}

string Point::print() const
{
	return "";
}

// static const Point &moveTowards(const Point &curr, const Point &other, const double dist){
//     return curr;
    
// }



double Point::getX() const
{
	return 0.0;
}

double Point::getY() const
{
	return 0.0;
}


 //cout << "Value of a is " << a;