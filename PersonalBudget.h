#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H
#include <iostream>
#include <string>

#include"UserManager.h"
#include"IncomeManager.h"
#include"ExpenseManager.h"
#include"AuxiliaryMethods.h"

using namespace std;

class PersonalBudget
{
    UserManager userManager;
    IncomeManager *incomeManager;
    ExpenseManager *expenseManager;
    string incomesXMLFileName;
    string expensesXMLFileName;

public:
    PersonalBudget(string usersXMLFileName, string incomesXMLFileNameParam, string expensesXMLFileNameParam)
    : userManager(usersXMLFileName), incomesXMLFileName(incomesXMLFileNameParam), expensesXMLFileName(expensesXMLFileNameParam)
    {
        incomeManager = NULL;
        expenseManager = NULL;
    };

    ~PersonalBudget()
    {
        delete incomeManager;
        incomeManager = NULL;
        delete expenseManager;
        expenseManager = NULL;
    };

    void displayRegistrationMenu();
    void displayUsersMenu();
    void signUp();
    void logIn();
    void changePassword();
    void logOut();
    void addExpense();
    void addIncome();
    void displayThisMonthBalance();
    void displayLastMonthBalance();
    void displayBalanceFromSelectedTime();
    bool isUserLoggedIn();
    int getLoggedUserID();
};

#endif
