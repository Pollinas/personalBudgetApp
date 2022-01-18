#ifndef EXPENSE_H
#define EXPENSE_H
#include <iostream>

using namespace std;

class Expense
{
    int date;
    int expenseID;
    int userID;
    string item;
    double amount;

public:

    Expense(int date=0 , int expenseID =0, int userID=0, string item="", double amount = 0)
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

    void setDate(int newDate);
    void setExpenseID(int newExpenseID);
    void setUserID(int newUserID);
    void setItem(string newItem);
    void setAmount(double newAmount);

    int getDate();
    int getExpenseID();
    int getUserID();
    string getItem();
    double getAmount();

};

#endif
