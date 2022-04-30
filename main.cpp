#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>

#include <iostream>
using namespace std;

#include "datatier/DictionaryLoader.h"
#include "datatier/UserFileHandler.h"
using namespace datatier;
#include "Dictionary.h"
using namespace model;
#include "GameWindow.h"

#include "UserSelectionWindow.h"
using namespace view;

#include "GuessChecker.h"
using namespace model;

#include <iostream>
using namespace std;

int main (int argc, char ** argv)
{
    string pageTitle = "Wordle by Alton, Wagner";

    ViewModel* viewModel = new ViewModel();
    UserSelectionWindow userWindow(400, 300, pageTitle.c_str(), viewModel);
    userWindow.show();

//    string username = "test";
//    viewModel->initializeGame(username);
//    GameWindow mainWindow(500, 700, pageTitle.c_str(), viewModel);
//    mainWindow.show();
//
    int exitCode = Fl::run();
    return exitCode;
}
