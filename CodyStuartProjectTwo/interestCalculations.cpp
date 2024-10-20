#include "interestCalculations.h"
#include "menu.h"

Menu menu; //This is probably dirty but we need to use functions from the menu class in this one.

InterestCalculations::InterestCalculations() { //defualt constructor sets the private member variables to 0.
    m_initialInvestment = 0;
    m_monthlyDeposit = 0;
    m_annualInterest = 0;
    m_numberOfYears = 0;
}

double InterestCalculations::calculateBalanceWithoutMonthlyDeposit(double t_initialInvestment, double t_interestRate, int t_numberOfYears) {
    double currentBalance;
    double finalBalance = 0;
    double monthlyInterestRate;
    double interestEarnedThisYear;
    int i;
    int j;

    monthlyInterestRate = (t_interestRate / 100) / 12; //calculate interest rate per month by dividing the decimal form of the percent by 12
    currentBalance = t_initialInvestment; //Start the balance at the initial amount invested

    //This is to catch if the users sets the number of years to invest as 0 meaning nothing is invested.
    if (t_numberOfYears == 0) {
        cout << "Balance and interested earned per year" << endl;
        cout << menu.nCharString(45, '=') << endl;
        menu.printInterestEarnedTitle();
        menu.printInterestEarnedDetails(t_numberOfYears, t_initialInvestment, 0);
        return t_initialInvestment;
    }

    //Prints to the console a title for this box, a line, and each of the columns
    cout << "Balance and interested earned per year" << endl;
    cout << menu.nCharString(45, '=') << endl; //prints 45 equals signs to the console
    menu.printInterestEarnedTitle(); 

    //starting at one calculates interest earned per month and tallies up the final balance 
    for (i = 1; i <= t_numberOfYears; i++) { //loop to iterate years
        interestEarnedThisYear = 0;
        for (j = 0; j < 12; j++) { //loop to iterate months
            interestEarnedThisYear = interestEarnedThisYear + (currentBalance * monthlyInterestRate);
            currentBalance = currentBalance + (currentBalance * monthlyInterestRate);
        }
        menu.printInterestEarnedDetails(i, currentBalance, interestEarnedThisYear); //put out to the console the values for this year
        finalBalance = currentBalance; //determine the final Balance of this year so we can return it at the end of the function
    }
    cout << endl;
    return finalBalance;
}

double InterestCalculations::balanceWithMonthlyDeposit(double t_initialInvestment, double t_monthlyDeposit, double t_interestRate, int t_numberOfYears) {
    double currentBalance;
    double finalBalance = 0;
    double monthlyInterestRate;
    double interestEarnedThisYear;
    int i;
    int j;

    monthlyInterestRate = (t_interestRate / 100) / 12; //calculate interest rate per month by dividing the decimal form of the percent by 12
    currentBalance = t_initialInvestment; //Start the balance at the initial amount invested

    //This is to catch if the users sets the number of years to invest as 0 meaning nothing is invested.
    if (t_numberOfYears == 0) {
        cout << "Balance and interested with an additional monthly deposit" << endl;
        cout << menu.nCharString(45, '=') << endl;
        menu.printInterestEarnedTitle();
        menu.printInterestEarnedDetails(t_numberOfYears, t_initialInvestment, 0);
        return t_initialInvestment;
    }

    //Prints to the console a title for this box, a line, and each of the columns
    cout << "Balance and interested with an additional monthly deposit" << endl;
    cout << menu.nCharString(45, '=') << endl; //prints 45 equals signs to the console
    menu.printInterestEarnedTitle();

    //starting at one calculates interest earned per month and tallies up the final balance 
    for (i = 1; i <= t_numberOfYears; i++) { //loop to iterate over the years
        interestEarnedThisYear = 0;
        for (j = 0; j < 12; j++) { //loop to iterate over the months
            interestEarnedThisYear = interestEarnedThisYear + (currentBalance * monthlyInterestRate);
            currentBalance = currentBalance + (currentBalance * monthlyInterestRate) + t_monthlyDeposit;
        }
        menu.printInterestEarnedDetails(i, currentBalance, interestEarnedThisYear);
        finalBalance = currentBalance;
    }
    cout << endl;
    return finalBalance;
}


void InterestCalculations::setInitialInvestment(double& t_initialInvestment) {
    m_initialInvestment = t_initialInvestment;

}
void InterestCalculations::setMonthlyDeposit(double& t_monthlyDeposit) {
    m_monthlyDeposit = t_monthlyDeposit;
}

void InterestCalculations::setAnnualInterest(double& t_annualInterest) {
    m_annualInterest = t_annualInterest;
}

void InterestCalculations::setNumberOfYears(int& t_numberOfYears) {
    m_numberOfYears = t_numberOfYears;
}

double InterestCalculations::getInitialInvestment() {
    return m_initialInvestment;
}

double InterestCalculations::getMonthlyDeposit() {
    return m_monthlyDeposit;
}

double InterestCalculations::getAnnualInterest() {
    return m_annualInterest;
}

int InterestCalculations::getNumberOfYears() {
    return m_numberOfYears;
}

void InterestCalculations::changeAllValues() {
    double initialInvest;
    double monthlyDeposit;
    double annualInterest;
    int years;

    //Pretty self explanatory, Prompts the user to enter the amount pertaining to the value to be modified and then modifies it.
    cout << "Enter the amount initially invested: ";
    cin >> initialInvest;
    setInitialInvestment(initialInvest);
    cout << "Enter the amount deposited monthly: ";
    cin >> monthlyDeposit;
    this->setMonthlyDeposit(monthlyDeposit);
    cout << "Enter the annual interest rate: ";
    cin >> annualInterest;
    setAnnualInterest(annualInterest);
    cout << "Enter the number of years invested: ";
    cin >> years;
    setNumberOfYears(years);
    cout << endl;

}