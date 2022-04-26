#ifndef SETTINGS_H
#define SETTINGS_H


namespace model
{

class Settings
{
    public:
        Settings();
        virtual ~Settings();
        void setReuseLetters(bool toSet);
        bool getReuseLetters();

    private:
        bool reuseLetters;
};
}

#endif // SETTINGS_H
