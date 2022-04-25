#include "DictionaryLoader.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;
#include "Dictionary.h"
using namespace model;

namespace datatier
{

DictionaryLoader::DictionaryLoader()
{

}

DictionaryLoader::~DictionaryLoader()
{

}

Dictionary DictionaryLoader::readDictionaryFile()
{
    int lineSize = 6;
    Dictionary dictionary;
    ifstream dictFile("dictionary.txt");
    string line;

    while(getline(dictFile, line))
        {
            if (line.size() == lineSize)
            {
                dictionary.insertWord(line);
            }

        }

    dictFile.close();
    return dictionary;
}


}
