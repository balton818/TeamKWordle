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
    vector<GuessCheckerResult> result;
    vector<char> duplicatesInGuess;

    if (this->guessCharRates.size() == 0)
    {
        this->determineGuessCharRates(guess);
    }

    for (int index = 0; index < 5; index++)
    {
        char currentLetter = toupper(guess[index]);
        if (this->answerCharRates[currentLetter] < this->guessCharRates[currentLetter] &&  this->answerCharRates[currentLetter] != 0)
        {
            if (find(duplicatesInGuess.begin(), duplicatesInGuess.end(), currentLetter) == duplicatesInGuess.end())
            {
                duplicatesInGuess.push_back(currentLetter);
            }
        }
        this->standardGuessParsing(index, currentLetter, result);
    }
    if (duplicatesInGuess.size() > 0)
    {
         this->handleGuessDuplicates(result, duplicatesInGuess, guess);
    }

    return result;
}

void GuessChecker::handleGuessDuplicates(vector<GuessCheckerResult>& result, vector<char>& duplicatesInGuess, string& guess)
{
    int firstInstanceIndex = 6;
    int correctIndex = -1;
    int duplicates = duplicatesInGuess.size() - 1;

    while (duplicates >= 0)
    {
        char currentDuplicate = duplicatesInGuess.at(duplicates);
        int duplicateRate = this->answerCharRates[currentDuplicate];
        for (int index = 0; index < this->answer.length(); index++)
        {
            if (guess[index] == currentDuplicate)
            {
                if (result[index] == GuessCheckerResult::CORRECT)
                {
                    correctIndex = index;
                    duplicateRate--;

                }
                if (correctIndex == firstInstanceIndex && correctIndex != index && duplicateRate <= 0)
                {
                    result.at(index) = GuessCheckerResult::DUPLICATE_WRONG;
                }
                if (correctIndex < 0 && firstInstanceIndex < 6 && duplicateRate <= 0)
                {
                    result.at(index) = GuessCheckerResult::DUPLICATE_WRONG;
                }

                if (index < firstInstanceIndex)
                {
                    firstInstanceIndex = index;
                    if (index != correctIndex)
                    {
                        duplicateRate--;
                    }
                }

                if (correctIndex > firstInstanceIndex && this->answerCharRates[currentDuplicate] == 1)
                {
                    result.at(firstInstanceIndex) = GuessCheckerResult::DUPLICATE_WRONG;
                    firstInstanceIndex = index;
                }
            }
        }
        duplicates--;
    }
}

void GuessChecker::standardGuessParsing(int index,char currentLetter, vector<GuessCheckerResult>& result)
{
    if (this->answer[index] == currentLetter)
    {
        result.push_back(GuessCheckerResult::CORRECT);
    }
    else if (this->answerCharRates[currentLetter])
    {
        result.push_back(GuessCheckerResult::WRONG_POSITION);
    }
    else
    {
        result.push_back(GuessCheckerResult::WRONG_LETTER);
    }
}

void GuessChecker::setAnswer(string& answerWord)
{
    this->answer = answerWord;
}

void GuessChecker::setAnswerCharRates(unordered_map<char,int> answerCharRates)
{
    this->answerCharRates = answerCharRates;
}

void GuessChecker::determineGuessCharRates(string& guess)
{
    for (int charPosition = 0; charPosition < guess.size(); charPosition++) {
        this->guessCharRates[guess[charPosition]]++;
    }
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
