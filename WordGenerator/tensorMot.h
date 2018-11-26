#include<string>
#include "matriceMot.h"

/*-------------------------------------------------------------
 
 ------------------------------------------------------------*/

class tensorMot{
private:
    matriceMot *tensorTransition;
    int ascii;
    
public:
    
    tensorMot();
    void afficherTensor(std::string dic);
    void add_word(std:: string mot);
    void incrementerCompteurCase(char lettrePrec1, char lettrePrec2,char lettreSuiv);
    void rendreStochastique();
};


