#include "UserSelectionWindow.h"

#include "GameWindow.h"
#include "SettingsWindow.h"
#include <FL/Fl_Box.H>

namespace view
{
UserSelectionWindow::UserSelectionWindow(int width, int height, const char* title, ViewModel* viewModel) : Fl_Window(width, height, title)
{
    this->viewModel = viewModel;
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
    int startX = (this->w() / 2) - (Constants::USER_SELECTION_TITLE_BOX_WIDTH / 2);
    this->titleBox = new Fl_Box(startX, 20, Constants::USER_SELECTION_TITLE_BOX_WIDTH, Constants::USER_SELECTION_TITLE_BOX_HEIGHT, "Wordle");
    this->titleBox->box(FL_UP_BOX);
    this->titleBox->labelfont(FL_BOLD+FL_ITALIC);
    this->titleBox->labelsize(36);
    this->titleBox->labeltype(FL_SHADOW_LABEL);
}

void UserSelectionWindow::addInput()
{
    int startX = (this->w() / 2) - (Constants::USER_SELECTION_INPUT_WIDTH / 2);
    this->usernameInput = new Fl_Input(startX, (this->h() / 2 - Constants::USER_SELECTION_INPUT_HEIGHT), Constants::USER_SELECTION_INPUT_WIDTH, Constants::USER_SELECTION_INPUT_HEIGHT, "Username: ");
}

void UserSelectionWindow::addPlayGameButton()
{
    int startX = (this->w() / 2) - (Constants::USER_SELECTION_BUTTON_WIDTH / 2);
    int startY = (this->h() / 2) + Constants::USER_SELECTION_BUTTON_TOP_OFFSET;
    this->playGame = new Fl_Button(startX, startY, Constants::USER_SELECTION_BUTTON_WIDTH, Constants::USER_SELECTION_BUTTON_HEIGHT, "Play Game");
    this->playGame->callback(this->playGame_callback, this);
}

void UserSelectionWindow::addSettingsButton()
{
    int startX = (this->w() / 2) - (Constants::USER_SELECTION_BUTTON_WIDTH / 2);
    int startY = (this->h() / 2 + Constants::USER_SELECTION_BUTTON_HEIGHT + 2 * Constants::USER_SELECTION_BUTTON_TOP_OFFSET);
    this->changeSettings = new Fl_Button(startX, startY, Constants::USER_SELECTION_BUTTON_WIDTH, Constants::USER_SELECTION_BUTTON_HEIGHT, "Settings");
    this->changeSettings->callback(this->settings_callback, this);
}

void UserSelectionWindow::playGame_callback(Fl_Widget* widget, void* data)
{
    UserSelectionWindow* window = (UserSelectionWindow*)data;
    string username = window->usernameInput->value();
    if (username.length() > 0)
    {
        window->viewModel->initializeGame(username);
        window->viewModel->displayPage(PageType::GAME_PAGE);
        window->hide();
    }
}

void UserSelectionWindow::settings_callback(Fl_Widget* widget, void* data)
{
    UserSelectionWindow* window = (UserSelectionWindow*)data;
    string username = window->usernameInput->value();
    if (username.length() > 0)
    {
        window->viewModel->setSettings(username);
        window->viewModel->displayPage(PageType::SETTINGS_PAGE);
    }
}

UserSelectionWindow::~UserSelectionWindow()
{
    delete this->titleBox;
    delete this->usernameInput;
    delete this->changeSettings;
    delete this->playGame;
}
}

