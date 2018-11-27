
#include"matriceMot.h"
#include<string>
#include<iostream>
#include<iomanip>

//Constructor
matriceMot::matriceMot(){
    this->ascii = 128;
    this->matriceTransition=new vecteurTransition[this->ascii]();
    for (int i =0 ; i<this->ascii;i++){
      matriceTransition[i]=vecteurTransition();
    }
}

//Overload []
vecteurTransition& matriceMot::operator[] (const int index) {return this->matriceTransition[index];}
vecteurTransition& matriceMot::operator[] (const char index) {return this->matriceTransition[int(index)];}

//Display
void matriceMot::afficherMatrice(std::string dic){
    for(int i = 0; i < this->ascii;i++){
        if (dic.find(char(i)) != std::string::npos) {
            std::cout << std::fixed;
            std::cout<< std::setw(6) <<char(i);
        }
    }
    for(int i = 0; i<this->ascii;i++){
        if (dic.find(char(i)) != std::string::npos) {
            this->matriceTransition[i].afficher(dic);
        }
    }
}


//Integrate a new word into the matrix
void matriceMot::add_word(std::string mot) {
    for (int i=0; i<(mot.length()-1);i++){
        this->incrementerCompteurCase(mot[i],mot[i+1]);
    }
}


void matriceMot::incrementerCompteurCase(char lettrePrecedente,char lettreSuivante){
      this->matriceTransition[int(lettrePrecedente)].incrementerCompteurLettre(lettreSuivante);
}


void matriceMot::rendreStochastique(){
    for (int i =0;i<this->ascii;i++){
        this->matriceTransition[i].rendreStochastique();
    }
}

