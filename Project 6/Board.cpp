//
//  Board.cpp
//  Bunco
//
//  Created by Howard Stahl on 1/27/17.
//  Copyright © 2017 Howard Stahl. All rights reserved.
//

#include "Board.h"


namespace cs31
{
Board::Board() : mRound( 0 )
{
    // initialize each BoardRow
    for (int i = 1; i <= 6; i++)
    {
        mBoardRow[ i ].setRound( i );
    }
}

void Board::setCurrentRound( int round )
{
    // unset the current board row
    if (mRound >= 0 && mRound <= 6)
        mBoardRow[ mRound ].setCurrentRound( false );
    mRound = round;
    // set the current board row
    if (mRound >=0 && mRound <=6)
        mBoardRow[ mRound ].setCurrentRound(true);
}

void Board::markHumanAsWinner()
{
    mBoardRow[mRound].setHumanAsWinner();
}

void Board::markComputerAsWinner()
{
    mBoardRow[mRound].setComputerAsWinner();
}

// stringify the Board
std::string Board::display( ) const
{
    std::string s = "\t\t  Bunco Game\n\tHuman\t\t\tComputer\n";
    
    for( int i = 1; i <= 6; i++)
    {
        s += mBoardRow[ i ].display() + "\n";
    }
    
    return( s );
}

int Board::countUpHumanRoundWins( ) const
{
    int count = 0;
    for (int i = 1; i < 7; i++)
    {
        if (mBoardRow[i].didHumanWin())
            count++;
    }
    return count;
}

int Board::countUpComputerRoundWins( ) const
{
    int count = 0;
    for (int i = 1; i < 7; i++)
    {
        if (mBoardRow[i].didComputerWin())
            count++;
    }
    return count;
}
}
