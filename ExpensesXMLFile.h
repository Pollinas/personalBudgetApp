#ifndef EXPENSESXMLFILE_H
#define EXPENSESXMLFILE_H
#include <iostream>
#include<vector>
#include<cstdlib>
#include<string.h>
#include "Markup.h"
#include"Expense.h"
#include "AuxiliaryMethods.h"
#include"XMLFile.h"

using namespace std;

class ExpensesXMLFile : public XMLFile
{
    int lastExpenseID;
    string expensesXMLFileName;

   public:

       ExpensesXMLFile(string expensesXMLFileNameParam)
       : XMLFile(expensesXMLFileNameParam), expensesXMLFileName(expensesXMLFileNameParam)
       {
         lastExpenseID = 0;
       };

    vector <Expense> loadExpensesFromXMLFile();
    void addExpenseToXMLFile(Expense expense);
    int getLastExpenseID();

};


#endif
