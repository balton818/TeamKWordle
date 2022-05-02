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

// settings window class
//
// Author - Team K
//
class SettingsWindow : public Fl_Window
{

public:

    // constructs a settings window
    //
    // params - width - window width
    //          height - window height
    //          title - window title
    //          viewModel - the viewmodel for the window
    //
    SettingsWindow(int width, int height, const char* title, ViewModel* viewModel);

    // deconstructs a settings window
    //
    virtual ~SettingsWindow();

    //Updates the checkbox values to those found in the Settings object
    //
    void updateCheckboxValues(Settings* settings);

private:

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
};

}

#endif // SETTINGSWINDOW_H
