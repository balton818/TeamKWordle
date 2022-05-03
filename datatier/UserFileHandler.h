#ifndef USERFILEHANDLER_H
#define USERFILEHANDLER_H

#include <locale>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
using namespace std;

#include "User.h"
#include "Settings.h"
using namespace model;

namespace datatier
{

// User file handler class
//
// Author - Team K
//
class UserFileHandler
{

public:

    // Constructs a userfile handler for loading and saving users
    //
    UserFileHandler();

    // deconstructs a user file handler
    //
    virtual ~UserFileHandler();

    // loads user data into the wordle game
    //
    // Returns - map of usernames and user pointers
    //
    map<string, User*> loadUserData();

    // saves users to file
    //
    // Param - output the string of user data to save
    //
    void saveUsersToFile(string& output);

private:

    map<string, User*> users;
    string filename = "userData.wuf";

    void createUserFromData(vector<string> userData);
    void deleteAllUsers();
};

}

#endif // USERFILEHANDLER_H
