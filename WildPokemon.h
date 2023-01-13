#include "GameObject.h"
#include "Trainer.h"
#include <iostream>

#ifndef WildPokemon_h
#define WildPokemon_h
#include <string>

using namespace std;

class WildPokemon: public GameObject
{
    enum WildPokemonStates
    {
        IN_ENVIRONMENT = 0,
        IN_TRAINER = 1,
        DEAD = 2
    }; 

    protected:
        double attack = 1;
        double health = 10;
        bool variant = false;
        bool in_combat;
        string name;
        Trainer* current_trainer;
        double speed; //may never end up using this

    public:
        WildPokemon();
        WildPokemon(char);
        WildPokemon(string, int, char, unsigned int, Point2D);
        void follow(Trainer*);
        bool get_variant();
        double get_attack();
        double get_health();
        bool get_in_combat();
        bool Update();
        void ShowStatus();
        bool IsAlive();   
        bool ShouldBeVisible();   
};


#endif