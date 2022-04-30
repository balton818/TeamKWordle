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

namespace viewmodel
{

class ViewModel
{
public:
    ViewModel();
    virtual ~ViewModel();
    void initializeGame(string& username);
    vector<GuessCheckerResult> checkGuess(string& guessToCheck);
    string& getStats();
    void loadUser();
    void saveUser();
    void startNewGame();
    void handleWin();
    void handleLoss();
    void updateSettings(bool hardModeEnabled, bool letterReuseEnabled);



private:
    map<string, User*> users;
    User* currentUser;
    DictionaryLoader* dictLoader;
    Dictionary* dictionary;
    UserFileHandler* fileHandler;
    Settings* gameSettings;
    GuessChecker guessChecker;
    string currentSolution;


    bool userExists(string& username);

};
}
#endif // VIEWMODEL_H
