#include "Settings.h"

namespace model
{

Settings::Settings()
{
    this->reuseLetters = false;
}

Settings::~Settings()
{
    //dtor
}

void Settings::setReuseLetters(bool toSet)
{
    this->reuseLetters = toSet;
}

bool Settings::getReuseLetters()
{
    return this->reuseLetters;
}

}
