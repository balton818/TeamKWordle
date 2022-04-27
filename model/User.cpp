#include "User.h"

#include <string>
#include <map>
using namespace std;

namespace model
{
User::User()
{
    this->currentWinStreak = 0;
    this->gamesPlayed = 0;
    this->gamesWon = 0;
    this->maxWinStreak = 0;
    this->createGuessDistribution();
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
    while (guessNumber < 7){
        this->guessDistribution.insert({guessNumber, 0});
        guessNumber++;
    }

}

double User::getWinPercentage()
{
    int oneHundred = 100;
    int winPercent = this->gamesWon / this->gamesPlayed;
    return winPercent * oneHundred;

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
    this->guessDistribution[guesses]++;
}
}
