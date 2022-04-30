#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H

namespace view
{
class SettingsWindow : public Fl_Window
{
    public:
        SettingsWindow(int width, int height, const char* title, ViewModel* viewModel);
        virtual ~SettingsWindow();
};
}

#endif // SETTINGSWINDOW_H
