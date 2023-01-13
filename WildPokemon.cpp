#include "WildPokemon.h"

using namespace std;

WildPokemon::WildPokemon(): GameObject('P')
{
    state = IN_ENVIRONMENT;
    name = "Pokemon";
    speed = 6.0; //slightly faster than the trainer
    cout<<"Wild Pokemon Default Constructed"<<endl;
}
WildPokemon::WildPokemon(char in_code): GameObject(in_code)
{
    state = IN_ENVIRONMENT;
    name = "Pokemon";
    speed = 6.0; //slightly faster than the trainer
    display_code = in_code;
}
WildPokemon::WildPokemon(string in_name, int in_id, char in_code, unsigned int in_speed, Point2D in_loc)
:GameObject(in_loc, in_id, in_code)
{
    name = in_name;
    display_code = in_code;
    id_num = in_id;
    speed = in_speed;
    cout<<"Wild Pokemon Constructed"<<endl;
}

void WildPokemon::follow(Trainer* trainer)
{
    if(state == IN_ENVIRONMENT)
    {
        current_trainer = trainer;
        state = IN_TRAINER;
    }
    return;
}

bool WildPokemon::get_variant()
{
    return variant;
}

double WildPokemon::get_attack()
{
    return attack;
}

double WildPokemon::get_health()
{
    return health;
}

bool WildPokemon::get_in_combat()
{
    if(state == IN_TRAINER)
    {
        in_combat = true;
    }
    else
    {
        in_combat = false;
    }
    return in_combat;
}

bool WildPokemon::Update()
{
    bool battle_check = get_in_combat();
    bool health_check = IsAlive();
    //cout<<"****HEALTH AFTER UPDATE IS: "<<health<<endl;

    if(health_check == false)
    {
        //cout<<"DEAD**************************************************************"<<endl;
        state = DEAD;
        return true;
    }

    if (battle_check == true)
    {
        health = health - 1;
        unsigned int trainer_health = current_trainer->GetHealth();
        trainer_health = trainer_health - attack;
        location = current_trainer->GetLocation();
        return true;
    }

    if (state == DEAD)
    {
        ShouldBeVisible();
        return false;
    }
    if(state == IN_TRAINER)
    {
        return false;
    }

return false;
}

void WildPokemon::ShowStatus() //Maybe make wild pokemon invisible until a player gets near like normal pokemon
{
    cout<<"("<<name<<") status: "<<endl;
    GameObject::ShowStatus();
    cout<<"Health: "<<health<<endl;
    cout<<"Attack: "<<attack<<endl;

    if (state == IN_TRAINER)
    {
        cout <<"Following "<<current_trainer->GetName()<<endl;
        return;
    }
    else if (state  == IN_ENVIRONMENT)
    {
        cout<<"In the wild"<<endl;
        return;
    }
    else if(state == DEAD)
    {
        cout<<"DEFEATED"<<endl;
    }
    else
    return;  
}

bool WildPokemon::IsAlive()
{
    if (health <= 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool WildPokemon::ShouldBeVisible()
{
    if (IsAlive() == true)
    {
        return true;
    }
    else 
        return false;
}



