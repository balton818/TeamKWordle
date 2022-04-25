#ifndef DICTIONARYNODE_H
#define DICTIONARYNODE_H
#define ALPHA_CHARS 26

#include <memory>
using namespace std;

namespace model
{
class DictionaryNode
{
    public:
        DictionaryNode();
        virtual ~DictionaryNode();
        DictionaryNode* createNode();
        bool isEndOfWord();
        void setEndOfWord(bool toSet);
        DictionaryNode* children[ALPHA_CHARS];

    private:
        bool endOfWord;
};
}

#endif // DICTIONARYNODE_H
