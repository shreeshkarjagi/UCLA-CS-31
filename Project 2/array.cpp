//
//  main.cpp
//  Project 4
//
//  Created by shreesh karjagi on 2/13/22.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <cassert>
using namespace std;

//declaring the functions first

int locateMinimum( const  string  array[ ],  int  n );
int countCommonElements( const string array1[ ], int  n1, const string array2[ ], int n2 );
int countVowels( const string array[ ], int n );
bool hasThreeOfX( const string array[ ], int n, string x );
string majorityElement( const string array[ ], int  n );
bool shiftRight( string array[ ], int n, int amount, string placeholder );
bool rotateLeft( string array[ ], int n, int amount );
int replaceAll( string array[ ], int n, char letterToReplace, char letterToFill );

int locateMinimum( const  string  array[ ],  int  n )
{
    int minimum = 0;
    if(n <= 0)
        return -1; //checks if n is <= to 0 and will return -1
    else
    {
        //returning the index of the smallest item found in the passed array
        for (int i = 0; i < n; ++i) //iterating through the array backwards
        {
            if(array[i] < array[minimum])
                minimum = i;
        }
    }
    return (minimum);
}
int countCommonElements( const string array1[ ], int  n1, const string array2[ ], int n2 )
{
    int countCommon = 0;
    if (n1 <= 0 || n2 <= 0) // not a valid case
        return -1; // checks if n1 or n2 is <= to 0 and will return -1
    else
    {
        for(int i = 0; i < n1; i++)
        {
            for(int j = 0; j < n2; j++) //nested forloop comparing the two arrays
            {
                if(array1[i] == array2[j])
                    countCommon++; //add to the initialized counter
            }
        }
    }
    return (countCommon);
}
int countVowels( const string array[ ], int n )
{
    int vowelCount = 0; //initialized a counter
    if (n <= 0) // not a valid case
        return -1;
    else
    {
        for (int i = 0; i < n; i++) //iterating through the array until n
        {
            for(int j = 0; j < array[i].size(); j++) //nested forloop comparing the i and the j elements in the array (j = i + 1)
            {
                if(toupper(array[i].at(j)) == 'A' || toupper(array[i].at(j)) == 'E' || toupper(array[i].at(j)) == 'I' || toupper(array[i].at(j)) == 'O' || toupper(array[i].at(j)) == 'U' || toupper(array[i].at(j)) == 'Y')
                    vowelCount++; // add to the count
            }
        }
    }
    return (vowelCount);
}
bool hasThreeOfX( const string array[ ], int n, string x )
{
    int count = 0;
    if (n <= 0) // not a valid case
        return false;
    else
    {
        for (int i = 0; i < n; i++) //iterating through the array
        {
            if(array[i] == x) //if I find the string x in the array i add to the count
            {
                count++;
            }
        }
    }
    if(count != 3) // count has to be = 3 or else false
        return false;
    else
        return true;
}

string majorityElement( const string array[ ], int  n )
{
    int count = 0;
    for (int i = 0; i < n; i++)//iterating through every element of the array
    {
        count = 1;
        for(int j = i+1; j < n; j++)// the rest of the array to find identical elements
            if (array[i] == array[j])
                count++;
        if (count > n/2) // from the spec if count > n/2 then we return the majority element
        {
            return array[i];
        }
    }
    return "";
}
bool shiftRight( string array[ ], int n, int amount, string placeholder )
{
    bool result = false;
    if (n <= 0 || amount <= 0) // not a valid case and incooperated amount <= 0 as there will  be no shifts to the right if the amount = 0 and the array will stay the same
    {
        result = false;
        return result;
    }
    else
    {
        for (int i = 0; i < n - 1; ++i) // I cycle through array backwards
        {
            array[n-1-i] = array[n-1-amount-i]; // shifting the element toward the right based on the amount
            if (n-1-amount-i== 0) //make sure i dont walk off the array
                break;
        }
        for (int i = 0; i < amount; ++i) // going through the elemnts of shifted array
        {
            if (i < n)
                array[i] = placeholder; // adding the placeholder to the empty spots
        }
        result = true;
        return result;
    }
}

int gcd(int a, int b)
{
    if (b == 0)
        return a;
 
    else
        return gcd(b, a % b);
}
 
bool rotateLeft( string array[ ], int n, int amount )
{
    amount = amount % n; //if amount is even then we can reduce the number of rotations because when amount = n the array stays the same
    bool result = false;
    string tempArray[amount];
    
    if (n <= 0 || amount <= 0)// not a valid case and incooperated amount <= 0, as amount is the remainder and if remainder is <= 0 no rotation takes place and array stays the same!
    {
        result = false;
        return result;
    }
    
    
    for (int i = 0; i < amount ; ++i) // this is to copy the original array into the temp array
    {
        tempArray[i] = array[i];
    }
    for(int i = 0; i < n - amount; ++i) //shifting to the left based on the amount, and it is n - amount so I don't walk off the array
    {
        array[i] = array[i+amount];
    }
    
    for(int i = 0; i < amount; ++i) // going through the elemnts of temparray
    {
        array[n-amount+i] = tempArray[i]; // setting last element as the first element and therefore completeing the rotation
    }
    result = true;
    return result;
}


// I took inspiration from the code I found online in order to understand the Modulo Operation and I used the while loop as inspiration for the my second for loop in the rotateleft function
/*

 string temp = amount % n;
 int g_c_d = gcd(amount, n);
 for (int i = 0; i < g_c_d; i++)


 string temp = array[i];
 int j = i;

 while (1) {
 int k = j + amount;
 if (k >= n)
 k = k - n;

 if (k == i)
 break;

 array[j] = array[k];
 j = k;
 }
 array[j] = temp;
 }
 }
 */


int replaceAll( string array[ ], int n, char letterToReplace, char letterToFill )
{
    int result = 0;
    if (n <= 0) {
        result = -1;
        return result;
    }
    else {
        for (int i = 0; i < n; i++)
        {
            for (size_t j = 0; j < array[i].size(); j++)
            {
                if (array[i].at(j) == letterToReplace) {
                    array[i].at(j) = letterToFill;
                    result++;
                }
            }
        }
    }
    return result;
}


int main()
{
    string folks[8] = { "samwell", "jon", "margaery", "daenerys", "tyrion", "sansa", "magdalena", "jon" };
    string data[5] = { "mama", "mama", "12", "sansa", "mama" };
    string test[5] = { "ju", "ju", "ju", "sansa", "mama" };
    string tester[7] = {"red", "red", "red", "blue", "blue","green","green"};
    string codeboard[7] = {"ee", "dd", "cc", "bb", "aa", "BB", "AA"};
    string a[6] = { "alpha", "beta", "gamma", "gamma", "beta", "delta" };

    



    
        assert(locateMinimum(folks, 8) == 3);
        assert(locateMinimum(folks, 5) == 3);
        assert(locateMinimum(a, 3) == 0);
        assert(countCommonElements(folks, 8, data, 5) == 1);
        assert(countCommonElements(folks, 3, data, 3) == 0);
        assert(countVowels(data, 5) == 8);
        assert(countVowels(folks, 8) == 21);
        assert(hasThreeOfX(data, 5, "mama") == true);
        assert(hasThreeOfX(folks, 8, "jon") == false);
        assert(hasThreeOfX(test, 5, "ju") == true);
        assert(majorityElement(data, 5) == "mama");
        assert(majorityElement(folks, 8) == "");
        assert(majorityElement(test, 5) == "ju");
        assert(shiftRight(data, 5, 2,"foo") == true);
        assert(shiftRight(data, -5, 10, "foobar") == false);
        assert(shiftRight(data, 5, 10, "bar") == true);
        assert(rotateLeft(folks, 8, 1) == true);
        assert(rotateLeft(folks, 8, 2) == true);
        assert(rotateLeft(test, 5, 2) == true);
        assert(rotateLeft(folks, 2, 12) == false);
        assert(shiftRight(codeboard , 1, 0, "foo" ) == false);
        assert(replaceAll(folks, 8, 'A', 'Z') == 0);
    
    
    
    //    cout<< majorityElement(tester,7)<< endl;
    cout << "-" << std::endl;
    cout << "All tests succeeded" << std::endl;
    return(0);
}


