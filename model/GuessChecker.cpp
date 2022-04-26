#include "GuessChecker.h"

#include <algorithm>
#include <string>
using namespace std;

namespace model
{

GuessChecker::GuessChecker(string& answerWord)
{
    transform(answerWord.begin(), answerWord.end(), answerWord.begin(), ::toupper);
    this->answer = answerWord;
}

vector<GuessCheckerResult> GuessChecker::checkGuess(string& guess)
{
    vector<GuessCheckerResult> result;
    for (int index = 0; index < 5; index++)
    {
        char currentLetter = toupper(guess[index]);
        if (this->answer[index] == currentLetter)
        {
            result.push_back(GuessCheckerResult::CORRECT);
        }
        else if (this->answerContains(currentLetter))
        {
            result.push_back(GuessCheckerResult::WRONG_POSITION);
        }
        else
        {
            result.push_back(GuessCheckerResult::WRONG_LETTER);
        }
    }
    return result;
}

bool GuessChecker::answerContains(char letter)
{
    for (int index = 0; index < this->answer.length(); index++)
    {
        if (this->answer[index] == letter)
        {
            return true;
        }
    }
    return false;
}

GuessChecker::~GuessChecker()
{
    //dtor
}
}
