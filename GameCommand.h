#ifndef GameCommand_h
#define GameCommand_h
#include <iostream>
#include "Model.h"
#include "Point2D.h"

using namespace std;

    void DoMoveCommand(Model&, int, Point2D);
    void DoMoveToCenterCommand(Model&, int, int);
    void DoMoceToGymCommand(Model&, int, int);
    void DoStopCommand(Model&, int);
    void DoBatlleCommand(Model&, int, unsigned int);
    void DoRecoverInCenterCommand(Model&, int, unsigned int);
    void DoAdvanceCommand(Model&, View&);
    void DoRunCommand(Model&, View&);
    void CreateNewObject(Model&, char,int,Point2D);
#endif