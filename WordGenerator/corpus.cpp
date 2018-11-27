#include<iostream>
#include<string>
#include <fstream>
#include "corpus.h"
#include <algorithm> //load std::transform

//Constructor
corpus::corpus(std::string chemin){

    this->cheminFichier=chemin;
    this->TransitionOrder1 = matriceMot();
    this->TransitionOrder2 = tensorMot();
    
    std::ifstream ifs(chemin);
    std::string v;
    do {
        
        ifs>>v;
        std::transform(v.begin(), v.end(), v.begin(), ::tolower); //Change v to lower mode (no capitalize letters)
        TransitionOrder1.add_word(v);
        TransitionOrder2.add_word(v);
    
    } while (!ifs.eof());
    ifs.close();

    this->TransitionOrder1.rendreStochastique();
    this->TransitionOrder2.rendreStochastique();
}


//Display
void corpus::afficherMatriceTransition(){
    this->TransitionOrder1.afficherMatrice();
}


void corpus::genererUnMotOrdre1(char lettreInit, int tailleMot){
    vecteurTransition v;
    v=this->TransitionOrder1[lettreInit];
    if(tailleMot==1) {
        std::cout<<lettreInit;
        }
    else {
        std::cout<<lettreInit;
        char lettreSuivante=v.selectionnerLettreSuivante();
        genererUnMotOrdre1(lettreSuivante,(tailleMot-1));
        }
}

void corpus::genererUnMotOrdre2(char lettreInit1, char lettreInit2, int tailleMot){
    
    vecteurTransition v;
    v=this->TransitionOrder2[lettreInit1][lettreInit2];
    
    if(tailleMot==1) {std::cout<< lettreInit1;}
    else if(tailleMot==2) {std::cout<< lettreInit1 << lettreInit2;}
    
    else {
        std::cout<<lettreInit1;
        char lettreSuivante=v.selectionnerLettreSuivante();
        genererUnMotOrdre2(lettreInit2, lettreSuivante,(tailleMot-1));
    }
}

