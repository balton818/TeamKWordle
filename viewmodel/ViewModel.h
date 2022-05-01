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
#include "../datatier/UserFileHandler.h"
using namespace datatier;

#include "PageType.h"
using namespace enums;

namespace viewmodel
{

class ViewModel
{
public:

    ViewModel();
    virtual ~ViewModel();

    void initializeGame(string& username);
    vector<GuessCheckerResult> checkGuess(string& guessToCheck);
    void loadUser();
    void saveUser();
    void startNewGame();
    void handleWin();
    void handleLoss();
    void updateSettings(bool hardModeEnabled, bool letterReuseEnabled);

    void displayPage(PageType pageType);
    vector<int> getCurrentUserStats();
    map<int, int> getGuessDistribution();

private:

    vector<Fl_Window*> gameWindows;

    const char* PAGE_TITLE = "Wordle by Alton, Wagner";
    int LOGIN_WINDOW_WIDTH = 400;
    int LOGIN_WINDOW_HEIGHT = 300;
    int GAME_WINDOW_WIDTH = 500;
    int GAME_WINDOW_HEIGHT = 700;
    int GAME_OVER_WINDOW_WIDTH = 500;
    int GAME_OVER_WINDOW_HEIGHT = 500;
    int SETTINGS_WINDOW_WIDTH = 300;
    int SETTINGS_WINDOW_HEIGHT = 200;

    map<string, User*> users;
    User* currentUser;
    DictionaryLoader* dictLoader;
    Dictionary* dictionary;
    UserFileHandler* fileHandler;
    Settings* gameSettings;
    GuessChecker guessChecker;
    string currentSolution;

    void createPages();

    bool userExists(string& username);

};
}
#endif // VIEWMODEL_H
