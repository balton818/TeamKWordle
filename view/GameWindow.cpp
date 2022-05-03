#include "GameWindow.h"

#include <FL/Fl.H>

#include "../enums/SpecialKey.h"
using namespace enums;

#include <iostream>
#include <string>
using namespace std;

namespace view
{

GameWindow::GameWindow(int width, int height, const char* title, ViewModel* viewModel) : Fl_Window(width, height, title)
{
    this->viewModel = viewModel;
    this->qwertyKeyLabels = {"Q", "W", "E", "R", "T", "Y", "U", "I", "O", "P", "A", "S", "D", "F", "G", "H", "J", "K", "L", "Z", "X", "C", "V", "B", "N", "M", "ENTER", "BACK"};
    this->currentGuessNumber = 0;
    this->controlsEnabled = true;
    this->drawGuessBoxes();
    this->drawKeyboard();
}

void GameWindow::drawGuessBoxes()
{
    for (int rowIndex = 0; rowIndex < Constants::GAME_WINDOW_NUMBER_OF_ROWS; rowIndex++)
    {
        vector<Fl_Box*> currentRow;
        for (int columnIndex = 0; columnIndex < Constants::GAME_WINDOW_NUMBER_OF_COLUMNS; columnIndex++)
        {
            int startX = (Constants::GAME_WINDOW_WIDTH / 2) - ((Constants::GAME_WINDOW_NUMBER_OF_COLUMNS * (Constants::GAME_WINDOW_GUESS_BOX_WIDTH) / 2)) + (columnIndex * Constants::GAME_WINDOW_GUESS_BOX_WIDTH);
            int startY = (Constants::GAME_WINDOW_GUESS_BOX_HEIGHT * rowIndex) + (rowIndex * Constants::GAME_WINDOW_ROW_SPACING) + Constants::GAME_WINDOW_TOP_OFFSET;
            Fl_Box* box = new Fl_Box(startX, startY, Constants::GAME_WINDOW_GUESS_BOX_WIDTH, Constants::GAME_WINDOW_GUESS_BOX_HEIGHT, "");
            box->box(FL_DOWN_BOX);
            box->labelfont(FL_BOLD);
            box->labelsize(25);
            currentRow.push_back(box);
        }
        this->guessBoxes.push_back(currentRow);
    }
}

void GameWindow::drawKeyboard()
{
    int keyCount [3] = {10, 9, 7};
    int keyNumber = 0;
    int finalX;
    int finalY;

    for (int keyRow = 0; keyRow < sizeof(keyCount)/sizeof(int); keyRow++)
    {
        for (int keyIndex = 0; keyIndex < keyCount[keyRow]; keyIndex++)
        {
            int startX = (Constants::GAME_WINDOW_WIDTH / 2) - ((keyCount[keyRow] * (Constants::GAME_WINDOW_KEY_WIDTH) / 2)) + (keyIndex * Constants::GAME_WINDOW_KEY_WIDTH);
            int startY = ((Constants::GAME_WINDOW_HEIGHT / 2) + Constants::GAME_WINDOW_TOP_OFFSET) + (Constants::GAME_WINDOW_KEY_HEIGHT * keyRow) + (10 * keyRow);
            Fl_Button* button = new Fl_Button(startX, startY, Constants::GAME_WINDOW_KEY_WIDTH, Constants::GAME_WINDOW_KEY_HEIGHT, this->qwertyKeyLabels[keyNumber].c_str());
            button->labelsize(20);
            button->callback(this->buttonClick_callback, (void*)this);
            this->keyboard.push_back(button);
            finalX = startX;
            finalY = startY;
            keyNumber++;
        }
    }
    this->addEnterKey((Constants::GAME_WINDOW_WIDTH / 2) - (keyCount[0] * Constants::GAME_WINDOW_KEY_WIDTH) / 2, finalY);
    this->addBackspaceKey(finalX + Constants::GAME_WINDOW_KEY_WIDTH, finalY);
    this->addNewGameButton(Constants::GAME_WINDOW_WIDTH / 2 -(Constants::GAME_WINDOW_KEY_WIDTH * 1.5), Constants::GAME_WINDOW_HEIGHT - 100);
}

void GameWindow::addNewGameButton(int xPosition, int yPosition)
{
    this->newGameButton = new Fl_Button(xPosition, yPosition, (Constants::GAME_WINDOW_KEY_WIDTH * 3.0), Constants::GAME_WINDOW_KEY_HEIGHT, "Start New Game");
    this->newGameButton->callback(this->newGameClick_callback, (void*)this);
}

void GameWindow::addEnterKey(int xPosition, int yPosition)
{
    this->enterKey = new Fl_Button(xPosition, yPosition, (Constants::GAME_WINDOW_KEY_WIDTH * 1.5), Constants::GAME_WINDOW_KEY_HEIGHT, "ENTER");
    this->enterKey->callback(this->enterClick_callback, (void*)this);
}

void GameWindow::addBackspaceKey(int xPosition, int yPosition)
{
    this->backspace = new Fl_Button(xPosition, yPosition, (Constants::GAME_WINDOW_KEY_WIDTH * 1.5), Constants::GAME_WINDOW_KEY_HEIGHT, "DELETE");
    this->backspace->callback(this->backspaceClick_callback, (void*)this);
}

void GameWindow::buttonClick_callback(Fl_Widget* widget, void* data)
{
    GameWindow* window = (GameWindow*)data;
    window->addLetterToCurrentGuess(widget->label());
}

void GameWindow::newGameClick_callback(Fl_Widget* widget, void* data)
{
    GameWindow* window = (GameWindow*)data;
    window->resetWindow();
    window->viewModel->startNewGame();
}

void GameWindow::resetWindow()
{
    this->clearGuessBoxes();
    this->clearKeyBoardColors();
    this->currentGuessNumber = 0;
}

void GameWindow::lockoutControls()
{
    this->controlsEnabled = false;
    for (auto itr = this->keyboard.begin(); itr != this->keyboard.end(); ++itr)
    {
        Fl_Button* button = *itr;
        button->deactivate();
    }
    this->enterKey->deactivate();
    this->backspace->deactivate();
    this->newGameButton->deactivate();
}

void GameWindow::clearKeyBoardColors()
{
    for (Fl_Button* currentKey : this->keyboard)
    {
        if (currentKey->color() != FL_GRAY)
        {
            currentKey->color(FL_GRAY);
            currentKey->redraw();
        }
    }
}

void GameWindow::clearGuessBoxes()
{
    while(this->currentGuessNumber >= 0)
    {
        for (Fl_Box* currentBox : this->guessBoxes[this->currentGuessNumber])
        {
            currentBox->label("");
            currentBox->redraw();
            currentBox->color(FL_GRAY);
        }

        this->currentGuessNumber--;
    }
}

void GameWindow::enterClick_callback(Fl_Widget* widget, void* data)
{
    GameWindow* window = (GameWindow*)data;
    window->enterGuess();
}

void GameWindow::backspaceClick_callback(Fl_Widget* widget, void* data)
{
    GameWindow* window = (GameWindow*)data;
    window->removeLastLetter();
}

void GameWindow::addLetterToCurrentGuess(const char* letter)
{
    int guessLength = this->currentGuess.size();
    if (guessLength < Constants::GAME_WINDOW_MAX_GUESS_LENGTH)
    {
        this->currentGuess.push_back(*letter);
        this->updateGuessBox(letter);
    }
}

void GameWindow::updateGuessBox(const char* letter)
{
    vector<Fl_Box*> currentRow = this->guessBoxes[this->currentGuessNumber];
    Fl_Box* currentBox = currentRow[this->currentGuess.size() - 1];
    currentBox->copy_label(letter);
    currentBox->redraw();
}

void GameWindow::removeLastLetter()
{
    if (!this->currentGuess.size() == 0)
    {
        Fl_Box* currentBox = this->guessBoxes.at(this->currentGuessNumber).at(this->currentGuess.size() - 1);
        this->currentGuess.pop_back();
        currentBox->label("");
        currentBox->redraw();
    }
}

void GameWindow::enterGuess()
{
    if (this->currentGuess.size() == Constants::GAME_WINDOW_MAX_GUESS_LENGTH)
    {
        string guess;
        for (char currentChar : this->currentGuess)
        {
            guess.push_back(currentChar);
        }

        vector<GuessCheckerResult> results = this->viewModel->checkGuess(guess);
        if (results.size() == 1)
        {
            fl_alert("Invalid Letter Position for Hard Mode");
        }
        else if (this->handleCheckerResult(results))
        {
            this->currentGuessNumber++;
            this->currentGuess.clear();
            if (this->currentGuessNumber == 6)
            {
                this->viewModel->handleLoss();
            }
        }
        else
        {
            fl_alert("Invalid word");

        }
    }
}

int GameWindow::handle(int e)
{
    int returnValue = Fl_Window::handle(e);
    if (e == FL_KEYUP && this->controlsEnabled)
    {
        int keyCode = Fl::event_key();
        if (keyCode == SpecialKey::DELETE)
        {
            this->removeLastLetter();
        }
        else if (keyCode == FL_Enter)
        {
            this->enterGuess();
        }
        else if (keyCode >= SpecialKey::A && keyCode <= SpecialKey::Z)
        {
            this->addLetterToCurrentGuess(Fl::event_text());
        }
    }

    return returnValue;
}

bool GameWindow::handleCheckerResult(vector<GuessCheckerResult> result)
{
    if (!result.empty())
    {
        this->updateGuessBoxAndKeyColors(result);
        return true;
    }

    return false;
}

void GameWindow::updateGuessBoxAndKeyColors(vector<GuessCheckerResult> result)
{
    int correctLetters = 0;
    vector<Fl_Box*> currentRow = this->guessBoxes[this->currentGuessNumber];
    for (int index = 0; index < 5; index++)
    {
        Fl_Box* currentBox = currentRow[index];
        GuessCheckerResult currentResult = result[index];
        if (this->determineColorForResult(currentResult) == FL_GREEN)
        {
            correctLetters++;
        }
        currentBox->color(this->determineColorForResult(currentResult));
        const char* labelText = currentBox->label();
        this->updateKeyColor(labelText, currentResult);
        currentBox->redraw();
    }

    if (correctLetters == 5)
    {
        this->viewModel->handleWin(this->currentGuessNumber + 1);
    }
}

void GameWindow::updateKeyColor(const char* keyLabel, GuessCheckerResult result)
{
    for (Fl_Button* currentKey : this->keyboard)
    {
        string label = currentKey->label();
        if (label == keyLabel)
        {
            if (result != GuessCheckerResult::DUPLICATE_WRONG)
            {
                currentKey->color(this->determineColorForResult(result));
            }

            currentKey->redraw();
        }
    }
}

Fl_Color GameWindow::determineColorForResult(GuessCheckerResult checkerResult)
{
    if (checkerResult == GuessCheckerResult::CORRECT)
    {
        return(FL_GREEN);
    }
    else if (checkerResult == GuessCheckerResult::WRONG_POSITION)
    {
        return FL_YELLOW;
    }
    else
    {
        return FL_DARK2;
    }
}

GameWindow::~GameWindow()
{
}

}

