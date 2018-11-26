#include<iostream>
#include<string>
#include <fstream>
#include "corpus.h"
#include <algorithm> //load std::transform

//Constructor
corpus::corpus(std::string chemin){

    this->cheminFichier=chemin;
    this->matriceMotTransition = matriceMot();
    
    std::ifstream ifs(chemin);
    std::string v;
    do {
    ifs>>v;
    std::transform(v.begin(), v.end(), v.begin(), ::tolower); //Change v to lower mode (no capitalize letters)
    matriceMotTransition.add_word(v);
    } while (!ifs.eof());
    ifs.close();

    this->matriceMotTransition.rendreStochastique();
}


//Display
void corpus::afficherMatriceTransition(){
    this->matriceMotTransition.afficherMatrice("abcdefghijklmnoppqrstuvwxyz");
}


void corpus::genererUnMot(char lettreInitiale, int tailleMot){
    vecteurLettre v;
    v=this->matriceMotTransition.getMatriceTransition(lettreInitiale);
    if(tailleMot==1) {
        std::cout<<lettreInitiale;
        }
    else {
        std::cout<<lettreInitiale;
        char lettreSuivante=v.selectionnerLettreSuivante();
        genererUnMot(lettreSuivante,(tailleMot-1));
        }
}
