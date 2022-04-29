#include "GuessChecker.h"

#include <algorithm>
#include <string>
using namespace std;

namespace model
{

GuessChecker::GuessChecker()
{

}

vector<GuessCheckerResult> GuessChecker::checkGuess(string& guess)
{
    int duplicateTracking = 0;
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

void GuessChecker()::setAnswerCharRates(unordered_map<char, int> answerCharRates)
{
    this->answerCharRates = answerCharRates;
}

void GuessChecker::setAnswer(string& answerWord)
{
    this->answer = answerWord;
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

void GuessChecker::determineGuessCharRates(string& guess)
{
    for (int charPosition = 0; charPosition < strlen(guess); charPosition++) {
        this->guessCharRates[guess[charPosition]]++;
    }
}

GuessChecker::~GuessChecker()
{
    //dtor
}
}
