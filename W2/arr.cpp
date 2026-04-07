// Ryan Parker Coding 1 Spring 2026
// Arrays, Loops, and Vectors

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int main () {
    srand(time(0));

    cout << "Let's learn about using arrays!\n"; 

    // Arrays in C++ have a defined size.
    // Arrays don't have a way to count how many things are in them.

    cout << "\nCreating an array of cards.\n";

    // Declaring a new int array with a size of five
    int cardCount[5];

    cardCount[0] = 2;   // The first starts at 0
    cardCount[1] = 5;
    cardCount[2] = 8;
    cardCount[3] = 6;
    cardCount[4] = 10;  // The last ends at 4

    cout << "\nThe first card is " << cardCount[0] << ".\n";

    cout << "\nHere are all of the cards:\n";

    int index = 0;
    while (index < 5) {
        cout << cardCount[index]  << "\n";
        index++;
    }

    cout << "\nLet's learn about for loops!\n";

    // for initialization test; action
    // for create the variable; how long do we loop for; how are we counting 
    for(int i = 0; i < 5; i++) {
        cout << i + 1 << ". " << cardCount[i] << "\n";
    }

    // Make a List of Names, let user choose what too add
    // Create the String array
    string names[10];
    // Create input String var
    string input;

    index = 0;
    // Start while loop or do while
    while(index < 10) {


    // Ask the player for a name or to type 'done'
    cout << "\nWhat name would you like to add? Or type 'done' to stop.\n";
    cin >> input;

    if(input == "done") {
        cout << "\nWe are done entering names.\n";
        break;
    }
    // Add names
    names[index++] = input;
    // Display the list of names
    }
    
    for(int i = 0; i < index; i++) {
        if(names[i] == "") {
            continue;
        }
        cout << i + 1 << ". " << names[i] << "\n";
    }

    string name = names[rand() % index];
    // Pick a random name and save it
    cout << "\nPick a random name! " << name << ".\n";

    // swtich statement picks a random response
    switch(rand() % 4) {
        case 0:
            cout << "I love " << name << "!\n";
            break;
        case 1:
            cout << "I Hate " << name << "!\n";
            break;
        case 2:
            cout << "I'm Fine with " << name << ".\n";
            break;
        case 3:
            cout << "Who is " << name << "?\n";
            break;
    }

    return 0;
}