#ifndef CONSTANTS_H
#define CONSTANTS_H

namespace constants
{
class Constants
{
    public:
//Constants for ViewModel
        static const int LOGIN_WINDOW_WIDTH = 400;
        static const int LOGIN_WINDOW_HEIGHT = 300;
        static const int GAME_WINDOW_WIDTH = 500;
        static const int GAME_WINDOW_HEIGHT = 700;
        static const int GAME_OVER_WINDOW_WIDTH = 500;
        static const int GAME_OVER_WINDOW_HEIGHT = 500;
        static const int SETTINGS_WINDOW_WIDTH = 300;
        static const int SETTINGS_WINDOW_HEIGHT = 200;

//Constants for UserSelectionWindow
        static const int USER_SELECTION_TITLE_BOX_WIDTH = 200;
        static const int USER_SELECTION_TITLE_BOX_HEIGHT = 50;
        static const int USER_SELECTION_INPUT_WIDTH = 150;
        static const int USER_SELECTION_INPUT_HEIGHT = 20;
        static const int USER_SELECTION_BUTTON_WIDTH = 100;
        static const int USER_SELECTION_BUTTON_HEIGHT = 30;
        static const int USER_SELECTION_BUTTON_TOP_OFFSET = 20;

//Constants for SettingsWindow
        static const int SETTINGS_WINDOW_TITLE_BOX_WIDTH = 200;
        static const int SETTINGS_WINDOW_TITLE_BOX_HEIGHT = 50;
        static const int SETTINGS_WINDOW_CHECKBOX_SIZE = 20;
        static const int SETTINGS_WINDOW_BUTTON_WIDTH = 150;
        static const int SETTINGS_WINDOW_BUTTON_HEIGHT = 30;

//Constants for GameWindow
        static const int GAME_WINDOW_TOP_OFFSET = 40;
        static const int GAME_WINDOW_GUESS_BOX_WIDTH = 45;
        static const int GAME_WINDOW_GUESS_BOX_HEIGHT = 45;
        static const int GAME_WINDOW_KEY_WIDTH = 45;
        static const int GAME_WINDOW_KEY_HEIGHT = 45;
        static const int GAME_WINDOW_ROW_SPACING = 10;
        static const int GAME_WINDOW_COLUMN_SPACING = 10;
        static const int GAME_WINDOW_NUMBER_OF_ROWS = 6;
        static const int GAME_WINDOW_NUMBER_OF_COLUMNS = 5;
        static const int GAME_WINDOW_MAX_GUESS_LENGTH = 5;

//Constants for GameOverWindow
        static const int NUMBER_OF_BOXES_FOR_GAME_OVER = 4;
        static const int GAME_OVER_LABEL_BOX_START_Y = 130;
        static const int GAME_OVER_LABEL_BOX_HEIGHT = 25;
        static const int GAME_OVER_BOX_START_X = 70;
        static const int GAME_OVER_BOX_START_Y = 50;
        static const int GAME_OVER_BOX_WIDTH = 75;
        static const int GAME_OVER_BOX_HEIGHT = 75;
        static const int GAME_OVER_BOX_SPACING = 20;
        static const int GAME_OVER_CHART_WIDTH = 350;
        static const int GAME_OVER_CHART_HEIGHT = 100;
        static const int GAME_OVER_BUTTON_WIDTH = 100;
        static const int GAME_OVER_BUTTON_HEIGHT = 30;

};
}

#endif // CONSTANTS_H
