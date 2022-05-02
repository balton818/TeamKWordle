#ifndef GAMEOVERWINDOW_H
#define GAMEOVERWINDOW_H

#include <FL/Fl_Window.H>
#include <FL/Fl_Chart.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Multiline_Output.H>
#include <FL/Fl_Button.H>

#include <vector>
using namespace std;

#include "ViewModel.h"
using namespace viewmodel;

namespace view
{

// GameOverWindow class for world game
//
// Author - Team K
//
class GameOverWindow : public Fl_Window
{

public:

    // constructs a gameOver window
    //
    // params - width - window width
    //          height - window height
    //          title - window title
    //          viewmodel - the current viewmodel
    //
    GameOverWindow(int width, int height, const char* title, ViewModel* viewModel);

    // deconstructs a gameover window
    //
    virtual ~GameOverWindow();

    // builds the window
    //
    void buildWindow();

private:

    vector<Fl_Box*> statsBoxes;
    vector<Fl_Box*> statsLabels;
    string statsBoxLabels [4] = {"Games\nPlayed", "Win %", "Current\nStreak", "Max\nStreak"};



    const char* PLAY_AGAIN = "Play Again";
    const char* END_GAME = "End Game";

    Fl_Chart* userStatsChart;
    Fl_Button* playAgainButton;
    Fl_Button* endGameButton;

    ViewModel* viewmodel;

    void addStatsBoxes();
    void addStatsLabels();
    void drawChart();
    void addPlayAgainButton();
    void addEndGameButton();
    void deleteStatsBoxesAndLabels();

    static void endGame_callback(Fl_Widget* widget, void* data);
    static void playAgain_callback(Fl_Widget* widget, void* data);
};

}

#endif // GAMEOVERWINDOW_H
