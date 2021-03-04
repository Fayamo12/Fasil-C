// Login-System-Semester-Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Fasil Tafesse
// Data Structures Spring, 2021
// Due 3/3/2021
// Semester Project


#include<iostream>
using namespace std;

int main()
{

    char username[10]; // character array for username
    char password[10]; //Character array for Password
    
    
    cout << "Set username" << endl;
    cout << "1. No space Should be there." << endl;
    cout << "2. Should not be more than 10 letters." << endl;
    cout << "3. Should not contain any special characters." << endl;

    //set username input
    for (int i = 0;i < 10;i++)
    {
        cin >> username[i];
       
        if (isspace(username[i]))
        {
            break;
        }
    }
    cout << "Set Password" << endl;
    cout << "1. Must contain integer." << endl;
    cout << "2. Must contain character." << endl;
    cout << "3. Must contain special character (#, !, $)." << endl;
    cout << "4. Must not contain repeated characters." << endl;
    cout << "4. Should be 10 letters." << endl;

}