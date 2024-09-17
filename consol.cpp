#include <string>
#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;

void delete228() {
    string file;
    cout << "Enter note name" << endl;
    cin >> file;
    file += ".txt";
    remove(file.c_str());
}

int main() {

}