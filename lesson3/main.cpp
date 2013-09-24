#include <cstdlib>
#include <iostream>
#include <ostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

vector<int> read_file(char* filename);
int ord(unsigned char chr);

int main(int argc, char** argv) {
    vector<int> data = read_file("./data.txt");
//    cout << (char) data[0] <<endl;
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
        cout << (int) line[0] <<endl;
//        data.push_back((int) tmp);
    }
    return data;
}

bool write_file(string data, char* filename) {

}

int ord(unsigned char chr) {
    int ret = int(chr);
    return ret;
}