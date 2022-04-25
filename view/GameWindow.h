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

#include <FL/Fl_Window.H>
namespace view
{
class GameWindow : public Fl_Window
{
    private:
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

        int handle(int e);

    public:
        GameWindow(int width, int height, const char* title);
        virtual ~GameWindow();
};
}


#endif // GAMEWINDOW_H
