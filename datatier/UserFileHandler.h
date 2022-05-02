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
class UserFileHandler
{
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

public:
    UserFileHandler();
    virtual ~UserFileHandler();
    map<string, User*> loadUserData();
    void saveUsersToFile(string& output);
};
}


#endif // USERFILEHANDLER_H
