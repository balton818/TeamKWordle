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
    int duplicates = duplicatesInGuess.size() - 1;

    while (duplicates >= 0)
    {
        char currentDuplicate = duplicatesInGuess.at(duplicates);
        int duplicateRate = this->answerCharRates[currentDuplicate];
        this->duplicateGuessParsing(currentDuplicate, duplicateRate, guess, result);
        duplicates--;
    }
}

void GuessChecker::duplicateGuessParsing(char& currentDuplicate, int& duplicateRate, string& guess, vector<GuessCheckerResult>& result)
{
    int firstInstanceIndex = 6;
    int correctIndex = -1;

    for (int index = 0; index < this->answer.length(); index++)
    {
        if (guess[index] == currentDuplicate)
        {
            this->duplicateGuessParsingConditions(firstInstanceIndex, correctIndex, duplicateRate, result, index);

            if (correctIndex > firstInstanceIndex && this->answerCharRates[currentDuplicate] == 1)
            {
                result.at(firstInstanceIndex) = GuessCheckerResult::DUPLICATE_WRONG;
                firstInstanceIndex = index;
            }
        }
    }
}

void GuessChecker::duplicateGuessParsingConditions(int& firstInstanceIndex, int& correctIndex, int& duplicateRate, vector<GuessCheckerResult>& result, int currentIndex)
{
    if (result[currentIndex] == GuessCheckerResult::CORRECT)
    {
        correctIndex = currentIndex;
        duplicateRate--;
    }
    if (correctIndex == firstInstanceIndex && correctIndex != currentIndex && duplicateRate <= 0)
    {
        result.at(currentIndex) = GuessCheckerResult::DUPLICATE_WRONG;
    }
    if (correctIndex < 0 && firstInstanceIndex < this->answer.size() && duplicateRate <= 0)
    {
        result.at(currentIndex) = GuessCheckerResult::DUPLICATE_WRONG;
    }
    if (currentIndex < firstInstanceIndex)
    {
        firstInstanceIndex = currentIndex;

        if (currentIndex != correctIndex)
        {
            duplicateRate--;
        }
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
    this->guessCharRates.clear();
    for (int charPosition = 0; charPosition < guess.size(); charPosition++) {
        this->guessCharRates[guess[charPosition]]++;
    }
}


GuessChecker::~GuessChecker()
{
    //dtor
}
}
