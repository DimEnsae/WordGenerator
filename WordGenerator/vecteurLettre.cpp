#include "vecteurLettre.h"
#include<string>
#include<iostream>
vecteurLettre::vecteurLettre(char lettreLigne,std::string listeLettre){

this->listeLettre=listeLettre;
this->lettreLigne=lettreLigne;
this->nomscolonnes=new char[listeLettre.length()];
this->nombreOccurence=new int[listeLettre.length()];
//Remplissage du nom des Colonnes
for(int i=0;i<listeLettre.length();i++){
nomscolonnes[i]=listeLettre[i];
}
//Remplissage à 0 pour le moment des occurences
for(int i=0;i<listeLettre.length();i++){
nombreOccurence[i]=0;
}

}

//Augmentation du compteur pour une des lettres suivantes
void vecteurLettre::incrementerCompteurLettre(char lettre){
  for(int i=0;i<listeLettre.length();i++){
    if(this->listeLettre[i]==lettre){
    this->nombreOccurence[i]++;
    }
  }
  }

void vecteurLettre::afficher(){
std::cout<<"La lettre considérée est : "<< this->lettreLigne <<std::endl;
std::cout<<"La liste des occurences par lettre suivante est : "<<std::endl;
for(int i=0;i<this->listeLettre.length();i++){
std::cout<<nomscolonnes[i]<<" "<<nombreOccurence[i]<<std::endl;
}
}
//Deuxième fonction d'affichage compatible avec une matrice mots
void vecteurLettre::afficherBis(){
//std::cout<<" ";
//for(int i=0;i<this->listeLettre.length();i++){
//std::cout<<" "<<this->nomscolonnes[i];
//}
std::cout<<std::endl;
std::cout<<this->lettreLigne;
for(int i=0;i<this->listeLettre.length();i++){
std::cout<<" "<<this->nombreOccurence[i];
}
std::cout<<std::endl;
}
