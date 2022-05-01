#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <vector>
#include <bits/stdc++.h>
using namespace std;
#include "DictionaryNode.h"
namespace model
{

// Dictionary class for wordle.
//
// Author - Team K
//
class Dictionary
{
public:

    // Constructs a dictionary object
    //
    Dictionary();

    // Dictionary destructor
    //
    virtual ~Dictionary();

    // Inserts a word into the dictionary trie structure
    //
    // Param - wordToInsert the word to insert into the trie
    //
    void insertWord(string& wordToInsert);

    // Check if a word is present in the dictionary if it is the word is valid
    //
    // Param - wordToCheck the word that is searched for in the trie
    //
    // Returns - true if the word is valid, false otherwise
    //
    bool isValidWord(string& wordToCheck);

    // Gets a random word for the player to guess
    //
    // Param - reuseLetters - indicates if guess word can reuse letters
    //
    // Returns - the word for the player to guess
    //
    string& getWordToGuess(bool canReuseLetters);

        // Param - wordToInsert the word to insert into the trie
        //
        void insertWord(string& wordToInsert);

        // Check if a word is present in the dictionary if it is the word is valid
        //
        // Param - wordToCheck the word that is searched for in the trie
        //
        // Returns - true if the word is valid, false otherwise
        //

private:

        // Gets a random word for the player to guess
        //
        // Param - reuseLetters - indicates if guess word can reuse letters
        //
        // Returns - the word for the player to guess
        //
        string& getWordToGuess(bool canReuseLetters);

        unordered_map<char, int> getAnswerCharRates();

    private:

        DictionaryNode* root;
        string wordToGuess;
        int getRandomIndex();
        char trieOffset = 'A';
        int getNextLetter(DictionaryNode* tempNode, DictionaryNode* dictCrawler,int randomIndex);
        bool checkIfUniqueChars(char wordBuilder[]);
        void generateWordToGuess(bool canReuseLetters);
        bool reUseLettersCheck(bool canReuseLetters, char wordBuilder[]);
        unordered_map<char, int> answerCharRates;
};
}
#endif // DICTIONARY_H
