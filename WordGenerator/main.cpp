#include <iostream>
#include "Node.h"

int main(){
    std::cout << "coucou" << std::endl;
    
    //Vertex
    Vertex v(4,0.33);
    v.display();
    
    //Node
    Node N("aa",8);
    N.add_map("a",Vertex(4,0.33));
    N.add_map("b",Vertex(5,0.6)); //Si on met une clé déjà existante ça n'écrase rien, sur de  ca ?
    N.display();

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
