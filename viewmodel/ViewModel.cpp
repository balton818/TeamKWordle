#define EZMODE 1 //change to 1 to show answer in terminal

#include "UserSelectionWindow.h"
#include "SettingsWindow.h"
#include "GameWindow.h"
#include "GameOverWindow.h"
using namespace view;

#include "User.h"
#include "Dictionary.h"
#include "Settings.h"
#include "GuessChecker.h"
using namespace model;

#include <typeinfo>
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

void ViewModel::createPages()
{
    UserSelectionWindow* loginPage = new UserSelectionWindow(Constants::LOGIN_WINDOW_WIDTH, Constants::LOGIN_WINDOW_HEIGHT, this->pageTitle, this);
    GameWindow* gamePage = new GameWindow(Constants::GAME_WINDOW_WIDTH, Constants::GAME_WINDOW_HEIGHT, this->pageTitle, this);
    SettingsWindow* settingsPage = new SettingsWindow(Constants::SETTINGS_WINDOW_WIDTH, Constants::SETTINGS_WINDOW_HEIGHT, this->pageTitle, this);

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
    cout << this->currentUser->getGuessDistribution().size() << endl;

    if (this->gameSettings == nullptr)
    {
        this->gameSettings = this->currentUser->getSettings();
    }

    if (this->dictionary == nullptr)
    {
        this->dictionary = this->dictLoader->readDictionaryFile();
    }

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
    bool validGuess = this->dictionary->isValidWord(guessToCheck);
    vector<GuessCheckerResult> result;
    if (validGuess)
    {
        if (this->gameSettings->getHardMode())
        {
            validGuess = this->guessChecker.validPositions(guessToCheck);
        }
        if (validGuess)
        {
            cout << "Your last guess: " << guessToCheck << endl;
            result = this->guessChecker.checkGuess(guessToCheck);
            return result;
        }
        else
        {
            result.push_back(GuessCheckerResult::DUPLICATE_WRONG);
            return result;
        }
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
    this->currentUser->changeSettings(this->gameSettings);
    stringstream userStream;
    for (auto& currentUser : this->users)
    {
        userStream << currentUser.second->userToString() << endl;
    }
    string users = userStream.str();
    this->fileHandler->saveUsersToFile(users);
}

void ViewModel::startNewGame()
{
    for (auto currentPage : this->gameWindows)
    {
        delete currentPage;
    }
    this->gameWindows.clear();
    this->createPages();
    this->initializeGame(this->currentUser->getUsername());
    this->displayPage(PageType::GAME_PAGE);
}

void ViewModel::handleWin(int guessesUsed)
{
    this->currentUser->updateStatsOnWin(guessesUsed);
    GameOverWindow* gameOverPage = new GameOverWindow(Constants::GAME_OVER_WINDOW_WIDTH, Constants::GAME_OVER_WINDOW_HEIGHT, this->pageTitle, this);
    this->gameWindows.push_back(gameOverPage);
    this->displayPage(PageType::GAME_OVER_PAGE);
    this->users[this->currentUser->getUsername()] = this->currentUser;
    this->saveUser();
}

vector<int> ViewModel::getCurrentUserStats()
{
    vector<int> stats;
    stats.push_back(this->currentUser->getGamesPlayed());
    stats.push_back(this->currentUser->getWinPercentage());
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
    GameOverWindow* gameOverPage = new GameOverWindow(Constants::GAME_OVER_WINDOW_WIDTH, Constants::GAME_OVER_WINDOW_HEIGHT, this->pageTitle, this);
    this->gameWindows.push_back(gameOverPage);
    this->displayPage(PageType::GAME_OVER_PAGE);
    this->users[this->currentUser->getUsername()] = this->currentUser;
    this->saveUser();
}

void ViewModel::setSettings(string& username)
{
    if (this->users.count(username))
    {
        Settings* settings = this->users[username]->getSettings();
        SettingsWindow* settingsPage = (SettingsWindow*)this->gameWindows[PageType::SETTINGS_PAGE];
        settingsPage->updateCheckboxValues(settings);
    }
}

ViewModel::~ViewModel()
{
    delete this->dictLoader;
    delete this->fileHandler;
}

}
