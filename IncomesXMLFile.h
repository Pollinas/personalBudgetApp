#ifndef INCOMESXMLFILE_H
#define INCOMESXMLFILE_H
#include <iostream>
#include <vector>
#include <cstdlib>
#include <string.h>
#include "Markup.h"
#include "Income.h"
#include "AuxiliaryMethods.h"
#include "XMLFile.h"


using namespace std;

class IncomesXMLFile : public XMLFile
{
    string incomesXMLFileName;
    int lastIncomeID;

   public:

       IncomesXMLFile(string incomesXMLFileNameParam)
       : XMLFile(incomesXMLFileNameParam), incomesXMLFileName(incomesXMLFileNameParam)
       {
           lastIncomeID = 0;
       };

    vector <Income> loadIncomesFromXMLFile();
    void addIncomeToXMLFile(Income income);
    int getLastIncomeID();


};


#endif
