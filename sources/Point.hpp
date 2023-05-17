#pragma once

#include <string>

namespace ariel
{

class Point{
    private:
        double _x,_y;

    public:
        Point(double x_ptr,double y_ptr);
        double distance(const Point point) const;
        std::string print() const;
        //Point moveTowards(Point src,Point dst,int dist);
        static Point moveTowards(Point curr, Point other, const double dist){
            return curr;   
        }
        double getX() const;
        double getY() const;

// static Point moveTowards(Point src, Point dest, double dist){
};



}

