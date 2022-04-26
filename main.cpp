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
    DictionaryLoader* load = new DictionaryLoader();
    Dictionary dict =   load->readDictionaryFile();
    string answer = dict.getWordToGuess(true);
    cout << "Wordle answer: " << answer << endl;
    GuessChecker* checker = new GuessChecker(answer);
    GameWindow mainWindow(500, 700, "Wordle by Alton, Wagner", checker);
    mainWindow.show();

    int exitCode = Fl::run();
    return exitCode;
}
