#include <string>
#include <map>
#include "Vertex.h"

class Node{
private:
    std::string name; //name of the node
    int intNode;
    std::map<std::string, Vertex> mapVertex;//following nodes

public:
    static int NodeCount; //je n'arrive pas à faire une fonction static pour y accéder en private

    Node(std::string name, int intNode);
    void add_map(std::string next , Vertex v);// to add a Vertex
    void display();
    void increment(std::string followingNode);

};
