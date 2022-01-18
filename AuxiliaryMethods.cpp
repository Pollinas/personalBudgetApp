#include"AuxiliaryMethods.h"

string AuxiliaryMethods::readLine()
{
    string line = "";
    getline(cin, line);
    return line;
}

char AuxiliaryMethods::readChar()
{
    string line= "";
    char sign  = {0};

    while (true)
    {
        getline(cin, line);

        if (line.length() == 1)
        {
            sign = line[0];
            break;
        }
        cout << "This is not a singular number. Try again." << endl;
    }
    return sign;
}

string AuxiliaryMethods::intToString (int number )
{
    std::ostringstream ss;
    ss << number;
   return ss.str();
}


string AuxiliaryMethods::getCurrentDate()
{
    string currentDate = "";
    time_t t = time(0);
    tm* now = localtime(&t);

    if ((now->tm_mon + 1)<10 && (now->tm_mday)<10)
        currentDate = to_string(now->tm_year + 1900) + "0" + to_string(now->tm_mon + 1) + "0" + to_string(now->tm_mday);

    else if((now->tm_mon + 1)<10)
        currentDate = to_string(now->tm_year + 1900) + "0" + to_string(now->tm_mon + 1) +  to_string(now->tm_mday);

    else if((now->tm_mday)<10)
        currentDate = to_string(now->tm_year + 1900) + to_string(now->tm_mon + 1) + "0" + to_string(now->tm_mday);

    else
        currentDate = to_string(now->tm_year + 1900) + to_string(now->tm_mon + 1) +  to_string(now->tm_mday);

    return currentDate;
}

string AuxiliaryMethods::commaToDot(string text)
{
    for (int i = 0; i<text.length(); i++)
    {
        if (text[i] == ',')
            text[i] = '.';
    }

    return text;
}

bool AuxiliaryMethods::checkDateCorrectness(string text)
{
    int day = atoi(text.substr(8,2).c_str());
    int month = atoi(text.substr(5,2).c_str());
    int year = atoi(text.substr(0,4).c_str());

    int currentYear = atoi(getCurrentDate().substr(0,4).c_str());
    int currentMonth =atoi(getCurrentDate().substr(4,2).c_str());
    int currentDay = atoi(getCurrentDate().substr(6,2).c_str());

    if (text.length()<10)
        return false;

    if (year<2000 || year > currentYear)
        return false;


    if (month > 12 || month < 0)
        return false;


    if(year == currentYear && month > currentMonth)
        return false;

    if (day<0 || day>getNumberOfDaysInAMonth(year,month))
        return false;

    if(year == currentYear && month == currentMonth && day > currentDay)
        return false;

    return true;
}

int AuxiliaryMethods::getNumberOfDaysInAMonth(int year, int month)
{
    if( month == 2)
	{
		if((year%400==0) || (year%4==0 && year%100!=0))
			return 29;
		else
			return 28;
	}

	else if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8
	||month == 10 || month==12)
		return 31;
	else
		return 30;
}

string AuxiliaryMethods::dateToDispalyFormat (string text)
{
    string dateToDisplay = "";

    dateToDisplay = text.substr(0,4) + "-" + text.substr(4,2) + "-" + text.substr(6,2);

    return dateToDisplay;
}

string AuxiliaryMethods::dateToStoreFormat (string text)
{
    string dateToStore = "";

    dateToStore = text.substr(0,4) + text.substr(5,2) + text.substr(8,2);

    return dateToStore;
}
