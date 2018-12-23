#include <iostream>
#include <string>
#include <vector>
#include "Automaton.h"
#include <cstdlib> //Standard C library that include atoi()
#include <time.h> //compute time of execution

/* MANUAL
 
./main PATH MEMORYLENGTH MODE
 
PATH -> path to the corpus
MEMORYLENGTH -> markov chain order
MODE = 1 pour generer du texte, 0 pour des mots
 
 
 Exemple d'entree au terminal :
 
 ./main ../data/NewEN.txt 3 0
 
 */

int main(int argc, char *argv[])
{
    clock_t tStart = clock();
    
    std::string current_exec_name = argv[0];
    std::cout << current_exec_name << "\n"; //argv[0] is the name of the compiled file (ici ./main)
    std::string path;
    int memory;
    int nbOfWords;
    int mode;
    
    
    std::cout << "\\ \\      / /__| | ___ ___  _ __ ___   ___" << std::endl;
    std::cout << " \\ \\ /\\ / / _ \\ |/ __/ _ \\| '_ ` _ \\ / _ \\ " << std::endl;
    std::cout << "  \\ V  V /  __/ | (_| (_) | | | | | |  __/ " << std::endl;
    std::cout << "   \\_/\\_/ \\___|_|\\___\\___/|_| |_| |_|\\___| " << std::endl;
    std::cout << std::endl;
    std::cout << "__________________________________________________" << std::endl;
    std::cout << "< Welcome ! Let's play with our word generator ! >" << std::endl;
    std::cout << "--------------------------------------------------" << std::endl;
    std::cout << "\\   ^__^" << std::endl;
    std::cout << " \\  (oo)\\_______" << std::endl;
    std::cout << "  //(__)\\       )\\/\\ " << std::endl;
    std::cout << "         ||----w |" << std::endl;
    std::cout << "         ||     ||" << std::endl;
   
    if (argc > 3) {

        path = argv[1];
        memory = atoi(argv[2]); //atoi convert command line argument to int
        mode = atoi(argv[3]);
        //nbOfWords = atoi(argv[4]);
        std::cout << "Markov Chain order : " << memory;
        if (mode == 1) {std::cout << ", Mode : Text" << std::endl;}
        else {std::cout << ", Mode : Word" << std::endl;}
        std::cout<<std::endl;
        std::cout << "Compute graph ... " << std::endl;
        Automaton Auto(path, memory, mode);
        printf("DONE, TIME TAKEN: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
        std::cout << "Do you want to display the graph ? [y/n] ";
        char answer;
        std::cin >> answer;
        if (answer == 'y') {Auto.display();}
        std::cout << "How many sequences do you want to generate ? [int/ 0 to quit] ";
        int answer2;
        std::cin >> answer2;
        while (answer2 > 0) {
            for (int i = 0; i < answer2; i++) {Auto.generate_word(Auto.get_init());}
            std::cout << std::endl;
            std::cout << "How many sequences do you want to generate ? [int/ 0 to quit] ";
            std::cin >> answer2;
        }
    }
    return 0;
}



