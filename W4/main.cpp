// Ryan parker Coding 1 week 14
// writing to and reading from files

#include<iostream>
#include<fstream> // file stream, includes io stream
#include<string>
#include<vector>

using namespace std;

// build a new function
// return type can be void, name is writeFile(input, path)

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

int main() {
    cout << "Let's do file operations!\n\n";

    // // Create a file
    // // name it
    // ofstream file;
    // file.open("save.txt");
    // // add text
    // file << "text was here.\n";
    // file << "more text was here.\n";
    // // close file
    // file.close();
    // // run program
    // // see it exists

    writeFile("Here is text.\nHere is more text.\nAnother line?");
    
    // string line; // hold line of text
    // ifstream readFile("save.txt");
    // if(readFile.is_open()) {
    //     while(getline(readFile, line)) {    // as long as there are lines
    //         cout << line << endl;           // display line
    //     }
    // }

    readFile();

    vector<string> names = {"Harry, Barry, Darry, Larry,"};

    readFile(names, "names.txt");

    for(int i = 0; i < names.size(); i++) {
        cout << names [i] << endl;
    }

    writeFile(names, "names.txt");

    return 0;
}