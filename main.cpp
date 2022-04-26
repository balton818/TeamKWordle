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
    string answer = "HELLO";
    cout << "Wordle answer: " << answer << endl;
    GuessChecker* checker = new GuessChecker(answer);
    GameWindow mainWindow(500, 700, "Wordle by Alton, Wagner", checker);
    mainWindow.show();
    DictionaryLoader* load = new DictionaryLoader();
    Dictionary dict =   load->readDictionaryFile();
    int i =0;
    while (i < 50)
    {
        string test = dict.getWordToGuess(false);
        cout << test << endl;
        i++;

    }

    int exitCode = Fl::run();
    return exitCode;
}
