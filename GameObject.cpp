#include "GameObject.h"
#include "Model.h"

GameObject::GameObject(char in_code)
{
    display_code = in_code;
    id_num=1;
    state=0;
    cout<<"GameObject constructed"<<endl;
}
GameObject::GameObject(Point2D in_loc, int in_id, char in_code)
{
    display_code=in_code;
    id_num=in_id;
    location=in_loc;
    state=0;
    cout<<"GameObject constructed"<<endl;
}
Point2D GameObject::GetLocation()
{
    return location;
}
int GameObject::GetId()
{
    return id_num;
}
char GameObject::GetState()
{
    return state;
}
void GameObject::ShowStatus()
{
    cout<<"("<<display_code<<") ("<<id_num<<") at "<<location<<endl;
}

GameObject::~GameObject()
{
    cout<<"GameObject destructed"<<endl;
}

void GameObject::DrawSelf(char* ptr) //takes the display code and plots it the grid along with the idnum in ascii
{
    ptr[0] = display_code;
    ptr[1] = '0' + id_num; //test
}
