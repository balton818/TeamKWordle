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

class GameOverWindow : public Fl_Window
{
    private:

        vector<Fl_Box*> statsBoxes;
        vector<Fl_Box*> statsLabels;
        string statsBoxLabels [4] = {"Games\nPlayed", "Win %", "Current\nStreak", "Max\nStreak"};
        int NUMBER_OF_BOXES = 4;
        int LABEL_BOX_START_Y = 130;
        int LABEL_BOX_HEIGHT = 25;
        int BOX_START_X = 70;
        int BOX_START_Y = 50;
        int BOX_WIDTH = 75;
        int BOX_HEIGHT = 75;
        int BOX_SPACING = 20;
        int CHART_WIDTH = 350;
        int CHART_HEIGHT = 100;
        int BUTTON_WIDTH = 100;
        int BUTTON_HEIGHT = 30;
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
        static void endGame_callback(Fl_Widget* widget, void* data);
        static void playAgain_callback(Fl_Widget* widget, void* data);

        void deleteStatsBoxesAndLabels();

    public:
        GameOverWindow(int width, int height, const char* title, ViewModel* viewModel);
        virtual ~GameOverWindow();
        void buildWindow();
};
}

#endif // GAMEOVERWINDOW_H
