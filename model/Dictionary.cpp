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
        if (!canReuseLetters)
        {
            if (!this->checkIfUniqueChars(wordBuilder))
            {
                this->wordToGuess = "";
                return;
            }
        }
    }
    this->wordToGuess = wordBuilder;
}

bool Dictionary::checkIfUniqueChars(char wordBuilder[])
{
    unordered_map<char, int> rates;
    for (int charPosition = 0; charPosition < strlen(wordBuilder); charPosition++) {
        rates[wordBuilder[charPosition]]++;
    }
    for (auto currentChar : rates) {
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
