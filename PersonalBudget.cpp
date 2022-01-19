#include "PersonalBudget.h"

void PersonalBudget::displayRegistrationMenu()
{
    char choice;

    system("cls");
    cout << "    >>> MAIN MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Sign up" << endl;
    cout << "2. Log in" << endl;
    cout << "9. Exit" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";

    choice = AuxiliaryMethods::readChar();

    if (choice == '1')
    {
        signUp();
        displayRegistrationMenu();
    }

    else if (choice == '2')
    {
        logIn();
        displayUsersMenu();
    }

    else if (choice == '9')
        exit(0);
    else
        cout<< "Please choose on of the available options."<< endl;

}

void PersonalBudget::displayUsersMenu()
{

    if (isUserLoggedIn())
    {
        char choice;

        system("cls");
        cout << " >>> USER'S MENU <<<" << endl;
        cout << "---------------------------" << endl;
        cout << "1. Add income." << endl;
        cout << "2. Add expense." << endl;
        cout << "3. Display this month's balance." << endl;
        cout << "4. Display last month's balance." << endl;
        cout << "5. Display balance from selected dates. " << endl;
        cout << "---------------------------" << endl;
        cout << "6. Change password." << endl;
        cout << "7. Log out." << endl;
        cout << "---------------------------" << endl;
        cout << "You choice: ";
        choice = AuxiliaryMethods::readChar();

        if(choice == '1')
        {
            addIncome();
            displayUsersMenu();
        }
        else if(choice == '2')
        {
            addExpense();
            displayUsersMenu();
        }
        else if(choice == '3')
        {
            displayThisMonthBalance();
            displayUsersMenu();
        }
        else if(choice == '4')
        {
            displayLastMonthBalance();
            displayUsersMenu();
        }
        else if(choice == '5')
        {
            displayBalanceFromSelectedTime();
            displayUsersMenu();
        }
        else if(choice == '6')
        {
            changePassword();
            displayUsersMenu();
        }
        else if(choice == '7')
        {
            logOut();
            displayRegistrationMenu();
        }

        else
            cout<< "Please choose one of the available options."<< endl;

    }

    else
    {
        cout << "To display user's menu you need to log in first." << endl;
        system("pause");
    }
}

void PersonalBudget::signUp()
{
    userManager.signUp();
}

void PersonalBudget::logIn()
{
    userManager.logIn();
    if (isUserLoggedIn())
    {
        incomeManager = new IncomeManager(incomesXMLFileName, getLoggedUserID());
        expenseManager = new ExpenseManager(expensesXMLFileName, getLoggedUserID());
    }
}

void PersonalBudget::changePassword()
{
    userManager.changePassword();
}

void PersonalBudget::logOut()
{
    userManager.logOut();
    delete incomeManager;
    incomeManager = NULL;
    delete expenseManager;
    expenseManager = NULL;
}

int PersonalBudget::getLoggedUserID()
{
    userManager.getLoggedUserID();
}

bool PersonalBudget::isUserLoggedIn()
{
    return (userManager.getLoggedUserID() > 0);
}

void PersonalBudget::addIncome()
{
     if (isUserLoggedIn())
    {
        incomeManager->addIncome();
    }
    else
    {
        cout<< "To add an income you need to log in first." <<endl;
        system("pause");
    }
}

void PersonalBudget::addExpense()
{
     if (isUserLoggedIn())
    {
        expenseManager->addExpense();
    }
    else
    {
        cout<< "To add an expense you need to log in first." <<endl;
        system("pause");
    }
}


void PersonalBudget::displayThisMonthBalance()
{
    if (isUserLoggedIn())
    {
        double incomesSum = 0.0;
        double expensesSum = 0.0;
        cout << endl;
        incomesSum = incomeManager-> displayThisMonthIncomes();
        cout <<endl;
        expensesSum = expenseManager->displayThisMonthExpenses();
        cout << endl;
        cout << endl <<  "This month balance: " << (incomesSum-expensesSum) << endl;
        system("pause");
    }
    else
    {
        cout<< "To display this month's balance you need to log in first." <<endl;
        system("pause");
    }

}

void PersonalBudget::displayLastMonthBalance()
{

    if (isUserLoggedIn())
    {
        double incomesSum = 0.0;
        double expensesSum = 0.0;

        cout << endl;
        incomesSum = incomeManager-> displayLastMonthIncomeBalance();
        cout << endl;
        expensesSum = expenseManager->displayLastMonthExpenseBalance();
        cout << endl;
        cout << endl << "Last month balance: " << (incomesSum-expensesSum) << endl;
        system("pause");
    }
    else
    {
        cout<< "To display last month's balance you need to log in first." <<endl;
        system("pause");
    }
}

void PersonalBudget::displayBalanceFromSelectedTime()
{

    if (isUserLoggedIn())
    {
        string dateBegin = "";
        string dateEnd = "";
        string temp = "";

        cout << "Insert beginning date in yyyy-mm-dd format. " << endl;
        temp = AuxiliaryMethods::readLine();
         if (AuxiliaryMethods::checkDateCorrectness(temp))
            {
             dateBegin = temp;
            }

        while (AuxiliaryMethods::checkDateCorrectness(temp) == false)
        {
            cout << "Incorrect date or date format. Insert date in yyyy-mm-dd format. " << endl;
            temp = AuxiliaryMethods::readLine();
            if (AuxiliaryMethods::checkDateCorrectness(temp))
            {
                 dateBegin = temp;
                 break;
            }
        }

        temp ="";

        cout << "Insert ending date in yyyy-mm-dd format. " << endl;
        temp = AuxiliaryMethods::readLine();

        if (AuxiliaryMethods::checkDateCorrectness(temp))
            {
             dateEnd = temp;
            }


         while (AuxiliaryMethods::checkDateCorrectness(temp) == false)
        {
            cout << "Incorrect date or date format. Insert date in yyyy-mm-dd format. " << endl;
            temp = AuxiliaryMethods::readLine();
            if (AuxiliaryMethods::checkDateCorrectness(temp))
            {
                 dateEnd = temp;
                 break;
            }
        }

        temp = "";

        while (stoi(dateEnd) < stoi(dateBegin))
        {
            dateEnd = "";
            cout << "Error. The ending date cannot be earlier than the beginning date." << endl;
            cout << "Insert ending date in yyyy-mm-dd format. " << endl;
            temp = AuxiliaryMethods::readLine();

            if (AuxiliaryMethods::checkDateCorrectness(temp))
            {
               dateEnd = temp;
               if (stoi(dateEnd) >= stoi(dateBegin))
                    break;
            }

            while (AuxiliaryMethods::checkDateCorrectness(temp) == false)
           {
            cout << "Incorrect date or date format. Insert date in yyyy-mm-dd format. " << endl;
            temp = AuxiliaryMethods::readLine();

                if (AuxiliaryMethods::checkDateCorrectness(temp))
                {
                 dateEnd = temp;
                 if (stoi(dateEnd) >= stoi(dateBegin))
                    break;
                }
           }
        }


        double incomesSum = 0.0;
        double expensesSum = 0.0;

        cout<<endl;
        incomesSum = incomeManager-> displayIncomeBalanceFromSelectedDates(dateBegin, dateEnd);
        cout << endl;
        expensesSum = expenseManager-> displayExpenseBalanceFromSelectedDates(dateBegin, dateEnd);
        cout << endl;
        cout << endl << "Balance from " << dateBegin << " to " << dateEnd << " : " << (incomesSum-expensesSum) << endl;
        system("pause");
    }
    else
    {
        cout<< "To display balance from selected dates you need to log in first." <<endl;
        system("pause");
    }

}
