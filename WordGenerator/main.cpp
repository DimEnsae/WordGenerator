#include <iostream>
#include <string>
#include <vector>
#include "Automaton.h"
#include <cstdlib> //Standard C library that include atoi()

/*
 Exemple d'entree au terminal
 ./main ../data/NewEN.txt 3 10
 Genere 10 mots a partir du corpus situe en ../data/NewEN.txt avec une memory length de taille 3
 */

int main(int argc, char *argv[])
{
    std::string current_exec_name = argv[0];
    std::cout << current_exec_name << "\n"; //argv[0] is the name of the compiled file (ici ./main)
    std::string path;
    int memory;
    int nbOfWords;
   
    if (argc > 3) {

        path = argv[1];
        memory = atoi(argv[2]); //atoi convert command line argument to int
        nbOfWords = atoi(argv[3]);
        std::cout << "Markov Chain order : " << memory << ", number of generated words : " << nbOfWords << "\n";
        Automaton Auto(path, memory);
        for (int i=0; i<nbOfWords; i++) {Auto.generate_word("#");}
        std::cout << "DONE - Execution time : " << std::endl;
        
        
    }
}
