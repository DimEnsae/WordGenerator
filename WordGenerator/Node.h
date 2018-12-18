#include <string>
#include <map>
#include "Vertex.h"

/*------------------------- NODE -------------------------------------
 
 Stock l'information stocké dans un noeud et ses arretes (Vertex).
 
 Arguments: map {next, Vertex}
 -key, charactere avec lequel on sort du noeud, par exemple si on regarde le mot bol avec un memory length de 2 et qu'on est sur le noeud "bo" on sort avec le charactere 'l' qui nous ammene ou noeud "ol", la map contiendra donc {'l', ("ol", weight)}
 -Values, Vertex associe a la sortiem dans l'exemple precedent: ("ol", weight)
 
 Methodes:
 -Un seul contructeur, map vide a la construction
 -getMap, accesseur de la map
 -add_map, ajout d'un element {next, Vertex} dans la map
 
 -increment, appel la methode increment du Vertex associé au charactere de sortie
 -display, affiche la map sous la forme
 l => (ol,1)
 -select_node_suivant, select randomly in the map (accoring to weight) a Vertex to go out of the Node
 
 ----------------------------------------------------------------*/

class Node{
private:
    std::map<char , Vertex> mapVertex;

public:
    Node();
    std::map<char , Vertex> getMap();
    void add_map(char next , Vertex v);
    void display();
    void increment(char NextLetter);
    std::string select_node_suivant();
};
