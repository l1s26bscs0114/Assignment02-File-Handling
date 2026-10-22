/*
 * Name       :Muhammad Hasnain
 * Reg No     : L1s26bscs0114
 * Assignment : 02 - File Handling
 * Question   : Q2_parking_report
 */

#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream inFile("parking.txt");
    ofstream outFile("report.txt");

    if (!inFile) {
        cout << "File not found!";
        return 1;
    }

    char plate[20], type[10];
    char colon1, colon2;
    int sh, sm, eh, em;
    int minutes, hours, fee;
    int vehicles = 0, cars = 0, bikes = 0;
    int total = 0, longest = 0;
    char longestPlate[20];

    inFile.ignore(1000, '\n');

    while (inFile >> plate >> type
        >> sh >> colon1 >> sm
        >> eh >> colon2 >> em) {

        minutes = (eh * 60 + em) - (sh * 60 + sm);

        hours = minutes / 60;
        int remaining = minutes % 60;

        if (type[0] == 'C') {
            cars++;
            fee = (minutes / 60) * 100;

            if (remaining > 0) {
                fee = fee + 100;
            }
        }
        else {
            bikes++;
            fee = (minutes / 60) * 40;

            if (remaining > 0) {
                fee = fee + 40;
            }
        }

        if (type[0] == 'B' && minutes <= 60) {
            fee = 40;
        }

        if (type[0] == 'B' && minutes > 60) {
            fee = 120;
        }

        outFile << plate << " " << type << " "
            << hours << " h " << remaining
            << " min Fee: " << fee << endl;

        vehicles++;
        total = total + fee;

        if (minutes > longest) {
            longest = minutes;

            int i = 0;
            while (plate[i] != '\0') {
                longestPlate[i] = plate[i];
                i++;
            }
            longestPlate[i] = '\0';
        }
    }

    outFile << "Vehicles: " << vehicles << endl;
    outFile << "Cars: " << cars << " Bikes: " << bikes << endl;
    outFile << "Total collected: " << total << endl;
    outFile << "Longest stay: " << longestPlate
        << " (" << longest / 60 << " h "
        << longest % 60 << " min)" << endl;

    inFile.close();
    outFile.close();

    cout << "Report saved in report.txt";

    return 0;
}
