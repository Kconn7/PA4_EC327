#include <iostream>
#include <fstream>
#include <cassert>
#include <iomanip>
#ifndef Vector2D_h
#define Vector2D_h

using namespace std;

class Vector2D
{
    public:

    double x,y;
    Vector2D();
    Vector2D(double in_x, double in_y);
    //friend istream operator >> (istream& left, const Point2D& right);
    
};

ostream& operator << (ostream& left, Vector2D& right);
Vector2D operator* (Vector2D v1, double dist);
Vector2D operator/ (Vector2D v1, double dist);
#endif