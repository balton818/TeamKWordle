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

// The guessChecker class responsible for checking guesses and relaying needed to changes for the wordle game.
//
// Author - Team k
//
class GuessChecker
{
    private:

        string answer;
        void determineGuessCharRates(string& guess);
        unordered_map<char,int> guessCharRates;
        unordered_map<char,int> answerCharRates;

        void standardGuessParsing(int index, char currentLetter, vector<GuessCheckerResult>& result);
        void handleGuessDuplicates(vector<GuessCheckerResult>& result, vector<char>& duplicatesInGuess,string& guess);
        void duplicateGuessParsing(char& currentDuplicate, int& duplicateRate, string& guess, vector<GuessCheckerResult>& result);
        void duplicateGuessParsingConditions(int& firstInstanceIndex, int& correctIndex, int& duplicateRate, vector<GuessCheckerResult>& result, int currentIndex);

    public:

        // Constructs a GuessChecker
        //
        GuessChecker();

        // deconstructs a GuessChecker
        //
        virtual ~GuessChecker();

        // Checks a user's guess against the current answer
        //
        // precondition - none
        // postcondition - guessCharRates.size() > 0
        //
        // Param - guess - the user's guess to be checked.
        //
        // Returns - a vector indicating the results in regards to letter position and correctness
        //
        vector<GuessCheckerResult> checkGuess(string& guess);

        // sets the current answer for the game
        //
        // Param - answerWord - the current answer
        //
        void setAnswer(string& answerWord);

        // sets the answer char rates
        //
        // Param - a map with the chars in the current answer as keys and their rates as values
        //
        void setAnswerCharRates(unordered_map<char,int> answerCharRates);

};
}

#endif // GUESSCHECKER_H
