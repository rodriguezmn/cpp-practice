// Guess my number game. Users try to guess the secret number.
// No data validation is performed in this program, it is 
// expected that users will enter a interger value between 0 and 9.

#include <iostream>
using std::cout;
using std::cin;

int main()
{
    int answer = 7;             // To store the secret number
    int guess;                  // To store the user guess
    bool notGuessed = true;     // To store number guessed status

    // Instruct the user about the game
    cout << "***GUESS MY NUMBER GAME***" << '\n' << '\n';
    cout << "Guess a secret number between 0 and 9." << '\n';

    // Continue to ask the user for the secret number until they get it right

    while (notGuessed)
    {
        cout << "Type your guess and press enter: ";
        cin >> guess;

        if (guess == answer)
        {
            cout << '\n' << '\n' << "Congratulations! " << guess << " is the secret number.";
            cout << '\n' << '\n';

            notGuessed = false;
        }

        if (guess < answer)
        {
            cout << "Your number is smaller than the secret number." << '\n';
        }

        if (guess > answer)
        {
            cout << "Your number is larger than the secret number." << '\n';
        }
    }
    return 0;
}