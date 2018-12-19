
#include <iostream>
#include <string>
#include <map>
#include "Node.h"

/*------------------------- AUTOMATON -------------------------------------
 
Stock l'integralite du graphe contenu dans le corpus.
 
 Arguments:
    -map {next, Vertex}
 -key, charactere avec lequel on sort du noeud, par exemple si on regarde le mot bol avec un memory length de 2 et qu'on est sur le noeud "bo" on sort avec le charactere 'l' qui nous ammene ou noeud "ol", la map contiendra donc {'l', ("ol", weight)}
 -Values, Vertex associe a la sortiem dans l'exemple precedent: ("ol", weight)
 
 Methodes:
 -Un seul constructeur,
    -memoryLength, ordre de la chaine de Markov
    -path, adresse physique du corpus
 -getMap, accesseur de la map
 -add_map, ajout d'un element {next, Vertex} dans la map
 
 -increment, appel la methode increment du Vertex associé au charactere de sortie
 -display, affiche la map sous la forme
 l => (ol,1)
 
 --a completer
 
 ----------------------------------------------------------------*/

class Automaton{
private:
    int memoryLength;
    std::map<std::string,Node> mapNode;
public:
    Automaton(std::string path, int memoryLength);
    void learnFromWord(std::string word);
    void add_map(std::string idNode, Node node);
    void display();
    void generate_word(std::string);
    std::string get_init();
};
