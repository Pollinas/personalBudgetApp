#ifndef USERSXMLFILE_H
#define USERSXMLFILE_H
#include <iostream>
#include <vector>
#include<cstdlib>
#include "Markup.h"

#include"User.h"
#include"XMLFile.h"
#include"AuxiliaryMethods.h"
using namespace std;

class UsersXMLFile : public XMLFile
{
   string usersXMLFileName;

   public:
       UsersXMLFile(string usersXMLFileNameParam)
       : XMLFile (usersXMLFileNameParam), usersXMLFileName(usersXMLFileNameParam){};

    vector <User> loadUsersFromXMLFile();
    void addUserToXMLFile(User user);
    void changeLoggedUserPasswordInXMLFile(string newPassword, int loggedUserID);

};


#endif
