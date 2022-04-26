#ifndef GUESSCHECKER_H
#define GUESSCHECKER_H

#include "GuessCheckerResult.h"
using namespace enums;

#include <string>
#include <vector>
using namespace std;

namespace model
{
class GuessChecker
{
    private:
        string answer;
        bool answerContains(char letter);

    public:
        GuessChecker(string& answerWord);
        virtual ~GuessChecker();
        vector<GuessCheckerResult> checkGuess(string& guess);
};
}

#endif // GUESSCHECKER_H