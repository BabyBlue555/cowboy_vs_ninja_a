#pragma once

#include <string>

namespace ariel
{

class Point{
    private:
        double _x,_y;

    public:
        Point(double x_ptr,double y_ptr);
        double distance(Point point);
        std::string print() const;
        //Point moveTowards(Point src,Point dst,int dist);
        static const Point &moveTowards(const Point &curr, const Point &other, const double dist);
        double getX() const;
        double getY() const;

};



}


// //class Programmer
// {
// public:
// Person person;
// private:
// std::string _company;
// public:
// string getCompany() const {...}
// void setCompany(string c) {...}
// …
// ;