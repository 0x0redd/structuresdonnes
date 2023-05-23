#include <stdio.h>
#include <stdlib.h>
#include "pile.c"
#include "file.c"
/*On se donne une file d’entiers que l’on voudrait trier avec le plus grand élément
en fin de file. On n’est autorisé à utiliser que la fonction videf() et les opérations
suivantes :
– defilerEnfiler(f1,f2) : Défile le premier élément de la file f1 et l’ajoute à la
file f2.
– comparer (f1,f2): Retourne 1 si le premier élément de f1 est plus grand ou égal
au premier
élément de f2 et 0 sinon.*/

//1. A partir des primitives de la structure file, proposer un algorithme pour chacune des deux dernières opérations .
void defilerenfiler(file f1,file f2){
    if(!videf(f1)){
        ajouterf(valeur(f1),&f2);
        supprimerf(&f1);
    }
    else printf("premiere file vide \n");
}

void comparer(file f1 , file f2){
    if (videf(f1) || videf(f2)){
        printf("comparaison impossible \n");
        return -1;
    }
    if(valeurf(f1) >= valeurf(f2)) return 1;
    return 0;
}

/* Donner un algorithme de tri qui utilise seulement ces trois opérations et 3 files.
La file f1 contiendra les entiers à trier, f2 contiendra les entiers triés après
exécution et la file f3 pourra servir de file auxiliaire. On pourra, aussi, utiliser la
fonction permuteFile(f1,f2) qui permute le contenu des deux files.*/

void permuteFile(file *f1, file *f2) {
    file f3;
    creerf(&f3);
    while(!videf(*f1)){
        ajouterf(valeurf(*f1),&f3);
        supprimerf(f1);
    }
    while(!videf(*f2)){
        ajouterf(valeurf(*f2),f1);
        supprimerf(f2);
    }
    while(!videf(f3)){
        ajouterf(valeurf(f3),f2);
        supprimerf(&f3);
    }
}


void tri(file f1, file *f2){
    file f3;
    creerf(&f3);
    defilerEnfiler(&f1,f2);

    while (!videf(f1)){

        while (!videf(*f2) && comparer(f1,f2) ) 
            defilerEnfiler(f2,&f3);

        defilerEnfiler(&f1,&f3);

        while(!videf(*f2))
            defilerEnfiler(f2,&f3);

        permuteFile(f2,&f3);
    }
}