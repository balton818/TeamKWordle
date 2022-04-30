#define EZMODE 1
 //change to 1 to show answer in terminal

#include "../model/User.h"
#include "../model/Dictionary.h"
#include "../model/Settings.h"
#include "../model/GuessChecker.h"
using namespace model;

#include <iostream>
#include<string>
using namespace std;

#include "ViewModel.h"
namespace viewmodel
{

ViewModel::ViewModel()
{
    this->dictLoader = new DictionaryLoader();
    this->fileHandler = new UserFileHandler();
    this->users = this->fileHandler->loadUserData();
    this->gameSettings = nullptr;
}

ViewModel::~ViewModel()
{
    delete this->dictLoader;
    delete this->fileHandler;
}

void ViewModel::initializeGame(string& username)
{
    if (!this->users.count(username))
    {
        this->users.insert(pair<string, User*>(username, new User(username)));
    }

    this->currentUser = this->users[username];
    cout << "Current player: " << this->currentUser->getUsername() << endl;

    if (this->gameSettings == nullptr)
    {
        this->gameSettings = this->currentUser->getSettings();
    }

    this->dictionary = this->dictLoader->readDictionaryFile();
    this->currentSolution = this->dictionary->getWordToGuess(this->gameSettings->getOnlyUniqueChars());

#if EZMODE == 1 //EZMODE value assigned on first line of file
    cout << "Wordle answer: " << this->currentSolution << endl;
#endif // EZMODE

    cout << "Hard: " << this->gameSettings->getHardMode() << endl;
    cout << "Unique: " << this->gameSettings->getOnlyUniqueChars() << endl;
    this->guessChecker.setAnswerCharRates(this->dictionary->getCharRates());
    this->guessChecker.setAnswer(this->currentSolution);
}

bool ViewModel::userExists(string& username)
{
    return this->users[username] == nullptr;
}

vector<GuessCheckerResult> ViewModel::checkGuess(string& guessToCheck)
{
    vector<GuessCheckerResult> result;
    if (this->dictionary->isValidWord(guessToCheck))
    {
        cout << "Your last guess: " << guessToCheck << endl;
        result = this->guessChecker.checkGuess(guessToCheck);
        return result;

    }
    return {};
}

void ViewModel::updateSettings(bool hardModeEnabled, bool letterReuseEnabled)
{
    delete this->gameSettings;
    Settings* newSettings = new Settings();
    newSettings->setHardMode(hardModeEnabled);
    newSettings->setOnlyUniqueChars(!letterReuseEnabled);
    this->gameSettings = newSettings;
}

string& ViewModel::getStats()
{

}

void ViewModel::saveUser()
{

}
void ViewModel::startNewGame()
{

}

void ViewModel::handleWin()
{

}

void ViewModel::handleLoss()
{

}
}
