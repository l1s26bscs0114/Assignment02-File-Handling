/*
 * Name       : Muhammad Hasnain
 * Reg No     : L1s26bscs0114
 * Assignment : 02 - File Handling
 * Question   : Q5_expense_tracker
 */

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main() {
    int choice;
    char category[20];
    char search[20];
    int amount;
    int total;

    do {
        cout << "===== Expense Tracker =====" << endl;
        cout << "1. Add an expense" << endl;
        cout << "2. Show all expenses" << endl;
        cout << "3. Show total of a category" << endl;
        cout << "4. Clear all expenses" << endl;
        cout << "5. Exit" << endl;

        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            ofstream outFile("expenses.txt", ios::app);

            cout << "Enter category: ";
            cin >> category;

            cout << "Enter amount: ";
            cin >> amount;

            outFile << category << " " << amount << endl;
            outFile.close();

            cout << "Expense added successfully!" << endl;
        }

        else if (choice == 2) {
            ifstream inFile("expenses.txt");

            if (!inFile) {
                cout << "No expenses found." << endl;
            }
            else {
                while (inFile >> category >> amount) {
                    cout << category << " " << amount << endl;
                }
                inFile.close();
            }
        }

        else if (choice == 3) {
            ifstream inFile("expenses.txt");

            cout << "Enter category to search: ";
            cin >> search;

            total = 0;

            while (inFile >> category >> amount) {
                if (strcmp(category, search) == 0) {
                    total = total + amount;
                }
            }

            inFile.close();

            cout << "Total of " << search << ": "
                << total << endl;
        }

        else if (choice == 4) {
            ofstream outFile("expenses.txt");
            outFile.close();

            cout << "All expenses cleared!" << endl;
        }

        else if (choice == 5) {
            cout << "Program closed." << endl;
        }

        else {
            cout << "Invalid choice!" << endl;
        }

        cout << endl;

    } while (choice != 5);

    return 0;
}
