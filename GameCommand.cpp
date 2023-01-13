#include "GameCommand.h"
#include "Model.h"

void DoMoveCommand(Model& model, int trainer_id, Point2D p1)
{
    
    Trainer* T = model.GetTrainerPtr(trainer_id - 1);
    cout<<"Moving ("<<T->GetName()<<") to "<<p1<<endl;
    T->StartMoving(p1);
}
void DoMoveToCenterCommand(Model& model, int trainer_id, int center_id)
{
    Trainer* T = model.GetTrainerPtr(trainer_id-1);
    PokemonCenter* C = model.GetPokemonCenterPtr(center_id - 1);
    cout<<"Moving ("<<T->GetName()<<") to pokemon center ("<<center_id<<")"<<endl;
    T->StartMovingToCenter(C);
}
void DoMoceToGymCommand(Model& model, int trainer_id, int gym_id)
{
    Trainer* T = model.GetTrainerPtr(trainer_id-1);
    PokemonGym* G = model.GetPokemonGym(gym_id - 1); 
    cout<<"Moving ("<<T->GetName()<<") to gym ("<<gym_id<<")"<<endl;
    T->StartMovingToGym(G);
}
void DoStopCommand(Model& model, int trainer_id)
{
    Trainer* T = model.GetTrainerPtr(trainer_id-1);
    cout<<"Stopping ("<<T->GetName()<<endl;
    T->Stop();
}
void DoRecoverInCenterCommand(Model& model, int trainer_id, unsigned int potions_needed)
{
    Trainer* T = model.GetTrainerPtr(trainer_id-1);
    cout<<"Recovering ("<<T->GetName()<<"'s) Pokemon's health"<<endl;
    T->StartRecoveringHealth(potions_needed);
}
void DoBatlleCommand(Model& model, int trainer_id, unsigned int battles)
{
    Trainer* T = model.GetTrainerPtr(trainer_id-1);
    cout<<"("<<T->GetName()<<"'s) is battling"<<endl;
    T->StartBattling(battles);
}   
void DoAdvanceCommand(Model& model, View& view)
{
    model.Update();
}
void DoRunCommand(Model& model, View& view)
{
    for(int i = 0; i < 5; i++)
    {
        //cout<<"Run Command has Run: "<<i<<endl;
        model.Update();
    }
}

void CreateNewObject(Model& model, char c,int id, Point2D point)
{
    model.CreateObject(c, id, point);
}




/*couple notes to self 11/23/22 if try to battle outside a gym core dump
trying to go to a gym that doesnt exist results in core dump
each command runs to completion when it should just advance one tick/do one move may be able 
to fish this by writing the doadvance/run commands and then calling those from the other
command functions


Actually pretty sure if i just remove the while loops in the move functions theyll essentially
just move once and await me to call an advance*/

