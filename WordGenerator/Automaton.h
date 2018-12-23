
#include <iostream>
#include <string>
#include <map>
#include "Node.h"

/*------------------------- AUTOMATON -------------------------------------

A partir d'un corpus de texte stock l'information sous forme de graphe.
 
 Arguments du constructeurs:
    -path, path menant au corpus
    -memoryLength, ordre de la chaine de Markov (L)
    -word, deux options
        word = 0 chaque noeud du graphe est un L-anagramme le graphe sert a generer des mots
        word = 1 chaque noeud du graphe est un ensemble de L mots le graphe sert a generer du texte

 Arguments:
    -memoryLength
    -word
    -map {NameNode, Node}
 -key, nom du noeud en chaine de charactere (ex ban pour un 3-anagramme, Je_suis_Bob pour du texte)
 -Values, Node associe

 Methodes:
 -Un seul constructeur
 -learnFromWord ...

 ----------------------------------------------------------------*/

class Automaton{
private:
    int memoryLength; //Length of the Markov Chain
    int word; //Creation mode
    std::map<std::string,Node> mapNode;
public:
    Automaton(std::string path, int memoryLength, int word);
    void learnFromWord(std::string word);
    void add_map(std::string idNode, Node node);
    void display();
    void generate_word(std::string);
    std::string get_init();
};
