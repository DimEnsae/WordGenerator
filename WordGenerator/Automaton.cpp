#include <iostream>
#include "Automaton.h"
#include <map>
#include <sys/timeb.h>
#include <ctime>
#include <fstream>

Automaton::Automaton(std::string path, int memoryLength){
    std::map<std::string , Node> mp;
    this->mapNode = mp;
    this->memoryLength = memoryLength;
    Node n1;
    Node n2;
    this->add_map("#", n1);
    this->add_map("$", n2);



    std::ifstream ifs(path);
    std::string v;
    ifs>>v;
    while (!ifs.eof()){
     //std::cout<<v;
    this->learnFromWord(v);
    ifs>>v;
    }
    ifs.close();

}

void Automaton::learnFromWord(std::string word){
    int L = this->memoryLength;
    std::string noeud="#";
   for(int i = 0 ;i<word.length();i++){
       std::string noeud_suiv = word.substr (std::max(0,i-L+1), i - std::max(0,i-L+1) + 1);
      // std::cout << "noeud : " << noeud << std::endl;

       std::map<std::string, Node>::iterator it;
       it = this->mapNode.find(noeud_suiv);

       if (it == this->mapNode.end()){
           Node n;
           this->add_map(noeud_suiv, n);
        //   std::cout << "Je suis 1" << std::endl;
           }

       char followingLetter = noeud_suiv[noeud_suiv.length() - 1];

       if (this->mapNode[noeud].getMap().count(followingLetter)>0) {
           this->mapNode[noeud].increment(followingLetter);
          // std::cout << "Je suis 2" << std::endl;
       }
       else{
           this->mapNode[noeud].add_map(followingLetter, Vertex(noeud_suiv, 1));
         //std::cout << "Je suis 3" << std::endl;
  }

       //A BIEN REECRIRE
       /*
       std::map<char, Vertex>::iterator it2;
       it2 = this->mapNode[noeud].getMap().find(followingLetter);
       std::cout << (it2 != this->mapNode[noeud].getMap().end()) << std::endl;

       if (it2 != this->mapNode[noeud].getMap().end()) {
           this->mapNode[noeud].increment(followingLetter);
           std::cout << "Je suis 2" << std::endl;}

           else {
               this->mapNode[noeud].add_map(followingLetter, Vertex(noeud_suiv, 1));
               std::cout << "Je suis 3" << std::endl;
           }
        */

       noeud = noeud_suiv;

       //std::cout << "following letter " << followingLetter << std::endl;
       //std::cout << "noeud_suiiv : " << noeud_suiv << std::endl;
   }
    /*
    std::map<char, Vertex>::iterator it3;
    it3 = this->mapNode[noeud].getMap().find('$');
    if (it3 != this->mapNode[noeud].getMap().end())
        mapNode[noeud].increment('$');
    else {
        this->mapNode[noeud].add_map('$', Vertex("$", 1));
    }*/
    if (this->mapNode[noeud].getMap().count('$')>0) {
        this->mapNode[noeud].increment('$');
    }
    else{
        this->mapNode[noeud].add_map('$', Vertex("$", 1));

    }
}

void Automaton::add_map(std::string idNode, Node node){
    this->mapNode.insert(std::pair<std::string,Node>(idNode,node));
//this->mapVertex[next] =  v;
}

void Automaton::display(){
    std::map<std::string,Node>::iterator it =this->mapNode.begin();

    for(it=this->mapNode.begin();it!=this->mapNode.end();it++){

    std::cout<<it->first<<":"<<std::endl;
    it->second.display();//surcharger par la suite
    std::cout<<std::endl;
    }
}



void Automaton::generate_word(std::string noeud_suivant) {

    if(noeud_suivant != "#"){
      char followingLetter=noeud_suivant[noeud_suivant.length()-1];
      if (followingLetter != '$'){
        std::cout<<followingLetter;}
    }
    if (noeud_suivant == "$") {std::cout<<std::endl;}
    else{
    noeud_suivant=this->mapNode[noeud_suivant].select_node_suivant();
    //std::cout << followingLetter;
    generate_word(noeud_suivant);
  }
}
