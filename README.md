# C++ Project

### Subject

In this project we present a word generator as well as a text generator. Using a corpus of texts we want to obtain texts/words generated automatically using a Markov chain model. The model is really simple and was made to demonstrate our ability to code in C++ for a second year project at ENSAE Paris. This project obtained the best mark for the C++ 2018 class.

`Projet_C.pdf` contains a report of the work provided (in French).


### Manual

- Compilation

Clone the repo and place yourself in the WordGenerator folder. A Makefile takes care of the compilation command (using g++), just enter the command:
```
make
```
Compiling is done under g++, which is normally pre-installed on Mac.

-Use

Call the `main` file from the compilation followed by a PATH giving the address of a corpus, a MEMORYLENGTH integer giving the order of the Markov Chain, and a 0/1 integer giving the MODE to create the graph (1 to generate text, 0 to generate words):
```
./main PATH MEMORYLENGTH MODE
``` 
Examples: 
```
./main ../data/NewEN.txt 3 0
``` 
Uses the dictionary `NewEN.txt` and builds the "letters" graph of the Markov chain of associated order 3.
The user will then be prompted to generate words from terminal.
```
./main ../data/mobydick.txt 4 1
``` 
Uses the novel Moby Dick and builds the "words" graph of the Markov chain of associated fourth order.
The user will then be prompted to generate words from terminal.


### Datasets

The `data` folder contains several toy sets including:
- English, French, Spanish and Hungarian dictionaries
- List of pokemon names in French and in English (generation 1 to 4)
- Moby Dick novel
- List of animal names
- A mix of animal and pokemon names
