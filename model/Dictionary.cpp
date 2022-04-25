#include "Dictionary.h"

#include <iostream>
#include <string>
#include <iostream>
#include <string.h>
#include <random>
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

    for (int currentChar = 0; currentChar < wordToInsert.length() -1 ; currentChar++)
    {
        int insertLocation = wordToInsert[currentChar] - this->trieOffset;
        if (dictCrawler->children[insertLocation] == NULL)
            dictCrawler->children[insertLocation] = new DictionaryNode();

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

string& Dictionary::getWordToGuess()
{
    char wordBuilder[5];
    DictionaryNode* dictCrawler = this->root;
    int randomIndex = this->getRandomIndex();

    for (int charIndex = 0; charIndex < sizeof(wordBuilder); charIndex++) {

        DictionaryNode* tempNode = dictCrawler->children[randomIndex];

        while (tempNode == NULL)
        {
            randomIndex = this->getRandomIndex();
            tempNode = dictCrawler->children[randomIndex];
        }

        wordBuilder[charIndex] = randomIndex + this->trieOffset;

        randomIndex = this->getRandomIndex();
        dictCrawler = tempNode;
    }

    if (dictCrawler->isEndOfWord())
    {
        this->wordToGuess = wordBuilder;
        cout << this->wordToGuess << endl;
        return this->wordToGuess;
    }
}

int Dictionary::getRandomIndex()
{
    random_device random;
    default_random_engine engine(random());
    uniform_int_distribution<int> range(0, ALPHA_CHARS);
    return range(engine);
}
}
