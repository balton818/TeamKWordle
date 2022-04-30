#include "UserSelectionWindow.h"

#include <GameWindow.h>
#include <FL/Fl_Box.H>

namespace view
{
UserSelectionWindow::UserSelectionWindow(int width, int height, const char* title, ViewModel* viewModel) : Fl_Window(width, height, title)
{
    this->viewModel = viewModel;
    this->MAIN_WINDOW_WIDTH = width;
    this->MAIN_WINDOW_HEIGHT = height;
    this->buildWindow();
}

void UserSelectionWindow::buildWindow()
{
    this->addTitleBox();
    this->addInput();
    this->addPlayGameButton();
    this->addSettingsButton();
}

void UserSelectionWindow::addTitleBox()
{
    int startX = (this->MAIN_WINDOW_WIDTH / 2) - (this->TITLE_BOX_WIDTH / 2);
    this->titleBox = new Fl_Box(startX, 20, this->TITLE_BOX_WIDTH, this->TITLE_BOX_HEIGHT, this->PAGE_TITLE);
    this->titleBox->box(FL_UP_BOX);
    this->titleBox->labelfont(FL_BOLD+FL_ITALIC);
    this->titleBox->labelsize(36);
    this->titleBox->labeltype(FL_SHADOW_LABEL);
}

void UserSelectionWindow::addInput()
{
    int startX = (this->MAIN_WINDOW_WIDTH / 2) - (this->INPUT_WIDTH / 2);
    this->usernameInput = new Fl_Input(startX, (this->MAIN_WINDOW_HEIGHT / 2 - this->INPUT_HEIGHT), this->INPUT_WIDTH, this->INPUT_HEIGHT, "Username: ");
}

void UserSelectionWindow::addPlayGameButton()
{
    int startX = (this->MAIN_WINDOW_WIDTH / 2) - (this->BUTTON_WIDTH / 2);
    int startY = (this->MAIN_WINDOW_HEIGHT / 2 + this->BUTTON_TOP_OFFSET);
    this->playGame = new Fl_Button(startX, startY, this->BUTTON_WIDTH, this->BUTTON_HEIGHT, "Play Game");
    this->playGame->callback(this->playGame_callback, this);
}

void UserSelectionWindow::addSettingsButton()
{
    int startX = (this->MAIN_WINDOW_WIDTH / 2) - (this->BUTTON_WIDTH / 2);
    int startY = (this->MAIN_WINDOW_HEIGHT / 2 + this->BUTTON_HEIGHT + 2 * this->BUTTON_TOP_OFFSET);
    this->changeSettings = new Fl_Button(startX, startY, this->BUTTON_WIDTH, this->BUTTON_HEIGHT, "Settings");
}

void UserSelectionWindow::playGame_callback(Fl_Widget* widget, void* data)
{
    UserSelectionWindow* window = (UserSelectionWindow*)data;
    string username = window->usernameInput->value();
    if (username.length() > 0)
    {
        window->viewModel->initializeGame(username);
        GameWindow* mainWindow = new GameWindow(500, 700, window->label(), window->viewModel);
        mainWindow->show();
        window->hide();
    }
}


void UserSelectionWindow::handlePlayGame()
{

}

UserSelectionWindow::~UserSelectionWindow()
{
    delete this->titleBox;
    delete this->usernameInput;
}
}

