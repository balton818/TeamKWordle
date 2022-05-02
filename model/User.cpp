#include "User.h"

#include <string>
#include <map>
#include <iostream>
#include <sstream>
using namespace std;

namespace model
{
User::User(string username)
{
    this->username = username;
    this->currentWinStreak = 0;
    this->gamesPlayed = 0;
    this->gamesWon = 0;
    this->maxWinStreak = 0;
    this->createGuessDistribution();
    this->settings = new Settings();
}

User::User(string username, int gamesPlayed, int gamesWon, int currentStreak, int maxStreak, map<int, int> guessDistribution, Settings* settings)
{
    this->username = username;
    this->currentWinStreak = currentStreak;
    this->gamesPlayed = gamesPlayed;
    this->gamesWon = gamesWon;
    this->maxWinStreak = maxStreak;
    this->guessDistribution = guessDistribution;
    this->settings = settings;
}

User::~User()
{
    //dtor
}

void User::setUserName(const string& username)
{
    this->username = username;
}

void User::createGuessDistribution()
{
    int guessNumber = 1;
    while (guessNumber < 7)
    {
        this->guessDistribution.insert({guessNumber, 0});
        guessNumber++;
    }

}

int User::getWinPercentage()
{
    int oneHundred = 100;
    int winPercent = this->gamesWon*oneHundred / this->gamesPlayed * oneHundred;

    return winPercent / oneHundred;
}

int User::getCurrentStreak()
{
    return this->currentWinStreak;
}

int User::getGamesPlayed()
{
    return this->gamesPlayed;
}

int User::getGamesWon()
{
    return this->gamesWon;
}

int User::getMaxWinStreak()
{
    return this->maxWinStreak;
}

map<int,int> User::getGuessDistribution()
{
    return this->guessDistribution;
}

void User::updateStatsOnWin(int guesses)
{
    this->currentWinStreak++;
    this->gamesPlayed++;
    this->gamesWon++;

    if (this->currentWinStreak > this->maxWinStreak)
    {
        this->maxWinStreak = this->currentWinStreak;
    }

    this->guessDistribution[guesses] =  this->guessDistribution[guesses]++;
}

void User::updateStatsOnLoss()
{
    this->currentWinStreak = 0;
    this->gamesPlayed++;
}

string& User::getUsername()
{
    return this->username;
}

Settings* User::getSettings()
{
    return this->settings;
}

void User::changeSettings(Settings* settings)
{
    this->settings = settings;
}

string& User::userToString()
{
    stringstream ss;
    char comma = ',';
    int guessNumber = 1;
    ss << this->username << comma;
    ss << boolalpha << this->settings->getOnlyUniqueChars() << comma;
    ss << boolalpha << this->settings->getHardMode() << comma;
    ss << this->gamesPlayed << comma;
    ss << this->gamesWon << comma;
    ss << this->currentWinStreak << comma;
    ss << this->maxWinStreak << comma;
    int numberOfGuesses = 7;
    while (guessNumber < numberOfGuesses)
    {
        if (guessNumber == 6)
        {
            ss << this->guessDistribution[guessNumber];
        }
        else
        {
            ss << this->guessDistribution[guessNumber] << comma;
        }

        guessNumber++;
    }
    this->userAsText = ss.str();
    return this->userAsText;
}

}
