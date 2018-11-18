//
//  main.cpp
//  WordGenerator
//
//  Created by Dimitri Meunier on 23/10/2018.
//  Copyright © 2018 Dimitri Meunier. All rights reserved.
//
//BOSSER LES CONSTRUCTEURS PAR COPIE !!!!!!
#include <iostream>

#include<fstream>
#include<string>
//#include "vecteurLettre.h"
//#include "matriceMot.h"
//#include "matrice.h"
#include "corpus.h"


int main(int argc, const char * argv[]) {
  // insert code here...

  //ça marche on verra plus tard^^
  //std::ifstream ifs("../pokemon_names.txt");
  //std::string v;
  //ifs>>v;
  //std::cout<<"j'ai lu"<<v<<std::endl;
//std::string chaine="Tue es belle";
//for(int i =0;i<1000;i++){
//std::cout<<chaine<<std::endl;
//std::cout<<chaine.length()<<std::endl;
//}
//char entre quote simple Rappel: le char est un entier
//std::string alphabet="abcdefghijklmnopqrstuvwxyz";
//std::cout<<a<<std::endl;

//std::cout << a << '\n';
//vecteurLettre test1=vecteurLettre('a',alphabet);
//test1.incrementerCompteurLettre('a');
//test1.incrementerCompteurLettre('b');
//est1.rendreStochastique();
//test1.afficherBis();
//std::cout<<test1.selectionnerLettreSuivante();
 //test1.afficherBis();
 //vecteurLettre test2();
 //std::string listeLettreMatrice="abcdefghijklmnopqrstuvwxyz";
//matriceMot m1=matriceMot("pioupioupioupiou",listeLettreMatrice);
//matriceMot m2("abcdefghi",listeLettreMatrice);
//matriceMot m3("ijklmnopqrstuvwxyz",listeLettreMatrice);

//matriceMot m4 = m2 + m3;
//m2.afficherMatrice();
//m3.afficherMatrice();
//m4.afficherMatrice();
//m4.afficherMatrice();
//vecteurLettre v('a',"ab");
//vecteurLettre w('a',"ab");
//v.incrementerCompteurLettre('b');
//w.incrementerCompteurLettre('b');
//vecteurLettre x = w+v;
//x.afficher();

//std::ifstream ifs("../pokemon_names.txt");
//std::string v;
//ifs>>v;
//while (!ifs.eof()){
//std::cout<<"j'ai lu "<<v<<std::endl;
//ifs>>v;
//}
//ifs.close();

//corpus corpus_test=corpus("../pokemon_names.txt","abcdefghijklmnopqrstuvwxyz");
//corpus_test.afficherMatriceTransition();
//corpus_test.genererUnMot('c',7);

//corpus corpus_test1=corpus("../Allemand.txt","abcdefghijklmnopqrstuvwxyz");
corpus corpus_test2=corpus("../Allemand.txt","abcdefghijklmnopqrstuvwxyz");
//corpus corpus_test3=corpus("../mobydick.txt","abcdefghijklmnopqrstuvwxyz");
//corpus_test1.afficherMatriceTransition();
//std::cout<<"ALLEMAND"<<std::endl;
//for (int i=0; i<200;i++){
//std::cout<<std::endl;
//corpus_test2.genererUnMot('a',10);
//}
corpus_test2.afficherMatriceTransitionColoree();
//std::cout<<"FRANCAIS"<<std::endl;
//for (int i=0; i<200;i++){
//std::cout<<std::endl;
//corpus_test2.genererUnMot('a',10);
//}

//std::cout<<"ESPAGNOL"<<std::endl;
//for (int i=0; i<200;i++){
//std::cout<<std::endl;
//corpus_test3.genererUnMot('s',6);
//}

//corpus_test2.genererUnMot('s',7);
//corpus_test3.genererUnMot('s',7);

    
std::string path = "../pokemon_names.txt";
std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
corpus c(path, alphabet);


  return 0;
}
