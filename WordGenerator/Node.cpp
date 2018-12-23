#include <iostream>
#include "Node.h"
#include <map>

Node::Node(){
    std::map<std::string , Vertex> mp;
    this->mapVertex = mp;
 }

std::map<std::string , Vertex> Node::getMap(){
    return this->mapVertex;
}


 void Node::add_map(std::string next , Vertex v){
     this->mapVertex.insert(std::pair<std::string ,Vertex>(next,v));
 }

void Node::display(){
    for(std::map<std::string , Vertex>::iterator it=this->mapVertex.begin(); it!=this->mapVertex.end();it++){
    std::cout<< "\t" << it->first<<"=>";
    it->second.display();
  }
}

 void Node::increment(std::string NextLetter){
this->mapVertex.find(NextLetter)->second.increment();}



std::string Node::select_node_suivant(){

  std::string nodeSuivant;
    
  std::map<std::string,int> weightCumule;
    
  int cumul=0;
    
  for(std::map<std::string , Vertex>::iterator it=this->mapVertex.begin(); it!=this->mapVertex.end();it++){

   cumul=cumul+it->second.getWeight();
   weightCumule.insert(std::pair<std::string,int>(it->second.getNextNode(),cumul));
   }
    
  srand(clock());
  float u=(rand()%99999/99999.0)*cumul; //génération de u entre 0 et max cumulé

  for(std::map<std::string , int>::iterator it=weightCumule.begin(); it!=weightCumule.end();it++){

   if(u<=it->second){
   nodeSuivant=it->first;
   break;
   }

  }
  return(nodeSuivant);
}

