#include <iostream>
#include "Node.h"

int main(){
    std::cout << "coucou" << std::endl;
    Node N("aa",8);
    N.add_map("a",Vertex(4,0.33));
    Vertex v(4,0.33);
    v.display();
    
    return 0;
}
