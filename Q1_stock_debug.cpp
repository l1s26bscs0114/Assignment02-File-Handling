
/*
 * Name       : Muhammad Hasnain
 * Reg No     : L1s26bscs0114
 * Assignment : 02 - File Handling
 * Question   : Q1 - Stock Report (Debugging)
 */

#include <iostream>
#include <fstream>
using namespace std;
//Fix <fstream>  missing

int main() {
    ifstream inFile("stock.txt");
    //Fix if(!infile)
    if (!inFile) {
        cout << "stock.txt not found!" << endl;
        return 1;
    }

    ofstream reorder("reorder.txt");

    char code[10];
    int qty, count = 0, low = 0;
    double price;
    //Fix change int total into double total
    double total = 0;

    while (count < 50 && inFile >> code >> qty >> price) {
        count++;
        total = total + qty * price;

        if (qty < 10) {
            reorder << code << " " << qty << endl;
            low++;
            // Fix add endl
        }
    }

    inFile.close();
    reorder.close();

    cout << "Items: " << count << endl;
    cout << "Total stock value: " << total << endl;
    cout << "Low stock items: " << low << endl;

    return 0;
}
