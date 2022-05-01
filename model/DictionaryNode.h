#ifndef DICTIONARYNODE_H
#define DICTIONARYNODE_H
#define ALPHA_CHARS 26

#include <memory>
using namespace std;

namespace model
{

// the dictionary node class for the dictionary trie
//
// Author - Team K
//
class DictionaryNode
{
public:

    // Dictionary Node constructor
    //
    DictionaryNode();

    // Dictionary Node destructor
    //
    virtual ~DictionaryNode();

    // checks if current node is the end of a word
    //
    // Returns - true if node is end of word, false otherwise
    //
    bool isEndOfWord();

    // sets node to be end of word or not
    //
    // Param - toSet - indicates if node is to be set as end of word
    //
    void setEndOfWord(bool toSet);

    // the nodes children.
    //
    DictionaryNode* children[ALPHA_CHARS];

private:
    bool endOfWord;
};
}

#endif // DICTIONARYNODE_H
