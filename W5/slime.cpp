// Ryan Parker Coding 1 week 15
// class inheritence, and inheritor files

#include<iostream>
#include<string>
#include<ctime>
#include<cstdlib>
#include<vector>

using namespace std;

// Vector of slimes
// get slimes to fight
// build slimes

vector<string> slimeNames ={"Earth", "Wind", "Ice", "Fire", "Acid"};

class baseSlime {
public:
    string name;
    int health;
    int damage;

    baseSlime() {
        name = slimeNames[rand() % slimeNames.size()] + " Slime";
        health = rand() % 5 + 5;
        damage = rand() % 6 + 4;
    }

    void hello() {
        cout << "Fighter: " << name; 
        cout << "\n Health: " << health; 
        cout << "\n Damage: " << damage << "\n\n";
    }

    bool attack(baseSlime& otherSlime) {
        otherSlime.health -= damage;
        cout << name << " attacks " << otherSlime.name << "!\n";

        if(otherSlime.health <= 0) {
            return true;
        }
        else {
            return false;
        }
    }
    //step 1, who attacks first
    //step 2, fighter A fighter B
    //step 3, fighter B will attack fighter A if still alive
};

int main() {
    srand(time(0));
    cout << "Let's make some slimes fight!\n\n";

    baseSlime chillSlime;
    chillSlime.name = "Chill Slime";
    chillSlime.health = 10;
    chillSlime.damage = 5;

    baseSlime lazySlime;
    lazySlime.name = "Lazy Slime";
    lazySlime.health = 20;
    lazySlime.damage = 3;

    chillSlime.hello();
    lazySlime.hello();

    cout << "Creating our glob of slimes...\n\n";
    vector<baseSlime> glob(6);

    for(int i = 0; i < glob.size(); i ++) {
        glob[i].hello();
        cout << "\n";
    }

    cout << "Let's have our slimes fight\n";

    baseSlime temp, tempt;

    baseSlime& fighterA = temp;
    baseSlime& fighterB = tempt;

    if(rand() % 2 == 0) {
        cout << "Chill slime goes first!\n";
        fighterA = chillSlime;
        fighterB = lazySlime;
    }
    else {
        cout << "Lazy slime goes first!\n";
        fighterA = lazySlime;
        fighterB = chillSlime;
    }

    while(fighterA.health > 0 && fighterB.health > 0) {

        if(fighterA.attack(fighterB)) {
            cout << fighterB.name << " has been defeated!\n";
        }
        else{
            if(fighterB.attack(fighterA)) {
                cout << fighterA.name << " has been defeated!\n";
            }

        }

    }

    return 0;
}