#include "PokemonCenter.h"

PokemonCenter::PokemonCenter(): Building()
{
    display_code='C';
    potion_capacity=100;
    num_potions_remaining=potion_capacity;
    pokedollar_cost_per_potion=5;
    state = POTIONS_AVAILABLE;
    cout<<"Pokemon default constructed"<<endl;
    //cout<<"**TEST 0: "<<num_potions_remaining<<endl;
}
PokemonCenter::PokemonCenter(int in_id,double potion_cost, unsigned int potion_cap, Point2D in_loc):
Building('C',in_id, in_loc)
{
    pokedollar_cost_per_potion=potion_cost;
    potion_capacity=potion_cap;
    num_potions_remaining = potion_capacity;
    state = POTIONS_AVAILABLE;
    cout<<"PokemonCenter constructed"<<endl;
    //cout<<"**TEST 0: "<<num_potions_remaining<<endl;
}

bool PokemonCenter::HasPotions() //checks to see if there are any potions left
{
    //cout<<"**TEST 1: "<<num_potions_remaining<<endl;
    if(num_potions_remaining>=1)
        return true;
    else
        return false;
}
unsigned int PokemonCenter::GetNumPotionRemaining() //returns num of potions
{
        //cout<<"**TEST 2: "<<num_potions_remaining<<endl;
    return num_potions_remaining;
}
bool PokemonCenter::CanAffordPotion(unsigned int potion, double budget) //check to see if they have enough money for desired potions
{
        //cout<<"**TEST 3: "<<num_potions_remaining<<endl;
    if ((potion*pokedollar_cost_per_potion)>budget)
        return false;
    else
        return true;
    
}
double PokemonCenter::GetPokeDollarCost(unsigned int potion) //returns potion cost * needed potions
{
        //cout<<"**TEST 4: "<<num_potions_remaining<<endl;
    return pokedollar_cost_per_potion*potion; // is potion the number of potions the cost or the kind of potion?
}
unsigned int PokemonCenter::DistributePotion(unsigned int potion_needed)
{
        //cout<<"**TEST 5: "<<num_potions_remaining<<endl;
    if (num_potions_remaining >= potion_needed)
    {
        num_potions_remaining=num_potions_remaining-potion_needed;
        return potion_needed;
    }
    else if (num_potions_remaining <= potion_needed)
    {
        //cout<<num_potions_remaining<<endl;
        unsigned int temp = num_potions_remaining;
        num_potions_remaining = 0;
        Update(); //calls an update to update that the center has run out
        return temp;
    }
}
bool PokemonCenter::Update() //updates the center and wether it has potions left or not
{
    //cout<<"**TEST 6: "<<num_potions_remaining<<endl;
    if(state == POTIONS_AVAILABLE)
    {
        if(num_potions_remaining <= 0)
        {
            state=NO_POTIONS_AVAILABLE;
            display_code='c';
            cout<<"PokemonCenter ("<<display_code<<")("<<id_num<<") has ran out of potions"<<endl;
            return true;
        }
        return false;
    }
    return true;
}
void PokemonCenter::ShowStatus()
{
    //cout<<"**TEST 7: "<<num_potions_remaining<<endl;
    cout<<"PokemonCenter Status: ";
    Building::ShowStatus();
    cout<<"PokeDollars per potion: ("<<pokedollar_cost_per_potion<<") has ("<<num_potions_remaining<<") potions remaining."<<endl<<endl;
}

PokemonCenter::~PokemonCenter()
{
    cout<<"PokemonCenter destructed"<<endl;
}