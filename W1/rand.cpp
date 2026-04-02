// Ryan Parker Coding 1 2026
// Switch, random numbers, and while loops.

// Task to create code that says "random numbers!"
// Then run program

#include <iostream>
#include <random>     // for random numbers
#include <ctime>    // for seeding numbers
using namespace std;
int main() {

    srand(time(0));               // seed the random number generator with the current time.

    cout << "Random Numbers!\n\n";

    cout << "\n\nOur first random number is " << rand() << ".\n";

    cout << "\n\nHere are some random numbers:\n\n";

    int counter = 0;
    while (counter++ < 10) {
        cout << (rand() % 10 ) + 1 << endl;
    }

    // the computer picks a random number between 1 and 10 inclusive
    int theNumber = (rand() % 10) + 1;
    // the computer asks the player to guess the number.
    int guess = -1;

    // guess the number game
    do {
            cout << "What is your guess?\n\n";
            // the player guesses
            cin >> guess;
            // the computer will say if it's 
                if (theNumber == guess) {
                    //  "correct" 
                    cout << "\nyou guessed it!\n";
                    return 0;
                }
                else if(guess > theNumber) {
                    //  "too high"
                    cout << "\nthat number is too high!\n";
                }
                else if( guess < theNumber) {
                    //  "too low"
                    cout << "\nthat number is too low!\n";
                }
           // let the player guess again if it was incorrect
        } while (guess != theNumber);


    return 0;
}