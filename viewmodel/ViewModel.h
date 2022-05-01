#ifndef VIEWMODEL_H
#define VIEWMODEL_H

#include "../model/User.h"
#include "../model/Dictionary.h"
#include "../model/Settings.h"
#include "../model/GuessChecker.h"
using namespace model;

#include<string>
using namespace std;

#include "../datatier/DictionaryLoader.h"
using namespace datatier;

namespace viewmodel
{

// the view model class for the wordle game
//
// Author - Team K
//
class ViewModel
{
    public:

        // create a view model object
        //
        ViewModel();

        // deconstructs a view model object
        //
        virtual ~ViewModel();

        // initializes the world game
        //
        // Param - the username for the user playing
        //
        void initializeGame(string& username);

        // Checks the user inputted guess with a Guess Checker
        //
        // Param - guesToCheck - the user's guess
        //
        vector<GuessCheckerResult> checkGuess(string& guessToCheck);

        // gets the current stats
        //
        // Returns - the current stats as a string
        //
        string& getStats();

        // Loads a user for the game
        //
        void loadUser();

        // Saves a user
        //
        void saveUser();

        // starts a new game
        //
        void startNewGame();

        // handles changes when a user wins
        //
        void handleWin();

        // handles changes on loss
        //
        void handleLoss();



    private:
        User currentUser;
        DictionaryLoader* dictLoader;
        Dictionary* dictionary;
        Settings gameSettings;
        GuessChecker guessChecker;
        string currentSolution;

};
}
#endif // VIEWMODEL_H
