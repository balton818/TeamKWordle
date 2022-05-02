#include "UserFileHandler.h"

#include <iostream>

namespace datatier
{

UserFileHandler::UserFileHandler()
{
}

UserFileHandler::~UserFileHandler()
{

}

map<string, User*> UserFileHandler::loadUserData()
{
    string line;
    string word;
    ifstream inFile;
    vector<string> currentRowValues;

    inFile.open(this->filename);
    this->users.clear();

    if (inFile.is_open())
    {
        while (getline(inFile, line))
        {
            currentRowValues.clear();
            stringstream sstream(line);
            while(getline(sstream, word, ','))
            {
                currentRowValues.push_back(word);
            }
            this->createUserFromData(currentRowValues);
        }
        inFile.close();
    }
    return this->users;
}

void UserFileHandler::createUserFromData(vector<string> userData)
{
    if (userData.size() == this->guessDistributionEndIndex + 1)
    {
        string username = userData[this->usernameIndex];
        bool uniqueCharSetting = userData[this->uniqueCharSettingIndex] == "true";
        bool reuseCharSetting = userData[this->reuseCharSettingIndex] == "true";
        bool hardModeSetting = userData[this->hardModeSettingIndex] == "true";
        int gamesPlayed = stoi(userData[this->gamesPlayedIndex]);
        int gamesWon = stoi(userData[this->gamesWonIndex]);
        int currentStreak = stoi(userData[this->currentWinStreakIndex]);
        int maxStreak = stoi(userData[this->maxWinStreakIndex]);

        Settings* userSettings = new Settings();
        userSettings->setOnlyUniqueChars(uniqueCharSetting);
        userSettings->setPlayerReuseChars(reuseCharSetting);
        userSettings->setHardMode(hardModeSetting);

        map<int, int> guessDistribution;
        int counter = 1;
        for (int index = this->guessDistributionStartIndex; index <= this->guessDistributionEndIndex; index++)
        {
            guessDistribution.insert(pair<int,int>(counter, stoi(userData[index])));
            counter++;
        }

        User* currentUser = new User(username, gamesPlayed, gamesWon, currentStreak, maxStreak, guessDistribution, userSettings);
        this->users.insert(pair<string, User*>(username, currentUser));
    }
}


}


