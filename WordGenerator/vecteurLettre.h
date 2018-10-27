#include<string>
class vecteurLettre{
//Rq: arkov, convergence de la chaine à l'infini ?
//En gros un vecteur sera lié à une lettre (par exemple a) et donnera par ex pour la colonne d le nombre de fois que la lettre d est arrivée après un a
//Par la suite, la classe Mot sera une addition de vecteurs lettres potentiellement une matrice assez vide
//et on pourra additionner les matricesMots d'un corpus entre eux dans la classe mot matrice
// une instance de la classe mot matrice sera le motavec sa matrice de matriceTransition
//Il faudra penser à redre sa maztrice de transition spazrse

//Lors de l'instanciation d'une classe corpus il faudra déclarer une variable static liste de lettres qui
//correpondra à la liste exhaustive des lettres du corpus et permettra d'instencier les matrices mots de tous les mots du corpus et de les additionner.
//Fonction d'affichage de la maztrice de transition liée à un corpus,  stochastisation des matrices en niveau
private:
std::string listeLettre; //pour avoir le nombre de colonnes de la matrice de transition(évite d'allouer de l'espace mémoire à rien dutout)
char lettreLigne;
char *nomscolonnes;//ce sera une liste
int *nombreOccurence; //Ce sera une liste

public:
  vecteurLettre(char lettreLigne,std::string listeLettre);
  char getlettreLigne();
  void afficher();
  void afficherBis();
  void incrementerCompteurLettre(char lettre);

};
