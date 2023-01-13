#include "GameObject.h"
#ifndef Building_h
#define Building_h

using namespace std;

class Building: public GameObject
{
    private:
        unsigned int trainer_count=0;

    public:
        Building();
        Building(char, int, Point2D);

        void AddOneTrainer();
        void RemoveOneTrainer();
        void ShowStatus();
        bool ShouldBeVisible();
};
#endif