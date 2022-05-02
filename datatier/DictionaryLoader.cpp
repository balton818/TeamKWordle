#include "DictionaryLoader.h"

#include "Dictionary.h"
using namespace model;

#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

namespace datatier
{

DictionaryLoader::DictionaryLoader()
{

}

DictionaryLoader::~DictionaryLoader()
{

}

Dictionary* DictionaryLoader::readDictionaryFile()
{
    int lineSize = 6;
    Dictionary* dictionary = new Dictionary();
    ifstream dictFile("dictionary.txt");
    string line;

    while(getline(dictFile, line))
    {
        if (line.size() == lineSize)
        {
            transform(line.begin(), line.end(), line.begin(), ::toupper);
            dictionary->insertWord(line);
        }

    }

    dictFile.close();
    return dictionary;
}

}
