#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Toggle_Button.H>
#include <FL/Fl_Return_Button.H>

#include <vector>
#include <string>
using namespace std;

<<<<<<< HEAD
#include "GuessChecker.h"
using namespace model;

#include "GuessCheckerResult.h"
using namespace enums;

=======
#include <FL/Fl_Window.H>
>>>>>>> 40823b162f1cca38e657558392d1aad0be2af11f
namespace view
{
class GameWindow : public Fl_Window
{
    private:
        GuessChecker* checker;

        int TOP_OFFSET;
        int WINDOW_WIDTH;
        int WINDOW_HEIGHT;
        int GUESS_BOXES_START_X;
        int GUESS_BOXES_START_Y;
        int GUESS_BOX_WIDTH;
        int GUESS_BOX_HEIGHT;

        int ROW_SPACING;
        int COLUMN_SPACING;

        int NUMBER_OF_ROWS;
        int NUMBER_OF_COLUMNS;

        int KEY_WIDTH;
        int KEY_HEIGHT;

        int MAX_GUESS_LENGTH;

        int currentGuessNumber;
        vector<char> currentGuess;

        Fl_Button* enterKey;
        void addEnterKey(int xPosition, int yPosition);
        Fl_Button* backspace;
        void addBackspaceKey(int xPosition, int yPosition);

        vector<string> qwertyKeyLabels;

        vector<vector<Fl_Box*>> guessBoxes;
        void drawGuessBoxes();

        vector<Fl_Button*> keyboard;
        void drawKeyboard();

        static void buttonClick_callback(Fl_Widget* widget, void* data);
        static void enterClick_callback(Fl_Widget* widget, void* data);
        static void backspaceClick_callback(Fl_Widget* widget, void* data);

        void addLetterToCurrentGuess(const char* letter);
        void updateGuessBox(const char* letter);
        void removeLastLetter();
        void enterGuess();
        void handleCheckerResult(vector<GuessCheckerResult> result);
        void updateGuessBoxAndKeyColors(vector<GuessCheckerResult> result);
        void updateKeyColor(const char* keyLabel, GuessCheckerResult checkerResult);
        Fl_Color determineColorForResult(GuessCheckerResult checkerResult);
        int handle(int e);

    public:
        GameWindow(int width, int height, const char* title, GuessChecker* checker);
        virtual ~GameWindow();
};
}


#endif // GAMEWINDOW_H
