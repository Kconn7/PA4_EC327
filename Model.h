#ifndef Model_h
#define Model_h
#include <iostream>
#include "Trainer.h"
#include "PokemonCenter.h"
#include "PokemonGym.h"
#include "View.h"
#include "WildPokemon.h"
#include <list>

using namespace std;

class Model
{
    private:
    int time;
    
    /*GameObject* object_ptrs[10];
    int num_object;
    Trainer* trainer_ptrs[10];
    int num_trainers;
    PokemonCenter* center_ptrs[10];
    int num_centers;
    PokemonGym* gym_ptrs[10];
    int num_gyms;
    WildPokemon* wildpokemon_ptrs[10];
    int num_wildpokemon;*/

    list<GameObject*> Object_Ptrs;
    list<GameObject*>::iterator game_object_it;

    list<GameObject*> active_ptrs;
    list<GameObject*>::iterator active_it;

    list<Trainer*> Trainer_ptrs;
    list<Trainer*>::iterator trainer_it;

    list<PokemonCenter*> PokemonCenter_ptrs;
    list<PokemonCenter*>::iterator PokemonCenter_it;

    list<PokemonGym*> PokemonGym_ptrs;
    list<PokemonGym*>::iterator PokemonGym_it;

    list<WildPokemon*> WildPokemon_ptrs;
    list<WildPokemon*>::iterator WildPokemon_it;

    public:
    Model();
    ~Model(); //note for the deconstructors for other files ask what this means pg20
    Trainer* GetTrainerPtr(int);
    PokemonCenter* GetPokemonCenterPtr(int);
    PokemonGym* GetPokemonGym(int);
    GameObject* GetGameObjectPtr(int); // added this function for easier accessing of the showstatus function
    bool Update();
    //bool CheckWinLose(); //new bool to check if the win conditions are met
    void Display(View&);
    void ShowStatus();
    void CreateObject(char, int, Point2D);
};
#endif