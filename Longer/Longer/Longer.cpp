// Asks user to enter two strings and tells them which one is longer

#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::string;

int main()
{
    string firstString;     // To contain first string
    string secondString;    // To contain second string

    cout << "Enter the first string: ";
    cin >> firstString;

    cout << "Enter second string: ";
    cin >> secondString;
    cout << '\n';

    if (firstString.length() == secondString.length())
    {
        cout << "Both strings have the same length." << '\n';
    }
    if (firstString.length() < secondString.length())
    {
        cout << "The first string is shorter than the second one." << '\n';
    }
    if (firstString.length() > secondString.length())
    {
        cout << "The first string is larger than the second one." << '\n';
    }

    return 0;
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
