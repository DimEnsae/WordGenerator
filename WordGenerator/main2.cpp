#include <iostream>
#include "vecteurLettre.h"

int main() {
    
    //Comprendre vecteurLigne
    vecteurLettre v('b', "abcdefghijklmnopqrstuvwxyz");
    std::cout << v.getlettreLigne() << std::endl;
    std::cout << v.getnombreOccurence(8) << std::endl;
    v.afficher();
    v.incrementerCompteurLettre('c');
    v.incrementerCompteurLettre('d');
    v.afficherBis();
    vecteurLettre w('d', "abcdefghijklmnopqrstuvwxyz");
    w.incrementerCompteurLettre('e');
    vecteurLettre r = w + v;
    r.afficherBis();
    r.rendreStochastique();
    r.afficherBis();
    
    //
    
    
    return 0;
}
