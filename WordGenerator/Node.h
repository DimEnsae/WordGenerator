#include <string>
#include <map>
#include "Vertex.h"

class Node{
private:
    std::map<char , Vertex> mapVertex; //dictionary (map) of next nodes

public:
    Node();
    std::map<char , Vertex> getMap();
    void add_map(char next , Vertex v);//add Vertex
    void display();
    void increment(char NextLetter);
};
