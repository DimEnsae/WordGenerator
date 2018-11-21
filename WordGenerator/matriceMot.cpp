#include "matriceMot.h"
#include<string>
#include<iostream>

matriceMot::matriceMot(std::string mot){

  this->mot=mot;
  this->ascii = 128;
  this->matriceTransition=new vecteurLettre[this->ascii]();

  for (int i =0 ; i< this->ascii;i++){
    matriceTransition[i]=vecteurLettre(char(i));
  }

  for (int i=0; i<(mot.length()-1);i++){
  this->incrementerCompteurCase(mot[i],mot[i+1]);
  }
}

matriceMot::matriceMot(){
this->ascii = 128;
  this->matriceTransition=new vecteurLettre[this->ascii]();
  for (int i =0 ; i<this->ascii;i++){
    matriceTransition[i]=vecteurLettre(char(i));
  }

}

void matriceMot::incrementerCompteurCase(char lettrePrecedente,char lettreSuivante){
  for (int i=0;i<this->ascii;i++){
    if (char(i)==lettrePrecedente){
      this->matriceTransition[i].incrementerCompteurLettre(lettreSuivante);
    }
  }
}

std::string matriceMot::getMot(){return(this->mot);}

vecteurLettre matriceMot::getMatriceTransition(char a){return this->matriceTransition[int(a)];}

void matriceMot::afficherMatrice(){
    
    std::cout<<"le mot en cours est "<<this->mot<<std::endl;
    std::cout<<" ";
    for(int i = 0; i < this->ascii;i++){
        std::cout<<" "<<char(i);
    }
    for(int i = 0; i<this->ascii;i++){
        this->matriceTransition[i].afficherBis();
    }
}


void matriceMot::rendreStochastique(){
for (int i =0;i<this->ascii;i++){
  this->matriceTransition[i].rendreStochastique();
}
}

matriceMot matriceMot::operator +(matriceMot m){ //attention la variable mot disparait !
  //need additionner deux vecteurs lettreSuivante doit etre fait avant rendre stochastique ?
 matriceMot resultat=matriceMot();
  for (int i=0;i<this->ascii;i++){
    resultat.matriceTransition[i]=this->matriceTransition[i]+m.matriceTransition[i];
  }
  return (resultat);
}

//faire une fonction qui va prendre une seule fois chaque lettre d'un mot //attributlettremotssansdoublon
//faire une fonction qui va rechercher une lettre en ligne dans la matrice et incrémenter la lettre encolonne

