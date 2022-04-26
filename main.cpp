#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>

#include "GameWindow.h"
using namespace view;

#include "GuessChecker.h"
using namespace model;

#include <iostream>
using namespace std;

int main (int argc, char ** argv)
{
    string answer = "HELLO";
    cout << "Wordle answer: " << answer << endl;
    GuessChecker* checker = new GuessChecker(answer);
    GameWindow mainWindow(500, 700, "Wordle by Alton, Wagner", checker);
    mainWindow.show();

    int exitCode = Fl::run();
    return exitCode;
}
