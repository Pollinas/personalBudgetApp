#include <iostream>
#include"PersonalBudget.h"
#include <ctime>
#include<string>
using namespace std;

int main()
{
    PersonalBudget personalBudget("users", "incomes", "expenses");
    personalBudget.displayRegistrationMenu();

    return 0;

}
