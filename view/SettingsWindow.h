#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H

#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Check_Button.H>
#include <FL/Fl_Button.H>

#include "ViewModel.h"
using namespace viewmodel;

namespace view
{
class SettingsWindow : public Fl_Window
{
private:
    const char* TITLE_BOX_TEXT = "Settings";
    const char* HARD_MODE = "Hard Mode";
    const char* REUSE_LETTERS = "Single Letter Occurrences";
    const char* APPLY_SETTINGS = "Apply Settings";
    int TITLE_BOX_WIDTH = 200;
    int TITLE_BOX_HEIGHT = 50;
    int CHECKBOX_SIZE = 20;
    int BUTTON_WIDTH = 150;
    int BUTTON_HEIGHT = 30;

    ViewModel* viewmodel;
    Fl_Box* titleBox;
    Fl_Check_Button* hardModeButton;
    Fl_Check_Button* reuseLettersButton;
    Fl_Button* applyButton;

    void buildWindow();
    void buildTitleBox();
    void drawCheckButtons();
    void addApplyButton();
    static void applySettings_callback(Fl_Widget* widget, void* data);

public:
    SettingsWindow(int width, int height, const char* title, ViewModel* viewModel);
    virtual ~SettingsWindow();

};
}

#endif // SETTINGSWINDOW_H
