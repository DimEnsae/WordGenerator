#include<string>
#include "matriceMot.h"

/*---------------------------------------------------------------------------------
 
Un corpus peut être n'importe quel texte lisible en C++.
 La classe corpus s'occupe de la lecture, d'instancier un matrice de transition
 associee et de generer du texte selon cette matrice.
 
----------------------------------------------------------------------------------*/
class corpus{
    
private:
    
    std::string cheminFichier;
    matriceMot matriceMotTransition;

public:
    corpus(std::string cheminFichier);
    void afficherMatriceTransition();
    void genererUnMot(char lettreInitiale,int tailleMot);
};
