#ifndef GUESSCHECKER_H
#define GUESSCHECKER_H

#include "GuessCheckerResult.h"
using namespace enums;

#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

namespace model
{
class GuessChecker
{
private:
    string answer;
    bool answerContains(char letter);
    unordered_map<char, int> guessCharRates;
    unordered_map<char, int> answerCharRates;

public:
    GuessChecker();
    virtual ~GuessChecker();
    vector<GuessCheckerResult> checkGuess(string& guess);
    void setAnswer(string& answerWord);
    void setAnswerCharRates(unordered_map<char, int> answerCharRates);
    void determineGuessCharRates(string& guess);

};
}

#endif // GUESSCHECKER_H
