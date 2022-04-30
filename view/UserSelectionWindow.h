#ifndef USERSELECTIONWINDOW_H
#define USERSELECTIONWINDOW_H

#include <FL/Fl_Window.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Box.H>

#include <ViewModel.h>
using namespace viewmodel;

namespace view
{
class UserSelectionWindow : public Fl_Window
{
private:
    Fl_Box* titleBox;
    Fl_Input* usernameInput;
    Fl_Button* changeSettings;
    Fl_Button* playGame;

    int FEEDBACK_WINDOW_HEIGHT;
    int FEEDBACK_WINDOW_WIDTH;
    int MAIN_WINDOW_HEIGHT;
    int MAIN_WINDOW_WIDTH;
    int TITLE_BOX_WIDTH = 200;
    int TITLE_BOX_HEIGHT = 50;
    int INPUT_WIDTH = 150;
    int INPUT_HEIGHT = 20;
    int BUTTON_WIDTH = 100;
    int BUTTON_HEIGHT = 30;
    int BUTTON_TOP_OFFSET = 20;
    const char* PAGE_TITLE = "Wordle";

    ViewModel* viewModel;

    void buildWindow();
    void addTitleBox();
    void addInput();
    void addPlayGameButton();
    void addSettingsButton();
    static void playGame_callback(Fl_Widget* widget, void* data);
    static void settings_callback(Fl_Widget* widget, void* data);

public:
    UserSelectionWindow(int width, int height, const char* title, ViewModel* viewModel);
    virtual ~UserSelectionWindow();
};
}

#endif // USERSELECTIONWINDOW_H
