#ifndef DICTIONARYLOADER_H
#define DICTIONARYLOADER_H

#include "Dictionary.h"
using namespace model;

namespace datatier
{

// Dictionary Loader class
//
// Author - Team K
//
class DictionaryLoader
{
    public:

        // Constructs a dictionary loader
        //
        DictionaryLoader();

        // deconstructs a dictionary loader
        //
        virtual ~DictionaryLoader();

        // reads a file in and builds a trie
        //
        Dictionary readDictionaryFile();
};
}

#endif // DICTIONARYLOADER_H
