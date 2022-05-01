#include "../model/User.h"
#include "../model/Dictionary.h"
#include "../model/Settings.h"
#include "../model/GuessChecker.h"
using namespace model;

#include <iostream>
#include<string>
using namespace std;

#include "../datatier/DictionaryLoader.h"
using namespace datatier;

#include "ViewModel.h"
namespace viewmodel
{

ViewModel::ViewModel()
{
    this->dictLoader = new DictionaryLoader();
}

ViewModel::~ViewModel()
{
    delete this->dictLoader;

}

void ViewModel::initializeGame(string& username)
{
    this->dictionary = this->dictLoader->readDictionaryFile();
    this->currentSolution = this->dictionary->getWordToGuess(true);
    cout << "Wordle answer: " << this->currentSolution << endl;
    this->currentUser.setUserName(username);
    this->guessChecker.setAnswerCharRates(this->dictionary->getAnswerCharRates());
    this->guessChecker.setAnswer(this->currentSolution);

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

void ViewModel::loadUser()
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
