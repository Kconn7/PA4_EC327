#include <math.h>
#include "Vector2D.h"

Vector2D::Vector2D()
{
    x=0.0;
    y=0.0;
}
Vector2D::Vector2D(double in_x,double in_y)
{
    x=in_x;
    y=in_y;
}

Vector2D operator* (Vector2D v1, double dist)
{
    v1.x=v1.x*dist;
    v1.y=v1.y*dist;
    return v1;
}
Vector2D operator/ (Vector2D v1, double dist)
{
    if(dist!=0)
    {
        v1.x=v1.x/dist;
        v1.y=v1.y/dist;
        return v1;
    }
    return v1;
}

ostream& operator << (ostream& left, Vector2D& right)
{
    left<<"("<<right.x<<","<<right.y<<")";
    return left;
}