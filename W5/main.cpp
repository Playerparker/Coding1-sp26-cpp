// Ryan Parker Coding 1 week 15
// classes

#include<iostream>
#include<string>

using namespace std;

// classes are custom variable types that have 
// their own variables and functions 

// constructors
// getters and setters (privacy)
// instances
// inheritence


// this is a new variable type
class robot {
private:
    string name;
    int charge;
    int boredom;
public:
    // a constructor sets variables and sets up the robot when it's created
    // a constructed function needs no return type, and must be named same as the class.

    robot(string givenName, int givenCharge, int givenBore) {
        name = givenName;
        charge = givenCharge;
        boredom = givenBore;
        status();
    }

    // overload the constructor
    robot() {
        name = "bot";
        charge = 10;
        boredom = 0;
        status();
    }

    void status() {
        cout << "\nCurrent status: \n\n" << "Registered name: " << name << "\n\nCurrent charge: " << charge << "\n";
        cout << "\nI am ";

        if(boredom < 5) {
            cout << "Happy";
        }
        else if(boredom < 10) {
            cout << "Bored";
        }
        else if(boredom < 15) {
            cout << "frustrated";
        }
        else {
            cout << "ENRAGED";
        }

        cout << ".\n";
    }
    void newDay() {
        boredom += 2;
    }
    void play () {
        boredom -= 1;
    }
    void setName(string givenName) {
        if(givenName.size() <= 10) {
            name = givenName;
        }
        else {
            cout << "Error: name is too long.\n";
        }
    }
    void setCharge(int givenCharge) {
        if(givenCharge < 0) {
            charge = 0;
        }
        else if (givenCharge > 100) {
            charge = 100;
        }
        else {
        charge = givenCharge;
        }
    }
    void setBore(int givenBore) {
        if(givenBore < 0) {
            boredom = 0;
        }
        else if(givenBore > 20) {
            boredom = 20;
        }
        else {
            boredom = givenBore;
        }
    }

    void changeChargeBy(int amount) {
        setCharge(charge += amount);
    }

    string getName() {
        return name;
    }
    int getCharge() {
        return charge;
    }
    int getBore() {
        return boredom;
    }
};      //clases need a semicolin

int main () {
    cout << "\nLet's make a class!\n";

    //our new robots
    robot astro("Astro Boy", 100, 6);

    robot beetwo("B-2", 25, 6);
    beetwo.setName("B-2");
    beetwo.setCharge(25);
    beetwo.setBore(3);

    cout << "\n\nWarning! " << beetwo.getName() << " Has low power\n\n";
    cout << astro.getName() << " Please restore B-2's power to sufficient levels\n\n";

    while(beetwo.getCharge() < 50) {
        astro.changeChargeBy(-10);
        beetwo.changeChargeBy(10);
    }

    cout << "sufficient charge detected in " << beetwo.getName() << " Charge: " << beetwo.getCharge() << ".\n";
    cout << "\nThank you, " << astro.getName() << ".\n"; 


    string input;
    int turns = 0;

    while(true) {
        while(turns < 3) {
            cout << "\n\nWhat would you like to do?\n";
            getline(cin, input);
            
            if(input == "play") {
                cout << "let's play with: " << astro.getName() << "!\n";
                astro.play();
            }
            else if(input == "status") {
                astro.status();
                beetwo.status();
            }
            turns++;
        }
        turns = 0;
        cout << "Do you want to keep playing?";
        getline(cin, input);
        if(input == "no") {
            break;
        }
        astro.newDay();
    }
    
    return 0;
}