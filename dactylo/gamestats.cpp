#include "gamestats.h"

GameStats::GameStats():d_fautes{0},d_correctes{0},d_backspaces{0},d_erreursParLettre{}
{
    //ctor
}

GameStats::~GameStats()
{
    //dtor
}

void GameStats::startTimer()
{
    d_debut=std::chrono::steady_clock::now();
}

void GameStats::stopTimer()
{
    d_fin=std::chrono::steady_clock::now();
}

void GameStats::addError(char attendu,char obtenu)
{
    d_fautes++;
    d_erreursParLettre[attendu]++;
}

void GameStats::addCorrectKey()
{
    d_correctes++;
}

void GameStats::addBackspace()
{
    d_backspaces++;
}

int GameStats::getFautes()
{
    return d_fautes;
}

double GameStats::getPrecision()
{
    int totalFrappes = d_fautes + d_correctes;
    if (totalFrappes == 0)
        return 100.0;

    return (static_cast<double>(d_correctes) / totalFrappes) * 100.0;
}

double GameStats::getDuration()
{
    std::chrono::duration<double> duree = d_fin-d_debut;
    return duree.count();
}

void GameStats::afficherStats(int size_input)
{
    std::cout<<"Statistiques de fin de jeu"<<endl;
    std::cout<<"Temps ecoule : " <<getDuration() << "secondes" <<endl;
    std::cout<<"Nombres de backspace utlises : "<< d_backspaces<<endl;
    std::cout<<"Nombre de fautes : "<< d_fautes <<endl;
    std::cout<<"Precision : "<< getPrecision() <<"%"<<endl;
    std::cout<<"Nombres de mots tapes par minutes (MPM) : "<< getWPM(size_input)<<endl;

    std::cout << "Lettres les plus difficiles pour vous :" << endl;
    for (const auto& [lettre, nbErr] : getWorstLetters(6))
    {
        if (lettre == ' ')
            std::cout << "[space] : " << nbErr << " erreurs" << endl;
        else if (lettre == '\n')
            std::cout << "[enter] : " << nbErr << " erreurs" << endl;
        else
            std::cout << lettre << " : " << nbErr << " erreurs" << endl;
    }

}

double GameStats::getWPM(int size_input)
{
    double duree=getDuration();
    double minutes = duree/60.0;
    return (size_input/5.0)/minutes;

}

std::vector<std::pair<char,int>> GameStats::getWorstLetters(int n)
{
    std::vector<std::pair<char,int>> lettres(d_erreursParLettre.begin(), d_erreursParLettre.end());

    std::sort(lettres.begin(), lettres.end(),
              [](const std::pair<char,int>& a, const std::pair<char,int>& b)
              {
                  return a.second > b.second;
              });

    if (n >= 0 && static_cast<int>(lettres.size()) > n)
    {
        lettres.resize(n);
    }

    return lettres;
}
