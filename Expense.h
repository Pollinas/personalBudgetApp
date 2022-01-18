#ifndef EXPENSE_H
#define EXPENSE_H
#include <iostream>

using namespace std;

class Expense
{
    string date;
    int expenseID;
    int userID;
    string item;
    double amount;

public:

    Expense(string date="" , int expenseID =0, int userID=0, string item="", double amount = 0)
    {
        this->date = date;
        this->expenseID = expenseID;
        this->userID = userID;
        this->item = item;
        this->amount = amount;
    };

    bool operator < (const Expense& str) const
    {
        return (date < str.date);
    }

    void setDate(string newDate);
    void setExpenseID(int newExpenseID);
    void setUserID(int newUserID);
    void setItem(string newItem);
    void setAmount(double newAmount);

    string getDate();
    int getExpenseID();
    int getUserID();
    string getItem();
    double getAmount();

};

#endif
