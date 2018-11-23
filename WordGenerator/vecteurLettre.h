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
  void afficher(std::string dic);
  void incrementerCompteurLettre(char lettre);
  void rendreStochastique();
  char selectionnerLettreSuivante();

};
