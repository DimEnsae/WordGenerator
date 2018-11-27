#include<string>
#include "vecteurTransition.h"

/*-------------------------------------------------------------
     Matrice de Transition de la chaine de Markov (ordre 1)
 
 Chaque ligne est un VecteurTransition associe a un sequence de longueur 1,
 une fois la matrice rendue stochastique elle sert de matrice de transition
 pour generer du texte.
 
 ------------------------------------------------------------*/

class matriceMot{
private:
    
    vecteurTransition *matriceTransition;
    int ascii;
    
public:
    
    //Constructor
    matriceMot();
    
    //Overload[]
    vecteurTransition& operator[] (const int index);
    vecteurTransition& operator[] (const char index);
    
    //Methods
    void afficherMatrice(std::string dic="abcdefghijklmnopqrstuvwxyz");
    void add_word(std:: string mot);
    void incrementerCompteurCase(char lettrePrecedente,char lettreSuivante);
    void rendreStochastique();
};
