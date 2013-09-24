#include <cstdlib>
#include <iostream>
#include <ostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

vector<int> read_file(char* filename);

int main(int argc, char** argv) {
    vector<int> data = read_file("./data.txt");
    return 0;
}

vector<int> read_file(char* filename) {
    string line;
    vector<int> data;
    ifstream file;
    file.open(filename);
    while(!file.eof()) {
        getline(file, line, '\n');
        data.push_back(atoi(line));
    }
    return data;
}
