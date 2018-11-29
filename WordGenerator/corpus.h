#ifndef CORPUS_H
#define CORPUS_H

#include<string>
#include "tensorMot.h"

/*---------------------------------------------------------------------------------
 
Un corpus peut être n'importe quel texte lisible en C++.
 La classe corpus s'occupe de la lecture, d'instancier un matrice de transition
 associee et de generer du texte selon cette matrice.
 
----------------------------------------------------------------------------------*/
class corpus{
    
private:
    
    std::string cheminFichier;
    matriceMot TransitionOrder1;
    tensorMot TransitionOrder2;

public:
    corpus(std::string cheminFichier);
    void afficherMatriceTransition();
    void genererUnMotOrdre1(char lettreInit,int tailleMot);
    void genererUnMotOrdre1Bis(int tailleMot, int nbmot=1);
    void genererUnMotOrdre2(char lettreInit1, char lettreInit2, int tailleMot);
    void genererUnMotOrdre2Bis(int tailleMot, int nbmot=1);
};

#endif
