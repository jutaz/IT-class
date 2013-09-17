#include <cstdlib>
#include <fstream>
#include <iostream>
#include <ostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

struct computer {
    float cpu;
    int ram;
    int hdd;
    int power;
    int price;
    int warranty;
};

computer requirements;

map<string, computer> read_file(char* filename);

int main(int argc, char** argv) {

    return 0;
}

map<string, computer> read_file(char* filename) {
    ifstream file;
    string line;
    int i = 0;
    file.open(filename);
    while(!file.eof()) {
        getline(file, line, '\n');
        
        if(i == 0) {

        }
    }
}

vector<string> split(const string &s, char delimiter) {
    stringstream line(s);
    string item;
    vector<string> data;
    while(getline(line, item, delimiter)) {
        data.push_back(item);
    }
    return data;
}

