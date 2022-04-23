#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>

#include <vector>
#include <string>
using namespace std;

namespace view
{
class GameWindow : public Fl_Window
{
    private:
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

        static vector<string> qwertyKeyLabels;

        vector<vector<Fl_Box*>> guessBoxes;
        void drawGuessBoxes();

    public:
        GameWindow(int width, int height, const char* title);
        virtual ~GameWindow();
};
}


#endif // GAMEWINDOW_H
