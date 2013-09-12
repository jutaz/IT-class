#include <cstdlib>
#include <stdio.h>
#include <fstream>
#include <string>
#include <iostream>
#include <map>
#include <sstream>

using namespace std;

bool write_file(char* filename, string data);
map<int, int> read_file(char* filename);

int main(int argc, char** argv) {
    map<int, int> file = read_file("./data.txt");
    int length = file.size();
    for (int i = 0; i < length; i++) {
        cout << file[i] << endl;
    }
    return 0;
}

map<int, int> read_file(char* filename) {
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