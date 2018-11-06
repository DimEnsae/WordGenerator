#include "vecteurLettre.h"
#include<stdlib.h>
#include<time.h>
#include<string>
#include<iostream>
#include <cstdlib>
#include <sys/timeb.h>
#include <ctime>

//Constructeur principal
vecteurLettre::vecteurLettre(char lettreLigne,std::string listeLettre){
  this->listeLettre=listeLettre;
  this->lettreLigne=lettreLigne;
  this->nomsColonnes=new char[listeLettre.length()];
  this->nombreOccurence=new float[listeLettre.length()];
  //Remplissage du nom des colonnes
  for(int i=0;i<listeLettre.length();i++){
    nomsColonnes[i]=listeLettre[i];
  }
  //Remplissage à 0 pour le moment des occurences
  for(int i=0;i<listeLettre.length();i++){
    nombreOccurence[i]=0;
  }
}

//Constructeur simplifié
vecteurLettre::vecteurLettre(){
  this->listeLettre="0";
  this->lettreLigne='0';
  this->nomsColonnes=0;//Pointeurs à null
  this->nombreOccurence=0;
}

//getter
char vecteurLettre::getlettreLigne(){
  return(this->lettreLigne);
}

float vecteurLettre::getnombreOccurence(int i){
  return(this->nombreOccurence[i]);
}
//Redéfinition du +
vecteurLettre vecteurLettre::operator +(vecteurLettre v){
  vecteurLettre resultat=vecteurLettre(v.lettreLigne,v.listeLettre);
  for(int i= 0; i<listeLettre.length();i++){
      resultat.nombreOccurence[i]=this->nombreOccurence[i]+v.nombreOccurence[i];
  }
  return resultat;
}

//Augmentation du compteur pour une des lettres suivantes
void vecteurLettre::incrementerCompteurLettre(char lettre){
  for(int i=0;i<listeLettre.length();i++){
    if(this->listeLettre[i]==lettre){
    this->nombreOccurence[i]++;
    }
  }
}

// je Ramène tout à 1
void vecteurLettre::rendreStochastique(){
  int total=0;
  for (int i=0;i<this->listeLettre.length();i++) {
    total=total+this->nombreOccurence[i];
  };
  for (int i=0;i<this->listeLettre.length();i++) {
    this->nombreOccurence[i]=this->nombreOccurence[i]/total;
  };
}

//Sélection de la lettre suivante étant donné le vecteur de proba d'inclusion
char vecteurLettre::selectionnerLettreSuivante(){
  //1 calcul des probabilités cumulées
  float *cumprob=0;
  cumprob=new float[this->listeLettre.length()];
  cumprob[0]=this->nombreOccurence[0];
  for(int i=1; i<this->listeLettre.length();i++){
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
 for(int i=1;i<this->listeLettre.length();i++){
  if((u>cumprob[i-1])&&(u<=cumprob[i])) {choix=i;}
 }
 return(this->nomsColonnes[choix]);
}

//Affichage colonne
void vecteurLettre::afficher(){
  std::cout<<"La lettre considérée est : "<< this->lettreLigne <<std::endl;
  std::cout<<"La liste des occurences par lettre suivante est : "<<std::endl;
  for(int i=0;i<this->listeLettre.length();i++){
    std::cout<<nomsColonnes[i]<<" "<<nombreOccurence[i]<<std::endl;
  }
}

//Deuxième fonction d'affichage compatible avec une matrice mots
void vecteurLettre::afficherBis(){
  std::cout<<std::endl;
  std::cout<<this->lettreLigne;
  for(int i=0;i<this->listeLettre.length();i++){
    std::cout<<" "<<this->nombreOccurence[i];
  }
  std::cout<<std::endl;
}
