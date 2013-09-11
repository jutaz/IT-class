#include <cstdlib>
#include <stdio.h>
#include <fstream>
#include <string>
#include <iostream>
#include <map>
#include <sstream>

using namespace std;

bool write_file(char*  filename, string data);
std::map<int, int> read_file(char* filename);

int main(int argc, char** argv) {
    std::map<int, int> file = read_file("./data.txt");
    int length = file.size();
    int odds = 1;
    int evens = 0;
    cout << length << endl;
    for (int i = 0; i < length; i++) {
        cout << i << endl;
        cout << file[i] << endl;
        if (file[i] % 2 != 0) {
            odds = (file[i] * odds);
        } else {
            evens = (file[i] + evens);
        }
    }
    if (odds == evens) {
        std::stringstream tmp;
        tmp << "Odd numbers multiplication and even numbers sum is equal: " << odds;
        string data = tmp.str();
        write_file("./results.txt", data);
    } else {
        std::stringstream tmp;
        tmp << "Odd numbers multiplication: " << odds << endl << "Even number sum: " << evens << endl;
        string data = tmp.str();
        write_file("./results.txt", data);
    }
    return 1;
}

std::map<int, int> read_file(char* filename) {
    ifstream file;
    string line;
    int i = 0;
    std::map<int, int> data;
    file.open(filename);
    while (!file.eof()) {
        getline(file, line, '\n');
        if (line.c_str() != "0") {
            data[i] = atoi(line.c_str());
        }
        line = "";
        i++;
    }
    file.close();
    return data;
}

bool write_file(char* filename, string data) {
    ofstream file;
    file.open(filename);
    if (file.is_open()) {
        file << data;
        file.close();
    } else {
        cout << "error writing to file";
    }
    return true;
}