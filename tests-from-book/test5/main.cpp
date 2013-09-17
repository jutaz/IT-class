#include <cstdlib>
#include <fstream>
#include <iostream>
#include <ostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

struct Tsatisfies {
    bool cpu;
    bool ram;
    bool hdd;
    bool power;
    bool price;
    bool warranty;
};

struct computer {
    float cpu;
    int ram;
    int hdd;
    int power;
    int price;
    int warranty;
    string name;
    float ratio;
    Tsatisfies satisfy_details;
    bool satisfies;
};

computer requirements;
int providers = 0;

map<string, computer> read_file(char* filename);
vector<string> split(const string &s, char delimiter);
computer calculate_best_pc(map<string, computer> data);

int main(int argc, char** argv) {
    map<string, computer> data = read_file("./kompiuteriai_duom.txt");
    computer calculated = calculate_best_pc(data);
    return 0;
}

computer calculate_best_pc(map<string, computer> data) {
    computer best;
    map<string, computer>::iterator iter;
    for (iter = data.begin(); iter != data.end(); iter++) {
        float ratio = (iter->second.price) / (iter->second.cpu + iter->second.ram + (iter->second.hdd / 1000)-(iter->second.power / 1000)+(iter->second.warranty / 20));
        iter->second.ratio = ratio;
        int satisfies = 0;
        if (iter->second.cpu >= requirements.cpu) {
            iter->second.satisfy_details.cpu = true;
            satisfies++;
        }
        if (iter->second.hdd >= requirements.hdd) {
            iter->second.satisfy_details.hdd = true;
            satisfies++;
        }
        if (iter->second.ram >= requirements.ram) {
            iter->second.satisfy_details.ram = true;
            satisfies++;
        }
        if (iter->second.power >= requirements.power) {
            iter->second.satisfy_details.power = true;
            satisfies++;
        }
        if (iter->second.warranty >= requirements.warranty) {
            iter->second.satisfy_details.warranty = true;
            satisfies++;
        }
        if(satisfies > 4) {
            iter->second.satisfies = true;
        }
    }
    return best;
}

map<string, computer> read_file(char* filename) {
    ifstream file;
    string line;
    map<string, computer> data;
    int i = 0;
    file.open(filename);
    while (!file.eof()) {
        getline(file, line, '\n');
        vector<string> tmp = split(line, ' ');
        if (i == 0) {
            requirements.cpu = atof(tmp[0].c_str());
            requirements.ram = atoi(tmp[1].c_str());
            requirements.hdd = atoi(tmp[2].c_str());
            requirements.power = atoi(tmp[3].c_str());
            requirements.price = atoi(tmp[4].c_str());
            requirements.warranty = atoi(tmp[5].c_str());
        } else if (i == 1) {
            providers = atoi(tmp[0].c_str());
        } else {
            data[tmp[0]].cpu = atof(tmp[1].c_str());
            data[tmp[0]].ram = atoi(tmp[2].c_str());
            data[tmp[0]].hdd = atoi(tmp[3].c_str());
            data[tmp[0]].power = atoi(tmp[4].c_str());
            data[tmp[0]].price = atoi(tmp[5].c_str());
            data[tmp[0]].warranty = atoi(tmp[6].c_str());
            data[tmp[0]].name = tmp[0];
        }
        i++;
    }
    return data;
}

vector<string> split(const string &s, char delimiter) {
    stringstream line(s);
    string item;
    vector<string> data;
    while (getline(line, item, delimiter)) {
        if (item == "" || item == " ") {
            continue;
        }
        data.push_back(item);
    }
    return data;
}


