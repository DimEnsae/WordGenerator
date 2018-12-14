#include <string>
#include "Vertex.h"
#include <map>

class Node{
private:
    std::string name; //name of the node
    int intNode;
    std::map<std::string, Vertex> mapVertex;//following nodes
public:
    Node(std::string name, int intNode);
    void add_map(std::string next , Vertex v);
    
    
    
};


