#include <iostream>
#include "Automaton.h"
#include <string>
#include <algorithm>


/*
std::string concatenate(std::string Tab[], int size) {
    std::string output="";
    for (int i=0; i<(size-1); i++) {
        output += Tab[i];
        output += "_";
    }
    output += Tab[size-1];
    return output;
}

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
}*/


int main(){
//std::cout<<extractNextWord("aa_bb")<<std::endl;
//std::cout<<createNew("aa_bb_cc","bibi",2)<<std::endl;
Automaton a("test_word.txt",3,1);
//Automaton b("test.txt",2,0);

//a.display();
//b.display();
for (int i=0; i<2;i++){a.generate_word(a.get_init());}
//b.generate_word(b.get_init());
    return 0;
}
