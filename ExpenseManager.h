#ifndef EXPENSEMANAGER_H
#define EXPENSEMANAGER_H
#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include "Expense.h"
#include "ExpensesXMLFile.h"
#include "AuxiliaryMethods.h"
#include "UserManager.h"

using namespace std;

class ExpenseManager
{
    const int LOGGED_USER_ID;
    vector <Expense> expenses;
    ExpensesXMLFile expensesXMLFile;

    Expense insertNewExpenseData();
    int getNewExpenseID();

  public:
    ExpenseManager(string expensesXMLFileName,int loggedUserID)
    : expensesXMLFile(expensesXMLFileName), LOGGED_USER_ID(loggedUserID)
    {
        expenses = expensesXMLFile.loadExpensesFromXMLFile();
    };

    void addExpense();
    double displayThisMonthExpenses();
    double displayLastMonthExpenseBalance();
    double displayExpenseBalanceFromSelectedDates(string dateBegin,string dateEnd);
    double calculateTotalExpense(vector <Expense> expensesTemp);


};



#endif
