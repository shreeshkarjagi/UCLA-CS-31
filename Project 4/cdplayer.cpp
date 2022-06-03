//
//  main.cpp
//  Project 3
//
//  Created by shreesh karjagi on 1/28/22.
//

#include <iostream>
#include <string>
#include <cassert>
#include <cctype>
using namespace std;
bool isValidCDPlayerString(string cdstring);
bool isOpen(string cdstring);
bool hasCD(string cdstring);
int totalTracksPlayed(string cdstring);
int currentTrack(string cdstring);

int main()
    {
        //isValid False statements
        assert(isValidCDPlayerString("") == false);
        assert(isValidCDPlayerString("xyz") == false );
        assert(isValidCDPlayerString("oic") == false );
        assert(isValidCDPlayerString("OIC xyz") == false );
        assert(isValidCDPlayerString("P123S") == false );
        assert(isValidCDPlayerString("OCIP123S") == false );
        assert(isValidCDPlayerString("OICR") == false );
        assert(isValidCDPlayerString("OCOICC") == false );
        assert(isValidCDPlayerString("OCOICOO") == false );
        assert(isValidCDPlayerString("OIP123") == false );
        assert(isValidCDPlayerString("OICS") == false );
        assert(isValidCDPlayerString("OP123C") == false );
        assert(isValidCDPlayerString("OIR123") == false );
        assert(isValidCDPlayerString("OIR123P") == false );
        assert(isValidCDPlayerString("OC123P") == false );
        //assert(isValidCDPlayerString("OICP147S") == false );
        //assert(isValidCDPlayerString("OICP123SOCP123S") == false );
        //assert(isValidCDPlayerString("OICP123P123456SOR") == false );
        //assert(isValidCDPlayerString("OICS123OC") == false );



        //isValid true statements
        assert(isValidCDPlayerString("OICPO") == true );
        assert(isValidCDPlayerString("OICP123SP456SORICP123") == true );
        assert(isValidCDPlayerString("OIRICP123SOR") == true );
        assert(isValidCDPlayerString("OICP123ORICP123") == true );
        assert(isValidCDPlayerString("OICP123SORICP123456SOR") == true );
        assert(isValidCDPlayerString("OICP123OC") == true );
        assert(isValidCDPlayerString("OICP123OCP") == true );
        assert(isValidCDPlayerString("OICP123OCP456") == true );
        assert(isValidCDPlayerString("OICP123ORS") == true );
        assert(isValidCDPlayerString("OICP123ORCS") == true );
        assert(isValidCDPlayerString("OICP123ORIS") == true );
        assert(isOpen("OICP123ORIS") == true );
        assert(isOpen("OIRICP123SOR") == true );
        assert(isOpen("OICP123ORICP123") == false );
        assert(isOpen("OICPO") == true );
        assert(isOpen("OICP123O") == true );
        assert(isOpen("OICP123OCP456") == false );
        assert(isOpen( "OICP123SORICP123456SOR" ) == true );
        assert(isOpen( "OICPP123SOR" ) == true );
        assert(isOpen( "OICP123OCP" ) == false );
        assert(isOpen( "OCOICO" ) == true );
        assert(isOpen( "OICP123OS" ) == true );
        assert(isOpen( "OICP123ORCS" ) == false );
        assert(isOpen( "OICS" ) == false );
        assert(hasCD( "OCOICC" ) == false );
        assert(hasCD( "OICP123SORICP123456SOR" ) == false );
        assert(hasCD( "OICP1P23SOR" ) == false );
        assert(hasCD( "OICP123O" ) == true );
        assert(hasCD( "OCP123" ) == false );
        assert(totalTracksPlayed( "OICP123SP456SORICP123" ) == 9 );
        assert(totalTracksPlayed( "OIRICP123SOR" ) == 3 );
        assert(totalTracksPlayed( "OICP123ORS" ) == 3 );
        assert(totalTracksPlayed( "OCIP123S" ) == -1 );
        assert(currentTrack( "OICP123SP456SORICP123" ) == 4);
        assert(currentTrack( "OIRICP123SOR" ) == 4 );
        assert(currentTrack( "OICP123ORS" ) == 4 );
        assert(currentTrack( "OCIP123S" ) == -1 );


    
        cout << "All tests succeeded" << endl;
            return( 0 );
    }

bool isValidCDPlayerString(string cdstring)
{
    //return false if string is empty
    if (cdstring =="")
    {
        return (false);
    }
    // 1) if first character is not 'O', return false
    if (cdstring.at(0) != 'O')
    {
        return (false);
    }
    bool isCDopen= true;
    bool isPlaying= false;
    bool hasCD= false;
    // 2) if the string contains a character apart from O, I, R, C, P , S , 1, 2, 3, 4, 5, 6, 7 and 8
    for (int i= 1; i < cdstring.length() ; i++)
    {
        
        if ((cdstring.at(i) !='O') && (cdstring.at(i) !='I') && (cdstring.at(i) !='R') && (cdstring.at(i) !='C') && (cdstring.at(i) !='P') && (cdstring.at(i) !='S') && (cdstring.at(i) !='1') && (cdstring.at(i) !='2') && (cdstring.at(i) !='3') && (cdstring.at(i) !='4') && (cdstring.at(i) !='5') && (cdstring.at(i) !='6') && (cdstring.at(i) !='7') && (cdstring.at(i) !='8') && (cdstring.at(i) !='9')) //contain only the uppercase letters O, I, R, C, P and S as well as digits 1, 2, 3, 4, 5, 6, 7, 8 and 9
        {
            return (false);
        }
        char character= cdstring.at(i);
        char previousCharacter= cdstring.at(i-1);
       // char nextCharacter= cdstring.at(i);
        //can only insert if player is open and the there's no cd
        if(character== 'I')
        {
            if(isCDopen == false || hasCD == true)
            {
                return (false);
            }
            hasCD = true;
        }
        //can only remove cd if player is open and cd is alredy in
        if(character== 'R')
        {
            if(isCDopen== false || hasCD== false)
            {
                return (false);
            }
            hasCD = false;
        }
        // can only close if cd player is open
        if(character== 'C')
        {
            if(isCDopen== false)
            {
                return (false);
            }
            isCDopen= false;
        }
        //can only open if cd player is closed
        if(character== 'O')
        {
            if(isCDopen== true)
            {
                return (false);
            }
            isCDopen= true;
        }
        //can only play if cd player closed and if cd is already in
        if(character== 'P')
        {
            if(isCDopen== true || hasCD== false)
            {
                return (false);
            }
            isPlaying= true;
        }
        // can stop playing if cd is playing from before
        if(character== 'S')
        {
            if(isPlaying== false)
            {
                return (false);
            }
            isPlaying= false;
        }
        //fix error where can only start playing tracks if cd player been playing
        if(character== '1' && previousCharacter != 'P')
        {
            return (false);
        }
        
        
    }
    return (true);
}

bool isOpen(string cdstring)
{
    bool openState = false;
    bool hello = isValidCDPlayerString(cdstring);
    if (hello == false)
        return (false);
    //this function returns true if, at the end of the player string, the cd player has been left open
    else
    
    {
        for (int i= 1; i < cdstring.length() ; i++)
        {
            char character= cdstring.at(i);
            if (character== 'O')
            {
                openState = true;
            }
            if(character== 'C')
            {
                openState = false;
            }
        }
        return (openState);
    }
}
bool hasCD(string cdstring)
{
    bool cdState = false;
    bool hello = isValidCDPlayerString(cdstring);
    if (hello == false)
        return (false);
    else
    
    {
        for (int i= 1; i < cdstring.length() ; i++)
        {
            char character= cdstring.at(i);
            if (character== 'I')
            {
                cdState = true;
            }
            if(character== 'R')
            {
                cdState = false;
            }
        }
        return (cdState);
    }
    
    
}
int totalTracksPlayed(string cdstring)
{
    int trackCounter= 0;
    int hello = isValidCDPlayerString(cdstring);
    if (hello == false)
        return (-1);
    //this function returns the total number of music tracks played by the player string across all the cds that have been played by this cdstring
    else
    {
        for (int i= 1; i < cdstring.length() ; i++)
        {
            char character= cdstring.at(i);
            if (isdigit(character))
            {
                trackCounter++;
            }
        }
    }
    return(trackCounter);
}
int currentTrack(string cdstring)
{
    int nextSongTN= 1;
    int hello = isValidCDPlayerString(cdstring);
    if (hello == false)
    {
        return (-1);
    }
    if (hasCD(cdstring)== false)
    {
        return (-1);
    }
    else
    {
            for (int i= 1; i < cdstring.length() ; i++)
            {
                char character= cdstring.at(i);
                if (isdigit(character))
                {
                    nextSongTN = character - '0';
                }
    }
        return(nextSongTN);
    }
    
    
}

