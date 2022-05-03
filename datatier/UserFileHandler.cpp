#include "UserFileHandler.h"

#include <iostream>

#include "Constants.h"
using namespace constants;

namespace datatier
{

UserFileHandler::UserFileHandler()
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
    if (userData.size() == Constants::USER_FILE_GUESS_DISTRIBUTION_END_INDEX + 1)
    {
        string username = userData[Constants::USER_FILE_USERNAME_INDEX];
        bool uniqueCharSetting = userData[Constants::USER_FILE_UNIQUE_CHAR_SETTING_INDEX] == "true";
        bool hardModeSetting = userData[Constants::USER_FILE_HARD_MODE_INDEX] == "true";
        int gamesPlayed = stoi(userData[Constants::USER_FILE_GAMES_PLAYED_INDEX]);
        int gamesWon = stoi(userData[Constants::USER_FILE_GAMES_WON_INDEX]);
        int currentStreak = stoi(userData[Constants::USER_FILE_CURRENT_WIN_STREAK_INDEX]);
        int maxStreak = stoi(userData[Constants::USER_FILE_MAX_WIN_STREAK_INDEX]);

        Settings* userSettings = new Settings();
        userSettings->setOnlyUniqueChars(uniqueCharSetting);
        userSettings->setHardMode(hardModeSetting);

        map<int, int> guessDistribution;
        int counter = 1;
        for (int index = Constants::USER_FILE_GUESS_DISTRIBUTION_START_INDEX; index <= Constants::USER_FILE_GUESS_DISTRIBUTION_END_INDEX; index++)
        {
            guessDistribution.insert(pair<int,int>(counter, stoi(userData[index])));
            counter++;
        }

        User* currentUser = new User(username, gamesPlayed, gamesWon, currentStreak, maxStreak, guessDistribution, userSettings);
        this->users.insert(pair<string, User*>(username, currentUser));
    }
}

void UserFileHandler::saveUsersToFile(string& output)
{
    fstream file;
    file.open(this->filename, fstream::out);
    file << output;
    file.close();
}

void UserFileHandler::deleteAllUsers()
{
    for (auto itr = this->users.begin(); itr != this->users.end(); ++itr)
    {
        pair<string, User*> currentPair = *itr;
        User* user = currentPair.second;
        delete user;
    }
}

UserFileHandler::~UserFileHandler()
{
    this->deleteAllUsers();
}

}


