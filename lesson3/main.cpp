#include <cstdlib>
#include <iostream>
#include <ostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<int> read_file(char* filename);
bool write_file(string data, char* filename);

int main(int argc, char** argv) {
    stringstream tmp;
    vector<int> data = read_file("./data.txt");
    for (int i =0; i< data.size(); i++) {
        tmp << (char) data[i] << " --> " << data[i] << endl;
    }
    write_file(tmp.str(), "./results.txt");
    return 0;
}

vector<int> read_file(char* filename) {
    string line;
    string all;
    vector<int> data;
    ifstream file;
    file.open(filename);
    while(!file.eof()) {
        getline(file, line, '\n');
        data.push_back((int) line[0]);
    }
    return data;
}

bool write_file(string data, char* filename) {
    ofstream file;
    file.open(filename);
    if(file.is_open()) {
        file << data;
        file.close();
        return true;
    }
    return false;
}