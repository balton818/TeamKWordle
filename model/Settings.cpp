#include "Settings.h"

namespace model
{

Settings::Settings()
{
    this->onlyUniqueChars = false;
    this->hardMode = false;
}

void Settings::setOnlyUniqueChars(bool toSet)
{
    this->onlyUniqueChars = toSet;
}

bool Settings::getOnlyUniqueChars()
{
    return this->onlyUniqueChars;
}

void Settings::setHardMode(bool toSet)
{
    this->hardMode = toSet;
}

bool Settings::getHardMode()
{
    return this->hardMode;
}

Settings::~Settings()
{
    //dtor
}

}
