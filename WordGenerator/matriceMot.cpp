#include "matriceMot.h"
//#include "vecteurLettre.h"
#include<string>
#include<iostream>


matriceMot::matriceMot(std::string mot,std::string listeLettreMatrice){

  this->mot=mot;
  this->listeLettreMatrice=listeLettreMatrice;
  this->matriceTransition=new vecteurLettre[this->listeLettreMatrice.length()]();

  //intitialisation de la matrice, je mets toutes les lettres (elle est carrée)
  for (int i =0 ; i< this->listeLettreMatrice.length();i++){
    matriceTransition[i]=vecteurLettre(this->listeLettreMatrice[i],this->listeLettreMatrice);
  }//Est-ce qu'on fait participer la fin du mot à la matrice de transition ?

  //Remplissage
  for(int i=0; i<(mot.length()-1);i++){
  this->incrementerCompteurCase(mot[i],mot[i+1]);
  }
}
matriceMot::matriceMot(std::string listeLettreMatrice){
  this->listeLettreMatrice = listeLettreMatrice;
  this->matriceTransition=new vecteurLettre[this->listeLettreMatrice.length()]();
  //intitialisation de la matrice, je mets toutes les lettres (elle est carrée)
  for (int i =0 ; i< this->listeLettreMatrice.length();i++){
    matriceTransition[i]=vecteurLettre(this->listeLettreMatrice[i],this->listeLettreMatrice);
  }//Est-ce qu'on fait participer la fin du mot à la matrice de transition ?

}


std::string matriceMot::getMot(){return(this->mot);}

void matriceMot::incrementerCompteurCase(char lettrePrecedente,char lettreSuivante){
  for (int i=0;i<this->listeLettreMatrice.length();i++){
    if (this->listeLettreMatrice[i]==lettrePrecedente){
      this->matriceTransition[i].incrementerCompteurLettre(lettreSuivante);
    }
  }
}
void matriceMot::rendreStochastique(){
for (int i =0;i<this->listeLettreMatrice.length();i++){
  this->matriceTransition[i].rendreStochastique();
}
}

matriceMot matriceMot::operator +(matriceMot m){
  //need additionner deux vecteurs lettreSuivante
 matriceMot resultat=matriceMot(m.listeLettreMatrice);
  for (int i=0;i<this->listeLettreMatrice.length();i++){
    resultat.matriceTransition[i]=this->matriceTransition[i]+m.matriceTransition[i];
  }
  return (resultat);
}

std::string matriceMot::getListeLettreMatrice(){return this->listeLettreMatrice;}
vecteurLettre matriceMot::getMatriceTransition(int i){return this->matriceTransition[i];}

void matriceMot::afficherMatrice(){

std::cout<<"le mot en cours est "<<this->mot<<std::endl;
std::cout<<" ";
  for(int i = 0; i < this->listeLettreMatrice.length();i++){
  std::cout<<" "<<this->listeLettreMatrice[i];
  }
  for(int i = 0; i < this->listeLettreMatrice.length();i++){
  this->matriceTransition[i].afficherBis();
  }
}

//faire une fonction qui va prendre une seule fois chaque lettre d'un mot //attributlettremotssansdoublon
//faire une fonction qui va rechercher une lettre en ligne dans la matrice et incrémenter la lettre encolonne
