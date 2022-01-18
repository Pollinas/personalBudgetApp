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

string User::getName()
{
    return name;
}

string User::getLastName()
{
    return lastName;
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

void User::setName (string newName)
{
    name = newName;
}

void User::setLastName (string newLastName)
{
    lastName = newLastName;
}
