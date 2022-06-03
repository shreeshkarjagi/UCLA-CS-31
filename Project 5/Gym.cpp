//
//  Gym.cpp
//  Project 5
//
//  Created by shreesh karjagi on 2/25/22.
//

#include "Gym.h" // <- includinng the header file
#include "GymMember.h"
#include "Kind.h"
#include <iostream>
#include <string>
using namespace std;

// constructor function
Gym::Gym(string name, string location, Kind kind) //nonstatic member function calls pointer?
{
    mName = name;
    mLocation = location;
    mKind = kind;
    hasCardio = false;
    hasWeights = false;
    hasPool = false;
    hasTrack = false;
}
void Gym::setFeatures(bool cardio, bool weights, bool pool, bool track) //setting them outside the constructor
{
    hasCardio = cardio;
    hasWeights = weights;
    hasPool = pool;
    hasTrack = track;
}

bool Gym::canWorkoutHere(GymMember&m)
{
    bool result = false;
    if (m.getKind() == OTHER)
    {
        if(mKind == OTHER)
            result = true;
    }
    else if (m.getKind() == REGULAR)
    {
        if(mKind == REGULAR)
            result = true;

    }
    else if (m.getKind() == PREMIER)
    {
        if(mKind == REGULAR || mKind == PREMIER)
            result = true;
    }
    else
    {
        if(mKind == REGULAR || mKind == PREMIER || mKind == EXECUTIVE)
            result = true;
    }
    return result;
}
bool Gym::checkin(GymMember&m, bool wantsCardio, bool wantsWeights, bool wantsPool, bool wantsTrack)
{
    bool result = true;
    if (canWorkoutHere(m) == false) // If you can't workout at the gym, then you cannot checkin at the gym 
    {
        result = false;
    }
    else if (wantsCardio == true && hasCardio == false)
    {
        result = false;
    }
    else if (wantsWeights == true && hasWeights == false)
    {
        result = false;
    }
    else if (wantsPool == true && hasPool == false)
    {
        result = false;
    }
    else
    {
        if(wantsTrack == true && hasTrack == false)
        {
            result = false;
        }
        else m.newWorkout();
    }
    
    return result;
    
}

bool Gym::hasCardioFeatures()
{
    return hasCardio;
}
bool Gym::hasWeightsFeatures()
{
    return hasWeights;
}
bool Gym::hasPoolFeatures()
{
    return hasPool;
}
bool Gym::hasTrackFeatures()
{
    return hasTrack;
}
Kind Gym::getKind()
{
    return mKind;
}
string Gym::getKindAsString() //can i copy from gym memb?
{
    string result;
    switch(mKind) //defines the enum appropriately as string
    {
        case OTHER:
            result = "OTHER";
            break;
        case REGULAR:
            result = "REGULAR";
            break;
        case PREMIER:
            result = "PREMIER";
            break;
        case EXECUTIVE:
            result = "EXECUTIVE";
            break;
    }
    return result;
}
string Gym::getLocation()
{
    return mLocation;
}
string Gym::getName()
{
    return mName;

}




