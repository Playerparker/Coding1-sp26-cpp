// ryan parker Coding 1 Spring 2026
// Vectors, iterators and algorithims

#include <iostream>
#include <string>
#include <vector>  // For vectors
#include<algorithm>

using namespace std;

int main () {
    cout << "Let's learn about vectors!\n";

    int chapter = 0;
    cout << "\nWhat chapter would you like to run?\n";
    cout << "\nPress 1 for Vectors.\n";
    cout << "\nPress 2 fo push_back and pop_back().\n";
    cout << "\nPress 3 for algorithims.\n";

    cin >> chapter;

    if (chapter == 1) {
        // Collection initalizer
        vector<string> names = {"Ace",
                                "King", 
                                "Queen", 
                                "Jack", 
                                "Joker"};
        
        cout << "\nThere are " << names.size() << " in the vector\n";
        cout << "\nHere are your names:\n";

        for(int i = 0; i < names.size(); i++) {
            cout << i + 1 << ". " << names [i] << "\n";
        }

        cout << "\nthe first name in the vector is " << *(names.begin()) << ".\n";

        //making out first iterator, it's a pointer to an element in a vector.
        vector<string>::iterator iter;

        iter = names.begin() + 2;

        cout << "\niter is pointing at " << *iter << ".\n";

    } // end of chapter 1
    if(chapter == 2) {
        cout << "\nLet's use push_back and pop_back().\n";

        vector<string> faveMovies;

        while (faveMovies.size() < 3) {
            cout << "\nplease add a favorite movie: ";
            string input;
            cin >> input;
            //getline(cin, input);

            faveMovies.push_back(input);
        }

        cout << "\nHere are you favorite movies: \n";
        // use a for loop with iter to move through the vector
        for(vector<string>::iterator iter = faveMovies.begin(); iter != faveMovies.end(); iter++) {
            cout << *iter << endl; 
        }
    }
    if (chapter == 3){
        vector<string> friends;

        friends.push_back("Joey");
        friends.push_back("Bowie");
        friends.push_back("Randal");
        friends.push_back("Daniel");
        friends.push_back("Zach");
        friends.push_back("Gregg");

        cout << "here are your friends:\n";
        for(int i = 0; i < friends.size(); i ++) {
            cout << friends[i] << ".\n";
        }

        cout << "Please choose a friend to go visit:\n";
        vector<string>::iterator chosenFriend;

        string input;
        cin >> input;

        //use algorithim
        chosenFriend = find(friends.begin(), friends.end(), input);

        if(chosenFriend != friends.end()) {

        cout << "\nLet's talk to " << *chosenFriend << " today!\n";
        }
        else {
            cout << "\nI couldn't find " << input << " in your friends.\n";
        }

        cout << "\nLet's give " << *chosenFriend << " a new name!\n";
        cin >> input;
        *chosenFriend = input;

        cout << "\nTheir name is now " << *chosenFriend << ".\n";

    }
    else {
        cout << "\n" << chapter << " isn't one of the options.\n";
    }

    
}