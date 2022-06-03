//
//  main.cpp
//  project 2
//
//  Created by shreesh karjagi on 1/19/22.
//

#include <iostream>
#include <string>//to use the string library
using namespace std;

int main()
{
    // declaring the variables at the top
    string plan;
    string autoPay;
    string paperlessBilling;
    int lines= 0;
    int gigaBytes= 0;
    double price= 0;
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2); // as the project spec demands that the format of the price be $ ___.00
    
    cout<< "What type of cell plan do you have? ";
    getline(cin,plan); // used getline since the input can contain white spaces such as 'Unlimited Extra'
    
    if(!(plan == "Unlimited Elite" || plan == "Unlimited Extra" || plan == "Unlimited Starter" || plan == "Prepaid")) //if not equal to these specific inputs then error statement
    {
        cout << "Your cell plan is not valid!";
        return -1;
    }
    
    cout << "Are you on autopay? ";
    cin >> autoPay;
    
    if(!(autoPay == "Yes" || autoPay == "No"))
    {
        cout << "Your autopay is not valid!";
    }
    
    cout << "Are you on paperless billing? ";
    cin >> paperlessBilling;
    
    if(!(paperlessBilling == "Yes" || paperlessBilling == "No"))
    {
        cout << "Your paperless billing is not valid!";
        return -1;
    }
    
    cout << "How many lines will be on your plan? ";
    cin >> lines;
    
    if(!( lines == 1 || lines == 2 || lines == 3))
    {
        cout <<"Your lines are not valid!";
        return -1;
    }
    cout << "How many gigabytes did you consume this month? ";
    cin >> gigaBytes;
    
    if(!(gigaBytes >=0 && gigaBytes<= 30))
    {
        cout<< "Your gigabytes are not valid!";
    }

//if statements calculating price
    // plan calculations
    if (plan == "Unlimited Elite")
        price = 85*lines;
    if (plan == "Unlimited Extra")
        price = 75*lines;
    if (plan == "Unlimited Starter")
        price = 65*lines;
    if (plan == "Prepaid")
        price = 50*lines;
    
    //discount for autopay
    if (autoPay == "Yes")
        price -= (2*lines);
    else if (autoPay == "No")
    {
    //does nothing
    }
    
    //discount for paperless billing
    if (paperlessBilling == "Yes")
        price -= (3*lines);
    else if (paperlessBilling == "No")
    {
    //does nothing
    }

    // discount for lines
    if (lines == 1)
        price -= 0;
    if (lines == 2)
        price -= 20;
    if (lines == 3)
        price -= 30;
    
    //data usage charge calculations
    
    if (plan == "Prepaid" && gigaBytes >4)
        price += 10* ((gigaBytes-4)/2);
    
    cout << "Your " << plan << " cell plan costs $" << price << "."; // final output statement that gets printed only if the user inputs everything correctly
    return(0);
}





