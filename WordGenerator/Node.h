#include <string>
#include <map>
#include "Vertex.h"

class Node{
private:
    std::string name; //name of the node
    int intNode; //Id of the Node
    std::map<std::string, Vertex> mapVertex; //dictionary (map) of next nodes

public:
    static int NodeCount; //je n'arrive pas à faire une fonction static pour y accéder en private
//Pourquoi compte-t-on les noeuds ?
    Node(std::string name, int intNode);
    void add_map(std::string next , Vertex v);//add Vertex
    void display();
    void increment(std::string followingNode);

};
