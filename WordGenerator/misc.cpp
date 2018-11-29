#include <iostream>

/*-------------------------------------------------------------------
 Pile of miscelleneaous helper functions
 
 
 -------------------------------------------------------------------*/



char firstLetter(std::string dic){
    //Tire aleatoirement un caractere dans dic
    
    float *cumprob=0;
    cumprob=new float[dic.length()];
    cumprob[0]=1./dic.length();
    for(int i=1; i<dic.length();i++){
        cumprob[i]=cumprob[i-1]+1./dic.length();
    }
    
    srand(clock());
    float u=rand()%99999/99999.0;
    
    int choix;
    if(u<=cumprob[0]){choix=0;}
    for(int i=1;i<dic.length();i++){
        if ((u>cumprob[i-1])&&(u<=cumprob[i])) {choix=i;}
    }
    return(dic[choix]);
}
