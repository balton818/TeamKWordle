#include "GameWindow.h"

namespace view
{
GameWindow::GameWindow(int width, int height, const char* title) : Fl_Window(width, height, title)
{

}

GameWindow::~GameWindow()
{
    //dtor
}
}

