#include<string>
#include "vecteurLettre.h"

class matriceMot{
private:
  std::string mot;
  vecteurLettre *matriceTransition;
  int ascii;
public:
  matriceMot(std::string mot);
  matriceMot();
  std::string getMot();
  void incrementerCompteurCase(char lettrePrecedente,char lettreSuivante);
  matriceMot operator + (matriceMot m);
  void afficherMatrice();
  void rendreStochastique();
  vecteurLettre getMatriceTransition(char a);
};
