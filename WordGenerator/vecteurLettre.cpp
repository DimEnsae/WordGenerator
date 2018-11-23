#include "vecteurLettre.h"
#include<stdlib.h>
#include<time.h>
#include<string>
#include<iostream>
#include <cstdlib>
#include <sys/timeb.h>
#include <ctime>

vecteurLettre::vecteurLettre(char lettreLigne){
  this->ascii = 128;
  this->lettreLigne=lettreLigne;
  this->nombreOccurence=new float[this->ascii];
  //Remplissage à 0 (pour le moment) des occurences
  for(int i=0;i<this->ascii;i++){
    nombreOccurence[i]=0;
  }
}

//Constructeur simplifié //What is the point of using that ?
vecteurLettre::vecteurLettre(){
  this->ascii = 128;
  this->lettreLigne='0';
  this->nombreOccurence=new float[this->ascii];
}

//getter
char vecteurLettre::getlettreLigne(){
  return(this->lettreLigne);
}

float vecteurLettre::getnombreOccurence(char a){
  return(this->nombreOccurence[int(a)]);
}

void vecteurLettre::afficher(std::string dic){
    std::cout<<std::endl;
    std::cout<<this->lettreLigne;
    for(int i=0;i<this->ascii;i++){
        if (dic.find(char(i)) != std::string::npos) {
            std::cout<<" "<<char(i)<<":"<<this->nombreOccurence[i];
        }
    }
    std::cout<<std::endl;
}


//Augmentation du compteur pour une des lettres suivantes
void vecteurLettre::incrementerCompteurLettre(char lettre){
    this->nombreOccurence[int(lettre)]++;
}

//Normalisation proba
void vecteurLettre::rendreStochastique(){
  int total=0;
  for (int i=0;i<this->ascii;i++) {
    total=total+this->nombreOccurence[i];
  };
  for (int i=0;i<this->ascii;i++) {
    this->nombreOccurence[i]=this->nombreOccurence[i]/total;
  };
}

//Explication Clement ???
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
    return(this->nomsColonnes[choix]);
}
*/
