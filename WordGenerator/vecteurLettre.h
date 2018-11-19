#include<string>

class vecteurLettre{

private:
std::string listeLettre; //Ex : 'abcdefghijklmnopqrstuvwxyz'
//pour avoir le nombre de colonnes de la matrice de transition(évite d'allouer de l'espace mémoire à rien du tout) -> Peut etre ameliorer en utilisant les encodage ASCII
char lettreLigne; //Ex : b et on regarde ce qui suit b
//Il faudra faire en sorte par la suite que ce ne soit plus une lettre ligne mais un couple, triplet etc.. -> Voiture matric multidimensionnelle
char *nomsColonnes;
//ce sera une liste peut re redondant avec la liste lettre dut mot
float *nombreOccurence; //Ce sera une liste

public:
  vecteurLettre(char lettreLigne,std::string listeLettre);
  vecteurLettre();//conctructeur sans rien avec des pointeurs nuls pour l'intitialisation de la matriceMot
  char getlettreLigne();
  float getnombreOccurence(int i);
  void afficher();
  void afficherBis();
  vecteurLettre operator + (vecteurLettre v); //Probleme si addition de lettreLigne different, a rendre plus robuste
  void incrementerCompteurLettre(char lettre);
  void rendreStochastique();
  //char selectionnerLettreSuivante();

};
