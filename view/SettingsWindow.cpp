#include "SettingsWindow.h"

#include <iostream>
namespace view
{
SettingsWindow::SettingsWindow(int width, int height, const char* title, ViewModel* viewModel) : Fl_Window(width, height, title)
{
    this->viewmodel = viewModel;
    this->buildWindow();
}

void SettingsWindow::buildWindow()
{
    this->buildTitleBox();
    this->drawCheckButtons();
    this->addApplyButton();
}

void SettingsWindow::buildTitleBox()
{
    int startX = (this->w() / 2) - (this->TITLE_BOX_WIDTH / 2);
    this->titleBox = new Fl_Box(startX, 20, this->TITLE_BOX_WIDTH, this->TITLE_BOX_HEIGHT, this->TITLE_BOX_TEXT);
    this->titleBox->box(FL_UP_BOX);
    this->titleBox->labelfont(FL_BOLD+FL_ITALIC);
    this->titleBox->labelsize(36);
    this->titleBox->labeltype(FL_SHADOW_LABEL);
}

void SettingsWindow::drawCheckButtons()
{
    int startX = this->titleBox->x();
    int startY = this->h() / 2;
    this->hardModeButton = new Fl_Check_Button(startX, startY, this->CHECKBOX_SIZE, this->CHECKBOX_SIZE, this->HARD_MODE);
    this->reuseLettersButton = new Fl_Check_Button(startX, this->hardModeButton->y() + this->CHECKBOX_SIZE, this->CHECKBOX_SIZE, this->CHECKBOX_SIZE, this->REUSE_LETTERS);
}

void SettingsWindow::addApplyButton()
{
    int startX = this->w() / 2 - this->BUTTON_WIDTH / 2;
    int startY = this->reuseLettersButton->y() + this->BUTTON_HEIGHT;
    this->applyButton = new Fl_Button(startX, startY, this->BUTTON_WIDTH, this->BUTTON_HEIGHT, this->APPLY_SETTINGS);
    this->applyButton->callback(this->applySettings_callback, this);
}

void SettingsWindow::applySettings_callback(Fl_Widget* widget, void* data)
{
    SettingsWindow* window = (SettingsWindow*)data;
    bool hardModeSelected = window->hardModeButton->value();
    bool reuseLettersSelected = window->reuseLettersButton->value();
    window->viewmodel->updateSettings(hardModeSelected, reuseLettersSelected);
    window->hide();
}

void SettingsWindow::updateCheckboxValues(Settings* settings)
{
    if (settings != nullptr)
    {
        this->hardModeButton->value(settings->getHardMode());
        this->reuseLettersButton->value(settings->getOnlyUniqueChars());
    }

}

SettingsWindow::~SettingsWindow()
{
    delete this->titleBox;
    delete this->hardModeButton;
    delete this->reuseLettersButton;
    delete this->applyButton;
}

}
