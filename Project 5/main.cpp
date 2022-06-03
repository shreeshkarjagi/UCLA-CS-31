//
//  main.cpp
//  Project 5
//
//  Created by shreesh karjagi on 2/24/22.
//

#include <iostream>
#include <string>
#include <cassert>

#include "Kind.h"
#include "Gym.h"
#include "GymMember.h"

using namespace std;


int main()
{
        // sample test code
        Gym gym( "SportsClub", "1800 Sepulveda Boulevard", PREMIER);
        gym.setFeatures(true, false, true, false );
        GymMember me( "Howard", "123456", EXECUTIVE );
        assert( me.workoutsThisMonth() == 0 );
        me.startNewMonth();
        me.newWorkout();
        assert( me.workoutsThisMonth() == 1 );
        if (gym.canWorkoutHere( me ))
        gym.checkin( me, true, false, true, false );
        assert( me.workoutsThisMonth() == 2 );
        Gym regu( "ReguGym", "San Diego", REGULAR );
        GymMember regular( "Someone Else", "22222", REGULAR );
        assert( regu.checkin( regular, false, false, false, false ) == true );
        GymMember premier( "Me", "11111", PREMIER );
        premier.startNewMonth();
        Gym porl( "ReguGym", "San Diego", REGULAR );
        porl.setFeatures( true, true, true, true );
        assert( regu.checkin( premier, false, false, true, false ) == true );
        assert( premier.workoutsThisMonth( ) == 1 );
        cout << "all tests passed!" << endl;
        return( 0 );
    }
