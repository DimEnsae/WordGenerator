#include <iostream>
#include "Automaton.h"
#include <string>
#include <algorithm>

void extract_sub(std::string mot, int L){
    for (int i=0; i<mot.length(); i++){
        std::cout << mot.substr (std::max(0,i-L+1), i - std::max(0,i-L+1) + 1 ) << std::endl;
    }
    
}



int main(){
    std::cout << "coucou" << std::endl;
    
    /*
    //Vertex
    Vertex v(4,0.33);
    v.display();
    
    //Node
    Node N("aa",8);
    N.add_map("a",Vertex(4,0.33));
    N.add_map("b",Vertex(5,0.6)); //Si on met une clé déjà existante ça n'écrase rien, sur de  ca ?
    N.display();
     */
    
    /*
    extract_sub("banane",1);
    extract_sub("banane",2);
    extract_sub("banane",3);
    
    std::cout << "bab"[0] << std::endl;*/
    
    
    std::cout << std::endl;
    Automaton a("blabla", 3);
    a.learnFromWord("banane");
    a.learnFromWord("banane");
    //a.learnFromWord("aaaa");
    a.learnFromWord("deco");
   a.display();
    
    
    Node n;
    n.add_map('a', Vertex("ba",3));
    a.add_map("ee", n);
    //a.display();
    

    //std::cout<<Node::NodeCount<<std::endl;
    /*
    Node M("bb",9);
    M.add_map("a",Vertex(9,0.53));
    M.add_map("c",Vertex(7,0.83));
    //N.displayNode();
    //N.increment("a");
     */

    /*
    //N.displayNode();

    
    Automaton A("chemin",1);
    A.add_map(0,N);
    A.add_map(1,M);
    A.display();
     */

    return 0;
}
