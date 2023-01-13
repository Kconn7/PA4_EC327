#include "PokemonGym.h"

PokemonGym::PokemonGym(): Building()
{
    display_code='G';
    max_number_of_battles=10;
    num_battle_remaining=max_number_of_battles;
    health_cost_per_battle=1;
    PokeDollar_cost_per_battle=1.0;
    experience_per_battle=2;
    cout<<"PokemonGym default constucted"<<endl;
}
PokemonGym::PokemonGym(unsigned int max_battle, unsigned int health_loss, double PokeDollar_cost, unsigned int exp_per_battle, int in_id, Point2D in_loc):
Building('G',in_id, in_loc)
{
    id_num=in_id;
    max_number_of_battles=max_battle;
    num_battle_remaining = max_number_of_battles;
    health_cost_per_battle=health_loss;
    experience_per_battle=exp_per_battle;
    PokeDollar_cost_per_battle=PokeDollar_cost;
    location=in_loc;
    state=NOT_DEFEATED;
    cout<<"PokemonGym constructed"<<endl;
}

double PokemonGym::GetPokeDollarCost(unsigned int battle_qty) //returns cost * number of battles
{
    return battle_qty*PokeDollar_cost_per_battle;
}
unsigned int PokemonGym::GetHealthCost(unsigned int battle_qty) //returns health cost * battles
{
    return health_cost_per_battle*battle_qty;
}
unsigned int PokemonGym::GetNumBattlesRemaining() //how many battles are left
{
    return num_battle_remaining;
}
bool PokemonGym::IsAbleToBattle(unsigned int battle_qty, double budget, unsigned int health) //checks if the player has enough money and health to battle
{
    double health_cost=battle_qty*health_cost_per_battle;
    double money_cost=battle_qty*PokeDollar_cost_per_battle;
    if ((health_cost < health) && (money_cost < budget))
    {
        return true;
    }
    return false;
}
unsigned int PokemonGym::TrainPokemon(unsigned int battle_units) //function that allows fights to occur
{
    double exp_gained;
    if(num_battle_remaining>=battle_units) //if the number of battles requested is less than that remaining it updates the remain by subtracting the requested amount
    {
        //cout<<"*****Num bats remaining: "<<num_battle_remaining<<endl;
        exp_gained=GetExperiencePerBattle();
        exp_gained=exp_gained*battle_units;
        num_battle_remaining=num_battle_remaining-battle_units;
        //cout<<"*****Num bats remaining 2: "<<num_battle_remaining<<endl;
        return exp_gained; //returns the amt of xp gained
    }
    else if (num_battle_remaining < battle_units) // checks if the battles requested is greater than just sets the battles to be equal to the number remaing
    {
        exp_gained = num_battle_remaining*battle_units;
        num_battle_remaining=0;
    }
    Update();
    return exp_gained;

}
unsigned int PokemonGym::GetExperiencePerBattle() //returns x per battle
{
    return experience_per_battle;
}
bool PokemonGym::Update() //checks if the gym has battles left if not updates it
{
    if(state==NOT_DEFEATED)
    {
        if(num_battle_remaining <= 0)
        {
            state=DEFEATED;
            display_code='g';
            cout<<"("<<display_code<<")("<<id_num<<") has been beated"<<endl;
            return true;
        }
        return false;
    }
    return false;
}
    
   /* do
    {
        cout<<num_battle_remaining<<endl;
        cout<<"this happened"<<endl;
        return false;
    }
    while(num_battle_remaining==0);

    state=DEFEATED;
    display_code='g';
    cout<<"("<<display_code<<")("<<id_num<<") has been beated"<<endl;
    return true;*/
bool PokemonGym::passed()
{
    if(num_battle_remaining==0)
        return true;
    else
        return false;
}
void PokemonGym::ShowStatus()
{
    cout<<"PokemonGymStatus: ";
    Building::ShowStatus();
    cout<<"Max number of battle: ("<<max_number_of_battles<<")"<<endl;
    cout<<"Health cost per battle: ("<<health_cost_per_battle<<")"<<endl;
    cout<<"PokeDollar per battle: ("<<PokeDollar_cost_per_battle<<")"<<endl;
    cout<<"Experience per battle: ("<<experience_per_battle<<")"<<endl;
    cout<<"("<<num_battle_remaining<<") battle(s) are remaining for this PokemonGym"<<endl<<endl;
}

unsigned int PokemonGym::GetMaxBattles()
{
    return max_number_of_battles; //simply returns max battles
}

PokemonGym::~PokemonGym()
{
    cout<<"PokemonGym destructed"<<endl;
}