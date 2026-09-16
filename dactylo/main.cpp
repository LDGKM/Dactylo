#include <iostream>
#include <fstream>
#include <string>
#include "typinggame.h"

using namespace std;

int main()
{
    std::string cheminTexteReference{"texteReference.txt"};
    std::fstream fichier{cheminTexteReference};

    if(!fichier)
    {
        cout<<"Une erreur dans le fichier reference"<<endl;
        return 0;
    }

    std::string texteReference;
    std::string ligne;

    while (std::getline(fichier,ligne))
    {
        if (!texteReference.empty())
            texteReference += "\n";
        texteReference += ligne;
    }
    fichier.close();

    cout << texteReference << endl;
    cout << "A vous de jouer :" << endl;

    TypingGame tG{texteReference};
    tG.run();
    return 0;
}
