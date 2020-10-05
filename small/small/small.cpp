// small.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using std::cout;
using std::cin;

#include "Functions.h"

int main()
{
    int a; // To contain interger 
    int b; // To contain interger

    cout << "Hello World!\n";
    cout << "Mars is " << 63.79 << " million km away." << '\n';

    cout << '\n' << '\n';
    int i = 2 + 2;
    i = i * 3;
    cout << i << '\n';

    
    cout << "Enter a number: ";
    cin >> i;
    cout << '\n' << i << '\n';

    cout << "Add two numbers a + b. Enter number a: ";
    cin >> a;
    cout << '\n' << "Enter number b: ";
    cin >> b;

    cout << "a + b is " << add(a, b);

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
