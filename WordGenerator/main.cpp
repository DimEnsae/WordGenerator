#include <iostream>
#include "corpus.h"


int main() {
    corpus c("../data/NewEN.txt");
    std::cout << "Generation a l'ordre 1" << std::endl << std::endl;
    c.genererUnMotOrdre1Bis(9,12);
    std::cout << std::endl;
    std::cout << "Generation a l'ordre 2" << std::endl << std::endl;
    c.genererUnMotOrdre2Bis(9,12);
    c.exportMatriceTocsv("./Mat.txt");
    
    return 0;
}
