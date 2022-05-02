#include "Dictionary.h"

#include <iostream>
#include <string>
#include <random>
#include <bits/stdc++.h>
using namespace std;

namespace model
{

Dictionary::Dictionary()
{
    this->root = new DictionaryNode();
}

Dictionary::~Dictionary()
{
    delete this->root;
}

void Dictionary::insertWord(string& wordToInsert)
{
    DictionaryNode* dictCrawler = this->root;

    for (int currentChar = 0; currentChar < wordToInsert.length() -1; currentChar++)
    {
        int insertLocation = wordToInsert[currentChar] - this->trieOffset;

        if (dictCrawler->children[insertLocation] == NULL)
        {
            dictCrawler->children[insertLocation] = new DictionaryNode();
        }

        dictCrawler = dictCrawler->children[insertLocation];
    }

    dictCrawler->setEndOfWord(true);
}


bool Dictionary::isValidWord(string& wordToCheck)
{
    DictionaryNode* dictCrawler = this->root;

    for (int currentChar = 0; currentChar < wordToCheck.length(); currentChar++)
    {
        int location = wordToCheck[currentChar] - this->trieOffset;

        if (dictCrawler->children[location] == NULL)
        {
            return false;
        }

        dictCrawler = dictCrawler->children[location];
    }
    return dictCrawler->isEndOfWord();
}

string& Dictionary::getWordToGuess(bool canReuseLetters)
{
    this->wordToGuess = "";
    this->generateWordToGuess(canReuseLetters);

    while(this->wordToGuess == "")
    {
        this->generateWordToGuess(canReuseLetters);
    }
    return this->wordToGuess;
}

void Dictionary::generateWordToGuess(bool canReuseLetters)
{
    char wordBuilder[5];
    DictionaryNode* dictCrawler = this->root;
    int randomIndex = this->getRandomIndex();

    for (int charIndex = 0; charIndex < sizeof(wordBuilder); charIndex++) {

        DictionaryNode* tempNode = dictCrawler->children[randomIndex];
        randomIndex = this->getNextLetter(tempNode, dictCrawler, randomIndex);
        tempNode = dictCrawler->children[randomIndex];
        wordBuilder[charIndex] = randomIndex + this->trieOffset;
        randomIndex = this->getRandomIndex();
        dictCrawler = tempNode;
    }

    if (dictCrawler->isEndOfWord())
    {
        if (!this->reUseLettersCheck(canReuseLetters, wordBuilder))
        {
            return;
        }
    }
    this->wordToGuess = wordBuilder;
}



bool Dictionary::reUseLettersCheck(bool canReuseLetters, char wordBuilder[])
{
     if (!this->checkIfUniqueChars(wordBuilder))
    {
        if (!canReuseLetters)
        {
            this->wordToGuess = "";
            return false;
        }
    }
    return true;
}

unordered_map<char, int> Dictionary::getAnswerCharRates()
{
    return this->answerCharRates;
}

bool Dictionary::checkIfUniqueChars(char wordBuilder[])
{
    this->answerCharRates.clear();

    for (int charPosition = 0; charPosition < strlen(wordBuilder); charPosition++)
    {
        this->answerCharRates[wordBuilder[charPosition]]++;
    }

    for (auto currentChar : this->answerCharRates)
    {
        if (currentChar.second > 1)
            return false;
    }
    return true;
}

int Dictionary::getNextLetter(DictionaryNode* tempNode, DictionaryNode* dictCrawler, int randomIndex)
{
    while (tempNode == NULL)
    {
        randomIndex = this->getRandomIndex();
        tempNode = dictCrawler->children[randomIndex];
    }
    return randomIndex;

}



int Dictionary::getRandomIndex()
{
    random_device random;
    default_random_engine engine(random());
    uniform_int_distribution<int> range(0, ALPHA_CHARS - 1);
    return range(engine);
}

}
