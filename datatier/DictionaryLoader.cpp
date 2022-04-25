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
    Dictionary dictionary;
    ifstream dictFile("dictionary.txt");
    string line;

    while(getline(dictFile, line))
        {
            if (line.size() == 6)
            {
                dictionary.insertWord(line);
            }

        }

    dictFile.close();
    return dictionary;
}


}
