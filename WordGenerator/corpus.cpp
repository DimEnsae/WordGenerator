#include<iostream>
#include<string>
#include <fstream>
#include "corpus.h"
//initialisation de l'objet matricede transition en amont
corpus::corpus(std::string chemin,std::string listeLettre): matriceMotTransition(listeLettre){
//lire un fichier générer les matrices mots et les additionner dans la foulée
//générer la matrice de proba
this->cheminFichier=chemin;
std::ifstream ifs(chemin);
std::string v;
ifs>>v;
while (!ifs.eof()){
//  std::cout<<v;
matriceMot tmp=matriceMot(v,listeLettre);
this->matriceMotTransition=this->matriceMotTransition + tmp;
ifs>>v;
}
ifs.close();

this->matriceMotTransition.rendreStochastique();
}
//En fonction un corpus devra savoir générer des mots ou bien on peut faire une classe générateur particulièrequi prend un corpus en entrée.
void corpus::afficherMatriceTransition(){
this->matriceMotTransition.afficherMatrice();
}

void corpus::genererUnMot(char lettreInitiale, int tailleMot){
//Etape 1 recherche de la ligne de la matrice de transition considérée
vecteurLettre v;
for (int i=0; i<this->matriceMotTransition.getListeLettreMatrice().length(); i++){
  if (this->matriceMotTransition.getMatriceTransition(i).getlettreLigne()==lettreInitiale){
    v=this->matriceMotTransition.getMatriceTransition(i);
  }
}
if(tailleMot==1){std::cout<<lettreInitiale;}else{
  std::cout<<lettreInitiale;
  char lettreSuivante=v.selectionnerLettreSuivante();
  genererUnMot(lettreSuivante,(tailleMot-1));
}

}
//Sélection d'une lettre suivante à partir d'une lettre de la matrice de transition
//Gp,ction de génération de mot de taille n, calcul taille moyenne
//Calcul de proba à partir d'un vecteur Ligne dans la classe vecteur Lettre finalment
