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
