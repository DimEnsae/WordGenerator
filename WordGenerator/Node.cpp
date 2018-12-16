#include <iostream>
#include "Node.h"
#include <map>

/*
Node::Node(std::string name, int intNode):mapVertex(<std::string, Vertex>){
    this->name = name;
    this-> intNode = intNode;
}
*/


Node::Node(std::string name, int intNode){
    this->name = name;
    this-> intNode = intNode;
    std::map<std::string, Vertex> mp;
    this->mapVertex = mp;
 }


 void Node::add_map(std::string next , Vertex v){
     this->mapVertex.insert(std::pair<std::string,Vertex>(next,v));
 //this->mapVertex[next] =  v;
 }

void Node::displayNode(){

std::map<std::string, Vertex>::iterator it =this->mapVertex.begin();// initialisation de l'itérator en dehors de la boucle
for(it=this->mapVertex.begin();it!=this->mapVertex.end();it++){
std::cout<<it->first<<"=>";
it->second.display();//surcharger par la suite
std::cout<<std::endl;

}
}
