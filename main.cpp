#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>

#include <iostream>
using namespace std;

#include "datatier/DictionaryLoader.h"
using namespace datatier;

#include "Dictionary.h"
using namespace model;

#include "GameWindow.h"
using namespace view;

#include "GuessChecker.h"
using namespace model;

#include <iostream>
using namespace std;

int main (int argc, char ** argv)
{
    ViewModel* viewModel = new ViewModel();
    string username = "test";
    viewModel->initializeGame(username);
    GameWindow mainWindow(500, 700, "Wordle by Alton, Wagner", viewModel);
    mainWindow.show();

    int exitCode = Fl::run();
    return exitCode;
}
