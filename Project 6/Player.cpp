//
//  Player.cpp
//  Bunco
//
//  Created by Howard Stahl on 1/27/17.
//  Copyright © 2017 Howard Stahl. All rights reserved.
//

#include "Player.h"



namespace cs31
{
Player::Player() : mDie( 6 ), mScore( 0 ), mRound( 0 )
{
    
}

//  increase the score if the amount matches this round's value
int Player::roll( )
{
    int rolledValue = 0;
    //Rolling the die
    mDie.roll( );
   //Setting value for current round
    rolledValue = mDie.getValue();
    if (mRound == rolledValue)
    {
        mScore++;
    }
    return rolledValue;
}

// TODO: allow for cheating
// use the amount argument as this Player's roll
// adjust the score for the current round accordingly
// increase the score if the amount matches this round's value
int Player::roll( int amount ) // <-- help :(
{
    //set value of dice
    mDie.setValue(amount);
    if (mRound == amount)
    {
        mScore++;
    }
    return amount;
}

void Player::setRound( int round )
{
    mRound = round;
    mScore = 0;
}

int  Player::getScore( ) const
{
    return mScore;
}
}
