#include <cstdlib>
#include <sstream>
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<string> read_file(char* filename);
map<int, int> parse_data(vector<string> data);
bool write_to_file(string data, char* filename);

int main(int argc, char** argv) {
    vector<string> data = read_file("./skaiciai_duom.txt");
    map<int, int> answer = parse_data(data);
    map<int, int>::iterator iter;
    int highest = 0;
    for (iter = answer.begin(); iter != answer.end(); ++iter) {
        if (iter->second > highest) {
            highest = iter->second;
        }
    }
    stringstream tmp;
    for (int i = highest; i > 0; i--) {
        for (iter = answer.begin(); iter != answer.end(); ++iter) {
            if (iter->second == i) {
                tmp << iter->first << endl;
            }
        }
    }
    string finalAnswer = tmp.str();
    if(finalAnswer == "") {
        finalAnswer = "NERA";
    }
    write_to_file(finalAnswer, "./skaiciai_rez.txt");
    return 0;
}

bool write_to_file(string data, char* filename) {
    ofstream file;
    file.open(filename);
    if(file.is_open()) {
        file << data;
        file.close();
        return true;
    }
    return false;
}

vector<string> read_file(char* filename) {
    ifstream file;
    string line;
    vector<string> data;
    int i = 0;
    file.open(filename);
    while (!file.eof()) {
        getline(file, line, '\n');
        if (i == 0) {
            i++;
            continue;
        }
        data.push_back(line);
        i++;
    }
    file.close();
    return data;
}

map<int, int> parse_data(vector<string> data) {
    map<int, int> answer;
    for (int i = 0; i < data.size(); i++) {
        for (int ii = 0; ii < data[i].length(); ii++) {
            if (data[i][ii] % 2 == 0 && data[i][ii] != '0') {
                stringstream tmp;
                tmp << data[i];
                string tmpi = tmp.str();
                answer[atoi(tmpi.c_str())] += 1;
            }
        }
    }
    return answer;
}

