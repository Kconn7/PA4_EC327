#include <math.h>
#include "Point2D.h"
#include "Vector2D.h"



Point2D::Point2D()
    {
        x=0.0;
        y=0.0;
    }

Point2D::Point2D(double in_x, double in_y)
    {
        x=in_x;
        y=in_y;
    }

double GetDistanceBetween(Point2D p1,Point2D p2)
{
    double dist;
    double temp = p2.x - p1.x;
    double temp2 = p2.y - p1.y;
    double po1 = pow(temp,2);
    double po2=pow(temp2,2);
    dist=sqrt(po1+po2);
    return dist;
}
/*   istream operator >> (istream& left, const Point2D& right)
    {
        left>>right.x>>right.y;
        return left;
    }*/
    ostream& operator << (ostream& left, Point2D& right)
    {
        left<<"("<<right.x<<","<<right.y<<")";
        return left;
    }

Vector2D operator - (Point2D p1, Point2D p2)
{
    Vector2D newV;
    newV.x = p1.x - p2.x;
    newV.y = p1.y - p2.y;
    return newV;
}

Point2D operator + (Point2D p, Vector2D v)
{
    Point2D newP;
    newP.x = p.x+v.x;
    newP.y = p.y+v.y;
    return newP;
}