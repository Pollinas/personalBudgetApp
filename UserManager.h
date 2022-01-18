#ifndef USERMANAGER_H
#define USERMANAGER_H
#include <iostream>
#include <vector>

#include"User.h"
#include"AuxiliaryMethods.h"
#include"UsersXMLFile.h"

using namespace std;

class UserManager
{
    vector <User> users;
    int loggedUserID;
    UsersXMLFile usersXMLFile;

    User insertNewUserData();
    int getNewUserID();
    bool loginExists(string login);

public:
    UserManager(string usersXMLFileName) : usersXMLFile (usersXMLFileName)
    {
        loggedUserID = 0;
        users = usersXMLFile.loadUsersFromXMLFile();
    }
    void signUp();
    int logIn();
    int logOut();
    void changePassword();
    int getLoggedUserID();
};

#endif
