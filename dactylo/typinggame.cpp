#include "typinggame.h"

TypingGame::TypingGame(const std::string& texteReference):d_texteReference{texteReference},d_stats{}
{
    //ctor
}

TypingGame::~TypingGame()
{
    //dtor
}

void TypingGame::run()
{
    std::string input=readInput();
    d_stats.stopTimer();
    d_stats.afficherStats(input.size());
}

std::string TypingGame::readInput()
{
    std::string input;
    char c;
    bool started= false;


    while (true)
    {
        c = _getch();

        if (!started)                  // <-- ajouter ce bloc
        {
            d_stats.startTimer();
            started = true;
        }

        if (c == '\r' || c== '\n')
        {
            std::cout<< std::endl;
            break;
        }

        if (c == '\b')
        {
            if (!input.empty())
            {
                d_stats.addBackspace();
                input.pop_back();

                std::cout<<"\b \b";
            }
        }
        else
        {
            if(input.size()<d_texteReference.size())
            {
                char attendu = d_texteReference[input.size()];
                if (c != attendu)
                {
                    d_stats.addError(attendu, c);
                }
                else
                {
                    d_stats.addCorrectKey();
                }

                input.push_back(c);
                std::cout << c;
                std::cout.flush();
            }
            else
            {
                std::cout<<"\nDebordement"<<std::endl;
                break;
            }

        }
    }
    return input;
}


