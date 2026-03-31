// ryan parker Coding 1 Spring 2026
// First C++ program

// To compile, open the Dev Command for VS 2022
// Nav to this folder with 'cd' for 'changed directorty'
// Use the command 'cl/Ehsc fimename.cpp'
// And then type 'filename' to run the .exe

#include <iostream>         // in-out stream for sending text to the console.
#include <string>           // for player name

using namespace std;       // so we don't have to type out "std::" all the time.

// Where program starts running code.
int main() {
    // var at the top is best practice.
    string playerName;              // var uses camelCase
    // ask the player name
    cout << "What is your name, player? ";

    // get input from the player using C in
    cin >> playerName;

    cout << "Hello " << playerName << "." << endl;

    //cout << "Hello World" << endl;      // C out for "Console out"
                                        // end L for "End line"

    return 0;                           // program ran successfully
}