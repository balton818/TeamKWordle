#include "GameWindow.h"

namespace view
{
static vector<string> qwertyKeyLabels = {"Q", "W", "E", "R", "T", "Y", "U", "I", "O", "P", "A", "S", "D", "F", "G", "H", "J", "K", "L", "Z", "X", "C", "V", "B", "N", "M", "ENTER", "BACK"};

GameWindow::GameWindow(int width, int height, const char* title) : Fl_Window(width, height, title)
{
    this->WINDOW_WIDTH = 500;
    this->WINDOW_HEIGHT = 700;

    this->GUESS_BOXES_START_X = 150;
    this->GUESS_BOXES_START_Y = 30;
    this->GUESS_BOX_WIDTH = 30;
    this->GUESS_BOX_HEIGHT = 40;

    this->ROW_SPACING = 10;
    this->COLUMN_SPACING = 10;

    this->NUMBER_OF_ROWS = 6;
    this->NUMBER_OF_COLUMNS = 5;

    this->drawGuessBoxes();
}

void GameWindow::drawGuessBoxes()
{
    int keyCounter = 0;

    for (int rowIndex = 0; rowIndex < this->NUMBER_OF_ROWS; rowIndex++)
    {
        vector<Fl_Box*> currentRow;
        for (int columnIndex = 0; columnIndex < this->NUMBER_OF_COLUMNS; columnIndex++)
        {
            int startX = this->GUESS_BOXES_START_X + (columnIndex * this->GUESS_BOX_WIDTH) + (columnIndex * this->COLUMN_SPACING);
            int startY = this->GUESS_BOXES_START_Y + (rowIndex * this->GUESS_BOX_HEIGHT) + (rowIndex * this->ROW_SPACING);
            Fl_Box* box = new Fl_Box(startX, startY, 30, 40, "");
            box->box(FL_DOWN_BOX);
            box->labelfont(FL_BOLD);
            box->labelsize(25);
            currentRow.push_back(box);
        }
        this->guessBoxes.push_back(currentRow);
    }
}

GameWindow::~GameWindow()
{
    //dtor
}
}

