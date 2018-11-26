#include "vecteurLettre.h"
#include<stdlib.h> //?
#include<time.h> //?
#include<string>
#include<iostream>
#include <cstdlib> //?
#include <sys/timeb.h> //?
#include <ctime> //?
#include <iomanip> //For cout manipulations

//Constructors ------------------------------------------------

vecteurLettre::vecteurLettre(char lettre){
    this->ascii = 128;
    this->lettre=lettre;
    this->nombreOccurence=new float[this->ascii];
    //Init occurences to 0
    for(int i=0;i<this->ascii;i++){
    nombreOccurence[i]=0;
    }
}

vecteurLettre::vecteurLettre(){
    this->ascii = 128;
    this->lettre='*';
    this->nombreOccurence=new float[this->ascii];
}


//Getter -----------------------------------------------------

char vecteurLettre::getlettre(){
    return(this->lettre);
}

float vecteurLettre::getnombreOccurence(char a){
    return(this->nombreOccurence[int(a)]);
}


//----------------------------------------------------------------

void vecteurLettre::afficher(std::string dic){
    std::cout<<std::endl;
    std::cout<<this->lettre;
    for(int i=0;i<this->ascii;i++){
        //Only displays characters contained in dic
        if (dic.find(char(i)) != std::string::npos) {
            std::cout << " ";
            std::cout << std::fixed << std::setprecision(3);
            std::cout << std::setw(2) << this->nombreOccurence[i];
        }
    }
    std::cout<<std::endl;
}


void vecteurLettre::incrementerCompteurLettre(char lettre){
    this->nombreOccurence[int(lettre)]++;
}

void vecteurLettre::rendreStochastique(){
    int total=0;
    for (int i=0;i<this->ascii;i++) {
    total=total+this->nombreOccurence[i];
    }
    for (int i=0;i<this->ascii;i++) {
    this->nombreOccurence[i]=this->nombreOccurence[i]/total;
    }
}




//---------Explication Clement ??? -----------------------------------



//Sélection de la lettre suivante étant donné le vecteur de proba d'inclusion
char vecteurLettre::selectionnerLettreSuivante(){
    //1 calcul des probabilités cumulées
    float *cumprob=0;
    cumprob=new float[this->ascii];
    cumprob[0]=this->nombreOccurence[0];
    for(int i=1; i<this->ascii;i++){
        cumprob[i]=cumprob[i-1]+this->nombreOccurence[i];
    }
    //génération d'un nombre aléatoire entre 0 et 1
    
    
    //timeb tb;
    //ftime(&tb);
    //int ncount =tb.millitm +(tb.time & 0xfffff)*1000;
    srand(clock());
    //srand(ncount);//Risque de générer la même pour chaque lettre => mot trop simple;
    float u=rand()%99999/99999.0;//drôle si on ne met pas le .0 le résultat est un entier.. donc 0
    
    //Sélection selon le cum sum de l'unité tirée sélectiond de j si  nombreoccurence[i]u
    //Rq ceci s'inspire de la méthode du tirage systématique en sondage et marche même si proba
    //lettre suivante nulle car dans ce cas on ne charge pas et le cumsumne bouge pas=>u ne peut se retrouver entre 2 nombres identiques
    int choix;
    if(u<=cumprob[0]){choix=0;}
    //std::cout<<u;
    for(int i=1;i<this->ascii;i++){
        if((u>cumprob[i-1])&&(u<=cumprob[i])) {choix=i;}
    }
    return(char(choix));
}

