#ifndef MENU_H
#define MENU_H
#pragma once
#include <iostream>
#include <iomanip>
using namespace std;

class Menu {
public:
	Menu();
	void printInterestEarnedTitle();
	void printInterestEarnedDetails(int year, double yearEndBalance, double interestEarned);
	void printModifyOptions();
	string nCharString(size_t n, char c);
};

#endif