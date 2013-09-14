#include <cstdlib>
#include <iostream>
#include <ostream>
#include <vector>
#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <math.h>

using namespace std;

struct Ttarnyba {
    string name;
    int x;
    int y;
};

bool write_to_file(string data, char* filename);
vector<string> split(const string &s, char delimiter);
vector<Ttarnyba> read_from_file(char* filename);
string calculate_route(vector<Ttarnyba> data);
double make_positive(int i);

int dayLimit = 0;
int items = 0;
int totalDriven = 0;
int aptarnautaTarnybu = 0;

int main(int argc, char** argv) {
    vector<Ttarnyba> data = read_from_file("./U1.txt");
    string company = calculate_route(data);
    stringstream tmp;
    tmp << aptarnautaTarnybu << " " << totalDriven << " " << company;
    string tofile = tmp.str();
    write_to_file(tofile, "./U1rez.txt");
    return 0;
}

vector<Ttarnyba> read_from_file(char* filename) {
    ifstream file;
    string line;
    vector<Ttarnyba> data;
    file.open(filename);
    while (!file.eof()) {
        getline(file, line, '\n');
        vector<string> tmp = split(line, ' ');
        if (tmp.size() == 2) {
            dayLimit = atoi(tmp[1].c_str());
            items = atoi(tmp[0].c_str());
            continue;
        }
        data.push_back({tmp[0], atoi(tmp[1].c_str()), atoi(tmp[2].c_str())});
    }
    file.close();
    return data;

}

bool write_to_file(string data, char* filename) {
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

vector<string> split(const string &s, char delimiter) {
    stringstream line(s);
    string item;
    vector<string> elems;
    while (getline(line, item, delimiter)) {
        elems.push_back(item);
    }
    return elems;
}

string calculate_route(vector<Ttarnyba> data) {
    string last = "";
    for (int i = 0; i < data.size(); i++) {
        int thisRoute = (make_positive(data[i].x)*2)+(make_positive(data[i].y)*2);
        if (thisRoute + totalDriven > dayLimit) {
            aptarnautaTarnybu = i + 1;
            return last;
        } else {
            totalDriven = thisRoute + totalDriven;
            last = data[i].name;
        }
    }
}

double make_positive(int i) {
    return sqrt(pow(i, 2));
}