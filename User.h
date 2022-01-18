#ifndef USER_H
#define USER_H
#include <iostream>


using namespace std;

class User
{

    string login;
    string password;
    int ID;

public:


    string getLogin();
    string getPassword();
    int getID();

    void setLogin(string newLogin);
    void setPassword(string newPassword);
    void setID (int newID);
};


#endif
