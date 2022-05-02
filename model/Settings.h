#ifndef SETTINGS_H
#define SETTINGS_H


namespace model
{

// The wordle game settings class
//
// Author - Team K
//
class Settings
{

public:

    // Constructs a settings object
    //
    Settings();

    // Deconstructs a settings object
    //
    virtual ~Settings();

    // sets word generation to only produce words with unique chars.
    //
    // Param - the bool indicating if the setting is enabled (true) or disabled (false)
    //
    void setOnlyUniqueChars(bool toSet);

    // get the bool indicating if the setting is enabled
    //
    // Return - true if enabled, false otherwise
    //
    bool getOnlyUniqueChars();

    // sets the ability of the player to reuse characters
    //
    // Param - the bool indicating if the setting is enabled (true) or disabled (false)
    //
    void setPlayerReuseChars(bool toSet);

    // get the bool indicating if the setting is enabled
    //
    // Return - true if enabled, false otherwise
    //
    bool getPlayerReuseChars();

    // sets hard mode meaning that the player must include any partially or fully correct letters in subsequent guesses.
    //
    // Param - the bool indicating if the setting is enabled (true) or disabled (false)
    //
    void setHardMode(bool toSet);

    // get the bool indicating if the setting is enabled
    //
    // Return - true if enabled, false otherwise
    //
    bool getHardMode();

private:

    bool onlyUniqueChars;
    bool playerCanReuseChars;
    bool hardMode;
};

}

#endif // SETTINGS_H
