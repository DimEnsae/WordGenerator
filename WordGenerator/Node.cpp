#include <iostream>
#include "Node.h"
#include <map>

/*
Node::Node(std::string name, int intNode):mapVertex(<std::string, Vertex>){
    this->name = name;
    this-> intNode = intNode;
}
*/
int Node::NodeCount=0;

Node::Node(std::string name, int intNode){
    this->name = name;
    this-> intNode = intNode;
    std::map<std::string, Vertex> mp;
    this->mapVertex = mp;
    NodeCount++; 
 }


 void Node::add_map(std::string next , Vertex v){
     this->mapVertex.insert(std::pair<std::string,Vertex>(next,v));
 //this->mapVertex[next] =  v;
 }

void Node::display(){

std::map<std::string, Vertex>::iterator it =this->mapVertex.begin();// initialisation de l'itérator en dehors de la boucle
  for(it=this->mapVertex.begin();it!=this->mapVertex.end();it++){
  std::cout<<it->first<<"=>";
  it->second.display();//surcharger par la suite
  std::cout<<std::endl;
  }
}

 void Node::increment(std::string followingNode){
this->mapVertex.find(followingNode)->second.increment(); //second récupère l'élément après la clé
}
