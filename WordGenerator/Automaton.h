
#include <iostream>
#include <string>
#include <map>
#include "Node.h"

class Automaton{
private:
    int memoryLength; //memory of the Automaton
    std::map<int,Node> mapNode;//the nodes
public:
    Automaton(std::string path);
    void fill(std::string word); //on généralisera aux mots plus tard
};
