#include "Settings.h"

namespace model
{

Settings::Settings()
{
    this->onlyUniqueChars = false;
    this->playerCanReuseChars = true;
    this->hardMode = false;
}

Settings::~Settings()
{
    //dtor
}

void Settings::setOnlyUniqueChars(bool toSet)
{
    this->onlyUniqueChars = toSet;
}

bool Settings::getOnlyUniqueChars()
{
    return this->onlyUniqueChars;
}

void Settings::setPlayerReuseChars(bool toSet)
{
    this->playerCanReuseChars = toSet;
}

bool Settings::getPlayerReuseChars()
{
    return this->playerCanReuseChars;
}

void Settings::setHardMode(bool toSet)
{
    this->hardMode = toSet;
}

bool Settings::getHardMode()
{
    return this->hardMode;
}

}
