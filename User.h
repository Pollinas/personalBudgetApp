#ifndef USER_H
#define USER_H
#include <iostream>


using namespace std;

class User
{

    string login;
    string password;
    int ID;
    string name;
    string lastName;

public:


    string getLogin();
    string getPassword();
    int getID();
    string getName();
    string getLastName();

    void setLogin(string newLogin);
    void setPassword(string newPassword);
    void setID (int newID);
    void setName (string newName);
    void setLastName ( string newLastName);
};


#endif
