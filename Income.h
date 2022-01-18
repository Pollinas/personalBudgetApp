#ifndef INCOME_H
#define INCOME_H
#include <iostream>

using namespace std;

class Income
{
    string date;
    int incomeID;
    int userID;
    string item;
    double amount;

public:

    Income(string date="", int incomeID =0, int userID=0, string item="", double amount = 0)
    {
        this->date = date;
        this->incomeID = incomeID;
        this->userID = userID;
        this->item = item;
        this->amount = amount;
    }

       bool operator < (const Income& str) const
    {
        return (date < str.date);
    }

    void setDate(string newDate);
    void setIncomeID(int newIncomeID);
    void setUserID(int newUserID);
    void setItem(string newItem);
    void setAmount(double newAmount);

    string getDate();
    int getIncomeID();
    int getUserID();
    string getItem();
    double getAmount();

};






#endif
