#include "Income.h"

void Income::setDate(string newDate)
{
    date = newDate;
}

void Income::setIncomeID(int newIncomeID)
{
    if (newIncomeID>0)
    incomeID = newIncomeID;
}

void Income::setUserID(int newUserID)
{
    if(newUserID>0)
    userID = newUserID;
}

void Income::setItem(string newItem)
{
    item = newItem;
}

void Income::setAmount(double newAmount)
{
    amount = newAmount;
}

string Income::getDate()
{
    return date;
}

int Income::getIncomeID()
{
    return incomeID;
}

int Income::getUserID()
{
    return userID;
}

string Income::getItem()
{
    return item;
}

double Income::getAmount()
{
    return amount;
}
