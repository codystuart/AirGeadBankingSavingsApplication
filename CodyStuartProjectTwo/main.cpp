/*
    Name: Cody Stuart
    Assignment: Project Two - Airgead Banking Savings Application
    Class: CS-210-17334-M01 Programming Languages
*/

#include "menu.h"
#include "interestCalculations.h"

using namespace std;

int main() {
    //class objects
    InterestCalculations interest;
    Menu menu;

    bool running = true;
    bool validChoice;

    int userChoice;
    int exitProgram;
    int years;

    double initialInvestment;
    double monthlyDeposit;
    double annualInterest;

    while (running) {

        //I moved this large print block here because I was having issues with it inside my menu class
        //Displays to the user all of the currently set valeus
        cout << fixed << setprecision(2);
        cout << "**********************************" << endl;
        cout << "**********Data Input**************" << endl;
        cout << "Initial Investment Amount: $" << interest.getInitialInvestment() << endl;
        cout << "Monthly Deposit: $" << interest.getMonthlyDeposit() << endl;
        cout << "Annual Interest: %" << interest.getAnnualInterest() << endl;
        cout << "Number of Years: " << interest.getNumberOfYears() << endl;
        cout << "**********************************\n" << endl;
        
        menu.printModifyOptions(); //prints to the console all of the options the user can choose to modify the values.
        cin >> userChoice; //Gets the choice based on the printed menu options
        cout << endl; //adds a space for a cleaner looking console

        //Do something based on the menu choice we just go
        switch (userChoice) {
            case 1:
                //prompt to change all values
                interest.changeAllValues();
                break;
            case 2:
                //prompt to change only the initial investment amount
                cout << "Enter initial investment amount: ";
                cin >> initialInvestment;
                interest.setInitialInvestment(initialInvestment);
                break;
            case 3:
                //prompt to change only the monthly amount deposited
                cout << "Enter monthly deposit amount: ";
                cin >> monthlyDeposit;
                interest.setMonthlyDeposit(monthlyDeposit);
                break;
            case 4:
                //prompt to change the annual interest earned
                cout << "Enter annual interest amount: ";
                cin >> annualInterest;
                interest.setAnnualInterest(annualInterest);
                break;
            case 5:
                //prompt to change the numbers of years interest is earned over
                cout << "Enter number of years : ";
                cin >> years;
                interest.setNumberOfYears(years);
                break;
            case 6:
                break;
        }

        //Gets the values set in the switch/case statement above
        initialInvestment = interest.getInitialInvestment();
        monthlyDeposit = interest.getMonthlyDeposit();
        annualInterest = interest.getAnnualInterest();
        years = interest.getNumberOfYears();

        //Prints out in its own section the final balance per year with only an initial deposit
        cout << menu.nCharString(47, '*') << endl;
        interest.calculateBalanceWithoutMonthlyDeposit(initialInvestment, annualInterest, years);
        cout << menu.nCharString(47, '*') << endl;
        cout << endl; // added a blank line a cleaner looking console

        //Prints out in its own section the final balance per year with an additional monthly deposit
        cout << menu.nCharString(47, '*') << endl;
        interest.balanceWithMonthlyDeposit(initialInvestment, monthlyDeposit, annualInterest, years);
        cout << menu.nCharString(47, '*') << endl;
    

        //Find out if the user wants to continue using the program
        validChoice = false;
        while (!validChoice) {
            cout << "Do you wish to continue?\n" << "1. Yes\n" << "2. No" << endl;
            cin >> exitProgram;
            if (exitProgram == 2) { //if the user's choice is to exit set the choice to valid and break the programs loop.
                running = false;
                validChoice = true;
            }
            else if (exitProgram == 1) { //if the user's choice is 1 which means yes set the choice as valid and stay in the main program loop.
                validChoice = true;
            }
        }
    }

    return 0;
}
