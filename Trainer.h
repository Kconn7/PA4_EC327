#include "GameObject.h"
#include "PokemonCenter.h"
#include "PokemonGym.h"
#include "Vector2D.h"
#include "Point2D.h" 

#ifndef Trainer_h
#define Trainer_h
#include <iostream>
#include <string>
using namespace std;

class Trainer: public GameObject
{
    enum TrainerStates
    {
        STOPPED = 0,
        MOVING = 1,
        FAINTED = 2,
        AT_CENTER = 3,
        IN_GYM = 4,
        MOVING_TO_CENTER = 5,
        MOVING_TO_GYM = 6,
        BATTLING_IN_GYM = 7, 
        RECOVERING_HEALTH = 8
    };

    private: 
        double speed;
        bool is_at_center = false;
        bool is_IN_GYM = false;
        unsigned int health = 20;
        unsigned int experience= 0;
        double PokeDollars = 0; //i set this as a very large number just for testing and wanted to reupload this sorry!
        unsigned int battles_to_buy = 0;
        unsigned int potions_to_buy = 0;
        string name;                      
        PokemonCenter* current_center;
        PokemonGym* current_gym;
        Point2D destination;
        Vector2D delta;
        //WildPokemon* following_pokemon;

    public:
        Trainer();
        Trainer(char);
        Trainer(string, int, char, unsigned int, Point2D);//need to include string in first spot
        void StartMoving(Point2D);
        void StartMovingToGym(PokemonGym*);
        void StartMovingToCenter(PokemonCenter*);
        void StartBattling(unsigned int);
        void StartRecoveringHealth(unsigned int);
        void Stop();
        bool HasFainted();
        bool ShouldBeVisible();
        void ShowStatus();
        bool Update();
        string GetName();
        virtual ~Trainer();
        double GetHealth();

    protected:
        bool UpdateLocation();
        void SetupDestination(Point2D);

};
double GetRandomAmountOfPokeDollars();
#endif