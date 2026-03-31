// Ryan Parker Coding 1 Spring 2026
// Using VS Codium and it's integrated terminal
// To learn about variables and logic.

#include <iostream>
using namespace std;
int main() {
    // \n or 'backslash n' maeks a new line.
    cout << "All about variables and logic!\n\n\n";

    // 40 minutes

    //Declaring a variable means it exists.
    //Defining a variable means giving it a value.
    int playerAge = -1;             //int whole numbers
    string playerName = ""; //strings are for words and letters
    float playerHeight = 1.8f;       // Hight in meters
    bool playAgain = true;          // true or false statements

    // if statement is a branch in unreal engine.
    if (playerAge == -1) {
        cout << "How old are you?\n\n";
        cin >> playerAge;

        if (playerAge < 13) {
            cout << "\nI'm sorry, this game is too grown up\n";
        }
        if ( 40 >= playerAge && playerAge >= 13) {
            cout << "\nCome on iiiiinnnn!\n";
        }
        if (playerAge > 40) {
            cout << "\nWow that's old!\n";
        }
    }
    if (playerName == "") {
        cout << "\nWhat's your name?\n\n";
        cin >> playerName;

        if (playerName == "Sally") {
            cout << "\nIs your name Sally\n\n(y/n)\n\n";
            string input;
            cin >> input;

            if (input == "y") {
                cout << "\nWell, that's nice!\n\n";
            }
            else {
                cout << "\n\nWhat is your name?\n\n";
                cin >> playerName;
            }

            cout << "Hello " << playerName << ".\n\n";
        }
    }

    // if their name and age mateches the age of the programmer of this program
    // unlock godmode

    bool godMode = false;

    if (playerAge == 20 && playerName == "Parker") {
        cout << "\n\nHello Creator. God mode enabled.\n\n";
        godMode = true;
    }
    if (playAgain) {
        cout << "\n\nLet's play a little game that I made!\n\n";
    }

    return 0;
}