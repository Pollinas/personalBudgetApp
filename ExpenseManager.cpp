#include"ExpenseManager.h"

void ExpenseManager::addExpense()
{
    Expense expense;

    system("cls");
    cout << " >>> ADDING NEW EXPENSE <<<" << endl << endl;
    expense = insertNewExpenseData();

    expenses.push_back(expense);

    expensesXMLFile.addExpenseToXMLFile(expense);

    cout << "New expense has been added." << endl;
    system("pause");

}

Expense ExpenseManager::insertNewExpenseData()
{
   Expense expense;
   string amount = "";
   char choice;
   string date = "";

    expense.setExpenseID(expensesXMLFile.getLastExpenseID() + 1);
    expense.setUserID(LOGGED_USER_ID);

    cout << "Is it today's expense? Insert 'y' for yes, 'n' for no." << endl;
    choice = AuxiliaryMethods::readChar();
    if (choice == 'y')
       expense.setDate(stoi(AuxiliaryMethods::getCurrentDate()));

    else if (choice == 'n')
    {
        cout << "Insert date in yyyy-mm-dd format. " << endl;
        string temp = AuxiliaryMethods::readLine();

           while (AuxiliaryMethods::checkDateCorrectness(temp) == false)
        {
            cout << "Incorrect date or date format. Insert date in yyyy-mm-dd format. " << endl;
            string temp = AuxiliaryMethods::readLine();

            if(AuxiliaryMethods::checkDateCorrectness(temp))
            {
                date = AuxiliaryMethods::dateToStoreFormat(temp);
                expense.setDate(stoi(date));
                break;
            }

        }

    }


    cout << "Insert item. (e.g. rent, restaurant, grocery shopping, birthday gift for Chris)" << endl;
    expense.setItem(AuxiliaryMethods::readLine());

    cout << "Insert amount." << endl;
    amount = AuxiliaryMethods::readLine();
    string temp = AuxiliaryMethods::commaToDot(amount);
    expense.setAmount(stod(temp));

    return expense;
}

double ExpenseManager::displayThisMonthExpenses()
{
     vector <Expense> thisMonthExpenses;
    double totalExpense = 0.0;
    string currentYear = (AuxiliaryMethods::getCurrentDate()).substr(0,4);
    string currentMonth = (AuxiliaryMethods::getCurrentDate()).substr(4,2);

     for(int i =0; i<expenses.size(); i++)
     {
         int date = expenses[i].getDate();
         string stringDate = to_string(date);

         if (stringDate.substr(0,4) == currentYear && stringDate.substr(4,2) == currentMonth)
            thisMonthExpenses.push_back(expenses[i]);
     }

     sort(thisMonthExpenses.begin(), thisMonthExpenses.end());
     totalExpense = calculateTotalExpense(thisMonthExpenses);

     for (int j =0; j<thisMonthExpenses.size(); j++)
     {
         int date = thisMonthExpenses[j].getDate();
         string stringDate = to_string(date);

         cout << AuxiliaryMethods::dateToDispalyFormat(stringDate) << " ";
         cout << thisMonthExpenses[j].getItem() << " ";
         cout << thisMonthExpenses[j].getAmount() << endl;
     }

     cout << "Total expense from this month: " << totalExpense << endl;

     return totalExpense;
}

double ExpenseManager::displayLastMonthExpenseBalance()
{

    vector <Expense> lastMonthExpenses;
    double totalExpense = 0.0;
    string currentYear = (AuxiliaryMethods::getCurrentDate()).substr(0,4);
    string lastMonth = "";
    string currentMonth = (AuxiliaryMethods::getCurrentDate()).substr(4,2);
    int temp = stoi(currentMonth)-1;

    if (stoi(currentMonth) == 1)
    {
        lastMonth = to_string(12);
        currentYear = to_string(stoi(currentYear) - 1);
    }
    else {
    if (temp<10)
        lastMonth = "0" + to_string(temp);
    else
        lastMonth = to_string(temp);
    }


     for(int i =0; i<expenses.size(); i++)
     {
         int date = expenses[i].getDate();
         string stringDate = to_string(date);

         if (stringDate == currentYear && stringDate.substr(4,2) == lastMonth)
            lastMonthExpenses.push_back(expenses[i]);
     }

     sort(lastMonthExpenses.begin(), lastMonthExpenses.end());
     totalExpense = calculateTotalExpense(lastMonthExpenses);

     for (int j =0; j<lastMonthExpenses.size(); j++)
     {
        int date = lastMonthExpenses[j].getDate();
         string stringDate = to_string(date);

         cout << AuxiliaryMethods::dateToDispalyFormat(stringDate) << " " ;
         cout << lastMonthExpenses[j].getItem() << " ";
         cout << lastMonthExpenses[j].getAmount() << endl;
     }

     cout << "Total expense from last month: " << totalExpense << endl;

     return totalExpense;
}


double ExpenseManager::displayExpenseBalanceFromSelectedDates(string dateBegin,string dateEnd)
{
    vector <Expense> expensesTemp;
    double totalExpense = 0.0;
    string yearBegin = dateBegin.substr(0,4);
    string monthBegin = dateBegin.substr(5,2);
    string dayBegin = dateBegin.substr(8,2);
    string yearEnd = dateEnd.substr(0,4);
    string monthEnd = dateEnd.substr(5,2);
    string dayEnd = dateEnd.substr(8,2);


     for(int i =0; i<expenses.size(); i++)
     {
          int date = expenses[i].getDate();
         string stringDate = to_string(date);

        if ((stringDate.substr(0,4) == yearBegin && stringDate.substr(4,2) == monthBegin
             && stringDate.substr(6,2) >= dayBegin)
             || (stringDate.substr(0,4) == yearBegin && stringDate.substr(4,2) > monthBegin)
             || (stringDate.substr(0,4) == yearEnd && stringDate.substr(4,2) == monthEnd
             && stringDate.substr(6,2) <= dayEnd)
             || (stringDate.substr(0,4) == yearEnd && stringDate.substr(4,2) < monthEnd)
             || (stringDate.substr(0,4) > yearBegin && stringDate.substr(0,4) < yearEnd))

             expensesTemp.push_back(expenses[i]);
     }


    sort(expensesTemp.begin(), expensesTemp.end());
     totalExpense = calculateTotalExpense(expensesTemp);

     for (int j =0; j < expensesTemp.size(); j++)
     {

        int date = expensesTemp[j].getDate();
         string stringDate = to_string(date);

         cout << AuxiliaryMethods::dateToDispalyFormat(stringDate) << " ";
         cout << expensesTemp[j].getItem() << " ";
         cout << expensesTemp[j].getAmount() << endl;
     }

     cout << "Total expense from selected dates: " << totalExpense << endl;

     return totalExpense;
}

double ExpenseManager::calculateTotalExpense(vector <Expense> expensesTemp)
{
    double sum = 0.0;

    for (int i =0; i<expensesTemp.size(); i++)
    {
        sum += expensesTemp[i].getAmount();
    }

    return sum;
}



