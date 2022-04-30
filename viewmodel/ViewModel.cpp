#define EZMODE 0 //change to 1 to show answer in terminal

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
}

ViewModel::~ViewModel()
{
    delete this->dictLoader;
    delete this->fileHandler;
}

void ViewModel::initializeGame(string& username)
{
    this->dictionary = this->dictLoader->readDictionaryFile();
    this->currentSolution = this->dictionary->getWordToGuess(true);
#if EZMODE == 1 //EZMODE value assigned on first line of file
    cout << "Wordle answer: " << this->currentSolution << endl;
#endif // EZMODE

    if (!this->users.count(username))
    {
        this->users.insert(pair<string, User*>(username, new User(username)));
    }

    this->currentUser = this->users[username];
    this->gameSettings = this->currentUser->getSettings();
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
        cout << guessToCheck << endl;
        result = this->guessChecker.checkGuess(guessToCheck);
        return result;

    }
    return {};
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
