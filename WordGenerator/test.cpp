#include <stdlib.h>
#include <stdio.h>
#include <iostream>

int main()
{
    FILE* fichier = NULL;
    int caractereActuel = 0;

    fichier = fopen("./test.txt", "r");

    if (fichier != NULL)
    {
        // Boucle de lecture des caractères un à un
        do
        {
            caractereActuel = fgetc(fichier); // On lit le caractère
            std::cout << char(caractereActuel) ;
            if(char(caractereActuel)=='/n'){std::cout<<"lol";}
        } while (caractereActuel != EOF); // On continue tant que fgetc n'a pas retourné EOF (fin de fichier)

        fclose(fichier);
    }

    return 0;
}
