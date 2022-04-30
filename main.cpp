#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>

#include <iostream>
using namespace std;

#include "UserSelectionWindow.h"
using namespace view;

#include "ViewModel.h"
using namespace viewmodel;

#include <iostream>
using namespace std;

int main (int argc, char ** argv)
{
    string pageTitle = "Wordle by Alton, Wagner";

    ViewModel* viewModel = new ViewModel();
    UserSelectionWindow userWindow(400, 300, pageTitle.c_str(), viewModel);
    userWindow.show();

    int exitCode = Fl::run();
    return exitCode;
}
