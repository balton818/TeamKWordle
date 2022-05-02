#ifndef VIEWMODEL_H
#define VIEWMODEL_H

#include "Constants.h"
using namespace constants;

#include "User.h"
#include "Dictionary.h"
#include "Settings.h"
#include "GuessChecker.h"
using namespace model;

#include<string>
using namespace std;

#include "DictionaryLoader.h"
#include "UserFileHandler.h"
using namespace datatier;

#include "PageType.h"
using namespace enums;

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
    // param - The amount of guesses the user needed to solve
    //
    void handleWin(int guessesUsed);

    // handles changes on loss
    //
    void handleLoss();

    // Sets the settings for the SettingsWindow
    // to those currently associated with the specified user
    // param - the user
    //
    void setSettings(string& username);

    // updates the settings when changed
    //
    void updateSettings(bool hardModeEnabled, bool letterReuseEnabled);

    // displays the desired page
    //
    // param - the page type to be displayed
    //
    void displayPage(PageType pageType);

    // gets the current user stats
    //
    // returns - vector of the current user stats
    //
    vector<int> getCurrentUserStats();

    // gets the current users guess distribution
    //
    // Returns - a map of the users guess distribution
    //
    map<int, int> getGuessDistribution();

private:

    vector<Fl_Window*> gameWindows;

    const char* pageTitle = "Wordle by Alton, Wagner";

    map<string, User*> users;
    User* currentUser;
    DictionaryLoader* dictLoader;
    Dictionary* dictionary;
    UserFileHandler* fileHandler;
    Settings* gameSettings;
    GuessChecker guessChecker;
    string currentSolution;

    void createPages();
    void getAndSetAnswer();

    bool userExists(string& username);

};

}

#endif // VIEWMODEL_H
