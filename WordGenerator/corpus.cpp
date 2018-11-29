#include<iostream>
#include<string>
#include <fstream>
#include "corpus.h"
#include "misc.h"
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
    if(tailleMot==1) {std::cout<<lettreInit;}
    else {
        std::cout<<lettreInit;
        char lettreSuivante=v.selectionnerLettreSuivante();
        genererUnMotOrdre1(lettreSuivante,(tailleMot-1));
        }
}

void corpus::genererUnMotOrdre1Bis(int tailleMot, int nbmots){
    //Pas besoin de generer la 1ere lettre, elle est generee aleatoirement
    //genere nbmots mots
    
    for (int j=0; j<nbmots; j++) {
        
        char lettreInit = firstLetter();
        genererUnMotOrdre1(lettreInit, tailleMot);
        std::cout << std::endl;
        
    }
}

void corpus::genererUnMotOrdre2(char lettreInit1, char lettreInit2, int tailleMot){
    //A l'ordre 2 ont doit preciser les deux premieres lettres
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

void corpus::genererUnMotOrdre2Bis(int tailleMot, int nbmots){
    //Les deux premieres lettres sont generees aleatoirement
    //genere nbmots mots
    
    for (int j=0; j<nbmots; j++) {
    
        char lettreInit1 = firstLetter();
        char lettreInit2 = this->TransitionOrder1[lettreInit1].selectionnerLettreSuivante();
        genererUnMotOrdre2(lettreInit1, lettreInit2,tailleMot);
        std::cout << std::endl;
    }
}

void corpus::exportMatriceTocsv(std:: string PATH) {
    
    std::ofstream monFlux(PATH);
    
    if(monFlux) {
        for (int i=0; i<128; i++) {
            for (int j=0; j<128; j++) {
                monFlux << this->TransitionOrder1[i][j];
                if (j<127) {monFlux << ";";}
            }
            if (i<127) {monFlux << "\n";}
            
        }
    }
    else {
        std::cout << "ERREUR: Impossible d'ouvrir le fichier." << std::endl;
    }
}

