#include "Trainer.h"
#include "Point2D.h"
#include <string>
#include <math.h>
#include <cstdlib>
using namespace std;

Trainer::Trainer(): GameObject('T')
{
    state=STOPPED;
    name="Trainer";
    speed=5.0;
    cout<<"Trainer Default Constructed"<<endl;
}
Trainer::Trainer(char in_code): GameObject(in_code)
{
    name="Trainer";
    speed=5.0;
    state = STOPPED;
    display_code=in_code;
}
Trainer::Trainer(string in_name, int in_id, char in_code, unsigned int in_speed, Point2D in_loc)
:GameObject(in_loc, in_id, in_code)//need to include string in first spot of trainer constructor 
{
    name = in_name;
    display_code=in_code;
    id_num=in_id;
    speed=in_speed;
    cout<<"Trainer constructed"<<endl;
}

void Trainer::ShowStatus() //function essientally only returns info to the user do not do much other than that
{
    cout<<"("<<name<<") status:"<<endl; //shows status of trainer then calls the gameobject function to show additional status
    GameObject::ShowStatus();
    cout<<"Health: "<<health<<endl;
    cout<<"PokeDollars: "<<PokeDollars<<endl;
    cout<<"Experience: "<<experience<<endl;

    if(state == STOPPED)
    {
        cout<<"stopped"<<endl<<endl;
        return;
    }
    else if(state == MOVING)
    {
        cout<<"moving at a speed of ("<<speed<<") to destination <"<<destination.x<<","<<destination.y;
        cout<<"> at each step of "<<delta<<endl<<endl;
        return;
    }
    else if(state == MOVING_TO_GYM)
    {
        cout<<"heading to PokemonGym ("<<current_gym->GetId()<<") at a speed of ("<<speed<<") at each step of "<<delta<<endl<<endl;
        return;
    }
    else if(state == MOVING_TO_CENTER)
    {
        cout<<"heading to Pokemon Center ("<<current_center->GetId()<<") at a speed of ("<<speed;
        cout<<") at each step of "<<delta<<endl<<endl;
    }
    else if(state == IN_GYM)
    {
        cout<<"inside PokemonGym ("<<current_gym->GetId()<<")"<<endl<<endl;
    }
    else if(state == AT_CENTER)
    {
        cout<<"inside PokemonCenter ("<<current_center->GetId()<<")"<<endl<<endl;
    }
    else if(state == BATTLING_IN_GYM)
    {
        cout<<"battling in PokemonGym ("<<current_gym->GetId()<<")"<<endl<<endl;
    }
    else if(state == RECOVERING_HEALTH)
    {
        cout<<"recovering health in PokemonCenter ("<<current_center->GetId()<<")"<<endl<<endl;
    }
    else if(state == FAINTED)
    {
        cout<<"FAINTED"<<endl<<endl;
    }

}

void Trainer::StartMoving(Point2D dest)
{
    SetupDestination(dest);
    if(HasFainted()==true) //check to see if fainted if true will not move
        {
            cout<<"("<<display_code<<")("<<id_num<<"): My Pokemon have fainted. I may move but you cannot see me."<<endl;
            return;
        }

    if (state == AT_CENTER) //this checks to see if the trainer is already in a center/gym and then removes them from the gym before moving to the next center/gym
    {
        current_center->RemoveOneTrainer();
    }
    else if (state == IN_GYM) //same deal
    {
        current_gym->RemoveOneTrainer();
    }

    state = MOVING;
    Point2D Currloc=GetLocation();
    if((dest.x==Currloc.x)&&(dest.y==Currloc.y)) //checks the xy position of desired location to the current location if they match then they will not move
        {
           cout<<"("<<display_code<<")("<<id_num<<"): I'm already there. See?"<<endl;
           return;
        }
    else
    {
        cout<<"("<<display_code<<")("<<id_num<<"): On my way."<<endl;
        if ((Update()==false) && (HasFainted() == false));
            if (HasFainted() == true) //if they ever faint while moving it will call update and then stop them from continuing to move
            {
                state = FAINTED;
                Update();
            }
        //state = STOPPED;
        //cout<<"** updated location bc of movement **"<<endl;
        //Update();
        return;
    }
}
void Trainer::StartMovingToGym(PokemonGym* gym) //function is essentiall the same as the previous two just for the case of the pokemon gyms
{
    SetupDestination((gym->GetLocation()));
    if(HasFainted()==true)
        {
            cout<<"("<<display_code<<")("<<id_num<<"): My Pokemon have fainted so I should have gone to the center."<<endl;
            return;
        }

    if (state == AT_CENTER) //this checks to see if the trainer is already in a center/gym and then removes them from the gym before moving to the next center/gym
    {
        current_center->RemoveOneTrainer();
    }
    else if (state == IN_GYM)
    {
        current_gym->RemoveOneTrainer();
    }

    Point2D Currloc=GetLocation();
    Point2D Gymloc = gym->GetLocation();
    
    if((Gymloc.x == Currloc.x) && (Gymloc.y == Currloc.y)) 
        {
            current_gym->AddOneTrainer(); //if the trainer is at the same gym it readds them to the gym before update is called
            cout<<"("<<display_code<<")("<<id_num<<"): I'm already at the PokemonGym!"<<endl;
            state = IN_GYM;
            current_gym = gym;
            return;
        }
    else
        {
            state = MOVING_TO_GYM;
            cout<<"("<<display_code<<")("<<id_num<<"): On my way to Gym (";
            cout<<gym->GetId()<<")"<<endl;

        if ((Update()==false) && (HasFainted() == false));
            if (HasFainted() == true)
            {
                state = FAINTED;
                Update();
            }
            //state = IN_GYM;
            current_gym = gym;
            //Update();
            return;
        }
}
void Trainer::StartMovingToCenter(PokemonCenter* center) //same deal as previous two functions
{
    SetupDestination(center->GetLocation());
    if(HasFainted()==true)
        {
            cout<<"("<<display_code<<")("<<id_num<<"): My Pokemon have fainted so I should have gone to the center."<<endl;
            return;
        }

    if (state == AT_CENTER) //this checks to see if the trainer is already in a center/gym and then removes them from the gym before moving to the next center/gym
    {
        current_center->RemoveOneTrainer();
    }
    else if (state == IN_GYM)
    {
        current_gym->RemoveOneTrainer();
    }
    Point2D Currloc=GetLocation();
    Point2D Centerloc = center->GetLocation();

    if((Centerloc.x == Currloc.x) && (Centerloc.y == Currloc.y)) //works but wonky
        {
            current_center->AddOneTrainer();
            cout<<"("<<display_code<<")("<<id_num<<"): I'm already at the PokemonCenter!"<<endl;
            state = AT_CENTER;
            current_center = center;
            return;
        }
    else
        {
            state = MOVING_TO_CENTER;
            cout<<"("<<display_code<<")("<<id_num<<"): On my way to Center (";
            cout<<center->GetId()<<")"<<endl;

        if ((Update()==false) && (HasFainted() == false));
            if (HasFainted() == true)
            {
                state = FAINTED;
                Update();
            }
            //state == AT_CENTER;
            current_center = center;
            //Update();
            return;
        }
}
void Trainer::StartBattling(unsigned int num_battles) //starts by intializing variables corresponding to info needed to be passed/compared to
{

    double cost = current_gym->GetPokeDollarCost(num_battles);
    int stat = current_gym->GetState();
    Point2D Currloc = GetLocation();
    Point2D Gymloc = current_gym->GetLocation();
    if (HasFainted()==true) // if fainted they cannot battle
        {
            cout<<"("<<display_code<<")("<<id_num<<"): My Pokemon have fainted so no more battles for me..."<<endl;
            return;
        }
    else if (state != IN_GYM) // if not in the gym they cannot battle
        {
            cout<<"("<<display_code<<")("<<id_num<<"): I can only battle in a PokemonGym!"<<endl;
            return;
        }
    else if (PokeDollars<cost) // if they do not have enough money they cannot battle
        {
            cout<<"("<<display_code<<")("<<id_num<<"): Not enough money for battles"<<endl;
            return;
        }
    else if (current_gym->GetNumBattlesRemaining() <= 0) //if there are no more battles you cannot battle
        {
            cout<<"Num bats remaining: "<<current_gym->GetNumBattlesRemaining()<<endl;
            cout<<"("<<display_code<<")("<<id_num<<"): Cannot battle! This PokemonGym has no more trainers to battle!"<<endl;
            return;
        }
    else if (current_gym->IsAbleToBattle(num_battles, PokeDollars, health) == false)
    {
         cout<<"("<<display_code<<")("<<id_num<<"): You do not have enough money or health"<<endl;
         return;
    }
    else if (current_gym->IsAbleToBattle(num_battles, PokeDollars, health) == true) 
        {
            state = BATTLING_IN_GYM; //sets state to battling important for the update call
            if (num_battles > current_gym->GetNumBattlesRemaining())
                battles_to_buy = (current_gym->GetNumBattlesRemaining()); //compare the number of battles remaing to max battles returned number is how many battles you can fight
            else
                battles_to_buy = num_battles;

            current_gym->TrainPokemon(num_battles);

            cout<<"("<<display_code<<"): Started to battle at the PokemonGym ("<<current_gym->GetId()<<") with ("<<battles_to_buy<<") battles"<<endl; 
            //current_gym->TrainPokemon(num_battles);
            //battles_to_buy = num_battles;
            Update();
            return;
        }       
}

void Trainer::StartRecoveringHealth(unsigned int num_potions) //function is very similar to the previous one
{
    //Point2D Currloc = GetLocation();
    //Point2D Centerloc = current_center->GetLocation();
    if (state != AT_CENTER) //if not at the center they cannot purchase potions
    {
        cout<<"("<<display_code<<")("<<id_num<<"): I can only recover health at a Pokemon Center!"<<endl;
        return;
    }
    else if ((current_center->CanAffordPotion(num_potions, PokeDollars)) == false) // if not enough money they cant buy potions
    {
        cout<<"("<<display_code<<")("<<id_num<<"): Not enough money to recover health."<<endl;;
        return;
    }
    else if ((current_center->HasPotions()) == false) // if the center is out of potions they cant buy any
    {
        cout<<"("<<display_code<<")("<<id_num<<"): Cannot recover! No potion remaining in this Pokemon Center"<<endl;
        return;
    }
    else if (state == AT_CENTER)
    {
        state = RECOVERING_HEALTH;
        potions_to_buy = current_center->DistributePotion(num_potions);
        cout<<"("<<display_code<<")("<<id_num<<"): Started recovering ("<<potions_to_buy<<") ";
        cout<<"potions at Pokemon Center ("<<current_center->GetId()<<")"<<endl;
        Update();
        //unsigned int potions_recieved = current_center->DistributePotion(num_potions);
        return;
    }
} 

void Trainer::Stop() //stops play when commanded
{
    state = STOPPED;
    cout<<"("<<display_code<<")("<<id_num<<"): Stopping.."<<endl;
    Update();
}

bool Trainer::HasFainted() //checks to see if health is zero and returns true accordingly
{
    if (health <= 0)
        return true;
    else 
        return false;
}

bool Trainer::ShouldBeVisible()
{
    if(state == FAINTED)
        return false;
    return true;
}

bool Trainer::Update() // checks the state of the trainer and depending on the state outcomes will differ
{
    if (HasFainted() == true)
    {
        state = FAINTED; //returns fainted and tells the program to stop taking moves from trainer
    }
    if(state == STOPPED) //stops the current action
    {
        /*cout<<"Health -1: "<<health<<endl;
        cout<<"PokeDollars: "<<PokeDollars<<endl;
        cout<<"Experience: "<<experience<<endl;*/
        return false;
    }

    else if(state == MOVING) //REMOVED AN ELSE THAT CALLED UPDATELOCATION() UNSURE IF I NEED THIS REMEMBER THIS!!!!
    {
        health = health - 1; //as the player moves one movement space they lose one health
        PokeDollars = PokeDollars + GetRandomAmountOfPokeDollars(); //they also gain some money
        if (UpdateLocation() == true) //if they arrive at their destination they stop
        {
            cout<<"Health: "<<health<<endl;
            cout<<"PokeDollars: "<<PokeDollars<<endl;
            cout<<"Experience: "<<experience<<endl;
            state = STOPPED;
            return true;
        }
        //cout<<"** Test Update location was called **"<<endl;
        //UpdateLocation();
        //return false;
    }

    else if(state == MOVING_TO_CENTER)
    {
        health = health - 1;
        PokeDollars = PokeDollars + GetRandomAmountOfPokeDollars();
        if (UpdateLocation()==true) //if they arrive they are at the center
        {
            cout<<"Health: "<<health<<endl;
            cout<<"PokeDollars: "<<PokeDollars<<endl;
            cout<<"Experience: "<<experience<<endl;
            state = AT_CENTER;
            return true;
        }
    }

    else if(state == MOVING_TO_GYM)
    {
        health = health - 1;
        PokeDollars = PokeDollars + GetRandomAmountOfPokeDollars();
        if (UpdateLocation()==true) // if they arrive they are at the gym
        {
            cout<<"Health: "<<health<<endl;
            cout<<"PokeDollars: "<<PokeDollars<<endl;
            cout<<"Experience: "<<experience<<endl;
            state = IN_GYM;
            return true;
        }
    }

    else if(state == IN_GYM) //displays trainer's condition
    {
        //cout<<"** this should add one trainer **"<<endl;
        //current_gym->AddOneTrainer();
        cout<<"Health: "<<health<<endl;
        cout<<"PokeDollars: "<<PokeDollars<<endl;
        cout<<"Experience: "<<experience<<endl;
        return false;
    }
    else if(state == AT_CENTER) //displays trainer's condition
    {
        //current_center->AddOneTrainer();
        cout<<"Health: "<<health<<endl;
        cout<<"PokeDollars: "<<PokeDollars<<endl;
        cout<<"Experience: "<<experience<<endl;
        return false;
    }
    else if(state == BATTLING_IN_GYM)
    {
        if (current_gym->GetHealthCost(battles_to_buy) >= health) //check to see if the health cost is greater than health if so it sets battlestobuy equal to the health / the health cost per battle
        {
            battles_to_buy = current_gym->GetHealthCost(health) / current_gym->GetHealthCost(1);
            health = 0;
        }
        else
        {
            health = health - current_gym->GetHealthCost(battles_to_buy); //reduces the trainer health to the health cost multiplied by number of battles
        }

        PokeDollars = PokeDollars - current_gym->GetPokeDollarCost(battles_to_buy);
        //experience = experience + current_gym->TrainPokemon(battles_to_buy);
        cout<<"** ("<<name<<") completed ("<<battles_to_buy<<") battle(s)! **"<<endl;
        cout<<"** ("<<name<<") gained ("<<((current_gym->GetExperiencePerBattle())*battles_to_buy)<<") experience! **"<<endl;
        //experience = experience + current_gym->GetExperiencePerBattle();
        state = IN_GYM;
        experience = experience + current_gym->GetExperiencePerBattle() * battles_to_buy;

    }
    else if(state == RECOVERING_HEALTH)
    {
        //unsigned int current_potions=(current_center->DistributePotion(potions_to_buy));
        unsigned int health_recovered = 5*potions_to_buy; //recovers trainers health
        health = health + health_recovered;
        PokeDollars = PokeDollars  - (current_center->GetPokeDollarCost(potions_to_buy));
        cout<<"** ("<<name<<") recovered ("<<health_recovered<<") health! **"<<endl;
        cout<<"** ("<<name<<") bought ("<<potions_to_buy<<") potion(s)! **"<<endl;
        state = AT_CENTER;

    }
    else if (state == FAINTED)
    {
        cout<<"("<<name<<") is out of health and can't move"<<endl;
        return false;
    }
    return false;
}

bool Trainer::UpdateLocation()
{
    if((fabs(destination.x-location.x) <= fabs(delta.x)) && (fabs(destination.y-location.y) <= fabs(delta.y))) //checks to see if they are within one step and then brings them to the location
    {
        //cout<<"dest-loc: "<<(destination.x-location.x)<<endl;
        location = destination;
        cout<<"Final step taken: arrived"<<endl;
        if (state == MOVING_TO_GYM)
            current_gym->AddOneTrainer(); //adds a trainer to respective building
        if (state == MOVING_TO_CENTER)
            current_center->AddOneTrainer();
        state = STOPPED;
        return true;
    }
    else //if not they move a spacde
    {
        //cout<<"dest-loc: "<<(destination.x-location.x)<<endl;
        location = location + delta;
        cout<<"Step taken"<<endl;
        return false;
    }
}

void Trainer::SetupDestination(Point2D dest) //setups the coords of the destination and the delta value of each of their strides
{
    destination=dest;
    location = GetLocation();
    delta = (destination - location)*(speed/GetDistanceBetween(destination,location));
    //state == MOVING;
    return;
}
double GetRandomAmountOfPokeDollars()
{
    srand((unsigned) time(0));
    double random = (rand() / (double) RAND_MAX)*2.0;
    random = (int)(random/.01+.5)*.01;
    return random;
}

string Trainer::GetName() //returns trainer name
{
    return name;
}

Trainer::~Trainer()
{
    cout<<"Trainer destructed"<<endl;
}

double Trainer::GetHealth()
{
    return health;
}

//note my ide was acting weird with strings it works on my own computer but unsure if it will work on lab computers i apologize in advance if this causes issues