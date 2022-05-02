#define EZMODE 1 //change to 1 to show answer in terminal

#include "UserSelectionWindow.h"
#include "SettingsWindow.h"
#include "GameWindow.h"
#include "GameOverWindow.h"
using namespace view;

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
    this->createPages();

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

void ViewModel::createPages()
{
    UserSelectionWindow* loginPage = new UserSelectionWindow(this->LOGIN_WINDOW_WIDTH, this->LOGIN_WINDOW_HEIGHT, this->PAGE_TITLE, this);
    GameWindow* gamePage = new GameWindow(this->GAME_WINDOW_WIDTH, this->GAME_WINDOW_HEIGHT, this->PAGE_TITLE, this);
    SettingsWindow* settingsPage = new SettingsWindow(this->SETTINGS_WINDOW_WIDTH, this->SETTINGS_WINDOW_HEIGHT, this->PAGE_TITLE, this);

    this->gameWindows.push_back(loginPage);
    this->gameWindows.push_back(settingsPage);
    this->gameWindows.push_back(gamePage);
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
    this->getAndSetAnswer();
}

void ViewModel::getAndSetAnswer()
{
    this->currentSolution = this->dictionary->getWordToGuess(this->gameSettings->getOnlyUniqueChars());

#if EZMODE == 1 //EZMODE value assigned on first line of this file
    cout << "Wordle answer: " << this->currentSolution << endl;
#endif // EZMODE

    this->guessChecker.setAnswerCharRates(this->dictionary->getAnswerCharRates());
    this->guessChecker.setAnswer(this->currentSolution);
}
void ViewModel::displayPage(PageType pageType)
{
    this->gameWindows[pageType]->show();
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

void ViewModel::saveUser()
{

}

void ViewModel::startNewGame()
{
    this->gameWindows.clear();
    this->createPages();
    this->getAndSetAnswer();


}

void ViewModel::handleWin(int guessesUsed)
{
    this->currentUser->updateStatsOnWin(guessesUsed);
    GameOverWindow* gameOverPage = new GameOverWindow(this->GAME_OVER_WINDOW_WIDTH, this->GAME_OVER_WINDOW_HEIGHT, this->PAGE_TITLE, this);
    this->gameWindows.push_back(gameOverPage);
    this->displayPage(PageType::GAME_OVER_PAGE);

}

vector<int> ViewModel::getCurrentUserStats()
{
    vector<int> stats;
    stats.push_back(this->currentUser->getGamesPlayed());
    stats.push_back((int)this->currentUser->getWinPercentage());
    stats.push_back(this->currentUser->getCurrentStreak());
    stats.push_back(this->currentUser->getMaxWinStreak());

    return stats;
}

map<int, int> ViewModel::getGuessDistribution()
{
    return this->currentUser->getGuessDistribution();
}

void ViewModel::handleLoss()
{
    this->currentUser->updateStatsOnLoss();
    GameOverWindow* gameOverPage = new GameOverWindow(this->GAME_OVER_WINDOW_WIDTH, this->GAME_OVER_WINDOW_HEIGHT, this->PAGE_TITLE, this);
    this->gameWindows.push_back(gameOverPage);
    this->displayPage(PageType::GAME_OVER_PAGE);
}
}
