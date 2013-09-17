#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <ostream>
#include <vector>
#include <map>
#include <string>


using namespace std;

int nutsForApplesExchangeRatio = 3;

int appleKids = 0;
int nutsKids = 0;

vector<int> apples;

vector<int> nuts;

void read_file(char* filename);
vector<int> split(const string &s, char delimiter);
int compute_exchange();
bool write_file(int data, char* filename);

int main(int argc, char** argv) {
    read_file("./gentys_duom.txt");
    write_file(compute_exchange(), "./gentys_rez.txt");
    return 0;
}

int compute_exchange() {
    int exchanged = 0;
    for (int i = 0; i < nuts.size(); i++) {
        if ((nuts[i] / nutsForApplesExchangeRatio) >= 1) {
            exchanged += (nuts[i] / nutsForApplesExchangeRatio);
        }
    }
    return exchanged;
}

void read_file(char* filename) {
    ifstream file;
    string line;
    int i = 0;
    file.open(filename);
    while (!file.eof()) {
        getline(file, line, '\n');
        vector<int> data = split(line, ' ');
        if (i == 0) {
            appleKids = data[0];
            nutsKids = data[1];
        } else if (i == 1) {
            apples = data;
        } else if (i == 2) {
            nuts = data;
        }
        i++;
    }
}

bool write_file(int data, char* filename) {
    ofstream file;
    file.open(filename);
    if (file.is_open()) {
        file << data;
        file.close();
        return true;
    }
    return false;
}

vector<int> split(const string &s, char delimiter) {
    stringstream line(s);
    string item;
    vector<int> data;
    while (getline(line, item, delimiter)) {
        data.push_back(atoi(item.c_str()));
    }
    return data;
}