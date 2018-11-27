#include <iostream>
#include "corpus.h"
#include <string>
#include <fstream>

//surcharge << ?
//generate words clean up and generalize to tensor
//Creer des helpers functions pour generer des mots

int main() {
    
    //vecteurTransition
    vecteurTransition v;
    std::cout << v['d'] << std::endl;
    v.incrementerCompteurLettre('c');
    v.incrementerCompteurLettre('d');
    v.afficher();
    v.rendreStochastique();
    std::cout << v[int('d')] << std::endl;
    v.afficher();
    
    //matricMot (1 order markov chain)
    matriceMot m;
    m.add_word("banane");
    m.add_word("bebobnbcb!");
    m['b'].afficher();
    std::cout << "NEW LINE" << std::endl;
    m.rendreStochastique();
    m.afficherMatrice();
    
    //Tensor of dimension 3 (2 order markov chain)
    std::cout << "TENSOR MOT" << std::endl;
    tensorMot T;
    T.add_word("baabcceggrbbbccabce");
    T.rendreStochastique();
    T['b']['c'].afficher();
    std::cout << T['b']['c']['e'] << std::endl;
    
    
    
    //Comprendre corpus
    //corpus c("./testcorpus.txt");
    //c.afficherMatriceTransition();
    
    
    corpus c2("../data/NewEN.txt");
    c2.afficherMatriceTransition();
    std::cout << "ORDRE 1" << std::endl;
    for (int i =0; i<8; i++) {
    c2.genererUnMotOrdre1('r',8);
    std::cout << std::endl;
    std::cout << std::endl;
    }
    
    std::cout << "ORDRE 2" << std::endl;
    for (int i =0; i<8; i++) {
        c2.genererUnMotOrdre2('r','e',8);
        std::cout << std::endl;
        std::cout << std::endl;
    }
    
     
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
