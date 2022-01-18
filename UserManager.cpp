#include "UserManager.h"

void UserManager::signUp()
{
    User user = insertNewUserData();

    users.push_back(user);

    usersXMLFile.addUserToXMLFile(user);

    cout << endl << "Account created." << endl << endl;
    system("pause");
}

User UserManager::insertNewUserData()
{
     User user;

    user.setID(getNewUserID());

    string login;

    do
    {
        cout <<"Insert login: " << endl;
        login = AuxiliaryMethods::readLine();
        user.setLogin(login);

    }

    while (loginExists(user.getLogin()));

    string password;
    cout << "Insert password: " << endl;
    password = AuxiliaryMethods::readLine();

    user.setPassword(password);

    string name;
    cout << "Insert name." << endl;
    name = AuxiliaryMethods::readLine();

    user.setName(AuxiliaryMethods::convertFirstLetterToUpperCaseTheRestToLower(name));

    string lastName;
    cout << "Insert last name." << endl;
    lastName = AuxiliaryMethods::readLine();

    user.setLastName(AuxiliaryMethods::convertFirstLetterToUpperCaseTheRestToLower(lastName));

    return user;
}

int UserManager::logIn()
{
    User user;

    string login = "";
    string password = "";

    cout << endl << "Insert login: ";
    login = AuxiliaryMethods::readLine();

    vector <User>::iterator itr =users.begin();
    while(itr!=users.end())
    {
        if (itr->getLogin() == login)
        {

            for (int numberOfAttempts = 3; numberOfAttempts > 0; numberOfAttempts--)
            {
                cout << "Insert password. Number of attempts left: " << numberOfAttempts << ": ";
                password = AuxiliaryMethods::readLine();

                if (itr->getPassword() == password)
                {
                    cout << endl << "You are logged in." << endl << endl;
                    loggedUserID = itr->getID();
                    system("pause");
                    return loggedUserID;

                }

            }
            cout << "You have inserted incorrect password 3 times." << endl;
            system("pause");
            return 0;
        }
        itr++;
    }
    cout << "There is no user with such login." << endl << endl;
    system("pause");
    return 0;
}

int UserManager::logOut()
{
    loggedUserID = 0;
}

void UserManager::changePassword()
{
    string newPassword = "";
    cout << "Insert new password: ";
    newPassword = AuxiliaryMethods::readLine();

    for (int i =0; i<users.size(); i++)
    {
        if (users[i].getID() == loggedUserID)
        {
            users[i].setPassword(newPassword);
            cout << "Password has been changed." << endl << endl;
            system("pause");
        }
    }
    usersXMLFile.changeLoggedUserPasswordInXMLFile(newPassword,loggedUserID);
}

int UserManager::getLoggedUserID()
{
    return loggedUserID;
}

int UserManager::getNewUserID()
{
    if (users.empty())
        return 1;
    else
        return users.back().getID() + 1;
}

bool UserManager::loginExists(string login)
{
    for (int i =0; i < users.size(); i++)
    {

        if (users[i].getLogin() == login)
        {
            cout << endl << "User with such login already exists." << endl;
            return true;
        }

    }
    return false;

}
