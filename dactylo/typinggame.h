#ifndef TYPINGGAME_H
#define TYPINGGAME_H

#include <string>
#include "gamestats.h"
#include <conio.h>

class TypingGame
{
    public:
        TypingGame(const std::string& texte);
        virtual ~TypingGame();

        void run();
        std::string readInput();
    protected:

    private:

        std::string d_texteReference;

        GameStats d_stats;
};

#endif // TYPINGGAME_H
