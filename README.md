# C++ Project

### Subject

In this project we present a word generator as well as a text generator. Using a corpus of texts we want to obtain texts/words generated automatically using a Markov chain model. The model is really simple and was made to demonstrate our ability to code in C++ for a second year project at ENSAE Paris. This project obtained the best mark for the C++ 2018 class.

`Projet_C.pdf` contains a report of the work provided (in French).


### Manual

- Compilation
Cloner le repo et se placer dans le dossier de codes WordGenerator. Un Makefile s'occupe de la commande de compilation, il suffit d'entrer la commande 
```
make
```
La compilation se fait sous g++ normalement pré-installé sur Mac.

-Utilisation 

Au terminal, appelez le fichier "main" issue de la compilation suivi d'un PATH donnant l'adresse d'un corpus, d'un entier MEMORYLENGTH donnant l'ordre de la chaîne de Markov, et d'un entier 0/1 donnant le MODE de création du graphe (1 pour générer du texte, 0 pour générér des mots). 
```
./main PATH MEMORYLENGTH MODE
``` 
Exemples: 
```
./main ../data/NewEN.txt 3 0
``` 
Utilise le dictionnaire "NewEN.txt" et construit le graphe "lettres" de la chaine de Markov d'ordre 3 associée.
L'utilisateur peut ensuite s'en servir pour génerer des mots au terminal.
```
./main ../data/mobydick.txt 4 1
``` 
Utilise le roman Moby Dick et construit le graphe "mots" de la chaine de Markov d'ordre 4 associée.
L'utilisateur peut ensuite s'en servir pour génerer du texte au terminal.


- Datasets
Le dossier data contient plusieurs toy sets dont :
- dictionnaires anglais, Français, espagnol et Hongrois
- Listes des noms de pokemons en Français en Anglais (génération 1 à 4)
- Moby Dick
- Liste de noms d'animaux
- Un mixte noms d'animaux et de pokemons
