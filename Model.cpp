#include "Model.h"
#include "Input_Handling.h"

Model::Model()
{
    Point2D pt1 (5,1);
    Point2D pt2 (10,1);
    Point2D ptC1 (1,20);
    Point2D ptC2 (10,20);
    Point2D ptG1 (0,0);
    Point2D ptG2 (5,5);
    Point2D ptP1 (10,12);
    Point2D ptP2 (15,5);

    /*num_object = 8;
    num_trainers = 2;
    num_centers = 2;
    num_gyms = 2;
    num_wildpokemon = 2;*/

    time = 0;

    /*for (int i = 0; i <= 10; i++)
    {
        object_ptrs[i] = NULL;
        trainer_ptrs[i] = NULL;
        center_ptrs[i] = NULL;
        gym_ptrs[i] = NULL;
        wildpokemon_ptrs[i] = NULL;
    }*/

    Trainer* T1 = new Trainer("Ash", 1,'T', 3, pt1);
    //object_ptrs[0] = T1;
    //trainer_ptrs[0] = T1;
    Trainer* T2 = new Trainer("Misty", 2, 'T', 2, pt2);
    //object_ptrs[1] = T2;
    //trainer_ptrs[1] = T2;

    PokemonCenter* C1 = new PokemonCenter(1, 1, 100, ptC1);
    //object_ptrs[2] = C1;
    //center_ptrs[0] = C1;
    PokemonCenter* C2 = new PokemonCenter(2, 2, 200, ptC2);
    //object_ptrs[3] = C2;
    //center_ptrs[1] = C2;

    PokemonGym* G1 = new PokemonGym(10, 1, 2.0, 3, 1, ptG1);
    //object_ptrs[4] = G1;
    //gym_ptrs[0] = G1;
    PokemonGym* G2 = new PokemonGym(20, 5, 7.5, 4, 2, ptG2);
    //object_ptrs[5] = G2;
    //gym_ptrs[1] = G2;

    WildPokemon* P1  = new WildPokemon("Wild Pokemon", 1, 'P', 3, ptP1);
    //object_ptrs[6] = P1;
    //wildpokemon_ptrs[0] = P1;
    WildPokemon* P2  = new WildPokemon("Wild Pokemon", 2, 'P', 2, ptP2);
    //object_ptrs[7] = P2;
    //wildpokemon_ptrs[1] = P2;

    Object_Ptrs.push_back(T1);
    Object_Ptrs.push_back(T2);
    Object_Ptrs.push_back(C1);
    Object_Ptrs.push_back(C2);
    Object_Ptrs.push_back(G1);
    Object_Ptrs.push_back(G2);
    Object_Ptrs.push_back(P1);
    Object_Ptrs.push_back(P2);

    active_ptrs.push_back(T1);
    active_ptrs.push_back(T2);
    active_ptrs.push_back(C1);
    active_ptrs.push_back(C2);
    active_ptrs.push_back(G1);
    active_ptrs.push_back(G2);
    active_ptrs.push_back(P1);
    active_ptrs.push_back(P2);

    Trainer_ptrs.push_back(T1);
    Trainer_ptrs.push_back(T2);

    PokemonCenter_ptrs.push_back(C1);
    PokemonCenter_ptrs.push_back(C2);

    PokemonGym_ptrs.push_back(G1);
    PokemonGym_ptrs.push_back(G2);

    WildPokemon_ptrs.push_back(P1);
    WildPokemon_ptrs.push_back(P2);

    cout<<"Model default constructed"<<endl<<endl;;
}

Model::~Model()
{
    /*for (int i = 0; i < 10; i++)
    {
        if (object_ptrs[i] != NULL)
        {
            delete object_ptrs[i];
        }
    }
    cout<<"Model destruced"<<endl;*/

    for(auto game_object_it  =Object_Ptrs.begin(); game_object_it != Object_Ptrs.end(); game_object_it++)
    {
        delete *game_object_it;
    }

    cout<<"Model destruced"<<endl;
}

Trainer* Model::GetTrainerPtr(int id)
{
    //return trainer_ptrs[id];
    for(auto trainer_it = Trainer_ptrs.begin(); trainer_it != Trainer_ptrs.end(); trainer_it++)
    {
        if(((*trainer_it)->GetId()) - 1 == id)
        {
            return *trainer_it;
        }
    }
    return 0;
}

PokemonCenter* Model::GetPokemonCenterPtr(int id)
{
    //return center_ptrs[id];
    for(auto PokemonCenter_it  =PokemonCenter_ptrs.begin(); PokemonCenter_it != PokemonCenter_ptrs.end(); PokemonCenter_it++)
    {
        if(((*PokemonCenter_it)->GetId()) - 1 == id)
        {
            return *PokemonCenter_it;
        }
    }
    return 0;
}

PokemonGym* Model::GetPokemonGym(int id)
{
    //return gym_ptrs[id];
    for(auto PokemonGym_it  =PokemonGym_ptrs.begin(); PokemonGym_it != PokemonGym_ptrs.end(); PokemonGym_it++)
    {
        if(((*PokemonGym_it)->GetId()) - 1 == id)
        {
            return *PokemonGym_it;
        }
    }
    return 0;
}

GameObject* Model::GetGameObjectPtr(int id)
{
    //return object_ptrs[id];
    for(auto game_object_it  =Object_Ptrs.begin(); game_object_it != Object_Ptrs.end(); game_object_it++)
    {
        if((*game_object_it)->GetId() == id)
        {
            return *game_object_it;
        }
    }
    return 0;
}

bool Model::Update() //updates every single object every tick
{
    /*int numobjects = 0;

    for (int i = 0; i < 10; i++)
    {
        if (object_ptrs[i] != NULL)
        {
            numobjects++;
        }
    }

    for (int i = 0; i < numobjects; i++) 
    {
        if(object_ptrs[i]->Update() == true)
        {
            //cout<<endl<<"***** TESTING *****"<<endl<<endl;

        }
     }

    for (int i = 0; i < 10; i++)
    {
        for( int j = 0; j<10; j++)
        {
            if((trainer_ptrs[i] != NULL) && (wildpokemon_ptrs[j] != NULL))
            {
                Point2D Trainerloc = trainer_ptrs[i]->GetLocation();
                cout<<"T: "<<Trainerloc<<endl;
                Point2D Pokeloc = wildpokemon_ptrs[j]->GetLocation();
                cout<<"P: "<<Pokeloc<<endl;
                if ((Trainerloc.x == Pokeloc.x) && (Pokeloc.y == Trainerloc.y))
                {
                    cout<<"******************follow executed************************"<<endl;
                    wildpokemon_ptrs[j]->follow(trainer_ptrs[i]);
                }

            }
        }
    }*/

    list<bool> update_values;
    list<bool>::iterator upvals_it;

    for(auto active_it = active_ptrs.begin(); active_it != active_ptrs.end(); active_it++)
    {
        update_values.push_back((*active_it)->Update());
    }

    for(auto wildpokemon_it = WildPokemon_ptrs.begin(); wildpokemon_it != WildPokemon_ptrs.end(); wildpokemon_it++)
    {
        for(auto trainer_it  =Trainer_ptrs.begin(); trainer_it != Trainer_ptrs.end(); trainer_it++)
        {
            Point2D Trainerloc = (*trainer_it)->GetLocation();
            Point2D Pokeloc = (*wildpokemon_it)->GetLocation();
            if ((Trainerloc.x == Pokeloc.x) && (Pokeloc.y == Trainerloc.y))
                (*wildpokemon_it)->follow((*trainer_it));
        }
    }

    for(auto gym_it = PokemonGym_ptrs.begin(); gym_it != PokemonGym_ptrs.end(); gym_it++)
    {
        if((*gym_it)->passed() == false)
        {
            break;
        }
        else
        {
            if(PokemonGym_ptrs.end() == next(gym_it, 1))
            {
                cout<<endl<<"GAME OVER: You win! All battles done!"<<endl<<endl;
                for(auto game_object_it = Object_Ptrs.begin(); game_object_it != Object_Ptrs.end(); game_object_it++)
                {
                    delete *game_object_it;
                }
                cout<<"Model Deconstructed"<<endl;
                exit(0);
            }
        }
    }

    for(auto trainer_it = Trainer_ptrs.begin(); trainer_it != Trainer_ptrs.end(); trainer_it++)
    {
        if((*trainer_it)->HasFainted() == false)
        {
            break;
        }
        else
        {
            if(Trainer_ptrs.end() == next(trainer_it, 1))
            {
                cout<<endl<<"GAME OVER: You lose! All of your Trainers' pokemon have fainted!"<<endl<<endl;
                for(auto game_object_it = Object_Ptrs.begin(); game_object_it != Object_Ptrs.end(); game_object_it++)
                {
                    delete *game_object_it;
                }
                cout<<"Model Deconstructed"<<endl;
                exit(0);
            }
        }
    }
return false;
}

//((Trainerloc.x) >= (Pokeloc.x + 2) && Trainerloc.y >= (Pokeloc.y +2)) && ((Trainerloc.x) >= (Pokeloc.x - 2) && Trainerloc.y >= (Pokeloc.y - 2))

void Model::ShowStatus() 
{
    cout<<endl<<"The time is: "<<time<<endl<<endl;
    /*for (int i = 0; i<10; i++)
    {
        if(GetGameObjectPtr(i) == NULL)
        {
            //cout<<"This ptr does not exist: "<<i<<endl;
        }
        else 
        {
            Object_Ptrs[i]->ShowStatus();
        }
    }
    return;*/

    for(auto game_object_it = Object_Ptrs.begin(); game_object_it != Object_Ptrs.end(); game_object_it++)
    {
        (*game_object_it)->ShowStatus();
    }
    return;

}

void Model::Display(View &View)
{
View.Clear();

/*for (int i = 0; i < 10; i++)
{
    if (GetGameObjectPtr(i) != NULL)
    {
        View.Plot(GetGameObjectPtr(i));
    }
}*/

for(auto game_object_it = Object_Ptrs.begin(); game_object_it != Object_Ptrs.end(); game_object_it++)
    {
        if((*game_object_it)->ShouldBeVisible() == true)
        {
            View.Plot(*game_object_it);
        }
    }

View.Draw();
return;
}

void Model::CreateObject(char type, int id, Point2D point)
{
    switch(type)
    {
        case 'c':
        {
            try
            {
                for(auto PokemonCenter_it = PokemonCenter_ptrs.begin(); PokemonCenter_it != PokemonCenter_ptrs.end(); PokemonCenter_it++)
                {
                    if(id == ((*PokemonCenter_it)->GetId())) 
                    {
                        throw Invalid_Input("Center Already Exists");
                    }
                }
                PokemonCenter* P = new PokemonCenter(id, 2 , 200, point);
                PokemonCenter_ptrs.push_back(P);
                Object_Ptrs.push_back(P);
                active_ptrs.push_back(P);
            }
            catch(Invalid_Input& except)
            {
                cout<<"Invalid Input - "<<except.msg_ptr<<endl;
            }
            break;
        }

        case 'g':
        {
            try
            {
                for(auto PokemonGym_it = PokemonGym_ptrs.begin(); PokemonGym_it != PokemonGym_ptrs.end(); PokemonGym_it++)
                {
                    if(id == ((*PokemonGym_it)->GetId())) 
                    {
                        throw Invalid_Input("Gym Already Exists");
                    }
                }
                PokemonGym* G = new PokemonGym(5,5,5,5,id,point);
                PokemonGym_ptrs.push_back(G);
                Object_Ptrs.push_back(G);
                active_ptrs.push_back(G);
            }
            catch(Invalid_Input& except)
            {
                cout<<"Invalid Input - "<<except.msg_ptr<<endl;
            }
            break;
        }

        case 't':
        {
            try
            {
                for(auto Trainer_it = Trainer_ptrs.begin(); Trainer_it != Trainer_ptrs.end(); Trainer_it++)
                {
                    if(id == ((*Trainer_it)->GetId())) 
                    {
                        throw Invalid_Input("Trainer Already Exists");
                    }
                }
                Trainer* P = new Trainer("Trainer",id, 'T' , 2, point);
                Trainer_ptrs.push_back(P);
                Object_Ptrs.push_back(P);
                active_ptrs.push_back(P);
            }
            catch(Invalid_Input& except)
            {
                cout<<"Invalid Input - "<<except.msg_ptr<<endl;
            }
            break;
        }

        case 'p':
        {
            try
            {
                for(auto WildPokemon_it = WildPokemon_ptrs.begin(); WildPokemon_it != WildPokemon_ptrs.end(); WildPokemon_it++)
                {
                    if(id == ((*WildPokemon_it)->GetId())) 
                    {
                        throw Invalid_Input("WildPokemon Already Exists");
                    }
                }
                WildPokemon* P = new WildPokemon("WildPokemon",id,'P',2, point);
                WildPokemon_ptrs.push_back(P);
                Object_Ptrs.push_back(P);
                active_ptrs.push_back(P);
            }
            catch(Invalid_Input& except)
            {
                cout<<"Invalid Input - "<<except.msg_ptr<<endl;
            }
            break;
        }

    }
















}

//Weird issue where my Trainer 1 is 2 and Trainer 2 is 3 same with Gym and center