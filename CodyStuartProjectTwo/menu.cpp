#include "menu.h"

Menu::Menu() {
}

void Menu::printInterestEarnedTitle() {
    cout << "Year\t" << "Year End Balance\t" << "Interest Earned" << endl;
}

void Menu::printInterestEarnedDetails(int year, double yearEndBalance, double interestEarned) {
    cout << fixed << setprecision(2); //sets doubles and floats to always print two decimal places 
    cout << year << "\t" << yearEndBalance << "\t\t\t" << interestEarned << endl;
}

void Menu::printModifyOptions() {
    cout << "Please Select an option to modify." << endl;
    cout << "==================================" << endl;
    cout << "1. Modify values." << endl;
    cout << "2. Modify initial investment. " << endl;
    cout << "3. Modify monthly deposit. " << endl;
    cout << "4. Modify annual interest rate." << endl;
    cout << "5. Modify number of years invested." << endl;
    cout << "6. Return to main menu." << endl;
    cout << "==================================" << endl;
    cout << "User's choice: ";
}

string Menu::nCharString(size_t n, char c) {
    int i;
    string outputString; // string to output

    //use loop to append the desired char to a string continuously until the desired size has been reached.
    for (i = 0; i < n; i++) {
        outputString += c;
    }

    return outputString;
}