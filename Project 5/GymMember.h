//
//  GymMember.h
//  Project 5
//
//  Created by shreesh karjagi on 2/20/22.
//
#ifndef GymMember_h
#define GymMember_h
#include <string>
#include <iostream>
#include "Kind.h"

class GymMember
{
private:
    std::string mName;
    std::string mAccountNumber;
    Kind mKind;
    int mWorkoutCount;
public:
// GymMember constructor
    GymMember(std::string name, std::string accountnumber, Kind kind);
    int workoutsThisMonth();
    void startNewMonth();
    void newWorkout();
    Kind getKind();
    std::string getKindAsString();
    std::string getName();
    std::string getAccountNumber();
};
#endif /* GymMember_h */
