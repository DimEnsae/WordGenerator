#include<string>

class vecteurLettre{

private:

char lettreLigne;
    int ascii;
float *nombreOccurence;

public:
    
  vecteurLettre(char lettreLigne);
  vecteurLettre();
  char getlettreLigne();
  float getnombreOccurence(char a);
  void afficherBis();
  vecteurLettre operator + (vecteurLettre v);
  void incrementerCompteurLettre(char lettre);
  void rendreStochastique();
  //char selectionnerLettreSuivante();

};
