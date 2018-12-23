#include <string>
#include <map>
#include "Vertex.h"

/*------------------------- NODE -------------------------------------
 
 Stock l'information stocké dans un noeud. Il s'agit d'un dictionaire de Vertex.
 
 Arguments: map {next, Vertex}
 -key, symbole avec lequel on sort du noeud (caractere pour la generation de mot, chaine de caracteres pour la generation de text),
 par exemple si on regarde le mot bol avec un memory length de 2 et qu'on est sur le noeud "bo" on sort avec le charactere 'l' qui nous ammene ou noeud "ol", la map contiendra donc {'l', ("ol", weight)}
 -Values, Vertex associe a la sortie dans l'exemple precedent: ("ol", weight)
 
 Methodes:
 -Un seul contructeur, map vide a la construction
 -getMap, accesseur de la map
 -add_map, ajout d'un element {next, Vertex} dans la map
 -increment, appel la methode increment du Vertex associé au charactere de sortie
 -display, affiche la map sous la forme
 l => (ol,1)
 -select_node_suivant, choisi aleatoirement selon les weight un vertex dans la map
 
 ----------------------------------------------------------------*/

class Node{
private:
    std::map<std::string , Vertex> mapVertex;

public:
    Node();
    std::map<std::string , Vertex> getMap();
    void add_map(std::string next , Vertex v);
    void display();
    void increment(std::string NextLetter);
    std::string select_node_suivant();
};
