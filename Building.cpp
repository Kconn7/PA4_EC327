#include "Building.h"

Building::Building(): GameObject('B') //note unsure if should pass code (char) or have its code inheirt () doesnt really work with ()
{
    cout<<"Building default constructed"<<endl;
}

Building::Building(char in_code, int in_id, Point2D in_loc):GameObject(in_loc, in_id, in_code)
{
    id_num=in_id;
    location=in_loc;
    display_code=in_code;
    state=0;
    cout<<"Building constructed"<<endl;
}

void Building::AddOneTrainer()
{
    trainer_count++;
}
void Building::RemoveOneTrainer()
{
    trainer_count--;
}
void Building::ShowStatus()
{
    cout<<"("<<display_code<<")("<<id_num<<") " <<endl<<"located at "<<location<<""<<endl;
    if (trainer_count==1)
        cout<<"("<<trainer_count<<") trainers is in this building"<<endl;
    else
        cout<<"("<<trainer_count<<") trainers are in this building"<<endl;

}
bool Building::ShouldBeVisible()
{
    return true;
}