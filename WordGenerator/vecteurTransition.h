#include<string>

/*---------------------------------------------------------------------------------------------
                Tableau unidimensionnel de taille "ascii"
 
 Permet de stocker le nombre de fois où chaque caractere a ete observe
 apres une sequence de lettres (la longueur de la sequence est l'ordre de la chaine de Markov)
 dans un mot ou un corpus.
 
 rendreStochastique transforme ces occurences en loi de probabilite.
 
 Exemple avec chaine de Markov d'ordre 1 :
 
 corpus = "banane"
 Le vecteurTransition associe a la sequence "n" comportera un 1 dans la case a et dans la case e
 et des 0 ailleurs, les 1 se transorment en 0.5 apres normalisation.
 
  Exemple avec chaine de Markov d'ordre 2 :
 
 A l'ordre deux il faut considerer les sequences "ba", "an", "na", "an", "ne"
 Le vecteurTransition associe a la sequence "na" comportera un 1 dans la case a et dans la case e
 et des 0 ailleurs, les 1 se transorment en 0.5 apres normalisation.
 
 ---------------------------------------------------------------------------------------------*/

class vecteurTransition{

private:

    int ascii;
    float *nombreOccurence;

public:
    
    //Constructor
    vecteurTransition();
    
    //Overload []
    float& operator[] (const int index);
    float& operator[] (const char index);
    //float& operator[] (const int ind1, const int ind2);

    //Methods
    void afficher(std::string dic="abcdefghijklmnopqrstuvwxyz"); //A ameliorer surcharge <<
    void incrementerCompteurLettre(char lettre);
    void rendreStochastique();
    char selectionnerLettreSuivante();

};
