#include <iostream>
#include "Automaton.h"
#include <map>
#include <sys/timeb.h>
#include <ctime>
#include <fstream>
#include <array>

//Does not belong IN the class Automaton but is useful here
std::string concatenate(std::string Tab[], int size) {
    std::string output="";
    for (int i=0; i<size; i++) {
        output += Tab[i];
    }
    return output;
}

void equal(std::string Tab1[], std::string Tab2[], int size) {
    for (int i=0; i<size; i++) {
        Tab1[i] = Tab2[i];
    }
}




Automaton::Automaton(std::string path, int memoryLength){
    
    this->memoryLength = memoryLength;
    std::map<std::string , Node> mp;
    this->mapNode = mp;

    Node n1;
    Node n2;
    this->add_map(this->get_init(), n1);
    this->add_map("$", n2);

    this->learnFromWord(path);
}

void Automaton::learnFromWord(std::string path){
    
    int L = this->memoryLength;
    std::string noeud[L];
    std::string noeud_str;
    std::string noeud_suiv[L];
    std::string noeud_suiv_str;
    
    //std::string noeud="#";
    for (int i=0; i<L; i++) {noeud[i] = "#";}
    
    std::ifstream ifs(path);
    std::string v;
    ifs>>v;
    while (!ifs.eof()){
        ifs>>v;
        
        //std::string noeud_suiv = word.substr (std::max(0,i-L+1), i - std::max(0,i-L+1) + 1);
        if (L>1) {
            for (int i=0; i<L-1; i++) {
                noeud_suiv[i] = noeud[i+1];
            }
        }
        noeud_suiv[L-1] = v;
        
        noeud_suiv_str = concatenate(noeud_suiv,L);
        //std::cout << noeud_suiv_str << std::endl;
        
        std::map<std::string, Node>::iterator it;
        it = this->mapNode.find(noeud_suiv_str);

       if (it == this->mapNode.end()){
           Node n;
           this->add_map(noeud_suiv_str, n);
           }

        std::string followingLetter = noeud_suiv[L-1];
        //std::cout << followingLetter << std::endl;

        noeud_str = concatenate(noeud,L);
       if (this->mapNode[noeud_str].getMap().count(followingLetter)>0) {
           this->mapNode[noeud_str].increment(followingLetter);
       }
       else{
           this->mapNode[noeud_str].add_map(followingLetter, Vertex(noeud_suiv_str, 1));
  }

        equal(noeud,noeud_suiv,L);
    }
    ifs.close();

    noeud_str = concatenate(noeud,L);
    if (this->mapNode[noeud_str].getMap().count("$")>0) {
        this->mapNode[noeud_str].increment("$");
    }
    else{
        this->mapNode[noeud_str].add_map("$", Vertex("$", 1));

    }
    this->display();
    
}


void Automaton::add_map(std::string idNode, Node node){
    this->mapNode.insert(std::pair<std::string,Node>(idNode,node));
}

void Automaton::display(){
    std::map<std::string,Node>::iterator it =this->mapNode.begin();

    for(it=this->mapNode.begin();it!=this->mapNode.end();it++){

    std::cout<<it->first<<":"<<std::endl;
    it->second.display();
    std::cout<<std::endl;
    }
}




void Automaton::generate_word(std::string noeud_suivant) {
    
    if(noeud_suivant != this->get_init()){
      char followingLetter=noeud_suivant[noeud_suivant.length()-1];
      if (followingLetter != '$'){
        std::cout<<followingLetter;
          
      }
    }
    
    if (noeud_suivant == "$") {std::cout<<std::endl;}
    
    else{noeud_suivant=this->mapNode[noeud_suivant].select_node_suivant();
        //std::cout << "c : " << noeud_suivant << std::endl;
        
    generate_word(noeud_suivant);
  }
}


std::string Automaton::get_init(){
    std::string init[this->memoryLength];
    for (int i=0; i<this->memoryLength; i++) {init[i] = "#";}
    return concatenate(init, this->memoryLength);
}
