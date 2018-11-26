#include<string>
#include "vecteurLettre.h"

/*-------------------------------------------------------------
     Matrice de Transition de la chaine de Markov (ordre 1)
 
 Chaque ligne est un VecteurLettre, une fois la matrice rendue
 stochastique elle sert de matrice de transition pour generer
 du texte.
 
 ------------------------------------------------------------*/

class matriceMot{
private:
    
    vecteurLettre *matriceTransition;
    int ascii;
    
public:
    
    matriceMot();
    vecteurLettre getMatriceTransition(char a);
    void afficherMatrice(std::string dic);
    void add_word(std:: string mot);
    void incrementerCompteurCase(char lettrePrecedente,char lettreSuivante);
    void rendreStochastique();
};
