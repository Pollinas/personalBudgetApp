#ifndef INCOMEMANAGER_H
#define INCOMEMANAGER_H
#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <string>

#include"Income.h"
#include"IncomesXMLFile.h"
#include"AuxiliaryMethods.h"
#include"UserManager.h"

using namespace std;

class IncomeManager
{
    const int LOGGED_USER_ID;
    vector <Income> incomes;
    IncomesXMLFile incomesXMLFile;

    Income insertNewIncomeData();
    int getNewIncomeID();

  public:
    IncomeManager(string incomesXMLFileName, int loggedUserID)
    : incomesXMLFile(incomesXMLFileName), LOGGED_USER_ID(loggedUserID)
    {
        incomes = incomesXMLFile.loadIncomesFromXMLFile();
    };

    void addIncome();
    double displayThisMonthIncomes();
    double calculateTotalIncome(vector <Income> incomesTemp);
    double displayLastMonthIncomeBalance();
    double displayIncomeBalanceFromSelectedDates(string dateBegin, string dateEnd);


};


#endif
