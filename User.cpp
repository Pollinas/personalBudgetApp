#include "User.h"

string User::getLogin()
{
    return login;
}

string User::getPassword()
{
    return password;
}

int User::getID()
{
    return ID;
}


void User::setLogin(string newLogin)
{
    login = newLogin;
}

void User::setPassword(string newPassword)
{
    password = newPassword;
}

void User::setID (int newID)
{
     if (newID>=0)
            ID = newID;
}
