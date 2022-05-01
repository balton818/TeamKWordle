#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>

#include <iostream>
using namespace std;

#include "UserSelectionWindow.h"
using namespace view;

#include "ViewModel.h"
using namespace viewmodel;

int main (int argc, char ** argv)
{
    ViewModel* viewModel = new ViewModel();
    viewModel->displayPage(PageType::LOGIN_PAGE);

    int exitCode = Fl::run();
    return exitCode;
}
