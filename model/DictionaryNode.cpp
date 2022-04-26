#include "DictionaryNode.h"

#include <iostream>
using namespace std;

namespace model
{

DictionaryNode::DictionaryNode()
{
     //DictionaryNode* dictNode = new DictionaryNode();

	for (int i = 0; i < ALPHA_CHARS; i++)
    {
        this->children[i] = NULL;
    }

	this->endOfWord = false;

}

DictionaryNode::~DictionaryNode()
{
    for (int i = 0; i < ALPHA_CHARS; i++)
    {
        delete this->children[i];
    }

}
void DictionaryNode::setEndOfWord(bool toSet)
{
    this->endOfWord = toSet;
}


//
//DictionaryNode* DictionaryNode::createNode()
//{
//    DictionaryNode* dictNode = new DictionaryNode();
//
//	for (int i = 0; i < ALPHA_CHARS; i++)
//    {
//        dictNode->children[i] = NULL;
//    }
//
//	dictNode->isEndOfWord = false;
//
//	return dictNode;
//};

bool DictionaryNode::isEndOfWord()
{
    return this->endOfWord;
}

}
