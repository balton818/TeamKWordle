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
        int reuseCharSettingIndex = 2;
        int hardModeSettingIndex = 3;
        int gamesPlayedIndex = 4;
        int gamesWonIndex = 5;
        int currentWinStreakIndex = 6;
        int maxWinStreakIndex = 7;
        int guessDistributionStartIndex = 8;
        int guessDistributionEndIndex = 13;

        User* currentUser;
        Settings* currentUserSettings;
        map<string, User*> users;
        string filename = "userData.wuf";

        void createUserFromData(vector<string> userData);

    public:
        UserFileHandler();
        virtual ~UserFileHandler();
        map<string, User*> loadUserData();
};
}


#endif // USERFILEHANDLER_H
