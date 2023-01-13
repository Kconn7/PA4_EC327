#include "Building.h"
#ifndef PokemonGym_h
#define PokemonGym_h
using namespace std;

class PokemonGym: public Building
{
    enum PokemonGymStates
    {
        NOT_DEFEATED=0,
        DEFEATED = 1
    };

    private:
    unsigned int num_battle_remaining;
    unsigned int max_number_of_battles;
    unsigned int health_cost_per_battle;
    double PokeDollar_cost_per_battle;
    unsigned int experience_per_battle;

    public:
    PokemonGym();
    PokemonGym(unsigned int, unsigned int, double, unsigned int, int, Point2D);
    ~PokemonGym();

    double GetPokeDollarCost(unsigned int);
    unsigned int GetHealthCost(unsigned int);
    unsigned int GetNumBattlesRemaining();
    bool IsAbleToBattle(unsigned int, double, unsigned int);
    unsigned int TrainPokemon(unsigned int);
    unsigned int GetExperiencePerBattle();
    unsigned int GetMaxBattles(); //added function for easier use of checking if the user is trying to fight more battles than possible
    bool Update();
    bool passed();
    void ShowStatus();
};
#endif