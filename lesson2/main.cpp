#include <cstdlib>
#include <stdio.h>
#include <fstream>
#include <string>
#include <iostream>
#include <map>
#include <sstream>
#include <vector>

using namespace std;

bool write_file(char* filename, string data);
map<string, vector<int> > read_file(char* filename);
vector<string> split(const string &s, char delimiter);
float average(vector<int> data);
bool has_only_good_marks(vector<int> data);

int main(int argc, char** argv) {
    map<string, vector<int> > file = read_file("./data.txt");
    int length = file.size();
    string maxAvgName = "";
    float maxAvg = 0;
    map<string, vector<int> >::iterator iter;
    for (iter = file.begin(); iter != file.end(); ++iter) {
        float avg = average(iter->second);
        if (has_only_good_marks(iter->second)) {
            maxAvg = avg;
            maxAvgName = iter->first;
        }
    }
    if(maxAvgName != "" && maxAvg) {
        stringstream tmp;
        tmp << "Auksciausia vidurki turi: \"" << maxAvgName << "\" su vidurkiu: " << maxAvg;
        string data = tmp.str();
        write_file("./results.txt", data);
    } else {
        string data = "auksciausio vidurkio niekas neturi";
        write_file("./results.txt", data);
    }
    return 0;
}

map<string, vector<int> > read_file(char* filename) {
    ifstream file;
    string line;
    string name;
    vector<int> tmpArray;
    map<string, vector<int> > data;
    vector<string> lineData;
    file.open(filename);
    while (!file.eof()) {
        getline(file, line, '\n');
        lineData = split(line.c_str(), ' ');
        for (int i = 0; i < lineData.size(); i++) {
            if (i == 0) {
                name = lineData[i];
            } else {
                tmpArray.push_back(atoi(lineData[i].c_str()));
            }
        }
        data[name] = tmpArray;
        tmpArray.clear();
        line = "";
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

float average(vector<int> data) {
    int tmp;
    float tmpAvg;
    int length = data.size();
    for (int i = 0; i < length; i++) {
        tmp = tmp + data[i];
    }
    return (tmp / length);
}

bool has_only_good_marks(vector<int> data) {
    int length = data.size();
    for (int i = 0; i < length; i++) {
        if (data[i] < 9) {
            return false;
        }
    }
    return true;
}