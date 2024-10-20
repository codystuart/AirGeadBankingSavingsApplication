#ifndef INTERESTCALCULATIONS_H
#define INTERESTCALCULATIONS_H
#pragma once

#include <iomanip>
#include <iostream>

using namespace std;

class InterestCalculations {
public:
	InterestCalculations();
	double calculateBalanceWithoutMonthlyDeposit(double t_initialInvestment, double t_interestRate, int t_numberOfYears);
	double balanceWithMonthlyDeposit(double t_initialInvestment, double t_monthlyDeposit, double t_interestRate, int t_numberOfYears);
	void changeAllValues();

	//Getters and Setters
	void setInitialInvestment(double& t_initialInvestment);
	void setMonthlyDeposit(double& t_monthlyDeposit);
	void setAnnualInterest(double& t_annualInterest);
	void setNumberOfYears(int& t_numberOfYears);

	double getInitialInvestment();
	double getMonthlyDeposit();
	double getAnnualInterest();
	int getNumberOfYears();


private:
	double m_initialInvestment;
	double m_monthlyDeposit;
	double m_annualInterest;
	int m_numberOfYears;

};

#endif