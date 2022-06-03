//
//  GymMember.cpp
//  Project 5
//
//  Created by shreesh karjagi on 2/24/22.
//

#include "GymMember.h" // <- includinng the header file
#include "Kind.h"
#include <iostream>
#include <string> // because we make use of strings
using namespace std;

// constructor function
GymMember::GymMember(string name, string accountnumber, Kind kind) //nonstatic member function calls pointer?
{
    this->mName = name;
    this->mAccountNumber = accountnumber;
    this->mKind = kind;
    this->mWorkoutCount = 0; //defined in GymMember.h
}

//mutators
void GymMember::startNewMonth() // reset the workout count back to zero, corresponding to starting a new month to track
{
    mWorkoutCount = 0;
}
void GymMember::newWorkout() // increment the workout count
{
    mWorkoutCount++;
}

//accesor functions
Kind GymMember::getKind()
{
    return mKind;
}

string GymMember::getKindAsString()
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
string GymMember::getName()
{
    return mName;
}
string GymMember::getAccountNumber()
{
    return mAccountNumber;
}
int GymMember::workoutsThisMonth() // accessor operation for workoutcount
{
    return mWorkoutCount;
}
