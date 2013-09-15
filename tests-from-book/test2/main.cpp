#include <cstdlib>
#include <string>
#include <iostream>
#include <ostream>
#include <sstream>
#include <vector>
#include <map>
#include <fstream>


using namespace std;

struct roof {
    int width;
    int heigth;
    int loose;
    int items;
};

int totalRoofs = 0;
roof clientRoof;

vector<roof> read_file(char* filename);
vector<string> split(const string &s, char delimiter);
string calculate_answer(vector<roof> data);
bool write_file(string data, char * filename);

int main(int argc, char** argv) {
    vector<roof> data = read_file("./stogas_duom.txt");
    string answer = calculate_answer(data);
    write_file(answer, "./stogas_rez.txt");
    return 0;
}

vector<roof> read_file(char* filename) {
    ifstream file;
    string line;
    vector<roof> answer;
    int i = 0;
    file.open(filename);
    while (!file.eof()) {
        getline(file, line, '\n');
        vector<string> data = split(line, ' ');
        if (data.size() == 1) {
            totalRoofs = atoi(data[0].c_str());
            i++;
            continue;
        }
        if (i > totalRoofs) {
            clientRoof.width = atoi(data[0].c_str());
            clientRoof.heigth = atoi(data[1].c_str());
        } else {
            answer.push_back({atoi(data[0].c_str()), atoi(data[1].c_str())});
        }
        i++;
    }
    return answer;
}

vector<string> split(const string &s, char delimiter) {
    stringstream line(s);
    string item;
    vector<string> elements;
    while (getline(line, item, delimiter)) {
        elements.push_back(item);
    }
    return elements;
}

bool write_file(string data, char * filename) {
    ofstream file;
    file.open(filename);
    if (file.is_open()) {
        file << data;
        file.close();
        return true;
    }
    return false;
}

string calculate_answer(vector<roof> data) {
    int neededArea = clientRoof.width * clientRoof.heigth;
    for (int i = 0; i < data.size(); i++) {
        int currentArea = 0;
        int items = 0;
        int tmpWidth = 0;
        int tmpHeigth = 0;
        while (clientRoof.width > tmpWidth) {
            items++;
            tmpWidth += data[i].width;
        }
        while (clientRoof.heigth > tmpHeigth) {
            items++;
            tmpHeigth += data[i].heigth;
        }
        currentArea = tmpWidth*tmpHeigth;
        data[i].loose = currentArea - neededArea;
        data[i].items = currentArea / (data[i].heigth * data[i].width);
    }
    int minLost = 0;
    roof winner;
    for (int i = 0; i < data.size(); i++) {
        if (i == 0 && minLost == 0) {
            minLost = data[i].loose;
            winner = data[i];
        }
        if (minLost > data[i].loose) {
            winner = data[i];
        }
    }
    stringstream tmp;
    tmp << winner.width << " " << winner.heigth << " " << winner.items << endl;
    return tmp.str();
}