#ifndef TENSORMOT_H
#define TENSORMOT_H

#include<string>
#include "matriceMot.h"

/*-------------------------------------------------------------
 Matrice de Transition de la chaine de Markov (ordre 2)
 
 Stock les VecteurTransition associes a des sequences de longueur 2,
 une fois le tenseur rendue stochastique il sert de tenseur de transition
 pour generer du texte.
 
 ------------------------------------------------------------*/

class tensorMot{
private:
    
    matriceMot *tensorTransition;
    int ascii;
    
public:
    
    //Constructor
    tensorMot();
    
    //Overload []
    matriceMot& operator[] (const int index);
    matriceMot& operator[] (const char index);
    
    //Methods
    void add_word(std:: string mot);
    void incrementerCompteurCase(char lettrePrec1, char lettrePrec2,char lettreSuiv);
    void rendreStochastique();
};

#endif
