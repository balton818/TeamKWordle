#ifndef USER_H
#define USER_H

#include <string>
#include <map>
using namespace std;

namespace model
{
class User
{
    public:
        User(const string& username);
        virtual ~User();
        double getWinPercentage();
        int getGamesPlayed();
        int getGamesWon();
        int getCurrentStreak();
        int getMaxWinStreak();
        map<int, int> getGuessDistribution();
        void updateStatsOnWin(int guesses);
        void updateStatsOnLoss();


    private:
        string username;
        int gamesPlayed;
        int gamesWon;
        int currentWinStreak;
        int maxWinStreak;
        map<int, int> guessDistribution;
        void createGuessDistribution();


};
}

#endif // USER_H
