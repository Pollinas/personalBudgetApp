#include "Expense.h"


void Expense::setDate(int newDate)
{
    date = newDate;
}

void Expense::setExpenseID(int newExpenseID)
{
    if (newExpenseID>0)
    expenseID = newExpenseID;
}

void Expense::setUserID(int newUserID)
{
    if(newUserID>0)
    userID = newUserID;
}

void Expense::setItem(string newItem)
{
    item = newItem;
}

void Expense::setAmount(double newAmount)
{
    amount = newAmount;
}

int Expense::getDate()
{
    return date;
}

int Expense::getExpenseID()
{
    return expenseID;
}

int Expense::getUserID()
{
    return userID;
}

string Expense::getItem()
{
    return item;
}

double Expense::getAmount()
{
    return amount;
}
