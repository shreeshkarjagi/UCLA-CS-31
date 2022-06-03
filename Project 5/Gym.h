//
//  Gym.h
//  Project 5
//
//  Created by shreesh karjagi on 2/25/22.
//

#ifndef Gym_h
#define Gym_h
#include <string>
#include <iostream>
#include "Kind.h"
#include "GymMember.h"


class Gym
{
private:
    std::string mName;
    std::string mLocation;
    Kind mKind;
    bool hasCardio;
    bool hasWeights;
    bool hasPool;
    bool hasTrack;
public:
// Gym constructor
    Gym(std::string name, std::string location, Kind kind);
    void setFeatures(bool cardio, bool weights, bool pool, bool track);
    bool canWorkoutHere(GymMember&m);
    bool checkin(GymMember&m, bool wantsCardio, bool wantsWeights, bool wantsPool, bool wantsTrack);
    bool hasCardioFeatures();
    bool hasWeightsFeatures();
    bool hasPoolFeatures();
    bool hasTrackFeatures();
    Kind getKind();
    std::string getKindAsString();
    std::string getLocation();
    std::string getName();
};
#endif /* Gym_h */
