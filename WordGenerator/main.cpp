//
//  main.cpp
//  WordGenerator
//
//  Created by Dimitri Meunier on 23/10/2018.
//  Copyright © 2018 Dimitri Meunier. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

//name : path of the file, freq : frequency matrix
int display_words (string name, vector<vector<int> > freq) {
    
    ifstream myFile(name); //open file

    if(myFile)
    {
        ifstream myFile(name);
        int compteur=0;
        string v;
        while (myFile.peek() != EOF) {
            myFile >> v;
            cout << v[0] << endl;
            compteur ++;
        }
        myFile.close();
        cout << "Le nombre de mots est : " << compteur << endl;
        
        return compteur;
    }
    else
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
        return 42;
    }
    
}




int main(int argc, const char * argv[]) {
    cout << getenv("PWD") << endl;
    
    //Vecteurs de stockage des frequences
    vector<vector<int> > freq(26, vector<int>(26));
    cout << display_words("../pokemon_names.txt", freq);
    
}


//Idea use structure to link letters to index of the matrixes
