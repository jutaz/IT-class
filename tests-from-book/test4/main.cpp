#include <cstdlib>
#include <fstream>
#include <ostream>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct number {
    int num;
    bool has_pair;
};

vector<number> read_file(char* filename);
int process(vector<number> data);
bool write_file(int data, char* filename);

int main(int argc, char** argv) {
    vector<number> data = read_file("./vienas_duom.txt");
    int number = process(data);
    write_file(number, "./vienas_rez.txt");
    return 0;
}

int process(vector<number> data) {
    vector<int> usedNumbers;
    for (int i = 0; i < data.size(); i++) {
        bool matchFound = false;
        for (int e = 0; e < usedNumbers.size(); e++) {
            if (data[i].num == usedNumbers[e]) {
                matchFound = true;
                break;
            }
        }
        if (matchFound) {
            bool found = false;
            int times = 0;
            for (int c = i; c != -1; c--) {
                if(times == 2) {
                    break;
                }
                if(data[c].has_pair) {
                    continue;
                }
                if(data[c].num == data[i].num && !data[c].has_pair) {
                    found = true;
                }
                if (data[c].num == data[i].num && found) {
                    times++;
                    data[c].has_pair = true;
                }
            }
        } else {
            usedNumbers.push_back(data[i].num);
        }
    }
    for (int d = 0; d < data.size(); d++) {
        if (!data[d].has_pair) {
            cout << data[d].num << endl;
//            return data[d].num;
        }
    }
    return 0;
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

vector<number> read_file(char* filename) {
    ifstream file;
    string line;
    int i = 0;
    vector<number> data;
    file.open(filename);
    while (!file.eof()) {
        getline(file, line, '\n');
        if (i == 0) {
            i++;
            continue;
        }
        data.push_back({atoi(line.c_str())});
    }
    return data;
}
