#include <string>

/*-------------------------VERTEX ----------------------------------
 Stock l'information stocké dans un vertex (arrete) sortant d'un
 noeud.
 
 
 Arguments: couple (nextNode , weight)
 
 -nextNode: vers quel noeud pointe le vertex
 -weight: poids du vertex (nombre de fois ou on a parcouru le vertex)
 
 Methodes:
 -Un seul contructeur
 -increment, incremente de 1 le weight du vertex
 -display, affiche le vertex sout la forme (nextNode , weight)
 -getWeight, accesseur du weight
 -getNextNode, accesseur nextNode
 
 ----------------------------------------------------------------*/


class Vertex{
private:
    std::string nextNode;
    float weight;
public:
    Vertex(std::string nextNode, float weight);
    void increment();
    void display();
    float getWeight();
    std::string getNextNode();
};
