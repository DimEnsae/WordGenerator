
#include "matriceMot.h"
#include<string>
#include<iostream>

matriceMot::matriceMot(){
this->ascii = 128;
    this->matriceTransition=new vecteurLettre[this->ascii]();
    for (int i =0 ; i<this->ascii;i++){
      matriceTransition[i]=vecteurLettre(char(i));
    }
    //int this->matriceTransition[128][128]
}

void matriceMot::add_word(std::string mot) {
for (int i=0; i<(mot.length()-1);i++){
    this->incrementerCompteurCase(mot[i],mot[i+1]);
    }
}

void matriceMot::incrementerCompteurCase(char lettrePrecedente,char lettreSuivante){
      this->matriceTransition[int(lettrePrecedente)].incrementerCompteurLettre(lettreSuivante);
}

vecteurLettre matriceMot::getMatriceTransition(char a){return this->matriceTransition[int(a)];}

void matriceMot::afficherMatrice(std::string dic){
    
    for(int i = 0; i < this->ascii;i++){
        if (dic.find(char(i)) != std::string::npos) {
            std::cout<<" "<<char(i);
        }
    }
    for(int i = 0; i<this->ascii;i++){
        if (dic.find(char(i)) != std::string::npos) {
            this->matriceTransition[i].afficher(dic);
        }
    }
}


void matriceMot::rendreStochastique(){
for (int i =0;i<this->ascii;i++){
  this->matriceTransition[i].rendreStochastique();
}
}

