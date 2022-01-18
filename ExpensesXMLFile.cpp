#include "ExpensesXMLFile.h"


void ExpensesXMLFile::addExpenseToXMLFile(Expense expense)
{
    string expenseID = AuxiliaryMethods::intToString(expense.getExpenseID());
     string userID = AuxiliaryMethods::intToString(expense.getUserID());
     string date = AuxiliaryMethods::dateToDispalyFormat(to_string(expense.getDate()));
     string item = expense.getItem();
     string amount = to_string(expense.getAmount());
     CMarkup xml;

    xml.Load(expensesXMLFileName+".xml");
    if (!XMLFileExists(expensesXMLFileName))
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Expenses");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Expense");
    xml.IntoElem();
    xml.AddElem("ExpenseID", expenseID);
    xml.AddElem("UserID", userID);
    xml.AddElem("Date", date);
    xml.AddElem("Item", item);
    xml.AddElem("Amount", amount);

    xml.Save(expensesXMLFileName + ".xml");
}

int ExpensesXMLFile::getLastExpenseID()
{
    CMarkup xml;
    int temp = 0;

    xml.Load(expensesXMLFileName+".xml");
    if (!XMLFileExists(expensesXMLFileName))
    {
        lastExpenseID = 0;
        return lastExpenseID;
    }

    xml.ResetPos();
    xml.FindElem();
    xml.IntoElem();

    while ( xml.FindElem("Expense") )
{
    xml.FindChildElem( "Expense" );
    if(stoi(xml.GetChildData()) > temp)
    {
        temp = stoi(xml.GetChildData());
        xml.ResetChildPos();
    }

}
    lastExpenseID = temp;
   xml.Save(expensesXMLFileName+".xml");
   return lastExpenseID;

}

vector <Expense> ExpensesXMLFile::loadExpensesFromXMLFile()
{
    int expenseID = 0;
    int userID = 0;
    string date;
    string item;
    double amount;

    vector <Expense> expenses;
    Expense expense;
    CMarkup xml;

    xml.Load(expensesXMLFileName+".xml");
    if (!XMLFileExists(expensesXMLFileName))
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Expenses");
    }

    xml.ResetPos();
    xml.FindElem();
    xml.IntoElem();

    while ( xml.FindElem("Expense") )
{
    xml.FindChildElem( "ExpenseID" );
    expenseID = stoi(xml.GetChildData());
    xml.ResetChildPos();
    xml.FindChildElem( "UserID" );
    userID = stoi(xml.GetChildData());
    xml.ResetChildPos();
    xml.FindChildElem( "Date" );
    date = xml.GetChildData();
    xml.ResetChildPos();
    xml.FindChildElem( "Item" );
    item = xml.GetChildData();
    xml.ResetChildPos();
    xml.FindChildElem( "Amount" );
    amount = stod(xml.GetChildData());
    xml.ResetChildPos();

     expense.setExpenseID(expenseID);
     expense.setUserID(userID);
     expense.setDate(stoi(AuxiliaryMethods::dateToStoreFormat(date)));
     expense.setItem(item);
     expense.setAmount(amount);
     expenses.push_back(expense);

}

    xml.Save(expensesXMLFileName + ".xml");

    return expenses;
}
