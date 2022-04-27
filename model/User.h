#ifndef USER_H
#define USER_H

#include <string>
#include <map>
using namespace std;

namespace model
{

// The user class for the Wordle game
//
// Author - Teamk K
//
class User
{
    public:
        // Constructor for the user object
        //
        User();

        // user deconstructor
        //
        virtual ~User();

        // Calculates the users win percentage
        //
        // Returns - the players win percentage
        //
        double getWinPercentage();

        // Gets the total games played by the player
        //
        // Returns - the games played by the user
        //
        int getGamesPlayed();

        // Gets the games won by the player
        //
        // Returns - the total games won by the player
        //
        int getGamesWon();

        // Gets the players current win streak
        //
        // Returns - the players current streak of wins
        //
        int getCurrentStreak();

        // Gets the players max win streak
        //
        // Returns - the max concurrent wins for the player
        //
        int getMaxWinStreak();

        // Gets the players guess distribution
        //
        // Returns - a map that shows the users guess distribution (i.e rate of 1 guess to win, 2 guesses to win/ etc)
        //
        map<int, int> getGuessDistribution();

        // Updates the player stats on win
        //
        // Param - guesses the number of guesses used to win
        //
        void updateStatsOnWin(int guesses);

        // Updates the player stats on loss
        //
        void updateStatsOnLoss();

        // sets user name for the user
        //
        // Param - the desired username
        //
        void setUserName(const string& username);


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
