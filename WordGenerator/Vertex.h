#include <string>

class Vertex{
private:
    std::string nextNode;
    float weight;
public:
    Vertex(std::string nextNode, float weight);
    void increment();
    void display();
    float getWeight();
    std::string getNextNode();
};
