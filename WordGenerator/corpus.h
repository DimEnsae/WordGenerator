#include<string>
#include "matriceMot.h"

//tester les constructeurs par copie dans la clase matrice
//une instance de classe corpus  va représenter le corpus sur lequel on va apprendre
// à partir d'un corpus on pourra générer une liste de mots associées
// Cette classe va utiliser à peu près toutes les autres

//Faire une fonction qui a un mot lui associe
// On pourra également par la suite créer une classe générateur
class corpus{
  private :
  std::string cheminFichier;
  matriceMot matriceMotTransition;

  public :
  corpus(std::string cheminFichier, std::string listeLettre);// Il faudra remplir la matrice de transition en analysant le corpus
  void afficherMatriceTransition();
  void genererUnMot(char lettreInitiale,int tailleMot);// Là on va pouvoir faire du récursif à mort
};
