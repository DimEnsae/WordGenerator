#include <iostream>
#include "corpus.h"
#include <string>
#include <fstream>

int main() {
    //Comprendre vecteurLigne
    
    /*
    vecteurLettre v('b');
    std::cout << v.getlettreLigne() << std::endl;
    std::cout << v.getnombreOccurence('d') << std::endl;
    std::cout<< char(125) << std::endl;
    v.incrementerCompteurLettre('c');
    v.incrementerCompteurLettre('d');
    v.afficher();
    vecteurLettre w('d');
    w.incrementerCompteurLettre('e');
    vecteurLettre r = w + v;
    r.afficher();
    r.rendreStochastique();
    r.afficher();
    
    
    vecteurLettre t;
    std::cout << t.getlettreLigne() << std::endl;
    t.afficher();
    t.incrementerCompteurLettre('c');
    t.afficher();
    
    
    //Comprendre matricMot
    matriceMot m;
    m.add_word("banane");
    m.add_word("bebobnbcb!");
    m.getMatriceTransition('b').afficher();
    //m.afficherMatrice();
    //matriceMot n("noo");
    //matriceMot q = m+n;
    m.rendreStochastique();
    m.afficherMatrice();
     */
    
    
    
    //Comprendre corpus
    corpus c("./testcorpus.txt");
    c.afficherMatriceTransition();
    
    /*
    corpus c2("../data/NewFR.txt");
    c2.afficherMatriceTransition();
    c2.genererUnMot('a',7);
    std::cout << std::endl;
    c2.genererUnMot('d',9);
    std::cout << std::endl;*/
     
    /*
    corpus c2("../german_words.txt");
    c2.afficherMatriceTransition();
    c2.genererUnMot('a',7);
    std::cout << std::endl;
    c2.genererUnMot('d',9);
    std::cout << std::endl;
    std::cout << char(66) << std::endl;*/
    
    //corpus d("../mobydick.txt");
    //d.afficherMatriceTransition();
    
    return 0;
}
