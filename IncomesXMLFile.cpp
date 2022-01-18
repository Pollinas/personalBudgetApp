#include "IncomesXMLFile.h"

void IncomesXMLFile::addIncomeToXMLFile(Income income)
{
    string incomeID = AuxiliaryMethods::intToString(income.getIncomeID());
    string userID = AuxiliaryMethods::intToString(income.getUserID());
    string date = AuxiliaryMethods::dateToDispalyFormat(to_string(income.getDate()));
    string item = income.getItem();
    string amount = to_string(income.getAmount());
    amount.erase ( amount.find_last_not_of('0') + 1, string::npos );

    CMarkup xml;

    xml.Load(incomesXMLFileName+".xml");
    if (!XMLFileExists(incomesXMLFileName))
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Incomes");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Income");
    xml.IntoElem();
    xml.AddElem("IncomeID", incomeID);
    xml.AddElem("UserID", userID);
    xml.AddElem("Date", date);
    xml.AddElem("Item", item);
    xml.AddElem("Amount", amount);

    xml.Save(incomesXMLFileName+".xml");

}

int IncomesXMLFile::getLastIncomeID()
{
    CMarkup xml;
    int temp = 0;

    xml.Load(incomesXMLFileName+".xml");
    if (!XMLFileExists(incomesXMLFileName))
    {
        lastIncomeID = 0;
        return lastIncomeID;
    }

    xml.ResetPos();
    xml.FindElem();
    xml.IntoElem();

    while ( xml.FindElem("Income") )
    {
        xml.FindChildElem( "IncomeID" );
        if(stoi(xml.GetChildData()) > temp)
        {
            temp = stoi(xml.GetChildData());
            xml.ResetChildPos();
        }
    }

    lastIncomeID = temp;
    xml.Save(incomesXMLFileName+".xml");
    return lastIncomeID;

}

vector <Income> IncomesXMLFile::loadIncomesFromXMLFile()
{
    int incomeID = 0;
    int userID = 0;
    string date;
    string item;
    double amount;

    vector <Income> incomes;
    Income income;
    CMarkup xml;

    xml.Load(incomesXMLFileName+".xml");

    if (!XMLFileExists(incomesXMLFileName))
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Incomes");
    }

    xml.ResetPos();
    xml.FindElem();
    xml.IntoElem();

    while ( xml.FindElem("Income") )
    {
        xml.FindChildElem( "IncomeID" );
        incomeID = stoi(xml.GetChildData());
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

        income.setIncomeID(incomeID);
        income.setUserID(userID);
        income.setDate(stoi(AuxiliaryMethods::dateToStoreFormat(date)));
        income.setItem(item);
        income.setAmount(amount);
        incomes.push_back(income);

    }

    xml.Save(incomesXMLFileName+".xml");

    return incomes;
}
