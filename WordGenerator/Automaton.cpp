#include <iostream>
#include "Automaton.h"
#include <map>



Automaton::Automaton(std::string path, int memoryLength){
  std::map<int, Node> mp;
  this->mapNode = mp;
  this->memoryLength =memoryLength;
}

void Automaton::learnFromWord(std::string word){
   for(int i = 0;i<word.length();i++){


   }
}


void Automaton::add_map(int idNode, Node node){
    this->mapNode.insert(std::pair<int,Node>(idNode,node));
//this->mapVertex[next] =  v;
}

void Automaton::display(){
  std::map<int,Node>::iterator it =this->mapNode.begin();// initialisation de l'itérator en dehors de la boucle
    for(it=this->mapNode.begin();it!=this->mapNode.end();it++){
    std::cout<<it->first<<":"<<std::endl;
    it->second.display();//surcharger par la suite
    std::cout<<std::endl;
    }
}
