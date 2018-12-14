#include <iostream>
#include "Vertex.h"


Vertex::Vertex(int nextNode, float weight){
    this->nextNode = nextNode;
    this->weight = weight;
}

void Vertex::increment() {this->weight++;}

void Vertex::display() {std::cout << "(" << this->nextNode << "," << this->weight << ")" << std::endl;}







