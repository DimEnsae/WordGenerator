#include<string>
#include "vecteurLettre.h"
class matriceMot{
private:
  std::string mot;
  vecteurLettre *matriceTransition;
  std::string listeLettreMatrice;
public:
  matriceMot(std::string mot,std::string listeLettreMatrice);//La matrice sera remplie dans le constructeur.
  matriceMot(std::string listeLettreMatrice);
  std::string getMot();
  void incrementerCompteurCase(char lettrePrecedente,char lettreSuivante);
  //Redéfinition de l'operateur +
  matriceMot operator + (matriceMot m);
  void afficherMatrice();
  void rendreStochastique();
  std::string getListeLettreMatrice();
  vecteurLettre getMatriceTransition(int i);
};
