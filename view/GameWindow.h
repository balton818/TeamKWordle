#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H


#include <FL/Fl_Window.H>
namespace view
{
class GameWindow : public Fl_Window
{
    public:
        GameWindow(int width, int height, const char* title);
        virtual ~GameWindow();
};
}


#endif // GAMEWINDOW_H
