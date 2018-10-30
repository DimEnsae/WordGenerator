#include<string>
class vecteurLettre{

private:
std::string listeLettre; //pour avoir le nombre de colonnes de la matrice de transition(évite d'allouer de l'espace mémoire à rien dutout)
char lettreLigne; //Il faudra faire en sorte par la suite que ce ne soit plus une lettre ligne mais un coupletriplet etc..
char *nomsColonnes;//ce sera une liste peut re redondant avec la liste lettre dut mot
float *nombreOccurence; //Ce sera une liste

public:
  vecteurLettre(char lettreLigne,std::string listeLettre);
  vecteurLettre();//conctructeur sans rien avec des pointeurs nuls pour l'intitialisation de la matriceMot
  char getlettreLigne();
  void afficher();
  void afficherBis();
  vecteurLettre operator + (vecteurLettre v);
  void incrementerCompteurLettre(char lettre);
  void rendreStochastique();
  char selectionnerLettreSuivante();

};
