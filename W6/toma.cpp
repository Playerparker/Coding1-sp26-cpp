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

vector<string> names = {"Harry", "Barry", "Darry", "Larry"};

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
    
public:
    // Creating a Toma base
    baseToma(string givName, int givHeal, int givDam, int givHun) {
        name = givName;
        health = givHeal;
        damage = givDam;
        hunger = givHun;
    }
    baseToma() {
        name = names[rand() % names.size()];
        health = rand() % 10 + 10;
        damage = rand() % 5 + 5;
        hunger = 0;
    }
    void hello() {
        cout << "Toma: " << name;
        cout << "\n Health: " << health;
        cout << "\n Damage: " << damage;
        if(hunger >= 10) {
            cout << "\nI am starving.\n";
        }
        else if(hunger >= 5) {
            cout << "\nI am hungry.\n";
        }
        else {
            cout << "\nI am fine.\n";
        }
    }
    
    bool attack(baseToma& otherToma) {
        otherToma.health -= damage;
        cout << name << " attacks " << otherToma.name << "!\n";

        if(otherToma.health <= 0) {
            return true;
        }
        else {
            return false;
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
    void changeHungerBy(int amount) {
        setHunger(hunger + amount);
    }
    void changeStatsBy() {
        setHealth(health + rand() % 3 + 1);
        setDamage(damage + rand() % 3 + 1);
        setHunger(hunger + 2);
    }

};

bool opponentTurn(baseToma& opponent, baseToma& pal) {
        int roll = rand() % 100;

        if(opponent.getHealth() <= 5 && rand() % 2 == 0) {
            cout << "\n" << opponent.getName() << " fled!\n";
            return true; 
        }
        else if(opponent.getHealth() <= 8 && roll < 40) {
            cout << "\n" << opponent.getName() << " heals!\n";
            opponent.setHealth(opponent.getHealth() + 2);
        }
        else {
            if(opponent.attack(pal)) {
                cout << "\n" << pal.getName() << " was defeated!\n";
                return true;
            }
    }
    return false;
}

int main() {

    readFile(names, "names.txt");
    writeFile(names, "names.txt");

    
    srand(time(0));
    string input;

    // create a Toma
    baseToma pal;
    pal.setName("Pal");
    pal.setHealth(15);
    pal.setDamage(6);
    pal.setHunger(2);

    //  display
    pal.hello();

    //  give player control
    while(true){
        cout << "\nWhat would you like to do? \n";
        cout << "\nFeed\n";
        cout << "\nChat\n";
        cout << "\nTrain\n";
        cout << "\nRecover\n";
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
            if(pal.getHunger() >= 6) {
                cout << "\nPal is too hungry to train!\n";
            }  
            else {
                cout << "\nGet up and jam, and pump up the jam!\n";
                pal.changeStatsBy();
            }
        }
        else if (input == "recover") {
            cout << "\nHaving a niiice rest~\n";
            pal.setHealth(pal.getHealth() + 5);
            pal.changeHungerBy(+2);
        }
        else if(input == "battle") {
             if(pal.getHunger() >= 10) {
                cout << "\nPal is starving and can't fight!\n";
            }
            else {
                cout << "\n\nChoose your opponnent!\n\n";
                vector<baseToma> gang(6);
                for(int i = 0; i < gang.size(); i++) {
                    cout << i + 1 << ". ";
                    gang[i].hello();
                    cout << "\n";
                }
                getline(cin, input);

                baseToma p1;
                baseToma& opponent = p1;
                bool opponentFound = false;
                int choice = stoi(input);

                if(choice >= 1 && choice <= gang.size()) {
                    opponent = gang[choice - 1];
                    opponentFound = true;
                }
                else {
                    cout << "Invalid choice.\n";
                }

                bool palGoesFirst = (rand() % 2 == 0);
                baseToma& fighterA = palGoesFirst ? pal : opponent;
                baseToma& fighterB = palGoesFirst ? opponent : pal;

                if(palGoesFirst){ 
                    cout << "Pal goes first!\n";
                }
                else { 
                    cout << opponent.getName() << " goes first!\n";
                    if(opponentTurn(opponent, pal)) { 
                        break;
                    }  
                }
                while(fighterA.getHealth() > 0 && fighterB.getHealth() > 0) {
                    cout << "\n--- " << pal.getName() << " ---\n";
                    cout << "Health: " << pal.getHealth() << " | Damage: " << pal.getDamage() << "\n";
                    cout << "\n--- " << opponent.getName() << " ---\n";
                    cout << "Health: " << opponent.getHealth() << " | Damage: " << opponent.getDamage() << "\n";
   
                    cout << "\nattack / heal / flee\n";
                    getline(cin, input);

                    if(input == "attack") {
                        if(pal.attack(opponent)) {
                            cout << "\n" << opponent.getName() << " defeated!\n";
                            break;
                        }
                        cout << "\nOpponents turn!\n";
                        if(opponentTurn(opponent, pal)) { 
                            break;
                        }    
                        pal.changeHungerBy(1);
                    }
                    else if(input == "heal") {
                        pal.setHealth(pal.getHealth() + 2);
                        if(opponentTurn(opponent, pal)) { 
                            break;
                        }   
                    }
                    else if(input == "flee") {
                        cout << "You ran away!\n";
                        break;
                    }
                    
                }
                if(pal.getHealth() <= 0) {
                    cout << "Pal was defeated!\n";
                }
                if(pal.getHunger() >= 5) {
                    cout << "Warning: Pal is hungry!\n";
                }
            }
            
        }
    }

    return 0;
}