#ifndef POINT_HPP
#define POINT_HPP
#include <iostream>
#include <string>
#include <cmath>
using std::string;
using std::to_string;
namespace ariel{
    class Point{
        private:
            double _x, _y;
        public:
            //constructor:
            Point(double x, double y);
            //gettes
            double getX() const;
            double getY() const;
            //functions
            double distance(const Point &otherPoint) const;
            string print() const;
            Point moveTowards(const Point &originPoint, const Point &destPoint, double dist);
    };
}
#endif