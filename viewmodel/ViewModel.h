#ifndef VIEWMODEL_H
#define VIEWMODEL_H

#include "User.h"
#include "Settings.h"
#include "Dictionary.h"
using namespace model;

#include "DictionaryLoader.h"
using namespace datatier;

class ViewModel
{
    public:
        ViewModel();
        virtual ~ViewModel();


    private:
        User currentUser;
        Dictionary wordleDictionary;
        Settings gameSettings;

};

#endif // VIEWMODEL_H
