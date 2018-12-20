#include <iostream>
#include "Automaton.h"
#include <map>
#include <sys/timeb.h>
#include <ctime>
#include <fstream>
#include <array>
#include <vector>
#include <sstream>

//Does not belong IN the class Automaton but is useful here
/*std::string concatenate(std::string Tab[], int size) {
    std::string output="";
    for (int i=0; i<(size-1); i++) {
        output += Tab[i];
        output += "_";
    }
    output += Tab[size-1];
    return output;
}*/

void equal(std::string Tab1[], std::string Tab2[], int size) {
    for (int i=0; i<size; i++) {
        Tab1[i] = Tab2[i];
    }
}

std::string extractNextWord(std::string noeud_suivant_str) {
    std::string nextWord="";
    for (int i = (noeud_suivant_str.length()-1); i>=0; i--) {
        if (noeud_suivant_str[i]!='_') {nextWord = noeud_suivant_str[i] + nextWord;}
        else {break;}
    }
    return nextWord;
}

std::string createNew(std::string noeud, std::string newWord, int memory) {
    //Delete First underscore
    if (memory>1) {
    int count=0;
    for (int i = 0; i<noeud.length(); i++) {
        if (noeud[i]=='_') {
            count = i+1;
            break;}
    }
    return noeud.substr (count, noeud.length() - count) + "_" + newWord;
    }
    return newWord;
}


std::vector<std::string> split(std::string strToSplit, char delimeter)
{
    std::stringstream ss(strToSplit);
    std::string item;
    std::vector<std::string> splittedStrings;
    while (std::getline(ss, item, delimeter))
    {
       splittedStrings.push_back(item);
    }
    return splittedStrings;
}


Automaton::Automaton(std::string path, int memoryLength,int word){
    //if word = 1 nodes are words, ord = 0,nodes are letters
    this->word=word;
    this->memoryLength = memoryLength;
    std::map<std::string , Node> mp;
    this->mapNode = mp;
    // typedef std::array<std::string, memoryLength> temp;
    //std::map<temp , Node> mp;
    //this->mapNode = mp;p

    Node n1;
    Node n2;
    this->add_map(this->get_init(), n1);
    this->add_map("$", n2);


      std::ifstream ifs(path);
      std::string v;
      std::string learningObject="";
      char delim='_';

      if (this->word==0){
          while (!ifs.eof()){
              ifs>>v;

              for(int i =0;i<v.length()-1;i++){
                char tmp=v[i];
                learningObject=learningObject+tmp+delim;
              }
              learningObject=learningObject+v[v.length()-1];
                this->learnFromWord(learningObject);
                learningObject="";
              }
      }else{
              std::string learningObject="";
              while (!ifs.eof()){

       ifs>>v;
    //   std::cout<<v<<std::endl;
       if(v[v.length()-1]=='.' || v[v.length()-1]=='!' || v[v.length()-1]=='?' || v[v.length()-1]==':' ){

         if(v.length()==1){learningObject=learningObject+v[0];}
         else{learningObject=learningObject+v.substr(0,v.length()-1)+delim+v[v.length()-1];} //je considère que les ponctuations sont des mots à part entière..
         this->learnFromWord(learningObject);
      //   std::cout<<learningObject<<std::endl;
         learningObject=""; //manque gestion des virgules et point virgule
        }else{
          //manque gestion des virgules et point virgule
          if(v[v.length()-1]==','||v[v.length()-1]==';'){
          if(v.length()==1){learningObject=learningObject+v[0]+delim;}
          else{learningObject=learningObject+v.substr(0,v.length()-1)+delim+v[v.length()-1]+delim;}

        }else{ learningObject=learningObject+v+delim;};
         //std::cout<<learningObject<<std::endl;
       }
       }
       }



            ifs.close();



}

void Automaton::learnFromWord(std::string learningObject){
//learningElement, letters separated by ";""-" or words separated by "-"
// le ";" est fait pour que ça s'adapte aux strings
    int L = this->memoryLength;
    std::string noeud_str;
    std::string noeud_suiv_str;
    noeud_str = this->get_init();



        //Il me faut une fonction qui compte le nombre de trait
        //il me faut une fonction qui prend le mot avant chaque "-"

    //    std::cout<<learningObject<<std::endl;
      std::vector<std::string> LO=split(learningObject,'_');
for(int  i = 0 ; i<LO.size();i++){
    //    std::cout<<"tour"<<i<<std::endl;

    /*   char suiv=learningObject[i];
      std::string del=";";
        std::string learningElement=del+suiv;
        std::cout << learningElement << '\n';*/
        std::string learningElement=LO[i];
        noeud_suiv_str = createNew(noeud_str, learningElement, this->memoryLength);

        std::map<std::string, Node>::iterator it;
        it = this->mapNode.find(noeud_suiv_str);

       if (it == this->mapNode.end()){
           Node n;
           this->add_map(noeud_suiv_str, n);
           }

        if (this->mapNode[noeud_str].getMap().count(learningElement)>0) {
           this->mapNode[noeud_str].increment(learningElement);
       }
       else{
           this->mapNode[noeud_str].add_map(learningElement, Vertex(noeud_suiv_str, 1));
  }

        noeud_str = noeud_suiv_str;
  //  }

}
    //noeud_str = concatenate(noeud,L);
    if (this->mapNode[noeud_str].getMap().count("$")>0) {
        this->mapNode[noeud_str].increment("$");
    }
    else{
        this->mapNode[noeud_str].add_map("$", Vertex("$", 1));

    }
  //  this->display();

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
      //char followingLetter=noeud_suivant[noeud_suivant.length()-1];
        std::string following = extractNextWord(noeud_suivant);
      if (following != "$"){
        std::cout<<following;

       if (this->word==1){//seule condition qui différencie l'affichage de phrase et celle de lettre.
        std::cout << " ";
      }
      }
    }

    if (noeud_suivant == "$") {std::cout<<std::endl;}

    else{noeud_suivant=this->mapNode[noeud_suivant].select_node_suivant();


    generate_word(noeud_suivant);
  }
}


std::string Automaton::get_init(){
    std::string init="";

    if (this->memoryLength>0) {
    for (int i=0; i<(this->memoryLength-1); i++) {init += "#_";}
    init += "#";
    }
    else {init = "#_";}
    return init;
}
