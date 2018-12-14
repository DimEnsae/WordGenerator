#include <iostream>
#include "Node.h"
#include <map>

/*
Node::Node(std::string name, int intNode):mapVertex(<std::string, Vertex>){
    this->name = name;
    this-> intNode = intNode;
}
*/

void Node::add_map(std::string next , Vertex v){
    //this->mapVertex.insert(next, v);
    //this->mapVertex[next] =  v;
    
}


Node::Node(std::string name, int intNode){
    this->name = name;
    this-> intNode = intNode;
    std::map<std::string, Vertex> mp;
    this->mapVertex = mp;
 }

