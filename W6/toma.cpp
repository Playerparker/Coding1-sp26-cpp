// Ryan Parker Coding 1 week 16
// Making Tomas

#include<iostream>
#include<string>
#include<ctime>
#include<cstdlib>
#include<vector>
#include<fstream>

using namespace std;

// list of names for Tomas in another file.
void writeFile(string input, string path = "save.txt") {
    ofstream file(path);        // open the file at the specified path
    file << input;
    file.close();
}
void writeFile(vector<string>& vec, string path = "vector.txt") {
    ofstream file(path);
    for(int i = 0; i < vec.size(); i++) {
        file << vec[i] << endl;
    }
    file.close();
}

void readFile(string path = "save.txt") {
    string line;
    ifstream file(path);
    if(file.is_open()) {
        while(getline(file, line)) {
            cout << line << endl;
        }
    }
    else {
        cout << "File not found.\n";
    }
    file.close();
}

void readFile(vector<string>& vec, string path = "vector.txt") {
    vec.clear();        // ensures vector is empty
    string line;
    ifstream file(path);
    if(file.is_open()) {
        while(getline(file, line)) {
            vec.push_back(line);
        }
    }
    file.close();
}



// class for Tomas
class baseToma {
private:
    //  Their name
    string name;
    //  Their health
    int health;
    //  Their damage
    int damage;
    //  Their hunger
    int hunger;
    //  Their personality
    string personality;
public:
    // Creating a Toma base
    baseToma(string givName, int givHeal, int givDam, int givHun, string givPers) {
        name = givName;
        health = givHeal;
        damage = givDam;
        hunger = givHun;
        personality = givPers;
    }
    baseToma() {
        name = "";
        health = rand() % 10 + 10;
        damage = rand() % 5 + 5;
        hunger = 0;
        personality = "";
    }
    void opponentToma() {
        string names;
        name = names[rand() % names.size()];
        health = rand() % 5 + 5;
        damage = rand() % 6 + 4;
    }
    void hello() {
        cout << "Toma: " << name;
        cout << "\n Health: " << health;
        cout << "\n Damage: " << damage;
        cout << "\n Personality: " << personality;
        if(hunger > 5) {
            cout << "\nI am hungry.\n";
        }
        else if(hunger == 10) {
            cout << "\nI am starving.\n";
        }
        else {
            cout << "\nI am fine.\n";
        }
    }
    //setters
    void setName(string givName) {
        name = givName;
    }
    void setHealth(int givHeal) {
        health = givHeal;
    }
    void setDamage(int givDam) {
        damage = givDam;
    }
    void setHunger(int givHun) {
        if(givHun < 0) {
            hunger = 0;
        }
        else if(givHun > 10) {
            hunger = 10;
        }
        else {
            hunger = givHun;
        }
    }
    void setPersonality(string givPers) {
        personality = givPers;
    }
    //getters
    string getName() {
        return name;
    }
    int getHealth() {
        return health;
    }
    int getDamage() {
        return damage;
    }
    int getHunger() {
        return hunger;
    }
    string getPersonality() {
        return personality;
    }

    void changeHungerBy(int amount) {
        setHunger(hunger += amount);
    }
    void changeStatsBy() {
        setHealth(health += rand() % 3 + 1);
        setDamage(damage += rand() % 3 + 1);
        setHunger(hunger += 2);
    }

};

int main() {
    srand(time(0));
    string input;

    vector<string> names = {"Harry", "Barry", "Darry", "Larry"};

    readFile(names, "names.txt");

    for(int i = 0; i < names.size(); i++) {
        cout << names [i] << endl;
    }

    writeFile(names, "names.txt");

    // create a Toma
    baseToma pal;
    pal.setName("Pal");
    pal.setHealth(15);
    pal.setDamage(6);
    pal.setHunger(2);
    pal.setPersonality("Adventurous");
    //  display
    pal.hello();

    //  give player control
    while(true){
        cout << "\nWhat would you like to do? \n";
        cout << "\nFeed\n";
        cout << "\nChat\n";
        cout << "\nTrain\n";
        cout << "\nBattle\n\n";

        getline(cin, input);
    
        if(input == "chat") {
            cout << "\nHelloooo Toma!\n";
            pal.hello();
        }
        else if(input == "feed") {
            cout << "\nDelectible five course meal\n";
            pal.changeHungerBy(-1); 
        }
        else if(input == "train") {
            cout << "\nGet up and jam, and pump up the jam!\n";
            pal.changeStatsBy();
        }

    }

    return 0;
}