// Flow.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using std::cout;
using std::cin;

int main()
{
    int firstNumber;
    int secondNumber;
    bool keepGoing = true;
    int answer;

    // Compare numbers until the user wants to stop

    while (keepGoing)
    {

        // Ask the user for two numbers
        // Compare the numbers 
        // Output result 

        cout << "Enter the first number: ";
        cin >> firstNumber;
        cout << "You entered: " << firstNumber << '\n';
        cout << "Enter the second number: ";
        cin >> secondNumber;
        cout << "You entered: " << secondNumber << '\n';


        if (firstNumber < secondNumber)
        {
            cout << "The first number is smaller than the second number" << '\n';
        }
        else if (firstNumber > secondNumber)
        {
            cout << "The first number is larger than the second number" << '\n';
        }
        else
            cout << "The numbers are equal" << '\n';

        cout << '\n' << "Do you want to compare another pair? : " << "0 means no, any other number means yes: ";
        cin >> answer;
        if (answer == 0)
        {
            keepGoing = false;
        }
    }
}

