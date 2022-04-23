#include "GameWindow.h"

#include <iostream>
#include <string>
using namespace std;

namespace view
{


GameWindow::GameWindow(int width, int height, const char* title) : Fl_Window(width, height, title)
{
    this->qwertyKeyLabels = {"Q", "W", "E", "R", "T", "Y", "U", "I", "O", "P", "A", "S", "D", "F", "G", "H", "J", "K", "L", "Z", "X", "C", "V", "B", "N", "M", "ENTER", "BACK"};

    this->TOP_OFFSET = 40;
    this->WINDOW_WIDTH = 500;
    this->WINDOW_HEIGHT = 700;

    this->GUESS_BOX_WIDTH = 45;
    this->GUESS_BOX_HEIGHT = 45;

    this->ROW_SPACING = 10;
    this->COLUMN_SPACING = 10;

    this->NUMBER_OF_ROWS = 6;
    this->NUMBER_OF_COLUMNS = 5;

    this->KEY_HEIGHT = 45;
    this->KEY_WIDTH = 45;

    this->drawGuessBoxes();
    this->drawKeyboard();
}

void GameWindow::drawGuessBoxes()
{
    for (int rowIndex = 0; rowIndex < this->NUMBER_OF_ROWS; rowIndex++)
    {
        vector<Fl_Box*> currentRow;
        for (int columnIndex = 0; columnIndex < this->NUMBER_OF_COLUMNS; columnIndex++)
        {
            int startX = (this->WINDOW_WIDTH / 2) - ((this->NUMBER_OF_COLUMNS * (this->GUESS_BOX_WIDTH) / 2)) + (columnIndex * this->GUESS_BOX_WIDTH);
            int startY = (this->GUESS_BOX_HEIGHT * rowIndex) + (rowIndex * this->ROW_SPACING) + this->TOP_OFFSET;
            Fl_Box* box = new Fl_Box(startX, startY, this->GUESS_BOX_WIDTH, this->GUESS_BOX_HEIGHT, "");
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

    for (int keyRow = 0; keyRow < 3; keyRow++)
    {
        for (int keyIndex = 0; keyIndex < keyCount[keyRow]; keyIndex++)
        {
            int startX = (this->WINDOW_WIDTH / 2) - ((keyCount[keyRow] * (this->KEY_WIDTH) / 2)) + (keyIndex * this->KEY_WIDTH);
            int startY = ((this->WINDOW_HEIGHT / 2) + this->TOP_OFFSET) + (this->KEY_HEIGHT * keyRow) + (10 * keyRow);
            Fl_Button* button = new Fl_Button(startX, startY, this->KEY_WIDTH, this->KEY_HEIGHT, this->qwertyKeyLabels[keyNumber].c_str());
            button->labelsize(20);
            button->callback(this->buttonClick_callback, (void*)this);
            this->keyboard.push_back(button);
            finalX = startX;
            finalY = startY;
            keyNumber++;
        }
    }
    this->addEnterKey((this->WINDOW_WIDTH / 2) - (keyCount[0] * this->KEY_WIDTH) / 2, finalY);
    this->addBackspaceKey(finalX + this->KEY_WIDTH, finalY);
}

void GameWindow::addEnterKey(int xPosition, int yPosition)
{
    this->enterKey = new Fl_Return_Button(xPosition, yPosition, (this->KEY_WIDTH * 1.5), this->KEY_HEIGHT, "ENTER");
    this->enterKey->labelsize(10);
    this->enterKey->callback(this->enterClick_callback);
}

void GameWindow::addBackspaceKey(int xPosition, int yPosition)
{
    this->backspace = new Fl_Button(xPosition, yPosition, (this->KEY_WIDTH * 1.5), this->KEY_HEIGHT, "DELETE");
    this->backspace->callback(this->backspaceClick_callback);
}

void GameWindow::buttonClick_callback(Fl_Widget* widget, void* data)
{
    cout << widget->label() << endl;
}

void GameWindow::enterClick_callback(Fl_Widget* widget, void* data)
{
    cout << widget->label() << endl;
}

void GameWindow::backspaceClick_callback(Fl_Widget* widget, void* data)
{
    cout << widget->label() << endl;
}

void addLetterToCurrentGuess(const char* letter)
{

}

GameWindow::~GameWindow()
{
    //dtor
}
}

