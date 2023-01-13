
#include "Building.h"
#ifndef PokemonCenter_h
#define PokemonCenter_h

using namespace std;

class PokemonCenter: public Building
{
    enum PokemonCenterStates
    {
        POTIONS_AVAILABLE =0,
        NO_POTIONS_AVAILABLE=1
    };

    private:
    unsigned int potion_capacity;
    unsigned int num_potions_remaining;
    double pokedollar_cost_per_potion;

    public:
    PokemonCenter();
    PokemonCenter(int,double,unsigned int, Point2D);
    ~PokemonCenter();

    bool HasPotions();
    unsigned int GetNumPotionRemaining();
    bool CanAffordPotion(unsigned int, double);
    double GetPokeDollarCost(unsigned int potion);
    unsigned int DistributePotion(unsigned int);
    bool Update();
    void ShowStatus();
};
#endif