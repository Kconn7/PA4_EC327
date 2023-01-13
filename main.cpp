#include "Model.h"
#include "View.h"
#include "GameCommand.h"
#include <iostream>
#include "Input_Handling.h"

using namespace std;

int main()
{
Model Model;
View View;
char type;
char cmd;
int trainer_id, center_id, gym_id,id;
unsigned int battles, potions_needed;
double x,y; //initalizes all the variables and objects

while (cmd != 'q') //checks if cmd is ever q if so ends
{
Model.ShowStatus();
Model.Display(View);
cout<<"Enter a command: ";
cin>>cmd;
try{
    switch (cmd)
    {
        case 'm':
        {
            cin>>trainer_id>>x>>y;
            Point2D temp(x,y);
            DoMoveCommand(Model, trainer_id, temp);
            break;
        }
        case 'c':
            cin>>trainer_id>>center_id;
            DoMoveToCenterCommand(Model, trainer_id, center_id);
            break;
        case 'g':
            cin>>trainer_id>>gym_id;
            DoMoceToGymCommand(Model, trainer_id, gym_id);
            break;
        case 's':
            cin>>trainer_id;
            DoStopCommand(Model, trainer_id);
            break;
        case 'p':
            cin>>trainer_id>>potions_needed;
            DoRecoverInCenterCommand(Model, trainer_id, potions_needed);
            break;
        case 'b':
            cin>>trainer_id>>battles;
            DoBatlleCommand(Model, trainer_id, battles);   
            break;
        case 'a':
            DoAdvanceCommand(Model, View);
            break;
        case 'r':
            DoRunCommand(Model, View);
            break;
        case 'q':
            cout<<"Quiting"<<endl;
            break;
        case 'n':
            cin>>type>>id>>x>>y;
            Point2D temp(x,y);
            CreateNewObject(Model,type,id,temp);
            cout<<endl<<"Creating new object"<<endl;
            break;
    }
}
catch (Invalid_Input& except)
{
    cout<<"Invalid Input - "<<except.msg_ptr<<endl;
}
}

return 0;
}