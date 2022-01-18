#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H
#include <iostream>
#include <sstream>
#include <ctime>
#include <algorithm>
#include <string>

using namespace std;

class AuxiliaryMethods
{

public:

    static string commaToDot(string text);
    static string getCurrentDate();
    static int getNumberOfDaysInAMonth(int year, int month);
    static bool checkDateCorrectness(string text);
    static string dateToDispalyFormat (string text);
    static string dateToStoreFormat (string text);
    static char readChar();
    static string readLine();
    static string intToString (int number);

};



#endif
