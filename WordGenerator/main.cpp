#include <iostream>
#include "Automaton.h"

int main(){
    std::cout << "coucou" << std::endl;
    Node N("aa",8);
    N.add_map("a",Vertex(4,0.33));
    N.add_map("b",Vertex(5,0.6));
    //Vertex v(4,0.33);
    //v.display();
    N.displayNode();
    return 0;
}
