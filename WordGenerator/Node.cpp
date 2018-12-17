#include <iostream>
#include "Node.h"
#include <map>

//int Node::NodeCount=0;

Node::Node(){
    std::map<char , Vertex> mp;
    this->mapVertex = mp;
 }

std::map<char , Vertex> Node::getMap(){
    return this->mapVertex;
}


 void Node::add_map(char next , Vertex v){
     this->mapVertex.insert(std::pair<char ,Vertex>(next,v));
     //this->mapVertex[next] =  v; Why does this not work ?
     //Should we perform a test of key existance ?
 }

void Node::display(){
    for(std::map<char , Vertex>::iterator it=this->mapVertex.begin(); it!=this->mapVertex.end();it++){
    std::cout<< "\t" << it->first<<"=>";
    it->second.display();              
  }
}

 void Node::increment(char NextLetter){
this->mapVertex.find(NextLetter)->second.increment(); //second récupère l'élément après la clé
}


//------------------------------------------------------------------------------------------
//std::map<std::string, Vertex>::iterator it =this->mapVertex.begin();// initialisation de l'itérator en dehors de la boucle, ca ne devrait par marcher a l'interieur de la boucle ?


/*
 Node::Node(std::string name, int intNode):mapVertex(<std::string, Vertex>){
 this->name = name;
 this-> intNode = intNode;
 }
 */
