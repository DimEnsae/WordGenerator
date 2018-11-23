#include<string>
#include "vecteurLettre.h"

class matriceMot{
private:
  std::string mot;
  vecteurLettre *matriceTransition;
  int ascii;
public:
  matriceMot();
  void add_word(std:: string mot);
  void incrementerCompteurCase(char lettrePrecedente,char lettreSuivante);
    void afficherMatrice(std::string dic);
  void rendreStochastique();
  vecteurLettre getMatriceTransition(char a);
};
