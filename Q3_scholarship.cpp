/*
 * Name       :Muhammad Hasnain
 * Reg No     : L1s26bscs0114
 * Assignment : 02 - File Handling
 * Question   : Q3_scholarship
 */
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    char filename[100];
    char name[30];
    double cgpa;
    int n, eligible = 0;

    cout << "Enter file name: ";
    cin.getline(filename, 100);

    ifstream inFile(filename);

    if (!inFile.is_open()) {
        cout << "File not found!" << endl;
        return 1;
    }

    ofstream outFile("scholarship.txt");

    if (!outFile.is_open()) {
        cout << "Output file cannot be opened!" << endl;
        return 1;
    }

    inFile >> n;
    inFile.ignore(1000, '\n');

    cout << "\nStudent List\n";

    for (int i = 0; i < n; i++) {
        inFile.getline(name, 30, ',');
        inFile >> cgpa;
        inFile.ignore(1000, '\n');

        cout << name << " - CGPA: " << cgpa << endl;

        if (cgpa >= 3.50) {
            outFile << name << "," << cgpa << endl;
            eligible++;
        }
    }

    cout << "\nTotal students: " << n << endl;
    cout << "Eligible students: " << eligible << endl;
    cout << "Not eligible students: " << n - eligible << endl;
    cout << "Scholarship list saved in scholarship.txt" << endl;

    inFile.close();
    outFile.close();

    return 0;
}
