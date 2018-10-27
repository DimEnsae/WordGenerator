
//tester les constructeurs par copie dans la clase matrice
//une instance de classe corpus  va représenter le corpus sur lequel on va apprendre
// à partir d'un corpus on pourra générer une liste de mots associées
// Cette classe va utiliser à peu près toutes les autres

//Faire une fonction qui a un mot lui associe
class corpus{
  private :
  std::string cheminFichier;
  std::Mot *listeMots;//Un objet de la classe mot.
  matrice matriceTransition;

  public :
  matrice(std::string cheminFichier,matriceTransition);// Il faudra remplir la matrice de transition en analysant le corpus




}
