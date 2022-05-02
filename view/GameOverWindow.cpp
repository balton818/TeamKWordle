#include "GameOverWindow.h"

#include <iostream>
namespace view
{
GameOverWindow::GameOverWindow(int width, int height, const char* title, ViewModel* viewModel) : Fl_Window(width, height, title)
{
    this->viewmodel = viewModel;
    this->buildWindow();
}

void GameOverWindow::buildWindow()
{
    this->addStatsBoxes();
    this->drawChart();
    this->addPlayAgainButton();
    this->addEndGameButton();
}

void GameOverWindow::addStatsBoxes()
{
    vector<int> stats = this->viewmodel->getCurrentUserStats();

    for (int index = 0; index < this->NUMBER_OF_BOXES; index++)
    {
        int startX = this->BOX_START_X + (index * (this->BOX_WIDTH + this->BOX_SPACING));
        Fl_Box* box = new Fl_Box(FL_NO_BOX, startX, this->BOX_START_Y, this->BOX_WIDTH, this->BOX_HEIGHT, "");
        box->labelsize(25);
        string result = to_string(stats[index]);
        const char* text = result.c_str();

        box->copy_label(text);
        this->statsBoxes.push_back(box);

        Fl_Box* label = new Fl_Box(FL_NO_BOX, startX, this->LABEL_BOX_START_Y, this->BOX_WIDTH, this->LABEL_BOX_HEIGHT, this->statsBoxLabels[index].c_str());
        this->statsLabels.push_back(label);

    }
}

void GameOverWindow::drawChart()
{
    map<int, int> distributionMap = this->viewmodel->getGuessDistribution();
    int startX = this->w() / 2 - this->CHART_WIDTH / 2;
    int startY = this->h() / 2;
    this->userStatsChart = new Fl_Chart(startX, startY, this->CHART_WIDTH, this->CHART_HEIGHT, "Guess Distribution");
    this->userStatsChart->type(FL_HORBAR_CHART);
    for (int index = 1; index <= distributionMap.size(); index++)
    {
        stringstream ss;
        ss << index;
        this->userStatsChart->add(distributionMap[index], ss.str().c_str(), FL_DARK_GREEN);
    }
}

void GameOverWindow::addPlayAgainButton()
{
    int startX = this->w() / 2 - (1.5* this->BUTTON_WIDTH);
    int startY = this->userStatsChart->y() + this->CHART_HEIGHT +  2* this->BUTTON_HEIGHT;
    this->playAgainButton = new Fl_Button(startX, startY, this->BUTTON_WIDTH, this->BUTTON_HEIGHT, this->PLAY_AGAIN);
    this->playAgainButton->callback(this->playAgain_callback, this);
}

void GameOverWindow::playAgain_callback(Fl_Widget* widget, void* data)
{
    GameOverWindow* window = (GameOverWindow*)data;
    window->viewmodel->startNewGame();
    window->hide();
}

void GameOverWindow::addEndGameButton()
{
    int startX = this->w() / 2 + this->BUTTON_WIDTH / 2;
    int startY = this->userStatsChart->y() + this->CHART_HEIGHT +  2* this->BUTTON_HEIGHT;
    this->endGameButton = new Fl_Button(startX, startY, this->BUTTON_WIDTH, this->BUTTON_HEIGHT, this->END_GAME);
    this->endGameButton->callback(this->endGame_callback, this);
}

void GameOverWindow::endGame_callback(Fl_Widget* widget, void* data)
{
    exit(0);
}

void GameOverWindow::deleteStatsBoxesAndLabels()
{
    for (int index = 0; index < this->statsBoxes.size(); index++)
    {
        delete this->statsBoxes[index];
        delete this->statsLabels[index];
    }
}

GameOverWindow::~GameOverWindow()
{
    delete this->userStatsChart;
    this->deleteStatsBoxesAndLabels();
    delete this->playAgainButton;
    delete this->endGameButton;
}
}
