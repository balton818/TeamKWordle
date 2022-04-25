#ifndef DICTIONARYLOADER_H
#define DICTIONARYLOADER_H
#include "Dictionary.h"
using namespace model;

namespace datatier
{
class DictionaryLoader
{
    public:
        DictionaryLoader();
        virtual ~DictionaryLoader();
        Dictionary readDictionaryFile();
};
}

#endif // DICTIONARYLOADER_H
