#include"tensorMot.h"
#include<string>
#include<iostream>
#include<iomanip>

//Constructor
tensorMot::tensorMot(){
    this->ascii = 128;
    this->tensorTransition=new matriceMot[this->ascii]();
    for (int i =0 ; i<this->ascii;i++){
        tensorTransition[i]=matriceMot();
    }
}

//Display (short version)
void tensorMot::afficherTensor(std::string dic){
    for(int i = 0; i<this->ascii;i++){
        if (dic.find(char(i)) != std::string::npos) {
            std::cout << char(i) << std::endl;
            this->tensorTransition[i].afficherMatrice(dic);
        }
    }
}


//Integrate a new word into the tensor
void tensorMot::add_word(std::string mot) {
    if (mot.length()>2) {
        for (int i=1; i<(mot.length()-1);i++){
            this->incrementerCompteurCase(mot[i-1],mot[i],mot[i+1]);
        }
    }
}


void tensorMot::incrementerCompteurCase(char lettrePrec1, char lettrePrec2,char lettreSuiv){
    this->tensorTransition[int(lettrePrec1)].getMatriceTransition(lettrePrec2).incrementerCompteurLettre(lettreSuiv);
}


void tensorMot::rendreStochastique(){
    for (int i =0;i<this->ascii;i++){
        for (int j=0;j<this->ascii;j++){
            this->tensorTransition[i].getMatriceTransition(char(j)).rendreStochastique();
        }
    }
}

