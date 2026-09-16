#ifndef GAMESTATS_H
#define GAMESTATS_H

#include <map>
#include <chrono>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
using namespace chrono;

class GameStats
{
    public:
        GameStats();
        virtual ~GameStats();
        void startTimer();
        void stopTimer();
        void addError(char attendu, char obtenu);
        void addCorrectKey();
        void addBackspace();
        double getDuration();
        void afficherStats(int size_input);
        double getWPM(int size_input);
        double getPrecision();
        int getFautes();
        std::vector<std::pair<char,int>> getWorstLetters(int n);

    protected:

    private:

        int d_fautes;

        int d_correctes;

        int d_backspaces;

        std::map<char, int> d_erreursParLettre;

        std::chrono::steady_clock::time_point d_debut;

        std::chrono::steady_clock::time_point d_fin;
};

#endif // GAMESTATS_H
