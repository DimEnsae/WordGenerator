#include<iostream>
#include<string>
#include <fstream>
#include <SFML/Graphics.hpp>
#include "corpus.h"

//initialisation de l'objet matricede transition en amont
corpus::corpus(std::string chemin,std::string listeLettre): matriceMotTransition(listeLettre){
//lire un fichier générer les matrices mots et les additionner dans la foulée
//générer la matrice de proba
this->cheminFichier=chemin;
std::ifstream ifs(chemin);
std::string v;
ifs>>v;
while (!ifs.eof()){
 //std::cout<<v;
matriceMot tmp=matriceMot(v,listeLettre);
this->matriceMotTransition=this->matriceMotTransition + tmp;
ifs>>v;
}
ifs.close();

this->matriceMotTransition.rendreStochastique();
}
//En fonction un corpus devra savoir générer des mots ou bien on peut faire une classe générateur particulièrequi prend un corpus en entrée.
void corpus::afficherMatriceTransition(){
this->matriceMotTransition.afficherMatrice();
}

void corpus::genererUnMot(char lettreInitiale, int tailleMot){
//Etape 1 recherche de la ligne de la matrice de transition considérée
vecteurLettre v;
for (int i=0; i<this->matriceMotTransition.getListeLettreMatrice().length(); i++){
  if (this->matriceMotTransition.getMatriceTransition(i).getlettreLigne()==lettreInitiale){
    v=this->matriceMotTransition.getMatriceTransition(i);
  }
}
if(tailleMot==1){std::cout<<lettreInitiale;}else{
  std::cout<<lettreInitiale;
  char lettreSuivante=v.selectionnerLettreSuivante();
  genererUnMot(lettreSuivante,(tailleMot-1));
}

}

void corpus::afficherMatriceTransitionColoree(){
  sf::RenderWindow window(sf::VideoMode(300, 300), "Matrice de Transition !");
  while (window.isOpen())
  {
      sf::Event event;
      while (window.pollEvent(event))
      {
          if (event.type == sf::Event::Closed)
              window.close();
      }
      window.clear();
//Je vais balayer la matrice  de transition et colorer en conséquence
sf::Font font;
font.loadFromFile("../OpenSans-BoldItalic.ttf");

//je mets les entêtes en ligne et en colonne


for(int i=0;i<26;i++){

sf::Text lettre;
lettre.setFont(font);
lettre.setString(this->matriceMotTransition.getListeLettreMatrice()[i]);
lettre.setPosition(25+i*10,10);
lettre.setFillColor(sf::Color::Red);
lettre.setCharacterSize(10);
window.draw(lettre);

//les lettres en lignes
sf:: Text lettre2=lettre;
lettre2.setPosition(15,23+i*10);
window.draw(lettre2);
}

for (int j=0; j<this->matriceMotTransition.getListeLettreMatrice().length(); j++){
for(int i=0; i<26;i++){
// je récupère la proba d'une case et dessine la couleur associée
 float probaCase =  this->matriceMotTransition.getMatriceTransition(j).getnombreOccurence(i);
      sf::RectangleShape rectangle(sf::Vector2f(9.f,9.f));
      rectangle.setFillColor(sf::Color(250*probaCase,0,0));
      rectangle.setPosition(23+10*i,23+10*j);
      rectangle.setOutlineThickness(1.f);
      rectangle.setOutlineColor(sf::Color(250,150,100));
      window.draw(rectangle);
}
}
  window.display();
}
}
//Sélection d'une lettre suivante à partir d'une lettre de la matrice de transition
//Gp,ction de génération de mot de taille n, calcul taille moyenne
//Calcul de proba à partir d'un vecteur Ligne dans la classe vecteur Lettre finalment
