#include<string>

/*--------------------------------------------------------------------------
        Tableau unidimensionnel de taille "ascii"
 
 Permet de stocker le nombre de fois où chaque caractere a ete observe
 apres "lettre" dans un mot ou un corpus.
 
 rendreStochastique transforme ces occurences en loi de probabilite
 
 
 
 ---------------------------------------------------------------------------*/

class vecteurLettre{

private:

    char lettre;
    int ascii;
    float *nombreOccurence;

public:
    
    //Constructor
    vecteurLettre();
    vecteurLettre(char lettre);
    
    //Getter
    char getlettre();
    float getnombreOccurence(char a);
    
    void afficher(std::string dic);
    void incrementerCompteurLettre(char lettre);
    void rendreStochastique();
    
    char selectionnerLettreSuivante();

};
