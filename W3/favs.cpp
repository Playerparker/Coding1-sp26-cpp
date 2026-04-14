// ryan parker Coding 1 Spring 2026
// Let's create a list of favorites

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main() {

    while (true) {
        cout << "\nWhat would you like to do?\n";
        cout << "\nYou can 'add', 'edit', 'remove', 'show', or 'quit'.\n";

        string input;
        int favNum;
        getline(cin, input);

        if(input == "test") {
            cout << "\nby default, getline only returns strings\n";
            cout << "\nconvert the string to an int with stoi(input):\n";
            cout << "\nWhat's your favorite number?\n";
            getline(cin, input);
            favNum = stoi(input);

            if(favNum > 13) {
                cout << "\nHeyo, your favNum is larger then my favNum.\n";
            }
        }
        if(input == "quit") {
            cout << "Thanks for playing";
            break;
        }
        else if(input == "add") {
            cout << "\nWhat number would you like to add? \n";
            cin >> input;

            favNum = stoi(input);

            cout << "\ngreat number!\n";
        }
        else {
            cout << "\nI don't recognize that input.\n";
        }
    }
}