#include<iostream>
#include<string>
#include <fstream>
#include "corpus.h"
#include <algorithm>

corpus::corpus(std::string chemin){

this->cheminFichier=chemin;
this->matriceMotTransition= matriceMot();
std::ifstream ifs(chemin);
std::string v;

do {
ifs>>v;
std::transform(v.begin(), v.end(), v.begin(), ::tolower);
matriceMotTransition.add_word(v);
} while (!ifs.eof());
ifs.close();

this->matriceMotTransition.rendreStochastique();
}

void corpus::afficherMatriceTransition(){
    this->matriceMotTransition.afficherMatrice("abcdefghijklmnoppqrstuvwxyz");
}


void corpus::genererUnMot(char lettreInitiale, int tailleMot){
//Etape 1 recherche de la ligne de la matrice de transition considérée
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


