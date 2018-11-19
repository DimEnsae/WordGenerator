#include <iostream>
#include "matriceMot.h"
#include <string>
#include <fstream>

int main() {
    
    //Comprendre vecteurLigne
    
    vecteurLettre v('b');
    std::cout << v.getlettreLigne() << std::endl;
    std::cout << v.getnombreOccurence('d') << std::endl;
    std::cout<< char(125) << std::endl;
    v.incrementerCompteurLettre('c');
    v.incrementerCompteurLettre('d');
    v.afficherBis();
    vecteurLettre w('d');
    w.incrementerCompteurLettre('e');
    vecteurLettre r = w + v;
    r.afficherBis();
    r.rendreStochastique();
    r.afficherBis();
    
    
    vecteurLettre t;
    std::cout << t.getlettreLigne() << std::endl;
    t.afficherBis();
    t.incrementerCompteurLettre('c');
    t.afficherBis();
    
    
    //Comprendre matricMot
    matriceMot m("banane");
    std::cout << m.getMot() << std::endl;
    m.getMatriceTransition('b').afficherBis();
    m.afficherMatrice();
    m.rendreStochastique();
    m.afficherMatrice();
    
    /*
    
    //Comprendre corpus
    corpus c("./testcorpus.txt", "abcdefghijklmnopqrstuvwxyz");
    c.afficherMatriceTransition();
    
    //Essai de creation automatique de listeMot
    
    std::ifstream ifs("./testcorpus.txt");
    std::string x;
    do {
        ifs>>x;
        std::cout<<x<<std::endl;
        for (int i=0;i<x.length();i++) {std::cout << int(x[i]) << " ";}
        std::cout << std::endl;
        
    } while (!ifs.eof());
    ifs.close();
     
     */
    
    
    return 0;
}
