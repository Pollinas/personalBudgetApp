#include"UsersXMLFile.h"

 void UsersXMLFile::addUserToXMLFile(User user)
 {
     string ID = AuxiliaryMethods::intToString(user.getID());
     string login = user.getLogin();
     string password = user.getPassword();
     CMarkup xml;

    xml.Load(usersXMLFileName+".xml");
    if (!XMLFileExists(usersXMLFileName))
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("UserID", ID);
    xml.AddElem("Login", login);
    xml.AddElem("Password", password);

    xml.Save(usersXMLFileName+".xml");

 }

 vector <User> UsersXMLFile::loadUsersFromXMLFile()
 {
    int id=0;
    string login="", password="";
    vector <User> users;
    User user;
    CMarkup xml;

    xml.Load(usersXMLFileName+".xml");

    if (!XMLFileExists(usersXMLFileName))
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }

    xml.ResetPos();
    xml.FindElem();
    xml.IntoElem();

    while ( xml.FindElem("User") )
{
    xml.FindChildElem( "UserID" );
    id = stoi(xml.GetChildData());
    xml.ResetChildPos();
    xml.FindChildElem( "Login" );
    login = xml.GetChildData();
    xml.ResetChildPos();
    xml.FindChildElem( "Password" );
    password = xml.GetChildData();
    //xml.ResetChildPos();

     user.setID(id);
     user.setLogin(login);
     user.setPassword(password);
     users.push_back(user);
}

   xml.Save(usersXMLFileName+".xml");

    return users;
 }


 void UsersXMLFile::changeLoggedUserPasswordInXMLFile(string newPassword,int loggedUserID)
 {
    CMarkup xml;

    xml.Load(usersXMLFileName+".xml");
    if (!XMLFileExists(usersXMLFileName))
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }

    xml.ResetPos();
    xml.FindElem();
    xml.IntoElem();

    while ( xml.FindElem("User") )
{
    xml.FindChildElem( "UserID" );
    if(stoi(xml.GetChildData()) == loggedUserID)
    {
        xml.ResetChildPos();
        xml.FindChildElem( "Password" );
        xml.RemoveChildElem();
        xml.AddChildElem("Password", newPassword);
    }

}

   xml.Save(usersXMLFileName+".xml");
 }
