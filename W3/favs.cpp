// ryan parker Coding 1 Spring 2026
// Let's create a list of favorites

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    vector<string> favGames = {"Tears of the Kingdom",
                               "Super Mario Wonder",
                               "Persona 3 Reloaded", 
                               "Baldurs Gate 3", 
                               "Assassins Creed III", 
                               "Hollow Knight",
                               "Deadlock",
                               "Team Fortress 2", 
                               "Astroneer", 
                               "Undertale", 
                               "Deltarune", 
                               "Slay the Spire", 
                               "Root"};

    string menuInput;
    string input;

    while (true) {
        cout << "\nWhat would you like to do?\n";
        cout << "\nYou can 'add', 'edit', 'remove', 'show', or 'quit'.\n";
        
        int favNum;
        getline(cin, menuInput);

        if(menuInput == "test") {
            cout << "\nby default, getline only returns strings\n";
            cout << "\nconvert the string to an int with stoi(input):\n";
            cout << "\nWhat's your favorite number?\n";
            getline(cin, input);
            favNum = stoi(input);

            if(favNum > 13) {
                cout << "\nHeyo, your favNum is larger then my favNum.\n";
            }
        }
        else if(menuInput == "add") {
            cout << "\nplease add another game: \n\n";

            getline(cin, input);
            favGames.push_back(input);
            cout << "\n" << input << " Has been added to your games list.\n";
        }
        else if(menuInput == "bulk") {
            //as for input
            cout << "\nenter as many games as you like, separated by comma.\n";
            //get input
            getline(cin, input);
            //build a temp string
            string temp;
            //find the comma
            int pos;
            //while input.size() !=0
            for(int i = 0; i < input.size(); i++) {
                pos = input.find(",");
                temp = input.substr(0, pos);
            }
            favGames.push_back(temp);
            cout << "\nThe games added are: \n" << temp;
            // use sub_str() to get all characters before comma

        }
        else if(menuInput == "edit") {
            cout << "\nHere are your games: \n";
            for(int i = 0; i < favGames.size(); i ++) {
                cout << favGames[i] << ".\n";
            }

            cout << "\nPlease choose a game to edit! \n";
            vector<string>::iterator chosenGame;

            getline(cin, input);

            chosenGame = find(favGames.begin(), favGames.end(), input);

            if(chosenGame != favGames.end()) {
                
                cout << "\nPlease edit " << *chosenGame << "\n";
                getline(cin, input);
                *chosenGame = input;

                cout << "\nIt is now " << *chosenGame << ".\n";
            }
            else {
                cout << "\nI couldn't find " << input << " in your games.\n";
            }
        }
        else if(menuInput == "remove") {
            sort(favGames.begin(), favGames.end());
            for(int i = 0; i < favGames.size(); i++) {
                cout << favGames[i] << endl;
            }

            cout << "\nWhat game do you wish to remove?\n";
            
            getline(cin, input);

            auto iter = find(favGames.begin(), favGames.end(), input);

            if (iter != favGames.end()) {
                cout << "\nFound it!\n";
                favGames.erase(iter);
            }
            else {
                cout << "\nI could not find that name in favs.\n";
            }
        }
        else if(menuInput == "show") {
            sort(favGames.begin(), favGames.end());

            cout << "\n\nHere's all your favorite games!: \n\n";

            for(int i = 0; i < favGames.size(); i++) {
                cout << i + 1 << ". " << favGames[i] << endl;
            }
        }
        else if(menuInput == "quit") {
            cout << "Thanks for playing";
            break;
        }
        else {
            cout << "\nI don't recognize that input.\n";
        }
    }
}