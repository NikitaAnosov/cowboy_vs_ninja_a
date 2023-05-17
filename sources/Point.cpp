#include "Point.hpp"
using namespace ariel;
Point::Point(double x, double y) : _x(x), _y(y) {}

double Point::getX() const { return _x; }
double Point::getY() const { return _y; }

double Point::distance(const Point &otherPoint) const
{
    double dist_x = _x - otherPoint._x;
    double dist_y = _y - otherPoint._y;
    return sqrt(dist_x * dist_x + dist_y * dist_y);
}

string Point::print() const
{
    return  "(" + to_string(getX())+ ", " + to_string(getY()) + ")" ;
}

Point Point::moveTowards(const Point &originPoint, const Point &destPoint, double dist)
{
    double dist_pointTOpoint = originPoint.distance(destPoint);
    if (dist_pointTOpoint <= dist)
        return destPoint;
    else
    {
        double ratio = dist / dist_pointTOpoint ;
        double dist_x = destPoint._x - originPoint._x;
        double dist_y = destPoint._y - originPoint._y;
        double dist_x2 = originPoint._x + dist_x * ratio;
        double dist_y2 = originPoint._y + dist_y * ratio;
        return Point(dist_x2, dist_y2);
    }
}
