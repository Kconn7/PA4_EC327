#include <iostream>
#include <fstream>
#include <cassert>
#include <iomanip>
#include "Point2D.h"
#ifndef GameObject_h
#define GameObject_h


using namespace std;

class GameObject
{
    protected:

    Point2D location;
    int id_num;
    char display_code;
    char state;

    public:

    GameObject(char);
    GameObject(Point2D,int,char);
    Point2D GetLocation();
    int GetId();
    char GetState();
    virtual ~GameObject();
    virtual void ShowStatus();
    virtual bool Update() = 0;
    virtual bool ShouldBeVisible() = 0;
    void DrawSelf(char* ptr);



};
#endif