#include <iostream>
#include <fstream>
#include <cassert>
#include <iomanip>
#include "Vector2D.h"
#ifndef Point2D_h
#define Point2D_h

using namespace std;

class Point2D
{
    public:

    double x,y;
    Point2D();
    Point2D(double in_x, double in_y);
    //friend istream operator >> (istream& left, const Point2D& right);
    
};
double GetDistanceBetween(Point2D p1,Point2D p2);
ostream& operator << (ostream& left, Point2D& right);
Vector2D operator - (Point2D, Point2D);
Point2D operator + (Point2D, Vector2D);
#endif