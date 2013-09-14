#include <cstdlib>
#include <stdio.h>
#include <fstream>
#include <string>
#include <iostream>
#include <map>
#include <sstream>
#include <vector>

using namespace std;

struct miestas {
    string city_name;
    string state_name;
    int habitants;
};

int numberOfCities = 0;

vector<miestas> read_file(char* filename);
bool write_file(string data, char* filename);
vector<string> split(const string &s, char delimiter);
string calculate_answer(vector<miestas> data);

int main(int argc, char** argv) {
    vector<miestas> data = read_file("./U2.txt");
    string answer = calculate_answer(data);
    write_file(answer, "./U2rez.txt");
    return 0;
}

bool write_file(string data, char* filename) {
    ofstream file;
    file.open(filename);
    if (file.is_open()) {
        file << data;
        file.close();
        return true;
    }
    return false;
}

vector<miestas> read_file(char* filename) {
    ifstream file;
    string line;
    vector<miestas> data;
    file.open(filename);
    while (!file.eof()) {
        getline(file, line, '\n');
        vector<string> tmp = split(line, ' ');
        if (tmp.size() == 1) {
            numberOfCities = atoi(tmp[0].c_str());
        } else {
            data.push_back({tmp[0], tmp[1], atoi(tmp[2].c_str())});
        }
    }
    file.close();
    return data;
}

vector<string> split(const string &s, char delimiter) {
    stringstream line(s);
    string item;
    vector<string> elems;
    while (getline(line, item, delimiter)) {
        elems.push_back(item);
    }
    return elems;
}

string calculate_answer(vector<miestas> data) {
    string answer = "";
    map<string, int> districts;
    map<string, int> minHabitants;
    map<int, string> line;
    for (int i = 0; i < data.size(); i++) {
        if (minHabitants[data[i].state_name] > data[i].habitants || minHabitants[data[i].state_name] == 0) {
            minHabitants[data[i].state_name] = data[i].habitants;
        }
        districts[data[i].state_name] += data[i].habitants;
    }
    map<string, int>::iterator iter;
    stringstream tmp;
    for (iter = districts.begin(); iter != districts.end(); ++iter) {
        stringstream tmpline;
        tmpline << iter->first << " " << minHabitants[iter->first] << " " << iter->second << endl;
        line[minHabitants[iter->first]] = tmpline.str();
    }
    tmp << line.size() << endl;
    map<int, string>::iterator iter2;
    for (iter2 = line.begin(); iter2 != line.end(); ++iter2) {
        tmp << iter2->second;
    }
    answer = tmp.str();
    return answer;
}