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

    int usernameIndex = 0;
    int uniqueCharSettingIndex = 1;
    int hardModeSettingIndex = 2;
    int gamesPlayedIndex = 3;
    int gamesWonIndex = 4;
    int currentWinStreakIndex = 5;
    int maxWinStreakIndex = 6;
    int guessDistributionStartIndex = 7;
    int guessDistributionEndIndex = 12;

    User* currentUser;
    Settings* currentUserSettings;
    map<string, User*> users;
    string filename = "userData.wuf";

    void createUserFromData(vector<string> userData);
};

}

#endif // USERFILEHANDLER_H
