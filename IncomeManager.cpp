#include "IncomeManager.h"

void IncomeManager::addIncome()
{
    Income income;

    system("cls");
    cout << " >>> ADDING NEW INCOME <<<" << endl << endl;
    income = insertNewIncomeData();

    incomes.push_back(income);

    incomesXMLFile.addIncomeToXMLFile(income);

    cout << "New income has been added." << endl;
    system("pause");

}

Income IncomeManager::insertNewIncomeData()
{
   Income income;
   string amount = "";
   string date = "";
   char choice;

    income.setIncomeID(incomesXMLFile.getLastIncomeID() + 1);
    income.setUserID(LOGGED_USER_ID);

    cout << "Is it today's income? Insert 'y' for yes, 'n' for no." << endl;
    choice = AuxiliaryMethods::readChar();
    if (choice == 'y')
        income.setDate(AuxiliaryMethods::getCurrentDate());

    else if (choice == 'n')
    {
        cout << "Insert date in yyyy-mm-dd format. " << endl;
        string temp = AuxiliaryMethods::readLine();

        while (AuxiliaryMethods::checkDateCorrectness(temp) == false)
        {
            cout << "Incorrect date or date format. Insert date in yyyy-mm-dd format. " << endl;
            string temp = AuxiliaryMethods::readLine();

            if (AuxiliaryMethods::checkDateCorrectness(temp))
                break;
        }

            date = AuxiliaryMethods::dateToStoreFormat(temp);
            income.setDate(date);
    }

    cout << "Insert item.(e.g. salary, Bitcoin income, rental)" << endl;
    income.setItem(AuxiliaryMethods::readLine());

    cout << "Insert amount." << endl;
    amount = AuxiliaryMethods::readLine();
    string temp = AuxiliaryMethods::commaToDot(amount);
    income.setAmount(stod(temp));

    return income;
}

double IncomeManager::calculateTotalIncome(vector <Income> incomesTemp)
{
    double sum = 0.0;

    for (int i =0; i<incomesTemp.size(); i++)
    {
        sum += incomesTemp[i].getAmount();
    }

    return sum;
}

double IncomeManager::displayThisMonthIncomes()
{
    vector <Income> thisMonthIncomes;
    double totalIncome = 0.0;
    string currentYear = (AuxiliaryMethods::getCurrentDate()).substr(0,4);
    string currentMonth = (AuxiliaryMethods::getCurrentDate()).substr(4,2);

     for(int i =0; i<incomes.size(); i++)
     {
         if (incomes[i].getDate().substr(0,4) == currentYear && incomes[i].getDate().substr(4,2) == currentMonth)
            thisMonthIncomes.push_back(incomes[i]);
     }

     sort(thisMonthIncomes.begin(), thisMonthIncomes.end());
     totalIncome = calculateTotalIncome(thisMonthIncomes);

     for (int j =0; j<thisMonthIncomes.size(); j++)
     {
         cout << AuxiliaryMethods::dateToDispalyFormat(thisMonthIncomes[j].getDate()) << " ";
         cout << thisMonthIncomes[j].getItem() << " ";
         cout << thisMonthIncomes[j].getAmount() << endl;
     }

     cout << "Total income from this month: " << totalIncome << endl;

     return totalIncome;
}

double IncomeManager::displayLastMonthIncomeBalance()
{
    vector <Income> lastMonthIncomes;
    double totalIncome = 0.0;
    string lastMonth = "";
    string currentYear = (AuxiliaryMethods::getCurrentDate()).substr(0,4);
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

     for(int i =0; i<incomes.size(); i++)
     {
         if (incomes[i].getDate().substr(0,4) == currentYear && incomes[i].getDate().substr(4,2) == lastMonth)
            lastMonthIncomes.push_back(incomes[i]);
     }

     sort(lastMonthIncomes.begin(), lastMonthIncomes.end());
     totalIncome = calculateTotalIncome(lastMonthIncomes);

     for (int j =0; j<lastMonthIncomes.size(); j++)
     {
         cout << AuxiliaryMethods::dateToDispalyFormat(lastMonthIncomes[j].getDate()) << " ";
         cout << lastMonthIncomes[j].getItem() << " ";
         cout << lastMonthIncomes[j].getAmount() << endl;
     }

     cout << "Total income from last month: " << totalIncome << endl;

     return totalIncome;

}

double IncomeManager::displayIncomeBalanceFromSelectedDates(string dateBegin, string dateEnd)
{
    vector <Income> incomesTemp;
    double totalIncome = 0.0;
    string yearBegin = dateBegin.substr(0,4);
    string monthBegin = dateBegin.substr(5,2);
    string dayBegin = dateBegin.substr(8,2);
    string yearEnd = dateEnd.substr(0,4);
    string monthEnd = dateEnd.substr(4,2);
    string dayEnd = dateEnd.substr(6,2);


     for(int i =0; i<incomes.size(); i++)
     {
         if ((incomes[i].getDate().substr(0,4) == yearBegin && incomes[i].getDate().substr(4,2) == monthBegin
             && incomes[i].getDate().substr(6,2) >= dayBegin)
             || (incomes[i].getDate().substr(0,4) == yearBegin && incomes[i].getDate().substr(4,2) > monthBegin)
             || (incomes[i].getDate().substr(0,4) == yearEnd && incomes[i].getDate().substr(4,2) == monthEnd
             && incomes[i].getDate().substr(6,2) <= dayEnd)
             || (incomes[i].getDate().substr(0,4) == yearEnd && incomes[i].getDate().substr(4,2) < monthEnd)
             || (incomes[i].getDate().substr(0,4) > yearBegin && incomes[i].getDate().substr(0,4) < yearEnd))

             incomesTemp.push_back(incomes[i]);
     }

     sort(incomesTemp.begin(), incomesTemp.end());
     totalIncome = calculateTotalIncome(incomesTemp);

     for (int j =0; j<incomesTemp.size(); j++)
     {
         cout << AuxiliaryMethods::dateToDispalyFormat(incomesTemp[j].getDate()) << " " ;
         cout << incomesTemp[j].getItem() << " ";
         cout << incomesTemp[j].getAmount() << endl;
     }

     cout << "Total income from selected dates: " << totalIncome << endl;

     return totalIncome;
}
