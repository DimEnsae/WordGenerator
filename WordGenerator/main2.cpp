#include <iostream>
#include "corpus.h"
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
    matriceMot n("noo");
    matriceMot q = m+n;
    q.rendreStochastique();
    q.afficherMatrice();
    
    
    
    //Comprendre corpus
    corpus c("./testcorpus.txt");
    c.afficherMatriceTransition();
    
    corpus d("../mobydick.txt");
    d.afficherMatriceTransition();
    
    return 0;
}
