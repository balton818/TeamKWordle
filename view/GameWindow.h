#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <FL/Fl.H>
#include <FL/fl_ask.H>


#include <vector>
#include <string>
using namespace std;

#include "ViewModel.h"
using namespace viewmodel;

#include "GuessCheckerResult.h"
using namespace enums;

#include <FL/Fl_Window.H>
namespace view
{

// The game window class
//
// Author - Team K
//
class GameWindow : public Fl_Window
{

public:

    // Constructs a gameWindow for the world game
    //
    // params - width - window width
    //          height - window height
    //          title - window title
    //          viewModel - the viewmodel for the window
    //
    GameWindow(int width, int height, const char* title, ViewModel* viewModel);

    // Deconstructs the game window
    //
    virtual ~GameWindow();

    // Resets the game Window
    //
    void resetWindow();

    // Disables all input functionality
    //
    void lockoutControls();

private:
    ViewModel* viewModel;

    const char* invalidGuess = "Invalid Word";

    int currentGuessNumber;
    vector<char> currentGuess;

    bool controlsEnabled;

    Fl_Button* enterKey;
    void addEnterKey(int xPosition, int yPosition);
    Fl_Button* backspace;
    void addBackspaceKey(int xPosition, int yPosition);
    Fl_Button* newGameButton;
    void addNewGameButton(int xPosition, int yPosition);

    vector<string> qwertyKeyLabels;

    vector<vector<Fl_Box*>> guessBoxes;
    void drawGuessBoxes();

    vector<Fl_Button*> keyboard;
    void drawKeyboard();

    static void buttonClick_callback(Fl_Widget* widget, void* data);
    static void enterClick_callback(Fl_Widget* widget, void* data);
    static void backspaceClick_callback(Fl_Widget* widget, void* data);
    static void newGameClick_callback(Fl_Widget* widget, void* data);

    void clearKeyBoardColors();
    void clearGuessBoxes();
    void addLetterToCurrentGuess(const char* letter);
    void updateGuessBox(const char* letter);
    void removeLastLetter();
    void enterGuess();
    bool handleCheckerResult(vector<GuessCheckerResult> result);
    void updateGuessBoxAndKeyColors(vector<GuessCheckerResult> result);
    void updateKeyColor(const char* keyLabel, GuessCheckerResult checkerResult);
    Fl_Color determineColorForResult(GuessCheckerResult checkerResult);
    int handle(int e);

    void deleteGuessBoxes();
    void deleteKeyboard();
};

}

#endif // GAMEWINDOW_H
